var http = require('http');
var url = require('url');
var port = 8056;
var hostname = '127.0.0.1';
var server = http.createServer(server_engine);
function server_engine(request,response,error){
    response.setHeader('Content-Type','application/json');
    response.writeHead(200,{'Content-Type':'application/json'});
    var urlData = url.parse(request.url,true).query;
    response.write(JSON.stringify(urlData,null,3));
    response.end('\n' + "Server response ended");
}
server.listen(port,hostname,function(){
    console.log("Server Started and ready : http://" + hostname + ":" + port);
});
