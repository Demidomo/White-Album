// Javascript assignment 1

const testArray = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const testArray2 = ["hello", "world", "how", "are", "you"];

// Q1 Print even numbers in given array

let printEven = ""; 

function evenNumber(arr) {
    for (let i = 0; i <= testArray.length; i += 1) {
        if (i % 2 === 0) {
            printEven += `${arr[i]} `;
        }
    }
    console.log(printEven);
}




// Q2 Reverse a string



function reverseString(str) {
    let text = "";
    for (let i = str.length - 1; i >= 0; i--) {
        text += str[i];
    }
    console.log(text);
}




// Q3 Fizzbuzz


for (i = 1; i <= 100; i++) {
    if (i % 3 === 0 && i % 5 === 0) {
        console.log("FizzBuzz");
    }

    else if (i % 3 === 0) {
        console.log("Fizz");
    }
    else if (i % 5 === 0) {

        console.log("Buzz");
    }
    else {
        console.log(i);
    }
}



// Q4 Array to string conversion

function arrayToString(arr) {
    let str = "";
    for (let i = 0; i < arr.length; i++) {
        str += `${arr[i]} `;
    }
    console.log(str);
}






// Q5 Find the sum of array

function sum(arr) {
    let sum = 0;
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    console.log(sum);
}




// Q6 Find the largest value in array 

function largest(arr) {
    let largestNum = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] > largestNum) {
            largestNum = arr[i];
        }
    }
    console.log(largestNum);
}


evenNumber(testArray);
reverseString("Hello");
arrayToString(testArray2);
sum(testArray);
largest(testArray);
