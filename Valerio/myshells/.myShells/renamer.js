const fs = require('fs');
const { execSync } = require('child_process');
const scanf = require('scanf');

const filesPath = process.argv[2]
const app = process.argv[3] ? process.argv[3] : 'preview'
const dir = fs.readdirSync(filesPath, 'utf8')
console.log('Folder:');
console.log(dir);
let name;
let ext;
for (file of dir) {
  if (/^\./.test(file)) continue
  ext = file.match(/\.[a-zA-Z]+$/)[0]
  execSync(`open '${filesPath}/${file}'`)
  process.stdout.write(`${file} to: `)
  name = scanf('%s')
  if (typeof name === 'object') {
    execSync(`osascript -e 'tell application "${app}" to quit'`)
    continue
  }
  fs.renameSync(`${filesPath}/${file}`, `${filesPath}/${name + ext}`)
  execSync(`osascript -e 'tell application "${app}" to quit'`)
}
