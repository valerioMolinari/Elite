/*
  il contenuto del flag -n va applicato a tutti
  infatti inserito un flag diverso da -n stdio e main saranno inclusi
  i flag possono essere composti per inserire più librerie
*/

const fs = require('fs')
const { exec } = require("child_process")

const [flag, fileName] = process.argv.slice(2)
const libraries = {
  stdio: {
    flag: 'n',
    include: "#include <stdio.h>"
  }
}

const newLib = (name, flag, include) => libraries[name] = { flag, include }

newLib('stdlib', 'l', '#include <stdlib.h>')
newLib('time', 't', '#include <time.h>')
newLib('unistd', 'u', '#include <unistd.h>')
newLib('math', 'm', '#include <math.h>')
newLib('string', 's', '#include <string.h>')

const flagArr = Object.entries(libraries).map(x => x[1].flag)
const getLib = (flag) => Object.entries(libraries).filter(x => x[1].flag == flag)[0]

let message = 'usage: [-i, -n, --edit]'
message += '\n\t-i: show this message'
message += '\n\t-n: create new file.c with stdio.h and main inside'
message += '\n\t-s: create new file.c with stdio.h, stdlib.h, main and system("clear") inside'
message += '\n\t--edit: edit this program in atom'

if (!(/^-/.test(flag)))
  throw `Error: first argument must be a flag but recieved ${flag}\n\n${message}`

if (flag === '--edit')
  exec(`atom ${__filename}`)
else if (flag === '-i')
  console.log(message);
else {
  const slicedFlag = flag.slice(1)
  for (letter of slicedFlag)
    if (flagArr.indexOf(letter) === -1)
      throw `Error: -${letter} is an unknown flag\n\n${message}`
  let head = libraries.stdio.include;
  for (letter of slicedFlag)
    head += '\n' + getLib(letter)[1].include
  return console.log(head);

}


switch (flag) {
  case '--edit':
    exec(`atom ${__filename}`)
    break;
  case '-i':
    console.log(message);
    break;
  case '-n':
    main(/\.c$/.test(fileName) ? fileName.slice(0, fileName.length - 2) : fileName, '#include <stdio.h>\n\nint main(void) {\n\n}')
    break;
  case '-s':
    main(/\.c$/.test(fileName) ? fileName.slice(0, fileName.length - 2) : fileName, '#include <stdio.h>\n#include <stdlib.h>\n\nint main(void) {\n\tsystem("clear");\n\n}')
    break;
  default:
    console.error('Error: unknown flag')
    console.log(message);
}

function main(fileName, text, number = 0) {
  const name = `${fileName}${number ? ` ${number}`:''}.c`
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
