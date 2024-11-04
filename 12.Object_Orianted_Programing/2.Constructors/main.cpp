#include <iostream>

using namespace std;

// Constructor################################################
//Constructor inside class definition-----------------------------------------
class Student {
private:
    int age;
 
public:
    // constructor
    Student() {
        age = 35;
        cout << "inside constuctor called\n";
    }
 
    void display() {
        cout << "age: "<< age << endl;
    }
};

void constructor_inside_example() {
    Student student;
    student.display();
}

//Constructor outside class definition-----------------------------------------
class Student_ {
private:
    int age;
 
public:
    // constructor
    Student_();
 
    void display() {
        cout << "age: "<< age << endl;
    }
};
Student_::Student_() {
    age = 35;
    cout << "outside constuctor called\n";
}

void constructor_outside_example() {
    Student_ student_;
    student_.display();
}
// Default constructor----------------------------------------------------------
class Base{
public:
    int a,b;
    //default constructor
    Base();
};

Base::Base() {
    a = 20;
    b = 30;
    cout << "Default Constructor without parameter" << endl;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}
// Parameterized constructor----------------------------------------------------------
class Base_2 {
private:
    int a;
    int b;
    string c;
public:
    Base_2();
    Base_2(int a_p);
    Base_2(int a_p, int b_p);
    Base_2(int a_p, int b_p, string c_p);
    
};

Base_2::Base_2::Base_2(){
    cout << "Default Constructor 0 parameter" << endl;
}
Base_2::Base_2(int a_p){
    a = a_p;
    cout << "One Parameter Constructor | a: " << a << endl;
}
Base_2::Base_2(int a_p, int b_p){
    a = a_p;
    b = b_p;
    cout << "two Parameter Constructor | a: " << a << " b: "<< b << endl;
}
Base_2::Base_2(int a_p, int b_p, string c_p){
    a = a_p;
    b = b_p;
    c = c_p;
    cout << "three Parameter Constructor | a: " << a << " b: "<< b << " c: " << c << endl;
}

void parameterized_constructor_example() {
    Base_2 obj;
    Base_2 obj2(1);
    Base_2 obj3(2, 3);
    Base_2 obj4(4, 5, "enes");
}

// Default argument Constructor-----------------------------------------------------------------

class Base_3 {
private:
    int a;
    int b;
    string c;

public:
    Base_3(int a_p, int b_p, string c_p); 
};

Base_3::Base_3(int a_p = 0, int b_p = 0, string c_p = "empty"){
    a = a_p;
    b = b_p;
    c = c_p;
    cout << "Default Parameter Constructor | a: " << a << " b: "<< b << " c: " << c << endl;
} 
void default_argument_constructor_example() {
    Base_3 obj;
    Base_3 obj2(1);
    Base_3 obj3(2, 3);
    Base_3 obj4(4, 5, "enes");
}
// Copy Constructor ------------------------------------------------------------------------
// Default Copy Constructor by Complier------------------------------------------------------
class Base_4 {
public:
    int a,b;
    Base_4(int a, int b);
    void print_values();
};

Base_4::Base_4(int a_p = 0, int b_p = 0) {
    a = a_p;
    b = b_p;
    cout << "Constructor called" << endl;
}

void Base_4::print_values() {
    cout << "a: " << a << " b: " << b << endl;
}

void default_copy_constructor_complier_example() {
    Base_4 obj(5, 6);
    Base_4 obj_2 = obj;
    obj.print_values();
    obj_2.print_values();
}
// Default Copy Constructor by User defined------------------------------------------------------
class Base_5 {
private:
    int a, b, c;

public:
    Base_5(int a, int b, int c);
    void print_values();

    //copy constructor
    Base_5(const Base_5 &obj);

    //Destructor
    ~Base_5();
};

Base_5::Base_5(int a_p = 0, int b_p = 0, int c_p = 0) {
    a = a_p;
    b = b_p;
    c = c_p;
    cout << "Constructor called" << endl;
}

Base_5::Base_5(const Base_5 &obj){
    a = obj.a;
    b = obj.b;
    //c = obj.c; bunu eklemediğimiz zaman c değerini almaz saçma değerler atıyor.
    cout << "Copy Constructor called" << endl;
}

void Base_5::print_values() {
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
}

Base_5::~Base_5() {
    cout << "Destrctor called" << endl;
}

Base_5 test_copy_constructor_base_5(Base_5 obj) {
    cout << "in test_copy_constructor_base_5 function" << endl;
    return obj;
}

void test_copy_constructor_reference_base_5(Base_5 &obj) {
    cout << "in test_copy_constructor_reference_base_5 function" <<endl;
}
void default_copy_constructor_user_defined_example() {
    Base_5 obj(1, 2, 3);
    Base_5 obj_2 = obj;
    cout << "\noriginal obj---------------------\n";
    obj.print_values();

    cout << "\ncopy obj-------------------------\n";
    obj_2.print_values();

    cout << "\nwith functions normal------------------\n";
    Base_5 obj_3 = test_copy_constructor_base_5(obj);

    cout << "\nwith functions referece-------------------\n";
    test_copy_constructor_reference_base_5(obj);
}

//Deep Copy --------------------------------------------------------------------------------
class Base_6 {
private:
    int a, b, c;
    int* data;

public:
    Base_6(int a, int b, int c, int value_for_pointer);
    void print_values();

    //copy constructor
    Base_6(const Base_6 &obj);

    //Destructor
    ~Base_6();
};

Base_6::Base_6(int a_p = 0, int b_p = 0, int c_p = 0, int value_for_pointer = 0) {
    a = a_p;
    b = b_p;
    c = c_p;

    data = new int;
    *data = value_for_pointer;

    cout << "Constructor called" << endl;
}

Base_6::Base_6(const Base_6 &obj){
    a = obj.a;
    b = obj.b;
    //c = obj.c; bunu eklemediğimiz zaman c değerini almaz saçma değerler atıyor. çünkü kopyalama yaparken normnal constructoru çağırmıyoruz

    // dataya orjinal objenin pointerinde tuttuğu datayı kopyalıyoruz datanın kendisini değil
    data = new int;
    *data = *(obj.data);
    cout << "Copy Constructor called" << endl;
}

void Base_6::print_values() {
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
    cout << "addres of data: " << data << " value of data: " << *data << endl;
}

Base_6::~Base_6() {
    delete data;
    cout << "Destrctor called" << endl;
}

Base_6 test_copy_constructor_Base_6(Base_6 obj) {
    obj.print_values();
    cout << "in test_copy_constructor_Base_6 function" << endl;
    return obj;
}

void default_copy_constructor_user_defined_example_base_6() {
    Base_6 obj(1, 2, 3, 100);
    Base_6 obj_2 = obj;
    cout << "\noriginal obj-------------------\n";
    obj.print_values();

    cout << "\ncopy obj-----------------------\n";
    obj_2.print_values();

    cout << "\nwith functions normal----------------\n";
    Base_6 obj_3 = test_copy_constructor_Base_6(obj);
    obj_3.print_values();

    cout << "\nwith functions normal not returning to a object---------------------\n";
    test_copy_constructor_Base_6(obj);
    cout << "last line----------------------------------\n";
}
//Move Constructor --------------------------------------------------------------------------------
class Base_7 {
private:
    int a, b, c;
    int* data;
    string name;
    string destrctor_for;

public:
    Base_7(int a_p, int b_p, int c_p, int value_for_pointer, string name_p);
    void print_values();

    //copy constructor
    Base_7(const Base_7 &obj);

    //move constructor
    Base_7(Base_7 &&obj);

    //Destructor
    ~Base_7();
};

Base_7::Base_7(int a_p = 0, int b_p = 0, int c_p = 0, int value_for_pointer = 0, string name_p = "empty") {
    a = a_p;
    b = b_p;
    c = c_p;
    name = name_p;
    destrctor_for = "Normal Constrctor";

    data = new int;
    *data = value_for_pointer;

    cout << "Constructor called" << endl;
}

Base_7::Base_7(const Base_7 &obj){
    a = obj.a;
    b = obj.b;
    c = obj.c; 
    name = obj.name;

    destrctor_for = "copy Constrctor";

    data = new int; // data = new int(*(obj.data))
    *data = *(obj.data);
    cout << "Copy Constructor called" << endl;
}

Base_7::Base_7(Base_7 &&obj){
    a = obj.a;
    b = obj.b;
    c = obj.c; 
    name = obj.name;

    destrctor_for = "Move Constrctor";

    // Altakileri yapmaya gerek yok çünkü ekstra yük bindiriyor
    //obj.a = 0;
    //obj.b = 0;
    //obj.c = 0;
    //obj.name = "deleted";

    data = obj.data;
    obj.data = nullptr;
    
    cout << "Move Constructor called" << endl;
}


void Base_7::print_values() {
    cout << "a: " << a << " b: " << b << " c: " << c << " name: " << name << endl;
    if (data == nullptr)
        cout << "nullptr\n";
    else
        cout << "addres of data: " << data << " value of data: " << *data << endl;
}

Base_7::~Base_7() {
    delete data;
    cout << "Destrctor called for: " << destrctor_for << endl;
}

Base_7 test_constructors_Base_7(Base_7 obj) {
    cout << "in test_constructors_Base_7: function" << endl;
    obj.print_values();
    return obj;
}

Base_7 test_constructors_no_input_Base_7() {
    cout << "in test_constructors_no_input_Base_7: no input function" << endl;

    Base_7 obj;
    return obj;
}

void move_constructor_example() {
    Base_7 obj(1, 2, 3, 100, "obj");
    Base_7 obj_2 = obj; // normal constructor çağrılmaz
    cout << "\noriginal obj--------------\n";
    obj.print_values();

    cout << "\ncopy obj----------------\n";
    obj_2.print_values();

    cout << "\nwith functions normal------------------\n";
    Base_7 obj_3 = test_constructors_Base_7(obj);
    cout << "input obj----\n";
    obj.print_values();

    cout << "output obj----\n";
    obj_3.print_values();

    cout << "\nwith functions normal not returning to a object---------------------\n";
    test_constructors_Base_7(obj);

    cout << "\nno input function-------------------------------------------\n";
    Base_7 obj_5 = test_constructors_no_input_Base_7();
    obj_5.print_values();

    cout << "\nmove constructor test--------------------------\n";
    Base_7 obj_4 = std::move(obj_3); // Move constructor çağrılır
    obj_4.print_values();
    obj_3.print_values();

    cout << "last line----------------------------------\n";
}

// Initilization List ####################################################################
// Basic  Initilization-------------------------------------------------------------------
class MyClass{
private:
    int a;
    int b;

public:
    MyClass();
    MyClass(int x);
    MyClass(int x, int y);
};

MyClass::MyClass() {
    cout << "default constructor 0 parameters\n";
}
MyClass::MyClass(int x) : a(x) {
    cout << "constructor 1 parameters\n";
}
MyClass::MyClass(int x, int y) : a(x), b(y) {
    cout << "constructor 2 parameters\n";
}
void basit_init_list_example() {
    MyClass obj;
    MyClass obj_1(1);
    MyClass obj_2(1, 2);
}

// const and reference data members Initilization-------------------------------------------------------------------
class MyClass_2{
private:
    const int constVar;
    int& refernceVar;

    const int& refernceVarForConstInternal;

    const int constVarInternal;

public:
    //MyClass_2();
    //MyClass_2(int constVar);
    MyClass_2(int x, int& y);
};

/*
MyClass_2::MyClass_2() {
    cout << "default constructor 0 parameters\n";
}
MyClass_2::MyClass_2(int x) : constVar(x) {
    cout << "constructor 1 parameters\n";
}
*/

MyClass_2::MyClass_2(int x, int& y) : constVar(x), refernceVar(y), refernceVarForConstInternal(constVar), constVarInternal(35){
    cout << "constructor 2 parameters\n";
    cout << "constVar: " << this->constVar << " referenceVar: " << this->refernceVar << endl;
    cout << "refernceVarForConstInternal: " << this->refernceVarForConstInternal << " constVarInternal: " << this->constVarInternal << endl;

}
void const_and_ref_init_list_example() {
    int value = 20;
    MyClass_2 obj(10, value); //referansa değer atarken onun bir refaran olduğunu bilidrmene gerek yok(rvalue için diyorum) direkt atıyoruz
}

// Delegaring Constrctors----------------------------------------------------------------------------
class MyClass_3 {
public:
    int x, y;


    MyClass_3() : MyClass_3(0, 0) {
        cout << "0 paremeter constrcutor\n";
    }
    MyClass_3(int x) : MyClass_3(x, 0) {
        cout << "1 paremeter constrcutor\n";
    }
    MyClass_3(int x, int y) : x(x), y(y) {
        cout << "2 paremeter constrcutor\n";
    }
};

void delegating_constructors_example() {
    MyClass_3 obj;
    cout << "x: " << obj.x << " y: " << obj.y << endl;
    
    MyClass_3 obj1(10);
    cout << "x: " << obj1.x << " y: " << obj1.y << endl;
    
    MyClass_3 obj2(10, 20);
    cout << "x: " << obj2.x << " y: " << obj2.y << endl;
}
// Initialization types examples -------------------------------------------------------------------
class Initialization_class {
public:    
    
    Initialization_class() {
        cout << "Constructor called: empty\n";
    }

    Initialization_class(int a_var) : a(a_var) {
        cout << "Constructor called: one\n";
    }

    Initialization_class(int a_var, int b_var) : b(b_var) {
        cout << "Constructor called: two\n";
    }

    Initialization_class(const Initialization_class& obj) {
        cout << "Copy Constructor called\n";
    }

    Initialization_class(Initialization_class&& obj) {
        cout << "Move Constructor called\n";
    }

    Initialization_class& operator=(const Initialization_class& obj) {
        cout << "copy assignment called\n";
        return *this;
    }

private:
    int a;
    int b;
};

void initialization_types_example() {
    cout << "Direct initializtion-----------\n";
    Initialization_class direct_init;
    Initialization_class direct_init_1(1);
    Initialization_class direct_init_2(1, 2);

    cout << "Direct initializtion 2-----------\n";
    Initialization_class direct_init_3 = 10;

    cout << "List initializtion-----------\n";
    Initialization_class list_init{};
    Initialization_class list_init_1{1};
    Initialization_class list_init_2{1, 2};

    cout << "Aggregate initializtion-----------\n";
    Initialization_class aggregate_init = {};
    Initialization_class aggregate_init_1 = {1};
    Initialization_class aggregate_init_2 = {1, 2};
}

// Initialization types examples 2-------------------------------------------------------------------
class Initialization_class_2 {
public:    
    
    explicit Initialization_class_2() {
        cout << "Constructor called: empty\n";
    }

    explicit Initialization_class_2(int a_var) : a(a_var) {
        cout << "Constructor called: one\n";
    }

    explicit Initialization_class_2(int a_var, int b_var) : b(b_var) {
        cout << "Constructor called: two\n";
    }

    explicit Initialization_class_2(const Initialization_class_2& obj) {
        cout << "Copy Constructor called\n";
    }

    explicit Initialization_class_2(Initialization_class_2&& obj) {
        cout << "Move Constructor called\n";
    }

    Initialization_class_2& operator=(const Initialization_class_2& obj) {
        cout << "copy assignment called\n";
        return *this;
    }

private:
    int a;
    int b;
};

void initialization_types_example_2() {
    cout << "Direct initializtion-----------\n";
    Initialization_class_2 direct_init;
    Initialization_class_2 direct_init_1(1);
    Initialization_class_2 direct_init_2(1, 2);

    // hata verir
    /*
    cout << "Direct initializtion 2-----------\n";
    Initialization_class_2 direct_init_3 = 10;
    */

    cout << "List initializtion-----------\n";
    Initialization_class_2 list_init{};
    Initialization_class_2 list_init_1{1};
    Initialization_class_2 list_init_2{1, 2};

    // hata verir conversion yapılamaz
    /*
    cout << "Aggregate initializtion-----------\n";
    Initialization_class_2 aggregate_init = {};
    Initialization_class_2 aggregate_init_1 = {1};
    Initialization_class_2 aggregate_init_2 = {1, 2};
    */
}

void copy_assignment_init_types_ex() {
    Initialization_class direct_init;
    direct_init = 5;

    // hata verir
    /*
    Initialization_class_2 direct_init_2;
    direct_init_2 = 5;
    */

    Initialization_class aggregate_init;
    aggregate_init = {5, 2};

    // hata verir
    /*
    Initialization_class_2 aggregate_init_2;
    aggregate_init_2 = {5, 2};
    */
}

void narrowing_example() {
    cout << "Direct initializtion-----------\n";
    //explict olmasıyla ilgisi yok
    Initialization_class_2 direct_init;
    Initialization_class_2 direct_init_1(1.2);
    Initialization_class_2 direct_init_2(1, 2.2);

    // hata verir
    /*
    cout << "List initializtion-----------\n";
    Initialization_class_2 list_init{};
    Initialization_class_2 list_init_1{1.2};
    Initialization_class_2 list_init_2{1, 2.5};
    */
}

// explicit keyword ---------------------------------------------------------------------
void explicit_keyword_example() {
    cout << "Copy assignment --------------------------------------------\n";
    Initialization_class_2 direct_init_1;
    direct_init_1 = static_cast<Initialization_class_2>(5);

    // {} aggregate
    Initialization_class_2 aggregate_init_1;
    aggregate_init_1 = static_cast<Initialization_class_2>(5, 2);

    cout << "init  ----------------------------------------------------\n";
    Initialization_class_2 direct_init_2 = static_cast<Initialization_class_2>(5);

    // {} aggregate
    Initialization_class_2 aggregate_init_2 = static_cast<Initialization_class_2>(5, 2);
}

int main() {
    cout << "\nInside Constructor -----------------------------------------------\n";
    constructor_inside_example();

    cout << "\nOutside Constructor -----------------------------------------------\n";
    constructor_outside_example();

    cout << "\nDefault Constructor -----------------------------------------------\n";
    constructor_outside_example();

    cout << "\nParameterized Constructor -----------------------------------------------\n";
    parameterized_constructor_example();

    cout << "\nDefault Argument Constructor -----------------------------------------------\n";
    default_argument_constructor_example();

    cout << "\nDefault Copy Constructor by Complier-----------------------------------------------\n";
    default_copy_constructor_complier_example();

    cout << "\nDefault Copy Constructor by User defined-----------------------------------------------\n";
    default_copy_constructor_user_defined_example();

    cout << "\nDefault Deep Copy Constructor by User defined-----------------------------------------------\n";
    default_copy_constructor_user_defined_example_base_6();

    cout << "\nMove Constructor-----------------------------------------------\n";
    move_constructor_example();

    cout << "\nInitilizaiton List examples#################################################\n";
    cout << "\nBasic Initilizaiton List-----------------------------------------------\n";
    basit_init_list_example();

    cout << "\nconst and ref Initilizaiton List-----------------------------------------------\n";
    const_and_ref_init_list_example();

    cout << "\nDelegating constructors-----------------------------------------------\n";
    delegating_constructors_example();

    cout << "\nInitialization_types-----------------------------------------------\n";
    initialization_types_example();

    cout << "\nInitialization_types-2-----------------------------------------------\n";
    initialization_types_example_2();

    cout << "\ncopy_assignment_init_types-----------------------------------------------\n";
    copy_assignment_init_types_ex();

    cout << "\nnarrowing_example-----------------------------------------------\n";
    narrowing_example();

    cout << "\nexplicit_keyword_example-----------------------------------------------\n";
    explicit_keyword_example();

    return 0;
}