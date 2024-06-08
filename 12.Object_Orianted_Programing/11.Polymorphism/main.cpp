#include <iostream>
using namespace std;

// Virtual Function ###########################################################################
// Normal class example -----------------------------------------------------------------------
class Base_Normal {
private:
    int baseValue;
public:
    Base_Normal(int baseVal) : baseValue(baseVal){
        cout << "Base construcotr called\n";
    } 

    void show() {
        std::cout << "Base class show function." << std::endl;
    }
    ~Base_Normal() {
        cout << "base class destructor\n";
    }  // Sanal yıkıcı
};

class Derived_Normal : public Base_Normal {
private:
    int derivedValue;
public:
    Derived_Normal(int baseVal, int derivedVal) : Base_Normal(baseVal), derivedValue(derivedValue) {
        cout << "derived constructor called\n";
    }

    void show() {  // Geçersiz kılma
        std::cout << "Derived class show function." << std::endl;
    }

    ~Derived_Normal() {
        cout << "derived class destructor\n";
    }
};

void normal_class_example() {
    cout << "normal derived class calling--------------\n";
    Derived_Normal derived_normal(10, 20);
    derived_normal.show();

    cout << "normal ptr calling--------------\n";
    Base_Normal* basePtr;
    Derived_Normal derivedObj(10, 20);
    basePtr = &derivedObj;

    basePtr->show();  // Output: Derived class show function.

    cout << "dynmaic ptr calling--------------\n";
    Base_Normal* dynamicPtr = new Derived_Normal(10, 20);
    dynamicPtr->show();
    delete dynamicPtr;

    cout << "\n-------------------------------\n";   
}

// virtual functions class example -----------------------------------------------------------------------
class Base_Virtual {
public:
int baseValue;
    Base_Virtual(int baseVal) : baseValue(baseVal){
        cout << "Base construcotr called\n";
    }

    virtual void show() {
        std::cout << "Base class show function." << std::endl;
    }
    virtual ~Base_Virtual() {
        cout << "base class destructor\n";
    }  // Sanal yıkıcı
};

class Derived_Virtual : public Base_Virtual {
private:
    int derivedValue;
public:
    Derived_Virtual(int baseVal, int derivedVal) : Base_Virtual(baseVal), derivedValue(derivedValue) {
        cout << "derived constructor called\n";
    }

    virtual void show() override{  // Geçersiz kılma
        std::cout << "Derived class show function." << std::endl;
    }

    virtual ~Derived_Virtual() {
        cout << "derived class destructor\n";
    }
};

void virtual_funcitons_class_example() {
    cout << "normal derived class calling--------------\n";
    Derived_Virtual derived_virtual(10, 20);
    derived_virtual.show();

    cout << "normal ptr calling--------------\n";
    Base_Virtual* basePtr;
    Derived_Virtual derivedObj(10, 20);
    basePtr = &derivedObj;

    basePtr->show();  // Output: Derived class show function.

    cout << "dynmaic ptr calling--------------\n";
    Base_Virtual* dynamicPtr = new Derived_Virtual(10, 20);
    dynamicPtr->show();
    delete dynamicPtr;

    cout << "\n-------------------------------\n";   
}

// Pure virtual function example ####################################################################
#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;  // pure virtual fonksiyon
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

void pure_virtual_example() {
    Shape* shape = new Circle();
    shape->draw();  // Output: Drawing a circle.
    delete shape;
}

int main() {
    cout << "Virtual Function ####################################################################\n";
    cout << "Difference Normal and Virtual functions---------------------------------------------\n";
    cout << "normal fun example----------------\n";
    normal_class_example();

    cout << "\nvirtual fun example----------------\n";
    virtual_funcitons_class_example();

    cout << "Pure Virtual Function ##############################################################\n";
    pure_virtual_example();
    return 0;
}