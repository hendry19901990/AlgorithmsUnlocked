var http = require('http');
var url = require('url');
try{
    var server = http.createServer(function(req,res){
    res.setHeader('Content-Type', 'application/json');
    res.writeHead(200, {'Content-Type':'application/json'});
    var urlData = url.parse(req.url,true).query;
    res.write(JSON.stringify(urlData,null,3));
    res.end();
    console.log("Running  Server");
}).listen(8020)}catch(err){
    console.log(err);
}
