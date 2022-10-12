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
        return printEven;
    }




    // Q2 Reverse a string



    function reverseString(str) {
        let text = "";
        for (let i = str.length - 1; i >= 0; i--) {
            text += str[i];
        }
        return text;
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
        return str;
    }






    // Q5 Find the sum of array

    function sum(arr) {
        let sumNum= 0;
        for (let i = 0; i < arr.length; i++) {
            sumNum += arr[i];
        }
        return sumNum;
    }




    // Q6 Find the largest value in array 

    function largest(arr) {
        let largestNum = 0;
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] > largestNum) {
                largestNum = arr[i];
            }
        }
        return largestNum;
    }


console.log(evenNumber(testArray));
console.log(reverseString("Hello"));
console.log(arrayToString(testArray2));
console.log(sum(testArray));
console.log(largest(testArray));
