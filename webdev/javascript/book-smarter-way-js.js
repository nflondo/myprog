// var spec = prompt("Your species?", "human");

//Note: every response to a prompt comes back as a string
var x = prompt("What does a dog wag?");
// in most cases == is the same as === but there are some exceptions, to make it simpler always use ===
// === can compare string to string, numbers, vars. etc
// it's case sensitive
// !=== not equal to
// != can usually be used in place of !==
var correctAnswer = "tail";
if (x === correctAnswer){
    alert("Correct!");
} else if ( x === "tale"){
    alert("Incorrect but close!");
} else {
    alert("Incorrect :-(");
}
// using and
// you can chain any number of conditions together
// the Or operator is ||
if ( age > 65 || age < 21 && res === "U.S"){

}
if ( weight > 300 && time < 6){
    alert("Come try out");    
}

// ARRAYS
var cities = ["Atlanta", "Baltimore", "Chicago", "Denver"]
alert("Welcome to " + cities[2]);
//you can mix var types in arrays (bad idea?)
var mixedArray = [1, "bob", "now is", true];
