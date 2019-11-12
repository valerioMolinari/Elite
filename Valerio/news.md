comando per installare newalias.js

assicuratevi di aver installato nodejs scrivendo node -v sul terminale
se ce l'avete:
  andate avanti
altrimenti:
  https://nodejs.org/it/

eseguite alias rbp
  se funziona:
    andate direttamente alle installazioni successive
altrimenti:
  Mac:
    echo "alias rbp='source ~/.zshenv'" >> ~/.zshenv
  Linux:
    echo "alias rbp='source ~/.bash_aliases'" >> ~/.bash_aliases

Mac:
  mkdir ~/myshells; rm ~/myshells/newalias.js; cp ~/git/Elite/Valerio/myshells/newalias.js ~/myshells || cp ~/github/Elite/Valerio/myshells/newalias.js ~/myshells; echo "alias newalias='node ~/myshells/newalias.js'" >> ~/.zshenv; rbp;

Linux:
  mkdir ~/myshells; rm ~/myshells/newalias.js; cp ~/git/Elite/Valerio/myshells/newalias.js ~/myshells || cp ~/github/Elite/Valerio/myshells/newalias.js ~/myshells; echo "alias newalias='node ~/myshells/newalias.js'" >> ~/.bash_aliases; rbp;

per capire come funziona scrivete newalias -i
