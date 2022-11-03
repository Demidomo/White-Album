const table = document.querySelector("studentRecordTable");
table.classList.add("table");

// const submitButton = document.getElementById("submitButton");

// // 1 Way is writing like this
// submitButton.addEventListener("click", function() {
//     alert("I am submitted");
// })

const tableArr = ["First name", "Last name", "Email", "Roll Number", "Contact"]

for (let item of tableArr) {
    let th = document.createElement("th");
    th.textContent = item;
    table.appendChild(th);
    th.classList.add("th");
}

let studentRecord = {
    firstName: "",
    lastName: "",
    rollNumber: 0,
    email: "",
    contact: 0
}


let studentRecordList = [];

function submitForm(event) {

    // Will talk about this
    event.preventDefault();

    // const firstName = document.getElementById("firstName")

    // Create new copy of that variable, so that we can remove references
    let newStudentRecord = JSON.stringify(studentRecord);
    newStudentRecord = JSON.parse(newStudentRecord);
    studentRecordList.push(newStudentRecord);

    // console.log(studentRecord, "New Student Record");
    // console.log(studentRecordList, "Student Record List");

    const tr = document.createElement("tr");
    table.appendChild(tr);
    tr.classList.add("tr");


    for (let key of studentRecord) {
        let td = document.createElement("td");
        th.textContent = studentRecord[key];
        tr.appendChild(td);
        th.classList.add("td");
    }

}


// Capture the event First when someone types
function changeFirstName(event) {

    // using that event.target.value i can access the value the user typed
    studentRecord.firstName = event.target.value;

}


// Capture the event First when someone types
function changeLastName(event) {

    // using that event.target.value i can access the value the user typed
    studentRecord.lastName = event.target.value;

}

function changeEmail(event) {

    studentRecord.email = event.target.value;
}

function changeRollNumber(event) {
    studentRecord.rollNumber = event.target.value;
}

function changeContact(event) {
    studentRecord.contact = event.target.value;
}



// The assignment is 

// Add other Field as value like and write event handlers for all of them
// Rollnumber
// email
// contact


// Now iterate over that array studentRecordList
// and show the table everytime as soon as you submit the form by calling submit button
