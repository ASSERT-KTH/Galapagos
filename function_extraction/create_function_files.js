const fs = require('fs');
const readline = require('readline')

const main = () => {  
    const data = fs.readFileSync('./top_functions.json');
    
    // Display the file data
    functions = JSON.parse(data)
    functions.forEach(fun => create_file(fun));
} 

const create_file = info => {
    const file = fs.readFileSync(info.path, "utf-8");
    const split = file.split("\n")
    func_array = split.slice(info.line - 1, info.end)
    fs.writeFileSync(`../functions/openssl/${info.name}`, func_array.join('\n') );
}

main()