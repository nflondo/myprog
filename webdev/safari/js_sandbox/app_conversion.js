let val;

// Number to string
// val = 5;
val = String(5);  // casting number to a string
val = String(4+4);
// Boolean to String
val = String(true);
// Date to string
val = String(new Date());
// Array to string
val = String([1,2,3,4]);

// toString() method
val = (5).toString();
val = (true).toString();

// String to numbers
val = Number('5');
// Boolean to number
val = Number(true); // 1
val = Number(false); // 0
val = Number(null); // 0
val = Number('hello'); // NaN Not a Number
val = Number([1,2,3]);

// parseInt() method
val = parseInt('100'); // no decimals
val = parseFloat('100.32');

// Type Coersion


// Output
console.log(val);
console.log(typeof val);
// console.log(val.length);  // length only works on strings
console.log(val.toFixed(2));  // allows to specify decimals and only works on numbers

const val1 = String(5);
const val2 = 6;  // JS changed this to string.  Type coersion.
const sum = val1 + val2;
console.log(sum);
console.log(typeof sum);