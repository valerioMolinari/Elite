// installazione: rm ~/myshells/valeshell.js; cp ~/git/Elite/Valerio/myshells/valeshell.js ~/myshells
// alias: newalias valeshell "node ~/myshells/valeshell.js"

//Funziona solo sui sistemi POSIX

if (process.platform === 'win32')
  return console.log('Unfortunately this program doesn\'t work on window, change OS ;)');

const fs = require('fs')
const path = require('path')
const { execSync, exec } = require("child_process")
const [flag, file] = process.argv.slice(2)
const fileName = path.basename(`${__dirname.split('/').slice(0,3).join('/')}/git/Elite/Valerio/myshells/${file}`, '.js')
const dirsplit = __dirname.split('/')
const mainFolder = dirsplit.slice(0, 3).join('/')
if (dirsplit[dirsplit.length - 1] !== 'myshells')
  return console.log(`\nError: newalias.js must be located in ${mainFolder}/myshells to work, now it is in ${__dirname}\n`);
const bash_profile = process.platform === 'darwin' ? `${mainFolder}/.zshenv` : `${mainFolder}/.bash_aliases`

let message = 'usage: [-i, -n, --edit]'
message += '\n\t-i: show this message'
message += '\n\t-n: add Valerio\'s program to myshells folder and makes an alias, use "valeshell -n [program\'s name]"'
message += '\n\t--edit: edit this program in atom'

switch (flag) {
  case '--edit':
    exec(`atom ${__filename}`)
    break;
  case '-i':
    console.log(message);
    break;
  case '-n':
    exec(`rm ~/myshells/${file}; cp ~/git/Elite/Valerio/myshells/${file} ~/myshells`, (err) => {
      if (err) throw err;
      console.log(`${file} added to ${mainFolder}/myshells\n`)
      fs.readFile(bash_profile, 'utf8', (err, data) => {
        if (err) throw err;
        if (!(new RegExp(`alias ${fileName}`).test(data)))
          exec(`echo "alias ${fileName}='node ~/myshells/${file}'" >> ${bash_profile}`, (err) => {
            if (err) throw err;
            console.log(`alias ${fileName} added to ${bash_profile}`);
          })
      })
    })
    break;
  default:
    throw `Error: ${flag} is an unknown flag\n\n${message}`
}
