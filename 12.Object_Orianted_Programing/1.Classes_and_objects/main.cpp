#include <iostream>
#include <string>

using namespace std;

// First Part ###########################################################
// Basic Class ----------------------------------------------------------
class Person {
public:
    // Veri üyeleri (Data Members)
    string name;
    int age;

    // Constructor
    Person() {
        cout << "Person's constructor\n";
    }

    // Üye fonksiyon (Member Function)
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    void display_2(string name, int age);

    //Destructors
    ~Person() {
        cout << "Person's destructor\n";
    }
};

void Person::display_2(string name, int age) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void basic_class_usage() {
    // Person sınıfının bir nesnesini oluşturma
    Person person1;

    // Nesnenin veri üyelerine değer atama
    person1.name = "Alice";
    person1.age = 30;

    // Üye fonksiyonu kullanarak nesnenin bilgilerini gösterme
    person1.display();    
    person1.display_2("Enes", 25);

    cout << "size of a object: " << sizeof(person1) << endl;

}

// Second Part ###########################################################
// Public ----------------------------------------------------------------
class MyClass {
public:
    int publicVar;  // Public veri üyesi

    void publicFunction() {  // Public üye fonksiyon
        // İşlemler
    }
};

void use_of_public() {
    MyClass obj;
    obj.publicVar = 10;          // Erişim sağlandı
    obj.publicFunction();        // Erişim sağlandı
}

// Private ----------------------------------------------------------------
class MyClass2 {
private:
    int privateVar;  // Private veri üyesi

    void privateFunction() {  // Private üye fonksiyon
        // İşlemler
    }

public:
    void setVar(int val) {  // Public setter fonksiyonu
        privateVar = val;
    }

    int getVar() {  // Public getter fonksiyonu
        return privateVar;
    }
};

void use_of_private() {
    MyClass2 obj;
    // obj.privateVar = 10;  // Derleme hatası: private üyeye erişim yok
    // obj.privateFunction() // Derleme hatası: private üyeye erişim yok
    obj.setVar(10);         // Public üye fonksiyon üzerinden erişim sağlandı
    int value = obj.getVar(); // Public üye fonksiyon üzerinden erişim sağlandı
}

// Protected ----------------------------------------------------------------
class BaseClass {
protected:
    int protectedVar;  // Protected veri üyesi

    void protectedFunction() {  // Protected üye fonksiyon
        // İşlemler
    }
};

class DerivedClass : public BaseClass {
public:
    void accessProtectedMembers() {
        protectedVar = 10;        // Erişim sağlandı içeriden her türlü ulaşabiliriz
        protectedFunction();      // Erişim sağlandı
    }
};

void use_of_protected() {
    DerivedClass obj;
    obj.accessProtectedMembers();
    // obj.protectedVar = 10;    // Derleme hatası: protected üyeye erişim yok
    // obj.protectedFunction // Derleme hatası: protected üyeye erişim yok
}

// Third Part ###########################################################
//Friend Class ----------------------------------------------------------
class ClassB;  // İleriye doğru bildirim (forward declaration)

class ClassA {
private:
    int privateVar = 32;

protected:
    int protectedVar = 64;

public:
    ClassA() {
        privateVar = 14;
        protectedVar = 12;
    }

    // ClassB'nin ClassA'nın özel üyelerine erişmesine izin ver
    friend class ClassB;
};

class ClassB {
public:
    void setPrivateVar(ClassA& a, int value) { //referan ile birlikte koymak mantıklı çünkü ana classın bir özelliğini değiştireceğiz
        a.privateVar = value;  // ClassA'nın private üyesine erişim
    }

    void printPrivateVar(ClassA& a) {
        std::cout << "ClassA's privateVar: " << a.privateVar << std::endl;
    }

    void setProtectedVar(ClassA& a, int value) { //referan ile birlikte koymak mantıklı çünkü ana classın bir özelliğini değiştireceğiz
        a.protectedVar = value;  // ClassA'nın protected üyesine erişim
    }

    void printProtectedVar(ClassA& a) {
        std::cout << "ClassA's protectedVar: " << a.privateVar << std::endl;
    }
};

void friend_class_example() {
    ClassA objA;
    ClassB objB;

    objB.setPrivateVar(objA, 42);  // ClassA'nın private üyesine erişim ve değer atama
    objB.printPrivateVar(objA);    // ClassA'nın private üyesinin değerini yazdırma

    objB.setProtectedVar(objA, 30);  // ClassA'nın private üyesine erişim ve değer atama
    objB.printProtectedVar(objA);    // ClassA'nın private üyesinin değerini yazdırma
}

//Global Friend Function ---------------------------------------------------------
class MyClass_friend_fun {
private:
    int privateVar;

public:
    // Constructor
    MyClass_friend_fun(int val) : privateVar(val) {}

    // Friend function bildirimi
    friend void displayPrivateVar(const MyClass_friend_fun& obj);
};

void displayPrivateVar(const MyClass_friend_fun& obj) {
    cout << "private var of a class inside friend function: " << obj.privateVar << endl;
}

void global_friend_function_example() {
    MyClass_friend_fun obj(5);
    displayPrivateVar(obj);
}

//Member function of another class as Friend Function ---------------------------------------------------------
class base; // forward definition 

// another class in which function is declared
class anotherClass {
public:
    void memberFunction(base& obj);
};
 
// base class for which friend is declared
class base {
private:
    int private_variable;
 
protected:
    int protected_variable;
 
public:
    base() {
        private_variable = 10;
        protected_variable = 99;
    }
 
    // friend function declaration
    friend void anotherClass::memberFunction(base&);
};

// friend function definition
void anotherClass::memberFunction(base& obj) // bu tanımlamayı anotherClass ın source file ında yapardık
{
    cout << "Private Variable: " << obj.private_variable
         << endl;
    cout << "Protected Variable: " << obj.protected_variable;
}

void internal_friend_function_example() {
    base baseObj;
    anotherClass anotherClassObj;
    anotherClassObj.memberFunction(baseObj);
}

// Multiple class using same friend function --------------------------------------------------------------
class ABC; 
 
class XYZ {
    int x;
 
public:
    void set_data(int a) { 
      x = a; 
    }
 
    friend void max(XYZ, ABC);
};
 
class ABC {
    int y;
 
public:
    void set_data(int a) { 
      y = a; 
    }
 
    friend void max(XYZ, ABC);
};
 
void max(XYZ t1, ABC t2)
{
    if (t1.x > t2.y)
        cout << t1.x;
    else
        cout << t2.y;
}

void multiple_class_friend_fun() {
    ABC _abc;
    XYZ _xyz;
    _xyz.set_data(20);
    _abc.set_data(35);

     // calling friend function
    max(_xyz, _abc); 
    cout << endl;
}

int main() {
    cout << "First Part #################################################\n";
    cout << "Basic Class Usage-----------------------------------------\n";
    basic_class_usage();

    cout << "\nSecond Part #################################################\n";
    cout << "public -----------------------------------------\n";
    use_of_public();

    cout << "\nprivate -----------------------------------------\n";
    use_of_private();

    cout << "\nprotected -----------------------------------------\n";
    use_of_protected();

    cout << "\nThird Part #################################################\n";
    cout << "Friend class example------------------------------------" << endl;
    friend_class_example();

    cout << "\nGlobal Friend function example------------------------------------" << endl;
    global_friend_function_example();

    cout << "\nInternal Friend function example------------------------------------" << endl;
    internal_friend_function_example();

    cout << "\nMultiple class using same friend functio nexample------------------------------------" << endl;
    multiple_class_friend_fun();
    
    return 0;
}