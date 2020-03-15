const fs = require('fs')
const { execSync } = require("child_process")
const [
  [flag, dictionaryPath], length
] = [process.argv.slice(2), Number(process.argv[4]) || 80];

function printList(path, length) {
  fs.readFile(path, "utf-8", (err, data) => {
    if (err) throw err
    const final = []
    data = data.split('\n').map(s => s.split(',').map(x => x.trim().split('.')[0]).filter(x => x)).flat()
    for (let i = 0; i < length; i++) {
      let name = data[Math.floor(Math.random() * data.length)]
      final.push(name)
      data.splice(data.indexOf(name), 1)
    }
    console.log(JSON.stringify(final).replace('[', '{').replace(']', '}'));
  })
}

let usage = "usage: [-c] [dictionary file path] [number of names]\n"

switch (flag) {
  case '--edit':
    `atom ${__filename}`
    break;
  case '-c':
    printList(dictionaryPath, length)
    break;
  default:
    console.error(`FlagError: unknown flag\n${usage}`)
}
