var spawn = require('child_process').spawn;
var start = spawn('ls');
start.on('close', function(data){
  if(data === 0) {
    var compile = spawn('g++',['run.cpp','-O3','-W','-pedantic','-march=native','-o','run.exe']);
    compile.stdout.on('data', (data) => {
        console.log('status : Compiling Started : ' + data);
    });
    compile.stderr.on('data', (data) => {
        console.log(String(data));
    });
    compile.on('close', (output, jsonDate) =>  {
      console.log('Compilation done. Exited with code ' + output);
      var run = spawn('./run.exe', []);
      run.stdout.on('data', (output) => {
          console.log(String(output));
      });
      run.stderr.on('data', (output) => {
          console.log(String(output));
      });
      run.on('close', (output) => {
          console.log('Execution done. Exited with code ' + output);
      })
    })
  }
})
