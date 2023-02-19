// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// getters and setters restrict certain info to be inputed


// template aka Superclass
class Chef {
    public: 
        void makeChicken() {
            cout << "Makes great chicken" << endl;
        }
        void makeSalad() {
            cout << "Makes salad" << endl;
        }
        void makeSpecial() {
            cout << "Makes special" << endl;
        }
        
};

// Subclass
// has access to all the functions in Chef class
// and this new class can do new things 
class ItalianChef : public Chef {
    
    // must be public for main to have access
    public: 
        void makePasta() {
            cout << "Makes pasta" << endl;
        }
        void makeSpecial() {
            cout << "Makes special in italian" << endl;
        }
};

// Object, an instance of the parent class
int main() {
    
    Chef chef;
    chef.makeChicken();
    chef.makeSpecial(); 
    
    // Inherited chef 
    ItalianChef italianChef;
    italianChef.makeChicken();
    italianChef.makePasta();
    italianChef.makeSpecial();

    return 0;
}
