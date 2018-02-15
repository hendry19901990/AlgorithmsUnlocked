console.log(`Process Architecture: ${process.arch}`);  
console.log(`Process PID: ${process.pid}`);  
console.log(`Process Platform: ${process.platform}`);  
console.log(`Process Version: ${process.version}`);  
function processData(input) {
    console.log(input.toString());
} 
process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", (input) => {
    _input += input;
});
process.on('SIGINT', () => {
    console.log('Got SIGINT. Press Control-D to exit.');
   });
process.stdin.on("end", () => {
   processData(_input);
}); /* Ctrl + D */