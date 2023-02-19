// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


// template 
class Book {
    public: 
        string title;
        string author;
        int pages;
        
        // Default constructor
        Book() {
            title = "None";
            author = "No one";
            pages = 0;
        }
        
        
        // Attribute constructor, created everytime an instance is created 
        Book(string aTitle, string aAuthor, int aPages) {
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
        


    
};

// Object, an instance of the parent class
int main() {


    // values will be passed in to the argument to save lines
    Book book1("James Webb", "NASA", 2232);
    book1.title = "Updated title for book 1";
    Book book2("Onetwothree", "OTT", 123); 
    Book book3; // Default value that was set earlier will be passed without needing arguments 
   
    
    cout << book3.title;
    
    return 0;
}
