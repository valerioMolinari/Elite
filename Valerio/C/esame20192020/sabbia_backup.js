const fs = require('fs');
const path = '/Users/mr.anderson2159/git/Elite/Valerio/C/esame20192020/gamelib.c';
const backup = [
  '/Users/mr.anderson2159/Library/Mobile Documents/com~apple~CloudDocs/Sviluppo/C/esame201920120/gamelib_backup.c',
  '/Users/mr.anderson2159/git/Elite/Valerio/C/esame20192020/gamelib_backup.c'
];

const printTime = () => {
  const date = new Date();
  console.log(`${date.toDateString()} ${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`);
}

console.clear();
const doBackup = () => {
  fs.readFile(path, 'utf8', (err, data) => {
    if (err) throw err;
    printTime();
    console.log('\tData read');
    for (let i = 0; i < 2; i++)
      fs.writeFile(backup[i], data, (err) => {
        if (err) throw err;
        console.log('\tbackup effettuato su ' + backup[i]);
      })
  });
}
doBackup();
setInterval(doBackup, 1800000);
