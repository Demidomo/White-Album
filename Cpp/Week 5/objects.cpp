// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


// template 
class Student {
    public: 
        string name;
        string major;
        double gpa;
        Student(string aName, string aMajor, double aGPA){
            name = aName;
            major = aMajor;
            gpa = aGPA;
        }
        
        // This function can be called by any of the class' object
        bool hasHonors() {
            if(gpa > 5) 
                return true; 
            
            return false;
        }
    
};

// Object, an instance of the parent class
int main() {


    Student student1("Jim", "Art", 4.90);
    Student student2("Charles", "CS", 9.40);
    
    cout << student1.hasHonors() << endl;
    cout << student2.hasHonors();

    return 0;
}
