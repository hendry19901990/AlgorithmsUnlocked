console.log(`Process PID: ${process.pid}`);  
console.log(`Process Platform: ${process.platform}`);  
var stdin = process.stdin;
var stdout = process.stdout;
var version = process.argv[1];
process.on('SIGINT', () => {
    console.log('Got SIGINT. Press Control-D to exit.');
});
process.on('uncaughtException', function (err) {
    console.log('Caught exception: ' + err);
});
function processInput(input){
    console.log('Data : ' + input.toString().trim());
    process.exit();
}
stdin.resume();
stdin.write("Parsing String " + version + '\n');
stdin.once('data', (data) => {
    data = data.toString().trim();
    if(!data || data === ''){
        stdout.write('No data passed...!\n');
        process.exit();
    }
    else{
        processInput(data);
    }
});