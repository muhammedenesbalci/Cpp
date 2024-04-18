#include "MyClass.h"
#include <iostream>

// Friend function definition directly in main.cpp
void friendFunction_2(MyClass& obj, int value) {
    obj.privateData = value; // Private member access via friend function
    std::cout << "Friend function_2 called. privateData set to: " << obj.privateData << std::endl;
}

int main() {
    MyClass obj(42);

    std::cout << "Private data before: " << obj.getPrivateData() << std::endl;

    // Using friend function to modify private data
    friendFunction(obj, 100);
    std::cout << "Private data after: " << obj.getPrivateData() << std::endl;

    friendFunction_2(obj, 1000);
    std::cout << "Private data after: " << obj.getPrivateData() << std::endl;

    return 0;
}
