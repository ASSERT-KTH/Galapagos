const fs = require('fs');
const readline = require('readline');

async function processLineByLine() {
  const fileStream = fs.createReadStream('function_data.dat');

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  const functions = []

  for await (const line of rl) {
    o = JSON.parse(line)
    functions.push(o)
  }

  const sorted = functions.sort( (a,b) => {
    return b.count - a.count  
  })

  const non_trivial = sorted.filter(f => f.end - f.line > 5)
  const non_printf = non_trivial.filter(f => !f.name.includes("printf"))

  const top = non_printf.slice(0,5)

  console.log(JSON.stringify(top, null, 4))
}

processLineByLine();