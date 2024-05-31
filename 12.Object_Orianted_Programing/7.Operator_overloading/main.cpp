#include <iostream>

using namespace std;

// Base Class oveerloading ###############################################################
// Arithmetic operators(+) ---------------------------------------------------------
class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i);

    // Overloading + operator
    Complex operator+(const Complex& obj) const;

    void print_values() const;
};

Complex::Complex(double r, double i) : real(r), imag(i) {
    cout << "constrcutor called\n";
}

Complex Complex::operator+(const Complex& obj) const {
    int real_part = this->real + obj.real;
    int imag_part = this->imag + obj.imag;

    Complex result_obj(real_part, imag_part);

    return result_obj;
}

void Complex::print_values() const {
    cout << "real: " << this->real << " imag: " << this->imag << endl;
}

void arithmetic_operator_example() {
    Complex c1(1.0, 2.0);
    Complex c2(2.0, 4.0);

    Complex c3 = c1 + c2;
    cout << "c3 = c1 + c2" << endl;
    c3.print_values();
}

// unary operators-------------------------------------------------------------------
// Increment and Decrement Operators (++, --)----------------------------------------
class Counter {
    int value;
public:
    Counter(int value = 0) : value(value) {}

    Counter& operator++() { //prefix önce değeri arttırıyor sonra objeyi return ediyor
        ++value;
        return *this;
    }

    Counter operator++(int) { // postfix normal objeyi return ediyor sonra objenin değerini arttırıyor
        Counter temp = *this;
        ++value;
        return temp;
    }

    int get_value() {
        return this->value;
    }
};

void increment_operator_example() {
    Counter a,b,c(5);
    cout << "a: " << a.get_value() << endl;
    cout << "b: " << b.get_value() << endl;
    cout << "c: " << c.get_value() << endl;

    a = ++c;  // Uses the overloaded prefix increment operator
    cout << "a = ++c" << endl;
    cout << "a: " << a.get_value() << endl;
    cout << "c: " << c.get_value() << endl;

    b = c++;  // Uses the overloaded postfix increment operator
    cout << "b = c++" << endl;
    cout << "b: " << b.get_value() << endl;
    cout << "c: " << c.get_value() << endl;
}

// Assignment operators Copy(=): ----------------------------------------------------
// Copy
class DeepCopy {
private:
    int* data_ptr;
public:
    DeepCopy(int data_value);

    DeepCopy& operator=(const DeepCopy& obj);
    void print_info() const;

    ~DeepCopy();
};

DeepCopy::DeepCopy(int data_value){
    cout << "constrcutor called\n";
    this->data_ptr = new int(data_value);
}

DeepCopy& DeepCopy::operator=(const DeepCopy& obj) {
    if (this == &obj) {
        return *this;
    } // aynı objemi diye kontrol ediyoruz

    //delete data_ptr; // left valuenin değerini  siliyoruz aşağıda kontrolü var ..buna gerek yok aynı pointeri kullanmak istiyoruz sonuçta 
    //data_ptr = new int(*(obj.data_ptr)); buna da gerek yok direkt eski pointerin gösterdii alana değerimizi yazalım
    *data_ptr = *(obj.data_ptr); // veri boyutu dinamik olmadığı için bunu bu şekilde yapabiliyoruz direkt yalnız arrayler vs kullansaydık böyle olmazdı sonuçta iki var olan objeyi birbirinie kopyalıyoruz copy constructor ile karıştırma
    //sonuç oalrak herkesin kendisine ait pointeri var ve aynı değerleri gösteriyorlar
    return *this;
}

void DeepCopy::print_info() const {
    cout << "addres of data_ptr: " << data_ptr << endl;
    cout << "value of data_ptr: " << (*data_ptr) << endl;
}

DeepCopy::~DeepCopy(){
    cout << "destrcutor called\n";
    delete data_ptr;
}

void copy_assignment_operator_example() {
    DeepCopy obj1(10);
    DeepCopy obj2(20);
    cout << "obj1 and obj2 values--------\n";
    obj1.print_info();
    obj2.print_info();
    
    obj1 = obj2;  // Uses the overloaded assignment operator
    cout << "obj1 and obj2 values--------\n";
    obj1.print_info();
    obj2.print_info();
}

// Assignemnt Operator Move(=) --------------------------------------------------------
class MoveAssignment {
private:
    int* data_ptr;
public:
    MoveAssignment(int value);

    MoveAssignment& operator=(MoveAssignment &&obj);
    void print_values() const;

    ~MoveAssignment();

};

MoveAssignment::MoveAssignment(int value) {
    this->data_ptr = new int(value);
}

MoveAssignment& MoveAssignment::operator=(MoveAssignment &&obj){
    if (this == &obj) {
        return *this;
    }

    // Clean up any existing data
    delete data_ptr;

    // Transfer ownership
    data_ptr = obj.data_ptr;
    obj.data_ptr = nullptr;

    return *this;
}

void MoveAssignment::print_values() const{
    if(this->data_ptr == nullptr) {
        cout << "addres: " << this->data_ptr << " value: None" << endl;
    } else {
        cout << "addres: " << this->data_ptr << " value: " << *(this->data_ptr) << endl;
    }
}

MoveAssignment::~MoveAssignment(){
    delete this->data_ptr;
}

void move_assignment_operator_example() {
    MoveAssignment obj1(10);
    MoveAssignment obj2(20);
    cout << "obj1 and obj2 values--------\n";
    obj1.print_values();
    obj2.print_values();
    
    obj1 = std::move(obj2);  // Uses the overloaded assignment operator
    cout << "obj1 and obj2 values--------\n";
    obj1.print_values();
    obj2.print_values();
}

// Comprassion Operator----------------------------------------------------------------
class Point_ {
    int x, y;
public:
    Point_(int x, int y) : x(x), y(y) {}

    bool operator==(const Point_& other) const {
        return (x == other.x && y == other.y);
    }
};

void comprasion_operator_example() {
    Point_ p1(1, 2);
    Point_ p2(1, 2);
    
    cout << "p1 == p2" << endl;
    if (p1 == p2) {  
        cout << "equal\n" << endl;
    } else {
        cout << "not equal\n" << endl;
    }

    Point_ p3(1, 3);
    cout << "p1 == p3" << endl;
    if (p1 == p3) {  
        cout << "equal\n" << endl;
    } else {
        cout << "not equal\n" << endl;
    }
}

// Comparison Operators (<, <=, >, >=)----------------------------------------------
class Box {
    int length, breadth, height;
public:
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}

    bool operator<(const Box& other) const {
        return (length * breadth * height) < (other.length * other.breadth * other.height);
    }
};

void comprasion_operator_example_2() {
    Box b1(3, 4, 5);
    Box b2(6, 7, 8);

    cout << "b1 < b2: " << (b1 < b2) << endl;
    cout << "b2 < b1: " << (b2 < b1) << endl;
}

//Subscript Operator ([])--------------------------------------------------------------
class Array {
    int* data;
    int size;
public:
    Array(int s) : size(s) {
        data = new int[s];
    }
    
    int& operator[](int index) {
        return data[index];
    }
    
    ~Array() {
        delete[] data;
    }
};

void subscript_operator_example() {
    Array arr(10);
    arr[0] = 1;  // Uses the overloaded subscript operator
    arr[1] = 2;

    for(int i = 0; i < 10; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Function Call Operator (())--------------------------------------------------------
class Functor {
public:
    int operator()(int x, int y) const {
        return x + y;
    }
};

void function_call_operator() {
    Functor add;
    int result = add(3, 4);  // Uses the overloaded function call operator
    cout << "add(3, 4)" << result << endl;
}

// Arrow Operator (->) ---------------------------------------------------------------
class Entity {
public:
    void display() const {
        std::cout << "Entity" << std::endl;
    }
};

class SmartPointer_2 {
    Entity* ptr;
public:
    SmartPointer_2(Entity* p) : ptr(p) {}

    Entity* operator->() {
        return ptr;
    }

    ~SmartPointer_2() {
        delete ptr;
    }
};

void arrow_operator_example() {
    SmartPointer_2 sp(new Entity());
    sp->display();  // Uses the overloaded arrow operator
}

// Pointer Dereference Operator (*)--------------------------------------------------
class SmartPointer {
public:
    int* ptr;

    SmartPointer(int p) {
        this->ptr = new int(p);
    }

    int& operator*() {
        return *(this->ptr);
    }

    ~SmartPointer() {
        delete this->ptr;
    }
};

void pointer_dereference_operator_example() {
    SmartPointer sp(42);
    int value = *sp;  // Uses the overloaded pointer dereference operator

    cout << "address: " << sp.ptr << " value: " << value << endl;
}


// Globall overloading ###############################################################
// Stream Insertion Operator (<<) ----------------------------------------------------
class Person {
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(n), age(a) {}

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }
};

void stream_insertion_operator_example() {
    Person p("Alice", 30);
    std::cout << p << std::endl;  // Uses the overloaded stream insertion operator
}

// Stream Extraction Operator--------------------------------------------------------
class Point {
public:
    int x, y;

    Point() : x(0), y(0) {}

    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

void stream_extraction_operator_example() {
    Point p;
    std::cout << "Enter coordinates (x y): ";
    std::cin >> p;  // Uses the overloaded stream extraction operator
    cout << "p.x: " << p.x << " p.y: " << p.y << endl; 
}

// two different class use global operator overloading ------------------------------
// Class A header file  -------------------------------------------------------
class Class_B; // forward 

class Class_A{
private:
    int a,b;
public:
    Class_A(int a, int b);

    friend Class_A operator+(const Class_A& class_a_obj, const Class_B& class_b_obj);
    friend Class_B operator+(const Class_B& class_b_obj, const Class_A& class_a_obj);

    void print_values() const;
};
// Class B header file
class Class_B{
private:
    int a,b;
public:
    Class_B(int a, int b);

    friend Class_A operator+(const Class_A& class_a_obj, const Class_B& class_b_obj);
    friend Class_B operator+(const Class_B& class_b_obj, const Class_A& class_a_obj);

    void print_values() const;
};

// ortak source file-----------------------------------------------------
Class_A::Class_A(int a, int b) : a(a), b(b) {
    cout << "Class A constructor\n";
};

Class_B::Class_B(int a, int b) : a(a), b(b) {
    cout << "Class B constructor\n";
};

Class_A operator+(const Class_A& class_a_obj, const Class_B& class_b_obj){
    int a = class_a_obj.a + class_b_obj.a;
    int b = class_a_obj.b + class_b_obj.b;

    return Class_A(a, b);
}
Class_B operator+(const Class_B& class_b_obj, const Class_A& class_a_obj) {
    int a = class_a_obj.a + class_b_obj.a;
    int b = class_a_obj.b + class_b_obj.b;

    return Class_B(a, b);
}

void Class_A::print_values() const { 
    printf("Class_A || a: %d b: %d\n", this->a, this->b);
}

void Class_B::print_values() const{
    printf("Class_B || a: %d b: %d\n", this->a, this->b);
}

void global_overloading_example() {
    Class_A class_a(1, 1);
    Class_B class_b(2, 2);

    Class_A class_a_res(0, 0);
    Class_B class_b_res(0, 0);

    class_a_res = class_a + class_b;
    class_b_res = class_b + class_a;

    class_a_res.print_values();
    class_b_res.print_values();
}

int main() {
    cout << "Base Class Operator Overloading ###################################\n";
    cout << "arithmetic_operator_example ---------------------------------------\n";
    arithmetic_operator_example();

    cout << "\nUnary: increment_operator_example ---------------------------------------\n";
    increment_operator_example();

    cout << "\nAssignment Operator ---------------------------------------\n";
    cout << "copy_assignment_operator_example ---------------------------------------\n";
    copy_assignment_operator_example();

    cout << "\nmove_assignment_operator_example ---------------------------------------\n";
    move_assignment_operator_example();

    cout << "\ncomprasion_operator_example ---------------------------------------\n";
    comprasion_operator_example();

    cout << "\ncomprasion_operator_example_2 ---------------------------------------\n";
    comprasion_operator_example_2();

    cout << "\nsubscript_operator_example ---------------------------------------\n";
    subscript_operator_example();

    cout << "\nfunction_call_operator ---------------------------------------\n";
    function_call_operator();

    cout << "\narrow_operator ---------------------------------------\n";
    arrow_operator_example();

    cout << "\npointer_dereference_operator_example ---------------------------------------\n";
    pointer_dereference_operator_example();

    cout << "Global Operator Overloading ###################################\n";
    cout << "\nstream_insertion_operator_example ---------------------------------------\n";
    stream_insertion_operator_example();

    cout << "\nstream_extraction_operator_example ---------------------------------------\n";
    stream_extraction_operator_example();

    cout << "\nglobal_operator_overloading_example ---------------------------------------\n";
    global_overloading_example();

    return 0;
}