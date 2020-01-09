#!/usr/bin/env node

/*
  QUESTO PROGRAMMA SIMULA IL PRE ESAME DI DISCRETA
  scrivete
  ./testDiscreta.js numeroDiDomandeACuiSieteArrivati
  in questa cartella per eseguirlo.

  Per l'alias: newalias discreta "~/git/Elite/Valerio/matematica\ discreta/testDiscreta.js"; rbp
*/

const { execSync } = require("child_process");
const { domande } = require("./question database.json");

const sorteggio = (n) => {
  const desiqual = (element, array) => {
    for (let i = 0; i < array.length; i++)
      if (array[i] === element)
        return true;
    return false;
  }
  const array = domande.slice(0, n).map(x => x.replace(/^\d+\.\s/, ''));
  const result = [];
  let random;
  for (let i = 0; i < 10; i++) {
    if (n == 76) {
      random = Math.floor(Math.random() * (i === 9 ? 4 : 8) + i * 8);
    } else {
      do {
        random = Math.floor(Math.random() * n);
      } while (desiqual(array[random], result));
    }
    result.push(array[random]);
  }
  return result;
}

const q = process.argv[2];
const sorted = sorteggio(q).map((x, i) => `${i+1}. ${x}`);
const min = process.argv[3] * 60000 || 20 * 60000;
const limit = process.argv[4] * 60000 || 2 * 60000;
let secs = min / 1000;

const clock = (sec) => {
  console.clear();
  const a = t => t.toString().length === 1 ? `0${t}` : t;
  const f = (Qs, L) => a(Math.floor(sec / Qs) % L);
  const s = f(1, 60);
  const m = f(60, 60);
  const h = f(3600, 24);
  console.log(`${h}:${m}:${s}\n`);
  console.log(sorted);
}

const startClock = (sound = 'Glass', flowTime = true) => {
  execSync(process.platform === 'darwin' ? `afplay /System/Library/Sounds/${sound}.aiff` : 'printf \\a');
  if (flowTime) {
    console.log(clock(secs--));
    const int = setInterval(() => { console.log(clock(secs--)) }, 1000);
    setTimeout(() => clearInterval(int), limit);
  }
}

for (let i = 0; i < 3; i++) {
  startClock('Basso', false);
  execSync('sleep .5');
}

setTimeout(() => clearInterval(int), min);
startClock();
const int = setInterval(() => {
  secs--;
  startClock();
}, limit);
