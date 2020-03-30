const fs = require('fs')

const [path] = process.argv.slice(2)

fs.readFile(path, 'utf8', (err, data) => {
  if (err) throw err;
  data = data.split('\n')

  const matrixs = []

  for (let i = 0; i < array.length; i++) {
    if (!data[i])
      matrixs.push()
  }


  console.log(data);
  // data = JSON.stringify(data.split('\n').filter(str => str.length > 1).map(str => str.split(" ").filter(x => x)))
  //   .replace(/\[/g, '{')
  //   .replace(/\]/g, '}')
  //   .replace(/"/g, '')
  // console.log(`new Matrix(new int[][] ${data});`);
});
