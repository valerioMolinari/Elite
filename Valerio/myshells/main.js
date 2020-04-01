// installazione: se avete valeshell -> valeshell -n main.js
// altrimenti -> rm ~/myshells/main.js; cp ~/git/Elite/Valerio/myshells/main.js ~/myshells;newalias main "node ~/myshells/main.js"

//Funziona solo sui sistemi POSIX

if (process.platform === 'win32')
  return console.log('Unfortunately this program doesn\'t work on window, change OS ;)');

const fs = require('fs')
const { exec } = require("child_process")

const [lang, flag, ...fileName] = process.argv.slice(2)

// Contiene tutte le librerie
const libraries = {
  stdio: {
    flag: 'n',
    include: "#include <stdio.h>"
  }
}

// Aggiunge una libreria a libraries
const newLib = (name, flag, include) => libraries[name] = { flag, include }

newLib('stdlib', 'l', '#include <stdlib.h>')
newLib('time', 't', '#include <time.h>')
newLib('unistd', 'u', '#include <unistd.h>')
newLib('math', 'm', '#include <math.h>')
newLib('string', 's', '#include <string.h>')
newLib('ctype', 'c', '#include <ctype.h>')
newLib('iostream', 'i', '#include <iostream>')

// Array dei flag delle librerie
const flagArr = Object.entries(libraries).map(x => x[1].flag)
// Restituisce una libreria partendo da un flag
const getLib = (flag) => Object.entries(libraries).filter(x => x[1].flag == flag)[0]

// Messaggio informazioni
let message = 'usage: [-c, -c++] [-i, -nltums, --edit]'
message += '\n\t-i: show this message'
message += '\n\t-n: create new file.c with stdio.h and main (-n is also applied to all the other flags)'
message += '\n\t-l: create new file.c with stdlib.h and system("clear")'
message += '\n\t-t: create new file.c with time.h'
message += '\n\t-u: create new file.c with unistd.h'
message += '\n\t-m: create new file.c with math.h'
message += '\n\t-s: create new file.c with string.h'
message += '\n\t-c: create new file.c with ctype.h'
message += '\n\t-i: create new file.cpp with iostream and main'
message += '\n\t-_: insert low dash to separate_name_like_this'
message += '\n\t--edit: edit this program in atom'

if (!(/^-/.test(lang)))
  throw `Error: first argument must be a flag but recieved ${lang}\n\n${message}`

if (lang === '--edit')
  exec(`atom ${__filename}`)
else if (lang === '-i')
  console.log(message);
else if (lang === '-c' || lang === '-c++') {
  const mergedName = fileName.join(' ')
  let slicedFlag = flag.slice(1)
  let file;
  // Elimina l'estensione dal nome del file
  if (lang === '-c')
    file = /\.c$/.test(mergedName) ? mergedName.slice(0, mergedName.length - 2) : mergedName
  else
    file = /\.cpp$/.test(mergedName) ? mergedName.slice(0, mergedName.length - 4) : mergedName
  // Crea un nome separato da underscores
  if (/_/.test(flag)) {
    file = file.split(/\s/).join('_')
    slicedFlag = Array.from(slicedFlag).filter(x => x !== '_').join('')
  }
  let head = lang === "-c" ? libraries.stdio.include : libraries.iostream.include;
  for (letter of slicedFlag)
    if (flagArr.indexOf(letter) === -1)
      throw `Error: -${letter} is an unknown flag\n\n${message}`
  for (letter of slicedFlag)
    if (letter !== 'n' && letter !== 'i')
      head += '\n' + getLib(letter)[1].include
  head += '\n\nint main(void) {\n\tsystem("clear");\n\n}'
  main(file, head)
}

function main(fileName, text, number = 0) {
  const name = `${fileName}${number ? ` ${number}`:''}.${lang === '-c' ? 'c' : 'cpp'}`
  fs.stat(name, (err, data) => {
    if (err) {
      if (err.code === 'ENOENT')
        return write(name, text)
      else throw err
    }
    main(fileName, text, ++number)
  })
}

function write(fileName, text) {
  fs.writeFile(fileName, text, (err) => {
    if (err) throw err;
    console.log(`${process.cwd()}/${fileName}`);
    exec(`atom "${fileName}"`)
  })
}
