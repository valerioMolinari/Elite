const { execSync } = require("child_process")
const path = require('path');

const [flag, alias, file] = process.argv.slice(2)
let usage = '\nusage: myshells [-cd-mk--edit]'
usage += '\n\t-i: get infos'
usage += '\n\t-mk: move new shell inside myShells, create an alias and source ~/.zshenv; \n\t     provide alias and file\'s name'
usage += '\n\t-edit: edit myShells.js\n'


switch (flag) {
    case '-i':
        console.log(usage);
        break
    case '--edit':
        execSync(`atom ${__filename}`)
        break
    case '-mk':
        if (/\//.test(file))
            throw 'Error: before using myshells move into the file\'s folder'
        let envoirment
        switch (path.extname(file)) {
            case ".js":
                envoirment = 'n'
                break;
            case ".py":
                envoirment = 'p'
                break
            default:
                throw `Error: unknown or unimplemented ${path.extname(file)} extention yet`
        }
        execSync(`mv ${process.cwd()}/${file} ~/myshells && printf "\nalias ${alias}='${envoirment} ~/myshells/${file}'" >> ~/.zshenv`)
        break
    default:
        throw `error: unknown flag\n${usage}`
}
