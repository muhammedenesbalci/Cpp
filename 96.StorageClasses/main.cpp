// C++ Program to illustrate the auto storage class
// variables
#include <iostream>
#include "extern_example.cpp"
#include "extern_usage.cpp"

using namespace std;
 
void autoStorageClass() {
    cout << "Demonstrating auto class\n";
 
    // Declaring an auto variable
    int a = 32;
    float b = 3.2;
    //char* c = "GeeksforGeeks";
    char d = 'G';
 
    // printing the auto variables
    cout << a << " \n";
    cout << b << " \n";
    //cout << c << " \n";
    cout << d << " \n";
}

// declaring the variable which is to
// be made extern an initial value can
// also be initialized to x
int x;
void externStorageClass()
{
    cout << "Demonstrating extern class\n";
 
    // telling the compiler that the variable
    // x is an extern variable and has been
    // defined elsewhere (above the main
    // function)
    extern int x;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'x'"
         << "declared, as extern: " << x << "\n";
 
    // value of extern variable x modified
    x = 2;
 
    // printing the modified values of
    // extern variables 'x'
    cout << "Modified value of the variable 'x'"
         << " declared as extern: \n"
         << x << endl;
}

void externStorageClass_2()
{
    cout << "Demonstrating extern class\n";
 
    // telling the compiler that the variable
    // x is an extern variable and has been
    // defined elsewhere (above the main
    // function)
    extern int x;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'x'"
         << "declared, as extern: " << x << "\n";
 
    // value of extern variable x modified
    x = 3;
 
    // printing the modified values of
    // extern variables 'x'
    cout << "Modified value of the variable 'x'"
         << " declared as extern: \n"
         << x << endl;
}

void externStorageClass_file_1()
{
    cout << "Demonstrating extern class with file\n";
    extern int my_variable;
    cout << "addres of myVariable: " << &my_variable <<endl;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'my_variable'"
         << "declared, as extern: " << my_variable << "\n";
 
    // value of extern variable x modified
    my_variable = 3;
 
    // printing the modified values of
    // extern variables 'x'
    cout << "Modified value of the variable 'my_variable'"
         << " declared as extern: \n"
         << my_variable << endl;
}

void externStorageClass_file_2()
{
    cout << "Demonstrating extern class with file\n";
    
    extern int my_variable;
    cout << "addres of myVariable: " << &my_variable <<endl;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'my_variable'"
         << "declared, as extern: " << my_variable << "\n";
 
    // value of extern variable x modified
}

void externStorageClass_file_3()
{
    cout << "Demonstrating extern class with file\n";
    extern_usage_fun();
}

//----------------------------------------------------------------------------
// C++ program to illustrate the use of mutalbe storage
// class specifiers

class Test {
public:
    int x;

    // defining mutable variable y
    // now this can be modified
    mutable int y;

    Test()
    {
        x = 4;
        y = 10;
    }
};

void use_of_mutable() {
        // t1 is set to constant
        const Test t1;
    
        // trying to change the value
        t1.y = 20;
        cout << t1.y << endl;
}

void use_of_mutable_2() {
        // t1 is set to constant
        const Test t1;
    
        // will throw error
        t1.x = 8;
        cout << t1.x;
}
int main()
{
    // To demonstrate auto Storage Class
    cout << "---------------------------------\n";
    autoStorageClass();

    cout << "---------------------------------\n";
    externStorageClass();

    cout << "---------------------------------\n";
    externStorageClass_2();

    cout << "---------------------------------\n";
    externStorageClass_file_1();
    cout << "+++++++++++++++++++++++++++++++++\n";
    externStorageClass_file_2();
    cout << "+++++++++++++++++++++++++++++++++\n";
    externStorageClass_file_3();

    cout << "---------------------------------\n";
    use_of_mutable();
    //use_of_mutable_2();
    return 0;
}