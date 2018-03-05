const http = require('http');
const file = require('fs');
var events = require('events');
const buffer = new Buffer(8192);
console.log("Working On:"+ __filename + "\n");
file.readFile('jar.txt',(error,data) => {
    if(error){
        return console.error(error.stack);
    }
    file.writeFile('dump.txt', data.toString(), (error,bindata) => {
        if(error){
            return console.error(error.stack);
        }
        console.log("Data Written\n");
    });
});
file.open('jar.txt','rs+',(error,fd_data) => {
    if(error){
        return console.error(error.stack);
    }
    console.log("File Opened Successfully, Reading File...\n");
    file.read(fd_data, buffer, 0, buffer.length, 0, (error, bytes, buffer) => {
        if(error){
            return console.error(error.stack);
        }
        console.log(bytes + " bytes read\n");
        if(bytes > 0){
            console.log(buffer.slice(0, bytes).toString() + "\n");
        }
        file.close(fd_data,(error) => {
            if(error){
                return console.error(error.stack);
            }
            console.log("File closed successfully.\n");
        });
    });
});
file.stat('dump.txt',(error,data) => {
    if(error){
        return console.error(error.stack);
    }
});




