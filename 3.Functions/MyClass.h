#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

class MyClass {
private:
    int privateData;

public:
    MyClass(int data);

    int getPrivateData();
    void setPrivateData(int newData);

    // Friend function declaration
    friend void friendFunction(MyClass& obj, int value);
    friend void friendFunction_2(MyClass& obj, int value);
};

#endif // MYCLASS_H
