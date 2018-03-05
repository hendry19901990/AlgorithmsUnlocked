var person = function(age,name,id,address,gender){
  this.age = age;
  this.name = name;
  this.id = id;
  this.address = address;
  this.gender = gender;
  this.toString = () => {
    return "The id number is : " + this.id;
  };
  this.printMethod = () => {
    return console.log("The person is " + this.name);
  };
};
exports.objectProperty = person;
