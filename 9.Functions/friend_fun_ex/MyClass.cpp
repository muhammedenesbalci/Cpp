#include "MyClass.h"

// Constructor definition
MyClass::MyClass(int data) : privateData(data) {}

// Getter definition
int MyClass::getPrivateData() {
    return privateData;
}

// Setter definition
void MyClass::setPrivateData(int newData) {
    privateData = newData;
}

// Friend function definition
void friendFunction(MyClass& obj, int value) {
    obj.privateData = value; // Private member access via friend function normalded class dışında böyler bir değişim yapamazsın
    std::cout << "Friend function 1 called. privateData set to: " << obj.privateData << std::endl;
}
