/*
* This program will ask the user to select 2 shapes to draw.
* The user can draw a rectangle or right angle triangle,
* base on the width and height value the user enters.
*/
#include <iostream>
#include <cmath>
using namespace std;

// Function drawShapes is created here, it contains variable and conditions for the user to draw shapes.
void drawShapes() {
    
    // User is asked to input 1 or 2 to draw either a rectangle or Right angle triangle. The input is stored as an integer variable.
    cout << "What shape you like to draw? (Choose 1 for Rectangle and 2 for Right angle triangle)" << std::endl;
    int shape;
    cin >> shape;

    // When user selects 1 to draw rectangle.
    if (shape == 1) {
        cout << "Enter the width and height of the rectangle: ";
        int width, height;
        cin >> width >> height;

        // Using 2 for loops to increment the '*' shape to draw a rectangle.
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cout << "*";
            }
            cout << endl;
        }
    }

    //  When user selects 2 to draw right angle triangle.
    else if (shape == 2) {
        cout << "Enter the width and height of the triangle: ";
        double width, height;
        cin >> width >> height;

        // Using 2 for loops again, the formula is adjusted to align its height to the appropriate width length.
        for (double i = height - 1; i >= 0; --i) {
            for (double j = 0; j <= round(width * i / height); ++j) {
                cout << "*";
            }
            cout << endl;
        }

    // In the case that user did not select 1 or 2, the user will have to restart the function to draw shapes. 
    } else {
        cout << "Invalid input. Please choose 1 or 2." << endl;
    }

    // Asking user if they would draw another shape
    cout << "---Do you want to try again? (y for yes, n for no)" << endl;
    char tryAgain;
    cin >> tryAgain;

    // User response was stored as a character variable type, and when 'y' is inputted, the program is called on again to restart for the user.
    // Otherwise, the program will cease. 
    if (tryAgain == 'y') {
        drawShapes();
    }
}

// Using the main function to call the drawShapes function
int main() {
    drawShapes();
    return 0;
}
