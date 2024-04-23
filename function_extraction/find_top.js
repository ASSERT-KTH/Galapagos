const fs = require('fs');
const readline = require('readline');

async function processLineByLine() {

  // first argument in cli does not exixt
  if (process.argv.length < 3) {
    console.log("Usage: node find_top.js <project>")
    process.exit(1)
  }

  const project = process.argv[2]

  const project_path = `../functions/${project}`

  const fileStream = fs.createReadStream(`${project_path}/function_data.dat`);

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  const functions = []

  for await (const line of rl) {
    o = JSON.parse(line)
    functions.push(o)
  }

  const sorted = functions.sort((a, b) => {
    return b.count - a.count
  })

  const non_trivial = sorted.filter(f => f.end - f.line > 5 && 35 > f.end - f.line)
  const non_printf = non_trivial.filter(f =>
    !f.name.includes("print") &&
    !f.name.includes("error") &&
    !f.name.includes("usage")
  )

  const top = non_printf.slice(0, 50)

  // write to file
  fs.writeFileSync(`${project_path}/functions_info.json`, JSON.stringify(top, null, 4));

  // console.log(JSON.stringify(top, null, 4))
}

processLineByLine();