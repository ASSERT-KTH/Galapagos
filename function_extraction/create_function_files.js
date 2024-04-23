const fs = require('fs');
const readline = require('readline')

const main = () => {

    // first argument in cli does not exixt
    if (process.argv.length < 3) {
        console.log("Usage: node create_function_files.js <project>")
        process.exit(1)
    }

    const project = process.argv[2]

    const project_path = `../functions/${project}`

    const data = fs.readFileSync(`${project_path}/functions_info.json`);

    // Display the file data
    functions = JSON.parse(data)
    functions.forEach((fun, i) => create_file(project_path, fun, i));
}

const create_file = (path, info, index) => {
    const file = fs.readFileSync(info.path, "utf-8");
    const split = file.split("\n")
    func_array = split.slice(info.line - 1, info.end)
    fs.writeFileSync(`${path}/${index}_${info.name}.c`, func_array.join('\n'));
}

main()