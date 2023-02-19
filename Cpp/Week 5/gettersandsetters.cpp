// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// getters and setters restrict certain info to be inputed


// template 
class Movie {
    
    // Main function will not have access to this 
    private: 
        string rating;
    
    
    // any code outside the class can access it, like all the attributes
    public: 
        string title;
        string director;
        
        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }
        
        // modifying the attributes
        void setRating(string aRating) {
           if(aRating == "G" || aRating == "PG" || aRating == "R") {
               rating = aRating;
           } else {
               rating = "NR";
           }
        }
        
        // this will be called at the main method
        string getRating() {
            return rating;
        }
};

// Object, an instance of the parent class
int main() {


    Movie avengers("Avengers", "JW", "234232");
    
    // Getter setters will anticipate if the attribute has been modified
   //  avengers.setRating("Dog");
    
    // unless it is within the setter's parameter, the getter will return the default value in else
    cout << avengers.getRating();
    

    return 0;
}
