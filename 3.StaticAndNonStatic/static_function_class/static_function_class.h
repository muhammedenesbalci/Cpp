#ifndef STATIC_FUNCTION_CLASS_H
#define STATIC_FUNCTION_CLASS_H

#include <iostream>

using namespace std;

class Efe {
public:
    int non_static_variable = 10;
    static const int static_variable = 5;

    // static member function
    static void printMsg();
};

#endif // STATIC_FUNCTION_CLASS_H