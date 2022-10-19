const array = [90, 98, 94, 89];

function findAverage(array) {
    let totalGrade = 0;
    let avgGrade = 0;
    for (let i = 0; i < array.length; i++) {
        totalGrade += array[i];
    }
    
    avgGrade = totalGrade / array.length;
    return avgGrade;
}

console.log(findAverage(array)); // 92.75
