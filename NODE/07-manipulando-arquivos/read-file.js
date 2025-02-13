const fs = require("node:fs")

const filename = "file.txt"

// Forma assíncrona
if(fs.existsSync(filename)){
    fs.readFile("./file.txt", "utf-8", (error, data) => {
        let text = error ? `Error reading file: ${error.message}` : data.split(",")
        console.log(text)
    })
} else {
    console.log("The archive doens't exists")
}

// Forma síncrona
// try {
//     const data = fs.readFileSync("./file.txt", "utf-8")
//     console.log(data)
// } catch (error) {
//     console.log("Error on reading file: ", error.message)
// }