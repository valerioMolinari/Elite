#!/usr/bin/env node

const { readFile } = require('fs');
const { execSync } = require("child_process");
const [effect, file] = process.argv.slice(2);
readFile(`${__dirname}/${file.toLowerCase()}`, 'utf8', (err, data) => {
  data = data.split('\n').map(x => x.trimRight()).filter(x => x);
  if (!(/slide/.test(effect)))
    for (let i = 0; i < data.length + 4; i++) {
      console.clear()
      if (effect === 'death')
        console.log('\n\n\n\n\n');
      else
        console.log('\n\n\n\n\n\n\n\n\n\n\n\n\n\n');
      for (let j = 0; j < i + 1; j++) {
        switch (j) {
          case i:
            if (effect === 'death')
              execSync('sleep .04');
            else
              execSync('sleep .1');
            if (effect === 'death')
              process.stdout.write('\x1b[31m    ');
            else
              process.stdout.write('\x1b[31m');
            break;
          case i - 1:
            if (effect === 'scontro')
              process.stdout.write('\x1b[93m');
            else if (effect === 'baco')
              process.stdout.write('\x1b[91m');
            else if (effect === 'death')
              process.stdout.write('\x1b[91m   ');
            break;
          case i - 2:
            if (effect === 'death')
              process.stdout.write('\x1b[31m  ');
            else
              process.stdout.write('\x1b[31m');
            break;
          case i - 3:
            if (effect === 'death')
              process.stdout.write('\x1b[31m ');
            break;
        }
        if (data[j])
          console.log(data[j]);
        process.stdout.write('\x1b[0m');
      }
    }
  else {
    if (/left/i.test(effect))
      for (let i = 0; i < (160 - data[data.length - 1].length) / 2; i++) {
        console.clear();
        for (let j = 0; j < data.length; j++)
          console.log((/arvais/i.test(file) ? '\x1b[96m' : '\x1b[91m') + ' '.repeat(i) + data[j] + '\x1b[0m');
        execSync('sleep .001');
      }
    else
      for (let i = 160 - data[data.length - 1].length; i > (160 - data[data.length - 1].length) / 2; i--) {
        console.clear();
        for (let j = 0; j < data.length; j++)
          console.log((/arvais/i.test(file) ? '\x1b[96m' : '\x1b[91m') + ' '.repeat(i) + data[j] + '\x1b[0m');
        execSync('sleep .001');
      }
  }
  console.log('\n\n');
});
