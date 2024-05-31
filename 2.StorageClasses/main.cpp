#include <iostream>

#include "extern_example/extern_example.cpp"
#include "extern_example/extern_usage.cpp"

#include "common_variable/common_variable.h"
#include "common_variable/file1.cpp"
#include "common_variable/file2.cpp"

#include <thread>

using namespace std;

// auto Storage class ----------------------------------------------------------------
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

// extern Storage class ----------------------------------------------------------------
// declaring the variable which is to
// be made extern an initial value can
// also be initialized to x
int x;
void externStorageClass() {
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

    cout << "address of extern x: " << &x << endl;
}

void externStorageClass_2() {
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

    cout << "address of extern x: " << &x << endl;
}

void externStorageClass_file_1() {
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

void externStorageClass_file_2() {
    cout << "Demonstrating extern class with file\n";
    
    extern int my_variable;
    cout << "addres of myVariable: " << &my_variable <<endl;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'my_variable'"
         << "declared, as extern: " << my_variable << "\n";
}

void externStorageClass_file_3() {
    cout << "Demonstrating extern class with file\n";
    extern_usage_fun();
}

void externStorageClass_file_4_common_variable() {
    cout << "Demonstrating extern class with file\n";
    function_in_file1(); // common_variable'ın değerini 100 olarak değiştir ve yazdır (file1.cpp)
    function_in_file2(); // common_variable'ın güncellenmiş değerini yazdır (file2.cpp)
    cout << "common_variable in main" <<  common_variable << endl;
    std::cout << "common_variable_const address in main: " << &common_variable << std::endl;
}

// static Storage class ----------------------------------------------------------------
int staticFun() {
    cout << "For static variables: ";
    static int count = 0;
    count++;
    return count;
}

int nonStaticFun()
{
    cout << "For Non-Static variables: ";

    int count = 0;
    count++;
    return count;
}

void static_and_non_static_example() {
    // Calling the static parts
    cout << staticFun() << "\n";
    cout << staticFun() << "\n";
    

    // Calling the non-static parts
    cout << nonStaticFun() << "\n";
    cout << nonStaticFun() << "\n";
}

// mutable Storage class ----------------------------------------------------------------
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
        //t1.x = 8;
        cout << t1.x;
}

// thread local Storage class ----------------------------------------------------------------
thread_local int var = 10;

void thread_local_ex() {
    // thread 1
    thread th1([]() {
        cout << "Thread 1 var Value: " << (var += 18) << '\n';
    });

    // thread 2
    thread th2([]() {
        cout << "Thread 2 var Value: " << (var += 7) << '\n';
    });

    // thread 3
    thread th3([]() {
        cout << "Thread 3 var Value: " << (var += 13) << '\n';
    });

    th1.join();
    th2.join();
    th3.join();
}
int main()
{
    // To demonstrate auto Storage Class
    cout << "\nautoStorageClass ---------------------------------\n";
    autoStorageClass();

    cout << "\nexternStorageClass ---------------------------------\n";
    externStorageClass();

    cout << "\nexternStorageClass_2 ---------------------------------\n";
    externStorageClass_2();

    cout << "\nexternStorageClass_file_1 ---------------------------------\n";
    externStorageClass_file_1();
    cout << "\nexternStorageClass_file_2 +++++++++++++++++++++++++++++++++\n";
    externStorageClass_file_2();
    cout << "\nexternStorageClass_file_3 +++++++++++++++++++++++++++++++++\n";
    externStorageClass_file_3();

    cout << "\nexternStorageClass_file_4_common_variable ---------------------------------\n";
    externStorageClass_file_4_common_variable();

    cout << "\nstatic_and_non_static_example ---------------------------------\n";
    static_and_non_static_example();

    cout << "\nuse_of_mutable and use_of_mutable_2 ---------------------------------\n";
    use_of_mutable();
    //use_of_mutable_2();
    
    cout << "t\nhread_local_ex ---------------------------------\n";
    thread_local_ex();
    
    return 0;
}