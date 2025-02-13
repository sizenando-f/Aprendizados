const fs = require("node:fs")

fs.rename("file.txt", "file.csv", (error) => {
    let text = error ? `Archive couldn't be renamed: ${error.message}` : "Archive was renamed successfully!"
    console.log(text)
})