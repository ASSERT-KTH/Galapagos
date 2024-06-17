const fs = require('fs');
const readline = require('readline');

async function processLineByLine() {

  // first argument in cli does not exixt
  if (process.argv.length < 4) {
    console.log("Usage: node generate_function_info.js <project>")
    process.exit(1)
  }

  const project = process.argv[2]
  const usecase_dir = process.argv[3]

  const pwd = process.cwd()
  const project_path = `${pwd}/../functions/${project}`

  const fileStream = fs.createReadStream(`${project_path}/function_definitions.dat`);

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
      console.log("Selected function", o.name, selected_functions[o.name]);
      const suffixes = [".c", ".h"];
      if (project == "libgcrypt" || suffixes.some(ext => o.path.endsWith(selected_functions[o.name] + ext))) {
        console.log("Adding function", o.name, selected_functions[o.name], "to the list of functions.");
        functions.push(o);
      }
    }
  }

  // now, for each function, we need to append its call count in the source codebase to the object
  // - cd to it
  // - run `cscope -R -b -q`
  // - for every function in project_path/functions_info.json, run
  //  N=`cscope -d -L3 $FUN | wc -l`
  //  echo "$a" | sed -E 's/[}]$/, \"count\": '"$N"'}/g'

  // cd to the project
  process.chdir(usecase_dir);

  // run cscope
  const { execSync } = require('child_process');
  execSync('cscope -R -b -q');

  // for each function, get the call count
  for (let i = 0; i < functions.length; i++) {
    const fun = functions[i];
    const N = execSync(`cscope -d -L3 ${fun.name} | wc -l`).toString().trim();
    functions[i].count = parseInt(N);
  }

  process.chdir(project_path);

  // write to file
  fs.writeFileSync(`functions_info.json`, JSON.stringify(functions, null, 4));

  // console.log(JSON.stringify(top, null, 4))
}

processLineByLine();
