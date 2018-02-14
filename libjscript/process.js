console.log(`Process Architecture: ${process.arch}`);  
console.log(`Process PID: ${process.pid}`);  
console.log(`Process Platform: ${process.platform}`);  
console.log(`Process Version: ${process.version}`);  
process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});
process.stdin.on("end", function () {
   processData(_input);
});