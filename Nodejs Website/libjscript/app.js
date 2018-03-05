var person = (age,name,id,address,gender) => {
  this.age = age;
  this.name = name;
  this.id = id;
  this.address = address;
  this.gender = gender;
};
person.prototype.toString = () => {
  return "The id number is : " + this.id;
};
person.prototype.printMethod = () => {
  return console.log("The person is " + this.name);
};
var John = new person(32,"John",909979,"House 13, Dalton Street","Male");
var JSONdata = JSON.stringify(John);
var JohnObject = JSON.parse(JSONdata);
var string = John.toString(); /* prototyping */
console.log(string);
console.log(JSONdata);
console.log(JohnObject);
