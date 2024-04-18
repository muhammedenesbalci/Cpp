/*
In C++, the terms "static" and "non-static" can refer to both member variables and member functions within a class. Here's a breakdown of the differences between static and non-static variables and functions:

Static Variables:
Static member variables are shared among all instances of a class. There is only one copy of a static variable that is shared by all objects of the class.
They are declared with the static keyword and are initialized outside the class definition.
Static variables have a class scope and can be accessed directly using the class name and the scope resolution operator (::).
Static variables are typically used for storing data that is shared across all instances of a class or for maintaining a global state within the class.

Non-Static Variables:
Non-static member variables are specific to each instance (object) of a class. Each object has its own copy of non-static variables.
Non-static variables are declared without the static keyword and are accessed through object instances using the dot operator (.).
Non-static variables are used to store object-specific data and state.

Static Functions:
Static member functions are associated with the class rather than the individual objects. They do not operate on any specific instance and can be called using the class name.
Static functions are declared with the static keyword and do not have access to non-static member variables or functions.
They can only directly access static member variables or call other static member functions.
Static functions are often used for utility functions or operations that don't require access to object-specific data.

Non-Static Functions:
Non-static member functions are associated with individual objects and operate on the data specific to those objects.
Non-static functions can access both static and non-static member variables and functions.
They are called through object instances using the dot operator (.) and have access to the object's data.
Here's an example that demonstrates the usage of static and non-static variables and functions in C++:
 */

#include <iostream>

class MyClass {
public:
    int nonStaticVar;              // Non-static member variable+
    static int staticVar;          // Static member variable

    void nonStaticFunc();

    static void staticFunc();
};

int MyClass::staticVar = 42;       // a static member variable must be defined and initialized outside the class definition.

void MyClass::nonStaticFunc() {         // Non-static member function
    std::cout << "Non-static function. Non-static variable: " << nonStaticVar << std::endl;
}

void MyClass::staticFunc() {     // Static member function
    std::cout << "Static function. Static variable: " << staticVar << std::endl;
}


int main() {
    MyClass obj1;
    MyClass obj2;

    obj1.nonStaticVar = 10;        // Setting non-static variable of obj1
    obj2.nonStaticVar = 20;        // Setting non-static variable of obj2

    std::cout << "Non-static variable of obj1: " << obj1.nonStaticVar << std::endl;
    std::cout << "Non-static variable of obj2: " << obj2.nonStaticVar << std::endl;

    MyClass::staticVar = 30;       // Setting static variable using class name
    std::cout << "Static variable: " << MyClass::staticVar << std::endl;

    obj1.nonStaticFunc();          // Calling non-static function using object instance

    MyClass::staticFunc();         // Calling static function using class name

    std::cout << obj1.staticVar << std::endl;
    std::cout << obj2.staticVar << std::endl;

    obj1.staticFunc();
    obj1.staticFunc();

    return 0;
}