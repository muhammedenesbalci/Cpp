#include <iostream>
#include <cstdarg>
#include <string>

using namespace std;

// Basic Func overloading example------------------------------------
void add(int a, int b) {
    cout << "int, int --------------\n";
    cout << "sum = " << (a + b) << endl;
}
 
void add(int a, int b, int c) {
    cout << "int, int, int --------------\n";
    cout << "sum = " << (a + b + c) << endl;
}

void add(double a, double b) {
    cout << "double, double --------------\n";
    cout << "sum = " << (a + b) << endl;
}

void add(int a, double b) { 
    cout << "int, double --------------\n";
    cout <<"sum = "<< (a + b) << endl;
} 

void add(double a, int b) {
    cout << "double, int --------------\n";
    cout<<"sum = "<<(a+b);
}

void print(int i) {
  cout << " Here is int " << i << endl;
}

void print(double  d) {
  cout << " Here is double " << d << endl;
}

void print(char const *c) {
  cout << " Here is char* " << c << endl;
}

void basic_fun_overloading_example(){
    add(10, 2);
    add(10, 2, 90);
    add(5.3, 6.2);
    add(5, 6.2);
    add(5.8, 6);

    print(10);
    print(10.10);
    print("ten");
}

// Class constrcutor overloading-----------------------------------------------
class construct {  
  
public: 
    float area;  
      
    // Constructor with no parameters 
    construct() { 
        area = 0; 
    } 
      
    // Constructor with two parameters 
    construct(int a, int b) { 
        area = a * b; 
    } 
      
    void disp() { 
        cout<< area << endl; 
    } 
}; 

void basic_construcotor_overloading_example() {
    construct o; 
    construct o2( 10, 20); 
      
    o.disp(); 
}
// variadic functions (not overlaodable)-----------------------------------------------------------------
void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        std::cout << num << " ";
    }

    va_end(args);
    std::cout << std::endl;
}

void basic_variadic_example() {
    printNumbers(3, 1, 2, 3);  // Output: 1 2 3
    printNumbers(5, 10, 20, 30, 40, 50);  // Output: 10 20 30 40 50
}

// variadic functions different types (not overlaodable)-----------------------------------------------------------------
void print(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == 'd') {
            int i = va_arg(args, int);
            std::cout << i << " ";
        } else if (*format == 'c') {
            int c = va_arg(args, int);  // 'char' is promoted to 'int' in variadic functions
            std::cout << static_cast<char>(c) << " ";
        } else if (*format == 'f') {
            double f = va_arg(args, double);
            std::cout << f << " ";
        } else if (*format == 's') {
            const char* s = va_arg(args, const char*);
            std::cout << s << " ";
        }
        ++format;
    }

    va_end(args);
    std::cout << std::endl;
}

void different_type_variadic_example() {
    printNumbers(3, 1, 2, 3);  // Output: 1 2 3
    printNumbers(5, 10, 20, 30, 40, 50);  // Output: 10 20 30 40 50
}

// const overloading-----------------------------------------------------------------
#include <iostream>

class MyClass {
public:
    void show() {
        std::cout << "Non-const function" << std::endl;
    }

    void show() const {
        std::cout << "Const function" << std::endl;
    }
};

void const_overload_example() {
    MyClass obj;
    const MyClass constObj;

    obj.show();        // Output: Non-const function
    constObj.show();   // Output: Const function

    // Even with a non-const object, you can call the const function explicitly
    obj.show();        // Output: Non-const function
    const MyClass* pObj = &obj;
    pObj->show();      // Output: Const function
}

int main() {
    cout << "\nBasic Func overloading example------------------------------------\n";
    basic_fun_overloading_example();

    cout << "\nClass constrcutor overloading example------------------------------------\n";
    basic_construcotor_overloading_example();

    cout << "\nbasic_variadic_example(not overlaodable)------------------------------------\n";
    basic_variadic_example();

    cout << "\nvariadic functions different types (not overlaodable)------------------------------------\n";
    different_type_variadic_example();

    cout << "\nconst overloading example------------------------------------\n";
    const_overload_example();
    return 0;
}