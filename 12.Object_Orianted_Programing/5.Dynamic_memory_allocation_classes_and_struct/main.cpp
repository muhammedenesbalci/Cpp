#include <iostream>

using namespace std;

// Class #############################################################################
class Base {
private:
    int a;
    int b;
    string name;

public:
    Base();
    Base(string name);
    Base(int a, string name);
    Base(int a, int b, string name);

    void set_a(int a);
    void set_b(int b);

    void print_members() const;
    ~Base();

};
Base::Base() {
    this->name = "empty";
    cout << "constructor called 0 parameter for: " << this->name << endl;;
    cout << "in constructor this: " << this << endl;
}
Base::Base(string name) {
    this->name = name;
    cout << "constructor called 1 parameter for: " << this->name << endl;;
    cout << "in constructor this: " << this << endl;
}

Base::Base(int a, string name) {
    this->a = a;
    this->name = name;
    cout << "constructor called 2 parameter for: " << this->name << endl;;
    cout << "this->a: " << this->a << endl;
    cout << "*(this).a: " << (*this).a << endl;
    cout << "in constructor this: " << this << endl;
}

Base::Base(int a, int b, string name) {
    this->a = a;
    this->b = b;
    this->name = name;
    cout << "constructor called 3 parameter for: " << this->name << endl;
    cout << "this->a: " << this->a << " this->b " << this->b << endl;
    cout << "*(this).a: " << (*this).a << " *(this).b: " << (*this).b << endl;
    cout << "in constructor this: " << this << endl;
    //cout << "*this: " << (*this) << endl; hata verir
}

void Base::set_a(int a) {
    this->a = a;
}

void Base::set_b(int b) {
    this->b = b;
}

void Base::print_members() const {
    cout << "a: " << this->a << " b: " << this->b << endl;
}

Base::~Base() {
    cout << "destructor called for: " << this->name << endl;
}

// Basic example ----------------------------------------------------------------------------
void class_basic_example() {
    Base base(1, 2, "obj");
    cout << "&base: " << &base << endl;
}

// Dynamic Memory Allocation ---------------------------------------------------------------
void class_dynmaic_memory_allocaiton_example() {
    cout << "first case ----------------------------\n";
    Base* obj = new Base(1, 2, "obj");
    cout << "obj: " << obj << endl;

    obj->print_members();

    cout << "Second case ----------------------------\n";
    obj->set_a(10);
    obj->set_b(20);
    obj->print_members();

    delete obj;

    cout << "last line ----------------------------\n";

    cout << "\nconstrucor difference -----------------------------------------\n";
    Base* obj_1 = new Base; //veya new Base() de olabilir ve bu önerilir
     Base* obj_2 = new Base("obj 2");
    Base* obj_3 = new Base(1, "obj 3");
    Base* obj_4 = new Base(1, 2, "obj 4");
    
    delete obj_1;
    delete obj_2;
    delete obj_3;
    delete obj_4;
}
int main() {
    cout << "\nClass example######################################\n";
    cout << "\nBasic example--------------------------------------\n";
    class_basic_example();

    cout << "\nDynmaic Memory Allocation--------------------------------------\n";
    class_dynmaic_memory_allocaiton_example();

    return 0;
}