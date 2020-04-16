import curses
import os

class Menu:
    __voices = []
    __choice = ''
    __options = {}
    def __init__(self, voices, **kwargs):
        self.__voices = list(map(lambda s : s.lower(), voices))
        self.__options = kwargs

    @staticmethod
    def __print(stdscr, color_pair, y, x, string):
        stdscr.attron(curses.color_pair(color_pair))
        stdscr.addstr(y, x, string)
        stdscr.attroff(curses.color_pair(color_pair))

    def print_menu(self, stdscr, selected):
        curses.curs_set(0)
        stdscr.clear()
        cap_voices = [s.capitalize() for s in self.__voices]
        increment = 0
        if 'head' in self.__options:
            self.__print(stdscr, 1, 0, 0, self.__options['head'])
            increment = 2
        for index, voice in enumerate(cap_voices):
            self.__print(stdscr, 2 if index is selected else 1, index + increment, 0, voice)
        stdscr.refresh()

    def __main(self, stdscr):
        curses.init_pair(1, curses.COLOR_GREEN, curses.COLOR_BLACK)
        curses.init_pair(2, curses.COLOR_BLACK, curses.COLOR_WHITE)
        key = 0
        selected = 0
        while not key in [10, 13]:
            self.print_menu(stdscr, selected)
            key = stdscr.getch()
            if key == curses.KEY_UP:
                if selected == 0:
                    selected = len(self.__voices) - 1
                else:
                    selected -= 1
            elif key == curses.KEY_DOWN:
                if selected == len(self.__voices) - 1:
                    selected = 0
                else:
                    selected += 1
        self.__choice = self.__voices[selected].lower()

    def raw_menu(self):
        os.system('cls' if os.name == 'nt' else 'clear')
        curses.wrapper(self.__main)
        return self.__choice

    def full_menu(self):
        self.__voices.append("torna indietro")
        self.__voices.append("salva ed esci")
        return self.raw_menu()

if __name__ == '__main__':
    pass