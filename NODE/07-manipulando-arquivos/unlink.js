const fs = require("node:fs")

fs.unlink("file.csv", (error) => {
    let text = error ? `Error on deleting file: ${error.message}` : "File deleted successfully!"
    console.log(text)
})