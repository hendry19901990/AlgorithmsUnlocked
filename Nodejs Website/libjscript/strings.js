/* A standard javascript object */
var person = {
  name: {
    firstname: "Sumit",
    lastname: "Lahiri",
    middlename: "Laplacian"
  },
  age: 89,
  gender: "Male",
  complexion: "Fair",
  cars: ["BMW","Ferrari","Jaguar-Landrover"],
  WorkExp:{
    first: {
      Position: "Program Coordinator",
      Company: "SAE Baja NIT Durgapur",
      Time: "April 2015"
    },
    second: {
      Position: "Senior Manager",
      Company: "Tata Motors",
      Time: "August 2016"
    }
  }
};
var jsondata = JSON.stringify(person); //convert javascript object to JSON notation.
var objtext = JSON.parse(jsondata);    //convert JSON data to javascript object.
// console.log(jsondata);
// console.log(objtext);
exports.person = person;