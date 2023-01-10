#include <iostream>
#include <cmath>

void drawShapes() {
    std::cout << "What shape you like to draw? (Choose 1 for Rectangle and 2 for Right angle triangle)" << std::endl;

    int shape;
    std::cin >> shape;

    if (shape == 1) {
        std::cout << "Enter the width and height of the rectangle: ";
        int width, height;
        std::cin >> width >> height;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    else if (shape == 2) {
        std::cout << "Enter the width and height of the triangle: ";
        double width, height;
        std::cin >> width >> height;

        for (double i = height - 1; i >= 0; i--) {
            for (double j = 0; j <= round(width * i / height); j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Invalid input. Please choose 1 or 2." << std::endl;
    }

    std::cout << "---Do you want to try again? (y for yes, n for no)" << std::endl;
    char tryAgain;
    std::cin >> tryAgain;

    if (tryAgain == 'y') {
        drawShapes();
    }
}

int main() {
    drawShapes();
    return 0;
}
