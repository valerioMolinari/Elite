const { readFile, writeFileSync } = require('fs');

readFile('scontroFinale.txt', 'utf8', (err, data) => {
  if (err) throw err;
  data = data.split('k').map(x => x.split('\n').filter(x => x));
  let string = '';
  console.log(data);
  for (let i = 0; i < data[0].length; i++) {
    string += data[0][i] + '\t\t' + data[1][i] + '\n';
  }
  writeFileSync('scontroFinaleAggiustato.txt', string, (err) => { if (err) throw err; })
});
