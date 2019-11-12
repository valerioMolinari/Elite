const { execSync } = require("child_process")
const p = process.argv.slice(2)
let i, price, time;

const clock = (sec) => {
  console.clear()
  const a = t => t.toString().length === 1 ? `0${t}` : t
  const f = (Qs, L) => a(Math.floor(sec / Qs) % L)
  const s = f(1, 60)
  const m = f(60, 60)
  const h = f(3600, 24)
  console.log(`${h}:${m}:${s}`)
}

const convertTime = (s) => {
  if (!(/\:/.test(s)))
    return 0
  s = s.split(':').map(Number)
  return s[0] * 3600 + s[1] * 60 + s[2]
}

const startClock = (callback = () => {}) => {
  i = convertTime(time)
  setInterval(() => {
    clock(i)
    callback(i)
    i++
  }, 1000)
}

let usage = '\nusage: clock [--edit-i-t-p]'
usage += '\n\t--edit: edit file clock.js'
usage += '\n\t-i: edit file clock.js'
usage += '\n\t-t: throws a cronometer ([,startTime])'
usage += '\n\t-p: throws a cronometer calculating a salary (price[,startTime]).js\n'

const flag = p[0]

switch (flag) {
  case '--edit':
    execSync(`atom ${__filename}`)
    break;
  case '-i':
    console.log(usage);
    break;
  case '-t':
    time = p[1]
    startClock()
    break;
  case '-p':
    price = p[1] / 3600
    time = p[2]
    startClock(x => console.log('€ ' + (x * price).toFixed(2)))
    break;
  case '-pv':
    price = p[1] / 3600
    time = p[2]
    price2 = p[3] / 3600
    afterTime = convertTime(p[4])
    startClock(x => console.log('€ ' + (x <= afterTime ? x * price : (afterTime * price + (x - afterTime) * price2)).toFixed(2)))
    break;
  default:
    throw `error: unknown flag\n${usage}`
}
