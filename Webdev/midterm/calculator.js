function calculator (num1, num2, operationType) {
    if (operationType === "add") {
        return num1 + num2;
    }
    
    else if (operationType === "subtract") {
        return num1 - num2;
    }
    
    else if (operationType === "divide") {
        return num1 / num2;
    }
    
    else if (operationType === "multiply") {
        return num1 * num2;
    }
}

console.log(calculator(3, 2, "subtract"))
