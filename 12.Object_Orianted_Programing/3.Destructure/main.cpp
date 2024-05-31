#include <iostream>
using namespace std;
 
//Basic Destructure example-----------------------------------------------------------------
class Base {
public:
    // Data Member
    string name;
    int* ptr;

    // User-Defined Constructor
    Base(string name_p);
 
    // User-Defined Destructor
    ~Base(); 
};
Base::Base(string name_p){ 
    ptr = new int;
    name = name_p;
    cout << "Constructor executed: " << name << endl; 
}

Base::~Base() { 
    delete ptr;
    cout << "Destrcture executed: " << name << endl;  
}

void basic_destructure_example() {
    Base base("base");
    Base b1("b1"), b2("b2"), b3("b3");
}
int main() {
    cout << "\nBasic Destructure example ---------------------------------------------\n";
    basic_destructure_example();
    
    return 0;
}
