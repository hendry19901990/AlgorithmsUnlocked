var http = require('http');
var url = require('url');
var fs = require("fs");
var port = 5656;
var hostname = '127.0.0.1';
var server = http.createServer(server_engine);
/* Read a Json File */
var jsonData = fs.readFileSync('data.json');
server_engine => (request,response,error) => {
    response.setHeader('Content-Type','application/json');
    response.writeHead(200,{'Content-Type':'application/json'});
    var urlData = url.parse(request.url,true).query;
    response.write(JSON.stringify(urlData,null,3));
    response.write(jsonData.toString(),null,6);
    response.end('\n' + "Server response ended");
}
server.listen(port,hostname,() => {
    console.log("Server Started and ready : http://" + hostname + ":" + port);
});

