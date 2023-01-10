/*
* This app asks student to enter their grade for various courses one by one.
* At the end the app computes the student's average and prints the result
* Student will enter -1 to indicate that the grades are finished 
*/

#include <iostream>
using namespace std;




int main() {
    cout << "This app computes the average grade that user enters.\n";
  

    int grade = 0;
    int counter = 0; // Keeps track of amount of grades
    int total = 0;
    int end = -1;
   

    while (grade != end) {
        cout << "Enter a grade (-1 to end)\n";
        cin >> grade;
        
        if (grade != end) {
            total += grade;
            ++counter;
        }
        
    } 
    
    cout << total / counter;

    return 0;
}
