/*
* This app asks student to enter their grade for various courses one by one.
* At the end the app computes the student's average and prints the result
* Student will enter -1 to indicate that the grades are finished
* Using ARRAY
*/

#include <iostream>
#include <vector>
using namespace std;




int main() {
    cout << "This app computes the average grade that user enters.\n";


    int grade = 0;
    int total = 0;
    int end = -1;

    vector<int> gradesVec;

    while (grade != end) {
        cout << "Enter a grade (-1 to end)\n";
        cin >> grade;

        if (grade != end) {
            gradesVec.push_back(grade);
        }

    }

    for (int i = 0; i < gradesVec.size(); ++i) {
        total += gradesVec.at(i);
    }

    int average = total / gradesVec.size();
    cout << average; 

    return 0;
}
