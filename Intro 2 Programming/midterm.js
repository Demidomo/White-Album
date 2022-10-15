// Coding question 1

for (let i = 1; i <= 10; i++) {
    console.log(i); // 1 2 3 4 5 6 7 8 9 10
} 


// Coding question 2


const fruitArr = ["apple", "banana", "orange"];

console.log(fruitArr[1]); // banana



// Coding question 3

const skyIsBlue = true;

if (skyIsBlue) {
    console.log("Hello World");
}

else {
    console.log("Goodbye")
}


// Second Solution
    
const skyIsBlue = true;
let message;

skyIsBlue ? 
    (message = "Hello World") : 
    (message = "Goodbye");

console.log(message); // Hello World




// Coding question 4

function welcome(namePara) {
    console.log(`Welcome ${namePara}`);
}

welcome("Matthew");  // Welcome Matthew
