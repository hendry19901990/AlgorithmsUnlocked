var event = require('events');
var EventEmiiter = new event.EventEmitter();

var EventHandler = function(){
    console.log("Event Occured");
}
EventEmiiter.addListener('someevent',EventHandler);
EventEmiiter.emit('someevent');