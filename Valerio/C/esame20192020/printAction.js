#!/usr/bin/env node

const { execSync } = require("child_process");
const { readFileSync } = require('fs');

const top = (i, j, color = '') => [
  ["/  \\", `/\x1b[37m# ${color}\\`],
  ["   \\", ` \x1b[37m# ${color}\\`],
  ["/  ", `/\x1b[37m# ${color}`]
][i][j];
const aisle = (i, j, color = '') => [
  ["/ /", `/\x1b[37m#${color}/`],
  ["|  |", `|\x1b[37m#${color} |`],
  ["\\ \\", `\\\x1b[37m#${color}\\`]
][i][j];
const low = ["/ __/", "\\  /", "\\__ \\", "\\__/"];

const printPlayer = player => {
  if (player)
    return (player === 'arvais' ? '\x1b[1m\x1b[36m' : '\x1b[1m\x1b[31m') + readFileSync(`${player}.txt`) + "\x1b[0m";
  return ''
}

function processStdin(callback) {
  const stdin = process.openStdin();
  let string = '';
  stdin.on('data', (chuck) => {
    string += chuck;
    stdin.on('end', (chuck) => callback(string));
  });
}

function spaces(n, string) {
  console.log(' '.repeat(n) + string);
}

function caveColors(cave) {
  switch (cave) {
    case '0':
      return "\x1b[0m";
      break;
    case '1':
      return "\x1b[1m\x1b[33m";
      break;
    case '2':
      return "\x1b[1m\x1b[36m";
      break;
    case '3':
      return "\x1b[1m\x1b[31m";
      break;
    case '4':
      return "\x1b[1m\x1b[35m";
      break;
  }
}

function lowAisleTop(player, string, space, connection, option) {
  function cases(thisCase) {
    if (string.length === tlength - 2 && newcave === 'hidden')
      console.log();
    else if (string.length <= tlength - 2 && grey == 'allPath') {
      switch (thisCase) {
        case 's':
          spaces(--space, `\x1b[2m\x1b[37m${low[0]}\x1b[0m`);
          break;
        case 'a':
          spaces(space, `\x1b[2m\x1b[37m${low[1]}\x1b[0m`);
          break;
        case 'd':
          spaces(space++, `\x1b[2m\x1b[37m${low[2]}\x1b[0m`);
      }
      execSync('sleep .1');
    } else
      switch (thisCase) {
        case 's':
          spaces(--space, /cave/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${low[0]}\x1b[0m` : low[0]);
          break;
        case 'a':
          spaces(space, /cave/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${low[1]}\x1b[0m` : low[1]);
          break;
        case 'd':
          spaces(space++, /cave/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${low[2]}\x1b[0m` : low[2]);
          break;
      }
    if (moveDown && string.length === tlength)
      console.log('\n\n');
    if (string.length === tlength && newcave === 'hidden') {
      console.log('\n');
      switch (open) {
        case 's':
          space -= 2;
          break;
        case 'd':
          space += 2;
      }
    } else if (string.length <= tlength && grey == 'allPath') {
      process.stdout.write("\x1b[0m\x1b[2m\x1b[37m");
      switch (thisCase) {
        case 's':
          spaces(--space, aisle(0, 0));
          spaces(--space, top(0, 0));
          break;
        case 'a':
          spaces(space, aisle(1, 0));
          spaces(space, top(0, 0));
          break;
        case 'd':
          spaces(++space + 1, aisle(2, 0));
          spaces(++space, top(0, 0));
      }
    } else {
      process.stdout.write("\x1b[0m\x1b[37m");
      switch (thisCase) {
        case 's':
          spaces(--space, at === 'aisle' && string.length > (tlength > 3 ? 3 : 1) ? aisle(0, 1, caveColors(string[1])) : (/aisle/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${aisle(0, 0)}\x1b[0m` : aisle(0, 0)));
          break;
        case 'a':
          spaces(space, at === 'aisle' && string.length > (tlength > 3 ? 3 : 1) ? aisle(1, 1, caveColors(string[1])) : (/aisle/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${aisle(1, 0)}\x1b[0m` : aisle(1, 0)));
          break;
        case 'd':
          spaces(++space + 1, at === 'aisle' && string.length > (tlength > 3 ? 3 : 1) ? aisle(2, 1, caveColors(string[1])) : (/aisle/.test(grey) && string.length > (tlength > 3 ? 3 : 1) ? `\x1b[2m\x1b[37m${aisle(2, 0)}\x1b[0m` : aisle(2, 0)));
      }
      if (!(string.length < 4 && connection === 'noDown')) {
        process.stdout.write(caveColors(string[2]));
        switch (thisCase) {
          case 's':
            spaces(--space, at === 'low' && string.length > (tlength > 3 ? 3 : 1) ? top(0, 1, caveColors(string[2])) : top(0, 0));
            break;
          case 'a':
            spaces(space, at === 'low' && string.length > (tlength > 3 ? 3 : 1) ? top(0, 1, caveColors(string[2])) : top(0, 0));
            break;
          case 'd':
            spaces(++space, at === 'low' && string.length > (tlength > 3 ? 3 : 1) ? top(0, 1, caveColors(string[2])) : top(0, 0));
        }
      }
    }
  }

  const { at, grey, printDefault, moveDown, open, newcave } = option;
  let constString;
  if (open && open.length === 1)
    string = string.slice(0, 1).concat(open + '0' + string.slice(1));
  else if (open)
    constString = string;
  const tlength = string.length;
  const lastNextDir = string[3];
  printPlayer(player) && console.log(printPlayer(player));
  process.stdout.write(caveColors(string[0]));
  if (connection !== 'noUp')
    spaces(space + 1, /cave/.test(grey) ? "\x1b[2m\x1b[37m__\x1b[0m" : "__");
  spaces(space, at === 'top' ? top(0, 1, caveColors(string[0])) : (/cave/.test(grey) ? `\x1b[2m\x1b[37m${top(0, 0)}\x1b[0m` : top(0, 0)));
  while (string) {
    switch (string[1]) {
      case 's':
        cases('s');
        break;
      case 'a':
        cases('a');
        break;
      case 'd':
        cases('d');
        break;
    }
    string = string.slice(2);
  }
  if (connection !== 'noDown')
    if (open && open.length > 1) {
      switch (open) {
        case 'down':
          spaces(space - 1, '/    \\');
          break;
        case 'down_at_lit':
          spaces(space - 1, `/ \x1b[1m\x1b[37m#${caveColors(constString)}  \\`);
          break;
        case 'down_at_unlit':
          spaces(space - 1, '/    \\');
          break;
        case 'down_at_out_lit':
          spaces(space - 1, '/    \\');
          spaces(space + 1, '\x1b[1m\x1b[37m#\x1b[0m');
          break;
        case 'down_at_out_unlit':
          spaces(space - 1, '/    \\\n');
          break;
      }
    } else
      spaces(space, low[3]);
  switch (lastNextDir) {
    case 'a':
      return { space, printDefault };
      break;
    case 'd':
      return { space: space + 1, printDefault };
      break;
    case 's':
      return { space: space - 1, printDefault };
      break;
    default:
      return { space, printDefault };
  }
}

function printTunnel(p, t, a, nd, callback) {
  const fxLength = [7, 6, 5, 11];
  let latReturn;
  let printDefault = true;
  let space = 32;
  for (let i = 0; i < fxLength[Number(a) - 1]; i++) {
    if (i) {
      if (t.length === 1 && (i === 2 || i === 3) && a !== '4') continue;
      latReturn = callback(p, t, a, nd, i);
      space = latReturn.space;
      printDefault = latReturn.printDefault;
    } else
      space = lowAisleTop(p, t.slice(0, 5), space, t.length > 3 ? 'noDown' : '', { at: 'top', action: '1' }).space;
    if (t.length > 3 && printDefault)
      lowAisleTop('', t.slice(4), space, 'noUp', { action: '1' });
    space = 32;
    execSync('sleep .3');
    if (i !== fxLength[Number(a) - 1] - 1)
      console.clear();
  }
}

function switchAction(player, tunnel, action, nextDirection, iterator) {
  let setOptions = option => lowAisleTop(player, tunnel.slice(0, 5), 32, tunnel.length > 4 ? 'noDown' : '', option);
  let printDefault;
  switch (Number(action)) {
    case 1:
      printDefault = true;
      switch (iterator) {
        case 1:
          return setOptions({ printDefault });
          break;
        case 2:
          return setOptions({ at: 'aisle', printDefault });
          break;
        case 3:
          return setOptions({ printDefault });
          break;
        case 4:
          return setOptions({ at: 'low', printDefault });
          break;
        case 5:
          return setOptions({ at: 'low', grey: 'cave', printDefault });
          break;
        case 6:
          return setOptions({ at: 'low', grey: 'cave&aisle', printDefault });
      }
      break;
    case 2:
      if (iterator === 1)
        lowAisleTop(player, tunnel, 32, '', { printDefault: false, at: 'top', grey: 'allPath' });
      if (iterator === 2)
        process.stdout.write('\x1b[0m' + caveColors(tunnel[0]));
      if (iterator >= 2) {
        printPlayer(player) && console.log(printPlayer(player));
        spaces(33, `${caveColors(tunnel[0])}__`);
        spaces(32, top(0, 1, caveColors(tunnel[0])));
        if (iterator === 2)
          spaces(32, low[3]);
        else
          spaces(nextDirection === 'a' ? 32 : (nextDirection === 's' ? 31 : 32), nextDirection === 'a' ? low[1] : (nextDirection === 's' ? low[0] : low[2]));
      }
      if (iterator >= 4) {
        process.stdout.write("\x1b[0m\x1b[37m");
        spaces(nextDirection === 'a' ? 32 : (nextDirection === 's' ? 30 : 35), nextDirection === 'a' ? aisle(1, 0, ) : (nextDirection === 's' ? aisle(0, 0) : aisle(2, 0)));
      }
      if (iterator === 5) {
        process.stdout.write(caveColors('0'));
        spaces(nextDirection === 'a' ? 32 : (nextDirection === 's' ? 29 : 35), top(0, 0));
        spaces(nextDirection === 'a' ? 32 : (nextDirection === 's' ? 29 : 35), low[3]);
        execSync('sleep .3');
      }
      return 32;
      break;
    case 3:
      setOptions = option => lowAisleTop(player, tunnel, 32, '', option);
      printDefault = false;
      switch (iterator) {
        case 1:
          return setOptions({ moveDown: true, printDefault, at: 'top' });
          break;
        case 2:
          return setOptions({ open: nextDirection, printDefault, at: 'top', newcave: 'hidden' });
          break;
        case 3:
          return setOptions({ open: nextDirection, printDefault, at: 'top', newcave: 'slideIn' });
          break;
        case 4:
          printTunnel(player, tunnel.slice(0, 1).concat(nextDirection + '0' + tunnel.slice(1)), 1, nextDirection, switchAction);
          return 32;
          break;
      }
      break;
    case 4:
      setOptions = option => lowAisleTop(player, tunnel, 32, '', option);
      printDefault = false;
      switch (iterator) {
        case 1:
          setOptions({ open: 'down', printDefault, at: 'top' });
          break;
        case 2:
          setOptions({ open: 'down_at_unlit', printDefault });
          break;
        case 3:
          setOptions({ open: 'down_at_lit', printDefault });
          break;
        case 4:
        case 6:
        case 8:
          setOptions({ open: 'down_at_out_unlit', printDefault });
          break;
        case 5:
        case 7:
        case 9:
          setOptions({ open: 'down_at_out_lit', printDefault });
          break;
        case 10:
          setOptions({ open: 'down_at_out_lit', printDefault });
          console.log("\n\t\tCongratulazioni sei riuscito a uscire! 🥳");
          execSync('sleep 2');
      }
      return 32;
      break;
    default:

  }
}

processStdin((buffer) => {
  const [player, tunnel, [action, nextDirection]] = buffer.split(':');
  printTunnel(player.toLowerCase(), tunnel, action, nextDirection, switchAction);
  process.stdout.write('\x1b[0m');
})
