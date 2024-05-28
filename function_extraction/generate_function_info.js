const fs = require('fs');
const readline = require('readline');

async function processLineByLine() {

  // first argument in cli does not exixt
  if (process.argv.length < 3) {
    console.log("Usage: node generate_function_info.js <project> [--preprocessed]")
    process.exit(1)
  }

  const project = process.argv[2]

  const preprocessed = process.argv.length == 4 && process.argv[3] === "--preprocessed"
  // if there's a third argument, it must be --preprocessed
  if (process.argv.length == 4 && process.argv[3] !== "--preprocessed") {
    console.log("Usage: node generate_function_info.js <project> [--preprocessed]")
    process.exit(1)
  }

  const project_path = `../functions/${project}`

  const fileStream = fs.createReadStream(`${project_path}/function_data.dat`);

  const rl = readline.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  const SELECTED_FUNCTIONS_PATH = `function-picks.json`
  // First, getting the selected functions for the project from the file
  const selected_functions = JSON.parse(fs.readFileSync(SELECTED_FUNCTIONS_PATH))[project]
  // print the selected functions
  console.log(selected_functions)

  let functions = []
  for await (const line of rl) {
    o = JSON.parse(line)
    // the name must be in the selected functions AND o.path must end with the respective function's file
    if (selected_functions[o.name]) {
      const suffix = preprocessed ? ".i" : [".c", ".h"];
      const endsWithSuffix = preprocessed
        ? o.path.endsWith(selected_functions[o.name] + suffix)
        : suffix.some(ext => o.path.endsWith(selected_functions[o.name] + ext));

      if (endsWithSuffix) {
        console.log("Adding function", o.name, selected_functions[o.name], "to the list of functions.");
        functions.push(o);
      }
    }
  }

  // write to file
  fs.writeFileSync(`${project_path}/functions_info.json`, JSON.stringify(functions, null, 4));

  // console.log(JSON.stringify(top, null, 4))
}

processLineByLine();