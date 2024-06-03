#include <iostream>

using namespace std;
// Acces modifiers for Inheritence ##########################################################
class Base {
public:
    void publicMethod() {
        cout << "Base public method" << endl;
    }
protected:
    void protectedMethod() {
        cout << "Base protected method" << endl;
    }
private:
    void privateMethod() {
        cout << "Base private method" << endl;
    }
};

class PublicDerived : public Base {
    // Base class'ın public ve protected üyeleri, Derived class'ta aynı kalır
public:
    void access_base_class_members() {
        this->publicMethod();
        this->protectedMethod();
        //this->privateMethod(); // ulaşılamaz
    }
};

class ProtectedDerived : protected Base {
    // Base class'ın public ve protected üyeleri, Derived class'ta protected olur
public:
    void access_base_class_members() {
        this->publicMethod();
        this->protectedMethod();
        //this->privateMethod(); // ulaşılamaz
    }
};

class PrivateDerived : private Base {
    // Base class'ın public ve protected üyeleri, Derived class'ta private olur
public:
    void access_base_class_members() {
        this->publicMethod();
        this->protectedMethod();
        //this->privateMethod(); // ulaşılamaz
    }
};

/*
//hiç bir üyeye ulaşamyız çünkü PrivateDerived classı private inheritence yapmış. Base classın ne public ne de protected üyelerine erişimimiz yok artık.
class DerivedClassPublic : public PrivateDerived{
    void access_base_class_members() {
        this->publicMethod();
        this->protectedMethod();
        //this->privateMethod(); // ulaşılamaz
    }
};
*/
void access_modifier_for_inheritence() {
    cout << "Public derived ------------------------------------------------\n";
    cout << "in class function -----------------------\n";
    PublicDerived publicDerived;
    publicDerived.access_base_class_members();
    cout << "outside class-----------------------\n";
    publicDerived.publicMethod();
    //publicDerived.protectedMethod(); // dışarıdan ulaşılamaz
    //publicDerived.privateMethod(); // dışarıdan ulaşılamaz

    cout << "Protected derived ------------------------------------------------\n";
    cout << "in class function -----------------------\n";
    ProtectedDerived protectedDerived;
    protectedDerived.access_base_class_members();
    cout << "outside class-----------------------\n";
    //protectedDerived.publicMethod(); // dışarıdan ulaşılamaz
    //protectedDerived.protectedMethod(); // dışarıdan ulaşılamaz
    //protectedDerived.privateMethod(); // dışarıdan ulaşılamaz

    cout << "Private derived ------------------------------------------------\n";
    cout << "in class function -----------------------\n";
    PrivateDerived privateDerived;
    privateDerived.access_base_class_members();
    cout << "outside class-----------------------\n";
    //privateDerived.publicMethod(); // dışarıdan ulaşılamaz
    //privateDerived.protectedMethod(); // dışarıdan ulaşılamaz
    //privateDerived.privateMethod(); // dışarıdan ulaşılamaz
}


// Inheritence types ##########################################################
// Single Inheritence---------------------------------------------------------
class Base_single {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Derived_single : public Base_single {
    // Derived class inherits from Base class
};

void single_inheritence_example() {
    Derived_single derived_single;
    derived_single.display();
}

// Multiple Inheritence---------------------------------------------------------
class Base_multiple_1 {
public:
    void display() {
        cout << "Base1 class" << endl;
    }
};

class Base_multiple_2 {
public:
    void show() {
        cout << "Base2 class" << endl;
    }
};

class Derived_multiple : public Base_multiple_1, public Base_multiple_2 {
    // Derived class inherits from both Base1 and Base2
};

void multiple_inheritence_example() {
    Derived_multiple derived_multiple;
    derived_multiple.display();
    derived_multiple.show();
}

// Multilevel Inheritence---------------------------------------------------------
class Base_multilevel {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Intermediate_multilevel : public Base_multilevel {
    // Intermediate class inherits from Base class
};

class Derived_multilevel : public Intermediate_multilevel {
    // Derived class inherits from Intermediate class
    // Indirectly inherits from Base class as well
};

void multilevel_inheritence_example() {
    Derived_multilevel derived_multilevel;
    Intermediate_multilevel intermediate_multilevel;

    derived_multilevel.display();
    intermediate_multilevel.display();
}
// Hierarchical Inheritence---------------------------------------------------------
class Base_hierarchical {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Derived_hierarchical_1 : public Base_hierarchical {
    // Derived1 class inherits from Base class
};

class Derived_hierarchical_2 : public Base_hierarchical {
    // Derived2 class inherits from Base class
};

void hierarchical_inheritence_example() {
    Derived_hierarchical_1 derived_hierarchical_1;
    Derived_hierarchical_2 derived_hierarchical_2;

    derived_hierarchical_1.display();
    derived_hierarchical_2.display();
}

// Hybrid Inheritence---------------------------------------------------------
class Base_hybrid {
public:
    void display() {
        cout << "Base class" << endl;
    }
};

class Intermediate_hybrid_1 : virtual public Base_hybrid {
    // Intermediate1 class inherits from Base class
    // Virtual inheritance to avoid diamond problem
public:
    void show_1(){
        cout << "Intermediate_hybrid_1 class" << endl;
    }
};

class Intermediate_hybrid_2 : virtual public Base_hybrid {
    // Intermediate2 class inherits from Base class
    // Virtual inheritance to avoid diamond problem
public: 
    void show_2(){
        cout << "Intermediate_hybrid_2 class" << endl;
    }
};

class Derived_hybrid : public Intermediate_hybrid_1, public Intermediate_hybrid_2 {
    // Derived class inherits from both Intermediate1 and Intermediate2
};

void hybrid_inheritence_example() {
    Derived_hybrid derived_hybrid;
    derived_hybrid.display();
    derived_hybrid.show_1();
    derived_hybrid.show_2();

    Intermediate_hybrid_1 intermediate_hybrid_1;
    intermediate_hybrid_1.display();

    Intermediate_hybrid_2 intermediate_hybrid_2;
    intermediate_hybrid_2.display();
}

// Constructor initialization for inheritence ################################################
// Single Inheritence------------------------------------------------------------------------

class Base__Single {
public:
    int baseValue;
    Base__Single(int val) : baseValue(val) { 
        std::cout << "Base Constructor: " << baseValue << std::endl; 
    }
    ~Base__Single() { 
        std::cout << "Base Destructor" << std::endl; 
    }
};

class Derived__Single : public Base__Single {
public:
    int derivedValue;
    Derived__Single(int baseVal, int derivedVal) : Base__Single(baseVal), derivedValue(derivedVal) { 
        std::cout << "Derived Constructor: " << derivedValue << std::endl; 
    }
    ~Derived__Single() { std::cout << "Derived Destructor" << std::endl; }
};

void single_inheritence_example__() {
    Derived__Single derived(1, 2);
}

// Multiple Inheritence------------------------------------------------------------------------
class Base__Mulitple_1 {
public:
    int baseValue_1;
    Base__Mulitple_1(int val) : baseValue_1(val) {
        cout << "Base Class - 1 constructor| val: " << this->baseValue_1 << endl;
    }

    ~Base__Mulitple_1() {
        cout << "Base Class - 1 destructor\n";
    }
};

class Base__Mulitple_2 {
public:
    int baseValue_2;
    Base__Mulitple_2(int val) : baseValue_2(val) {
        cout << "Base Class - 2 constructor| val: " << this->baseValue_2 << endl;
    }

    ~Base__Mulitple_2() {
        cout << "Base Class - 2 destructor\n";
    }
};

class Derived__Multiple : public Base__Mulitple_1, public Base__Mulitple_2 {
public:
    int derivedValue;
    Derived__Multiple(int baseValue_1, int baseValue_2, int val) 
        : Base__Mulitple_1(baseValue_1), Base__Mulitple_2(baseValue_2), derivedValue(val) {
        cout << "Derived class constructor | Base - 1 class value: " << this->baseValue_1 
             << " | Base - 2 class value: " << this->baseValue_2 
             << " | derived class value: " << this->derivedValue << endl; 
    }

    ~Derived__Multiple() {
        cout << "Derived class destructor\n";
    }
};

void multiple_inheritence_example__() {
    Derived__Multiple d(1, 2, 3);
}

//Multilevel inheritence--------------------------------------------------------------------
class Base__Multilevel {
public:
    int baseValue;
    Base__Multilevel(int val) : baseValue(val) { 
        std::cout << "Base Constructor: " << baseValue << std::endl; 
    }
    ~Base__Multilevel() { 
        std::cout << "Base Destructor" << std::endl; 
    }
};

class Intermediate__Multilevel : public Base__Multilevel {
public:
    int intermediateValue;
    Intermediate__Multilevel(int baseVal, int intermediateVal) : Base__Multilevel(baseVal), intermediateValue(intermediateVal) { 
        std::cout << "Intermediate Constructor: " << intermediateValue << std::endl; 
    }
    ~Intermediate__Multilevel() { 
        std::cout << "Intermediate Destructor" << std::endl; 
    }
};

class Derived__Multilevel : public Intermediate__Multilevel {
public:
    int derivedValue;
    Derived__Multilevel(int baseVal, int intermediateVal, int derivedVal) 
        : Intermediate__Multilevel(baseVal, intermediateVal), derivedValue(derivedVal) { 
        std::cout << "Derived Constructor: " << derivedValue << std::endl; 
    }
    ~Derived__Multilevel() {
        std::cout << "Derived Destructor" << std::endl; 
    }
};

void multilevel_inheritence_example__() {
    Derived__Multilevel d(10, 20, 30);
}

//Hierarchical inheritence--------------------------------------------------------------------
class Base__Hierarchical {
public:
    int baseValue;
    Base__Hierarchical(int val) : baseValue(val) { std::cout << "Base Constructor: " << baseValue << std::endl; }
    ~Base__Hierarchical() { std::cout << "Base Destructor" << std::endl; }
};

class Derived__Hierarchical_1 : public Base__Hierarchical {
public:
    int derived1Value;
    Derived__Hierarchical_1(int baseVal, int derived1Val) : Base__Hierarchical(baseVal), derived1Value(derived1Val) { 
        std::cout << "Derived1 Constructor: " << derived1Value << std::endl; 
    }
    ~Derived__Hierarchical_1() { std::cout << "Derived1 Destructor" << std::endl; }
};

class Derived__Hierarchical_2 : public Base__Hierarchical {
public:
    int derived2Value;
    Derived__Hierarchical_2(int baseVal, int derived2Val) : Base__Hierarchical(baseVal), derived2Value(derived2Val) { 
        std::cout << "Derived2 Constructor: " << derived2Value << std::endl; 
    }
    ~Derived__Hierarchical_2() { std::cout << "Derived2 Destructor" << std::endl; }
};

void hierarchical_inheritence_example__() {
    Derived__Hierarchical_1 d1(10, 20);
    Derived__Hierarchical_2 d2(30, 40);
}

//Hybrid inheritence--------------------------------------------------------------------
class Base__Hybrid {
public:
    int baseValue;
    Base__Hybrid(int val) : baseValue(val) { std::cout << "Base Constructor: " << baseValue << std::endl; }
    ~Base__Hybrid() { std::cout << "Base Destructor: "<< this->baseValue << std::endl; }
};

class Derived__Hybrid_1 : virtual public Base__Hybrid {
public:
    int derived1Value;
    Derived__Hybrid_1(int baseVal, int derived1Val) : Base__Hybrid(baseVal), derived1Value(derived1Val) { 
        std::cout << "Derived1 Constructor: " << derived1Value << std::endl; 
    }
    ~Derived__Hybrid_1() { std::cout << "Derived1 Destructor" << std::endl; }
};

class Derived__Hybrid_2 : virtual public Base__Hybrid {
public:
    int derived2Value;
    Derived__Hybrid_2(int baseVal, int derived2Val) : Base__Hybrid(baseVal), derived2Value(derived2Val) { 
        std::cout << "Derived2 Constructor: " << derived2Value << std::endl; 
    }
    ~Derived__Hybrid_2() { std::cout << "Derived2 Destructor" << std::endl; }
};

class Derived__Hybrid_3 : public Derived__Hybrid_1, public Derived__Hybrid_2 {
public:
    int derived3Value;
    Derived__Hybrid_3(int baseVal, int derived1Val, int derived2Val, int derived3Val) 
        : Base__Hybrid(baseVal), Derived__Hybrid_1(baseVal, derived1Val), Derived__Hybrid_2(baseVal, derived2Val), derived3Value(derived3Val) { 
        std::cout << "Derived3 Constructor: " << derived3Value << std::endl; 
    }
    ~Derived__Hybrid_3() { std::cout << "Derived3 Destructor" << std::endl; }
};

void hybrid_inheritence_example__() {
    Derived__Hybrid_3 d3(10, 20, 30, 40);
}


// Operator Overloading #####################################################################
// Base Sınıfta Operator Overloading -1 -------------------------------------------------------
class Base_Overload_1 {
public:
    int baseValue;
    Base_Overload_1(int val) : baseValue(val) {}

    // Operator overloading for '+'
    Base_Overload_1 operator+(const Base_Overload_1& other) const {
        return Base_Overload_1(this->baseValue + other.baseValue);
    }

    void print() const {
        std::cout << "Base value: " << this->baseValue << std::endl;
    }
};

class Derived_Overload_1 : public Base_Overload_1 {
public:
    int derivedValue;
    Derived_Overload_1(int baseVal, int derivedVal) : Base_Overload_1(baseVal), derivedValue(derivedVal) {
    }
    // No operator overloading in Derived class

    void print() const {
        std::cout << "Base value: " << this->baseValue << std::endl;
        std::cout << "derived value: " << this->derivedValue << std::endl;
    }
};

void base_overlaod_ex_1() {
    cout << "Base class----\n";
    Base_Overload_1 b1(10);
    Base_Overload_1 b2(20);
    Base_Overload_1 b3 = b1 + b2;
    b3.print();  // Output: Base value: 30

    cout << "Derived class----\n";
    Derived_Overload_1 d1(30, 300);
    Derived_Overload_1 d2(40, 400);
    Base_Overload_1 b4 = d1 + d2;  // Using Base class operator+
    b4.print();  // Output: Base value: 70 (Derived uses Base's operator+)
    cout << "Base class + derived class----\n";
    Base_Overload_1 b5 = b1 + d1;  // Using Base class operator+
    b5.print();  // Output: Base value: 40

}

// Base Sınıfta Operator Overloading -2 -------------------------------------------------------
class Base_Overload_2 {
public:
    int value;
    Base_Overload_2(int val) : value(val) {}

    // Operator overloading for '+'
    Base_Overload_2 operator+(const Base_Overload_2& other) const {
        return Base_Overload_2(this->value + other.value);
    }

    void print() const {
        std::cout << "Base value: " << value << std::endl;
    }
};

class Derived_Overload_2 : public Base_Overload_2 {
public:
    Derived_Overload_2(int val) : Base_Overload_2(val) {}

    // Constructor to convert Base to Derived
    Derived_Overload_2(const Base_Overload_2& base) : Base_Overload_2(base.value) {}

    // No operator overloading in Derived class
};

void base_overlaod_ex_2() {
    cout << "Base class----\n";
    Base_Overload_2 b1(10);
    Base_Overload_2 b2(20);
    Base_Overload_2 b3 = b1 + b2;
    b3.print();  // Output: Base value: 30

    cout << "Derived class----\n";
    Derived_Overload_2 d1(30);
    Derived_Overload_2 d2(40);
    Derived_Overload_2 d4 = d1 + d2;  // Using Base class operator+
    d4.print();  // Output: Base value: 70 (Derived uses Base's operator+)
    cout << "Base class + derived class----\n";
    Base_Overload_2 b4 = b1 + d1;  // Using Base class operator+
    b4.print();  // Output: Base value: 40
}

// Base ve Derived class operator overlaoding overriding -------------------------------------------------------
class Base_Overload_3 {
public:
    int baseValue;
    Base_Overload_3(int val) : baseValue(val) {}

    // Operator overloading for '+'
    virtual Base_Overload_3 operator+(const Base_Overload_3& other) const {
        cout << "base class operator overloading called\n";
        return Base_Overload_3(this->baseValue + other.baseValue);
    }

    virtual void print() const {
        std::cout << "Base value: " << baseValue << std::endl;
    }
};

class Derived_Overload_3 : public Base_Overload_3 {
public:
    int derivedValue;
    Derived_Overload_3(int baseVal, int derivedVal) : Base_Overload_3(baseVal), derivedValue(derivedVal) {

    }

    // Override the operator+ for the Derived class
    Derived_Overload_3 operator+(const Derived_Overload_3& other) const {
        cout << "derived class operator overloading called\n";
        return Derived_Overload_3((this->baseValue + other.baseValue), (this->derivedValue + other.derivedValue)); // Example modification
    }

    void print() const {
        std::cout << "Base value: " << this->baseValue << std::endl;
        std::cout << "derived value: " << this->derivedValue << std::endl;
    }
};

void base_and_derived_overload() {
    cout << "Base class----\n";
    Base_Overload_3 b1(10);
    Base_Overload_3 b2(20);
    Base_Overload_3 b3 = b1 + b2;
    b3.print();  

    cout << "Derived class----\n";
    Derived_Overload_3 d1(30, 300);
    Derived_Overload_3 d2(40, 400);
    Derived_Overload_3 d4 = d1 + d2;  
    d4.print();  
    cout << "Base class + derived class----\n";
    Base_Overload_3 b4 = b1 + d1;  
    b4.print();   
}

// Copy and move constructor example #########################################################
class Base_cp {
public:
    int baseValue;
    int* dynamicPtr;

    // Constructor
    Base_cp(int val) : baseValue(val) {
        this->dynamicPtr = new int(baseValue);
        cout << "Base Constructor" << endl;
    }

    // Copy Constructor
    Base_cp(const Base_cp& other) {
        cout << "Base Copy Constructor" << endl;
        this->baseValue = other.baseValue;
        this->dynamicPtr = new int(*(other.dynamicPtr));
    }

    // Move Constructor
    Base_cp(Base_cp&& other) {
        cout << "Base Move Constructor" << endl;
        this->baseValue = other.baseValue;
        this->dynamicPtr = other.dynamicPtr;
        other.dynamicPtr = nullptr;
        other.baseValue = 0;
    }

    // Destructor
    ~Base_cp() {
        cout << "Base Destructor" << endl;
        delete dynamicPtr;
    }
};

class Derived_cp : public Base_cp {
public:
    // Constructor
    Derived_cp(int baseVal) : Base_cp(baseVal) {
        cout << "Derived Constructor" << endl;
    }

    // Copy Constructor
    Derived_cp(const Derived_cp& other) : Base_cp(other) {
        cout << "Derived Copy Constructor" << endl;
    }

    // Move Constructor
    Derived_cp(Derived_cp&& other) noexcept : Base_cp(std::move(other)) {
        cout << "Derived Move Constructor" << endl;
    }

    // Destructor
    ~Derived_cp() {
        cout << "Derived Destructor" << endl;
    }
};

void copy_and_move_constrcutor_ex() {
    cout << "copy constrctor ex----------------\n";
    Derived_cp derived_c(5);
    Derived_cp derived_c_copy = derived_c;

    cout << "move constrctor ex----------------\n";
    Derived_cp derived_m(10);
    Derived_cp derived_c_move = std::move(derived_m);

    cout << "\n-------------------------------\n";
}

// Pointers with Inheritence #####################################################################
void pointer_examples() {
    cout << "Single Inheritence-----------------------\n";
    Derived__Single* derived_single = new Derived__Single(10, 15);
    delete derived_single;

    cout << "\nMultiple Inheritence-----------------------\n";
    Derived__Multiple* derived_multiple = new Derived__Multiple(10, 20, 25);
    delete derived_multiple;

    cout << "\nMultilevel Inheritence-----------------------\n";
    Derived__Multilevel* derived_multilevel = new Derived__Multilevel(10, 20, 25);
    delete derived_multilevel;

    cout << "\nMultilevel Inheritence-----------------------\n";
    cout << "derived 1--\n";
    Derived__Hierarchical_1* derived_hierarchical_1= new Derived__Hierarchical_1(10, 20);
    delete derived_hierarchical_1;

    cout << "derived 2--\n";
    Derived__Hierarchical_2* derived_hierarchical_2= new Derived__Hierarchical_2(10, 20);
    delete derived_hierarchical_2;

    cout << "\nHybrid Inheritence-----------------------\n";
    Derived__Hybrid_3* derived_hybrid = new Derived__Hybrid_3(10, 20, 25, 30);
    delete derived_hybrid;

    cout << "\n\nWrong example -----------------------\n";
    Base__Single* derived_single_w_base = new Derived__Single(10, 15);
    delete derived_single_w_base;

}

int main() {
    cout << "\nAccess Modifiers with Inheritence##################################################\n";
    access_modifier_for_inheritence();


    cout << "\nInheritence types ###############################################################\n";
    cout << "1-single inheritence example ------------------------------------------------\n";
    single_inheritence_example();

    cout << "\n2-multiple inheritence example ------------------------------------------------\n";
    multiple_inheritence_example();

    cout << "\n3-multilevel inheritence example ------------------------------------------------\n";
    multilevel_inheritence_example();

    cout << "\n4-hierarchical inheritence example ------------------------------------------------\n";
    hierarchical_inheritence_example();

    cout << "\n5-hybrid inheritence example ------------------------------------------------\n";
    hybrid_inheritence_example();


    cout << "\nConstrctor and Destrctor ###############################################################\n";
    cout << "1-single inheritence example ------------------------------------------------\n";
    single_inheritence_example__();
    
    cout << "\n2-multiple inheritence example ------------------------------------------------\n";
    multiple_inheritence_example__();

    cout << "\n3-multilevel inheritence example ------------------------------------------------\n";
    multilevel_inheritence_example__();

    cout << "\n4-hierarchical inheritence example ------------------------------------------------\n";
    hierarchical_inheritence_example__();

    cout << "\n5-hybrid inheritence example ------------------------------------------------\n";
    hybrid_inheritence_example__();

    cout << "\nOperator Overload ###############################################################\n";
    cout << "Base class Operator overload -1 ------------------------------------------------\n";
    base_overlaod_ex_1();

    cout << "\nBase class Operator overload -2 ------------------------------------------------\n";
    base_overlaod_ex_2();

    cout << "\nbase and derived operator overlaod ------------------------------------------------\n";
    base_and_derived_overload();

    cout << "\nCopy and Move constructor ###############################################################\n";
    copy_and_move_constrcutor_ex();

    cout << "\nPointers ###############################################################\n";
    pointer_examples();

    return 0;
}
