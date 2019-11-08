const list = process.argv.slice(2)
if (list.length < 2)
  throw 'Error: at least two arguments are required'
console.log(list[Math.round(Math.random() * (list.length - 1))]);
