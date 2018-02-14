var numbers = {
  array: [],
  isArrayFilled: function(){
    if (this.array.length <= 0)
    {
      console.log("It's lonely in here!.");
      return false;
    }
    else {
      console.log("Well, now it feels homely.");
      return true;
    }
  },
  getArrayNumbers : () => {
    return this.array;
  },
  getSquareNumbers : () => {
    for(i in this.array) {
      this.array[i] = this.array[i]*this.array[i];
    }
    return this.array;
  }
};
var int = {
  j: 2048,
  i: 17
};
var squareNumbers = numbers;
isFilled = squareNumbers.isArrayFilled();
function fillEmptyArray(){
  if(!isFilled)
  {
    console.log("Filling spaces now....");
    squareNumbers.array = [1,2,3,4,5,6,7,8,9,10];
  }
}
fillEmptyArray();
console.log("Well it's all filled here now, see " + squareNumbers.array);
console.log("Remainder of "+ int.j + "/" + int.i + " = " + int.j%int.i );
var xhttp = new XMLHttpRequest();
