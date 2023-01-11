#include <iostream>
#include <cmath>
using namespace std;

void drawShapes() {
    cout << "What shape you like to draw? (Choose 1 for Rectangle and 2 for Right angle triangle)" << endl;

    int shape;
    cin >> shape;

    // When user is drawing a rectangle
    if (shape == 1) {
        cout << "Enter the width and height of the rectangle: ";
        int width, height;
        cin >> width >> height;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // When user is drawing a triangle
    else if (shape == 2) {
        cout << "Enter the width and height of the triangle: ";
        double width, height;
        cin >> width >> height;

        for (double i = height - 1; i >= 0; i--) {
            for (double j = 0; j <= round(width * i / height); j++) {
                cout << "*";
            }
            cout << endl;
        }
    } else {
        cout << "Invalid input. Please choose 1 or 2." << std::endl;
    }

    // Asking user if they would draw another shape
    cout << "---Do you want to try again? (y for yes, n for no)" << endl;
    char tryAgain;
    cin >> tryAgain;

    // When user enters 'y', the program restarts
    if (tryAgain == 'y') {
        drawShapes();
    }
}

// Using the main function to call the drawShapes function
int main() {
    drawShapes();
    return 0;
}
