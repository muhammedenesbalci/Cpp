#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor to initialize the width and height
    Rectangle(double w, double h) {
        if (w > 0 && h > 0) {
            this->width = w;
            this->height = h;
        } else {
            this->width = 0;
            this->height = 0;
            std::cerr << "Width and height must be positive values." << std::endl;
        }
    }

    // Public method to set the width
    void setWidth(double w) {
        if (w > 0) {
            this->width = w;
        } else {
            std::cerr << "Width must be a positive value." << std::endl;
        }
    }

    // Public method to set the height
    void setHeight(double h) {
        if (h > 0) {
            this->height = h;
        } else {
            std::cerr << "Height must be a positive value." << std::endl;
        }
    }

    // Public method to get the width
    double getWidth() const {
        return this->width;
    }

    // Public method to get the height
    double getHeight() const {
        return this->height;
    }

    // Public method to calculate the area
    double getArea() const {
        return this->width * this->height;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);

    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.getArea() << std::endl;

    // Attempt to set an invalid width
    rect.setWidth(-10.0);

    // Set a valid width
    rect.setWidth(10.0);
    std::cout << "New Width: " << rect.getWidth() << std::endl;
    std::cout << "New Area: " << rect.getArea() << std::endl;

    return 0;
}
