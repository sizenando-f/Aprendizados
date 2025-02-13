const fs = require("node:fs")

const content = "Text created with assync writing"

// Forma assíncrona
fs.writeFile("./file.txt", content, "utf8", (error) => {
    let text = error ? `Error on writing file: ${error.message}` : "File wrote with success"
    console.log(text);
})

// Forma síncrona
// try {
//     fs.writeFileSync("./file.txt", "Hello, world!", "utf-8")
//     console.log("File wrote with sucess!")
// } catch (error) {
//     console.log("Error in writing the file: ", error.message)
// }