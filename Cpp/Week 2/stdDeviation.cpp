/*
* This app asks student to enter their grade for various courses one by one.
* At the end the app computes the student's average and prints the result
* Student will enter -1 to indicate that the grades are finished
* Using ARRAY
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float computeAverage(vector<int> items) {
    float total = 0.f;
    for (int i = 0; i < items.size(); ++i) {
        total += items.at(i);

    }

    float average = total / items.size();
    return average;
}

float computeStandardDeviation(vector<int> items) {

    float sum = 0.f, mean, standardDeviation = 0.f;
    for (int i = 0; i < items.size(); ++i) {
        sum += items.at(i);


    }

    mean = sum / items.size();

    for (int i = 0; i < items.size(); ++i) {
        standardDeviation += pow(items.at(i) - mean, 2);
    }

    return sqrt(standardDeviation / items.size());



}



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


    cout << computeAverage(gradesVec) << endl;
    cout << computeStandardDeviation(gradesVec);

    return 0;
}
