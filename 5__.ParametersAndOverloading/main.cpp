#include <iostream>

using namespace std;

//Call by value parameters
void plusOneCallByValue(int num) {
    num++;
    cout << "value of num in function is: " << num << endl;
}

// Call by reference parameters
void plusOneCallByReference(int &num) {
    num++;
    cout << "value of num in function is: " << num << endl;
}

// Call by value and reference parameters
void plusOneCallByValueAndCallByReference(int num1, int &num2) {
    num1++;
    num2++;

    cout << "value of num1 in function is: " << num1 << endl;
    cout << "value of num2 in function is: " << num2 << endl;
}

//Overloading functions
void overload_func() {
    cout << "empty" << endl;
}

void overload_func(int a, int b) {
    cout << "a + b : " << a + b << endl;
}

void overload_func(int a, int b, int c) {
    cout << "a + b + c: " << a + b + c << endl;
}

void overload_func(double a, int b, int c) {
    cout << "a + b + c: " << a + b + c << endl;
}

//Default parameter function
void function_with_default_parameters(int a = 0, int b = 0, int c = 0) {
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    cout << "a + b + c: " << a + b + c << endl;
}

//Constant parameter function
void function_with_const_parameters(const int &a, const int b) {

    //you can not change parameter
    //a++;
    //b++;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a + b : " << a + b << endl;
}

int main() {
    cout << "Call by value------------------------------------------------------------------------------------" << endl;
    int number = 10;
    cout << "value of number at start of program: " << number << endl;

    //number of value number not changed;
    plusOneCallByValue(number);
    cout << "value of number in main is : " << number << endl;

    cout << "Call by reference--------------------------------------------------------------------------------" << endl;

    int number2 = 10;
    cout << "value of number at start of program: " << number2 << endl;

    //number of value number changed;
    plusOneCallByReference(number2);
    cout << "value of number in main is : " << number2 << endl;

    cout << "Call by Value and Call by Reference--------------------------------------------------------------" << endl;
    int num1 = 10;
    int num2 = 10;

    cout << "value of num1 at start of program: " << num1 << endl;
    cout << "value of num2 at start of program: " << num2 << endl;

    //number of value num2 changed, value of num2 is not changed
    plusOneCallByValueAndCallByReference(num1, num2);

    cout << "value of num1 in main is : " << num1 << endl;
    cout << "value of num2 in main is : " << num2 << endl;

    cout << "Overloading Functions----------------------------------------------------------------------------" << endl;
    /*
     functions with the same name but different parameters
    */

    overload_func();
    overload_func(5, 6);
    overload_func(5, 6, 7);
    overload_func(5.6, 3, 8);

    cout << "Default parameters in function-------------------------------------------------------------------" << endl;
    function_with_default_parameters();
    function_with_default_parameters(1);
    function_with_default_parameters(1, 2);
    function_with_default_parameters(1, 2, 3);

    cout << "Constant parameters in function------------------------------------------------------------------" << endl;
    function_with_const_parameters(1, 2);

    return 0;

}