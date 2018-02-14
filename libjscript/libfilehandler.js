const http = require('http');
const file = require("fs");
const buffer = new Buffer(8192);
console.log("Working On:"+ __filename);
file.readFile('jar.txt',(error,data) => {
    if(error){return console.error(err);}
    console.log("ReadAsync Invoked -> " + "\n" + data.toString());
});
file.open('jar.txt','rs+',(error,data) => {
    if(error){
        return console.error(error);
    }
    console.log("File Opened Successfully, Reading File...");
    file.read(data, buffer, 0, buffer.length, 0, (error, bytes, buffer) => {
        if(error){
            return console.error(error);
        }
        console.log(bytes + " bytes read");
        if(bytes > 0){
            console.log(buffer.slice(0, bytes).toString());
        }
    });
});

