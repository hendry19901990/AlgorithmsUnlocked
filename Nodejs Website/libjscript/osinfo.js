const operating_system = require('os');
console.log("Geting OS information...")
function osInformation (){
    console.log("Dir : " + operating_system.homedir());
    console.log("Computer Name : " + operating_system.hostname());
    console.log("Operating System : " + operating_system.platform());
    console.log("Operating System Info : " + operating_system.type());
    console.log("Releases : " + operating_system.release());
    console.log("Architechture : " + operating_system.arch());
    console.log("CPU Info : " + operating_system.cpus());
    console.log("Endianness(OS) : " + operating_system.endianness());
    console.log("Average Loading Times " + operating_system.loadavg());
    console.log("ON Since : " + operating_system.uptime());
    console.log("Free System Memory : " + operating_system.freemem());
    console.log("Total System Memory : " + operating_system.totalmem());
    console.log("Network Interfaces : " + operating_system.networkInterfaces());
    console.log("User Information" + operating_system.userInfo());
}
setTimeout(osInformation,1200);