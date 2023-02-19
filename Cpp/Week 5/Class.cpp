// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


// template 
class Book {
    public: 
        string title;
        string author;
        int pages;
};


int main() {

    Book book1; 
    book1.title = "James Webb";
    book1.author = "NASA";
    book1.pages = 2232;
    book1.title = "Whaaaaat";
    
    Book book2; 
    book2.title = "Onetwothree";
    book2.author = "OTT";
    book2.pages = 123;
    
    cout << book1.title;
    
    return 0;
}
