const fs = require('fs');
const readline = require('readline');

async function processLineByLine() {

  // first argument in cli does not exixt
  if (process.argv.length < 3) {
    console.log("Usage: node generate_function_info.js <project>")
    process.exit(1)
  }

  const project = process.argv[2]

  const project_path = `../functions/${project}`

  const fileStream = fs.createReadStream(`${project_path}/function_data.dat`);

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  const SELECTED_FUNCTIONS_PATH = `function-picks.json`
  // First, getting the selected functions for the project from the file
  const selected_functions = JSON.parse(fs.readFileSync(SELECTED_FUNCTIONS_PATH))[project]

  selected_functions = []
  for await (const line of rl) {
    o = JSON.parse(line)
    if (selected_functions.map(f => f.name).includes(o.name)) {
      if (o.path.endsWith(selected_functions.find(f => f.name === o.name).filepath)) {
        selected_functions.push(o)
      }
    }
  }

  // write to file
  fs.writeFileSync(`${project_path}/functions_info.json`, JSON.stringify(selected_functions, null, 4));

  // console.log(JSON.stringify(top, null, 4))
}

processLineByLine();