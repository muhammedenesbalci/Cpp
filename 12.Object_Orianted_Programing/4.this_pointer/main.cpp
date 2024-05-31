#include <iostream>

using namespace std;

class Base {
private:
    int a;
    int b;

public:
    Base(int a, int b);

    Base& set_a(int a);
    Base& set_b(int b);
    void print_members() const;
    ~Base();

};
 
Base::Base(int a = 0, int b = 0) {
    this->a = a;
    this->b = b;
    cout << "constructor called\n";
    cout << "this->a: " << this->a << " this->b " << this->b << endl;
    cout << "*this).a: " << (*this).a << " *this).b: " << (*this).b << endl;
    cout << "in constructor this: " << this << endl;
    //cout << "*this: " << (*this) << endl; hata verir
}

Base& Base::set_a(int a) {
    this->a = a;
    return (*this);
}

Base& Base::set_b(int b) {
    this->b = b;
    return (*this);
}

void Base::print_members() const {
    cout << "a: " << this->a << " b: " << this->b << endl;
}

Base::~Base() {
    cout << "constructor called\n";
}
void basic_example() {
    Base base(1, 2);
    cout << "&base: " << &base << endl;
}

void chain_fun_exampple() {
    Base base;

    base.set_a(1).set_b(2);
    base.print_members();
}

int main() {
    cout << "\nBasic example--------------------------------------\n";
    basic_example();

    cout << "\nchain example--------------------------------------\n";
    chain_fun_exampple();

    return 0;
}