// // var, let, const, but stay away from var since let and const and fully supported
// var name = 'John Doe';
// console.log(name);
// name = 'Steve Smith';
// console.log(name);

// // Init var
// var greeting;
// console.log(greeting);
// greeting = 'Hello';
// console.log(greeting);

// // A variable can include letters, numbers, _ and $ And cannot start with a number

// // Multi-words variables conventions
// var firstName = 'John'; // Camel case
// var first_name = 'Sara' // Underscore
// var FirstName = 'Tom'; // Pascal case
// var firstname; // all lower case

// var works similar to let
// LET
// let name = 'John Doe';
// console.log(name);
// name = 'Steve Smith';
// console.log(name);

// CONST stand for constant
// const name = 'John';
// console.log(name);
// Cannot reassign
// name = 'Sara';
// Have to assign a value, it won't allow initialization without a value. This errors out:
// const person; 
const person = {  // this is an object
    name: 'John',
    age: 30
}
person.name = 'Sara';
console.log();

const numbers = [1,2,3,4,5]; // array
numbers.push(6);
console.log(numbers);
