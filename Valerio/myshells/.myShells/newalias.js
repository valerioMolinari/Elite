const fs = require('fs')
const { execSync } = require("child_process")
const bash_profile = '~/.zshenv'
const error = 'Error: 2 parameters expected (alias and body) but'
if (process.argv[2] === '--edit')
  return execSync(`atom ${__filename}`)
if (!process.argv[2])
  throw `${error} none recieved`
if (!process.argv[3])
  throw `${error} only one recieved`
if (process.argv[4])
  throw `${error} at least 3 recieved, try to wrap the body between quotation marks: "" `
const alias = `\n\nalias ${process.argv[2]}='${process.argv[3]}'`
fs.appendFile(bash_profile, alias, (err) => {
  if (err) throw err;
  fs.readFile(bash_profile, 'utf8', (err, data) => {
    if (err) throw err;
    data = data.split('\n').filter(x => x)
    data = data.slice(data.length - 3).join('\n')
    console.log(`\n.\n.\n.\n${data}\n`);
  });
})
