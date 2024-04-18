

// C++ program to demonstrate
// the use of static Static
// variables in a Function
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------------------------------
void static_variable_ex() {
    // static variable
    static int count = 0;
    cout << count << " ";
 
    // value is updated and
    // will be carried to next
    // function calls
    count++;
}

void static_ex_usage() {
    for (int i = 0; i < 5; i++)
        static_variable_ex();
}

//------------------------------------------------------------------------------------------
class GfG {
public:
    static int i;
 
    GfG(){
        // Do nothing
    };
};


void usage_of_static_v_class_1() {
    GfG obj1;
    GfG obj2;
    obj1.i = 2;
    obj2.i = 3;
 
    // prints value of i
    cout << obj1.i << " " << obj2.i;
}

void usage_of_static_v_class_2() {
    //int GfG::i = 1; hatayı görmek için yorum ifadesini sil
    GfG obj;
    // prints value of i
    cout << obj.i;
}

int GfG::i = 1;
void usage_of_static_v_class_3() {
    GfG obj;
    // prints value of i
    cout << obj.i <<endl;
    cout << GfG::i << endl;
    GfG::i = 5;
    cout << GfG::i << endl;
}
void usage_of_static_v_class_4() {
    GfG obj;
    // prints value of i
    GfG::i = 9;
    cout << obj.i <<endl;
    cout << GfG::i << endl;
    GfG::i = 5;
    cout << GfG::i << endl;
}

//------------------------------------------------------------------------------------------
class Enes {
    int i;
 
public:
    Enes()
    {
        i = 0;
        cout << "Inside Constructor\n";
    }
    ~Enes() { cout << "Inside Destructor\n"; }
};

void usage_of_non_static_class() {
    int x = 0;
    if (x == 0) {
        Enes obj;
    }
    cout << "End of main\n";
}

void usage_of_static_class() {
    int x = 0;
    if (x == 0) {
        static Enes obj;
    }
    cout << "End of main\n";
}

//------------------------------------------------------------------------------------------
class Efe {
public:
    // static member function
    static void printMsg() { cout << "Welcome to Efe!"; }
};

void usage_of_static_functions() {
    Efe::printMsg();
}

int main() {   
    //static_ex_usage();

    //hatalı kullaanım
    //usage_of_static_v_class_1();

    // hatalı kullanım
    //usage_of_static_v_class_2();

    // doğru kullanım
    //usage_of_static_v_class_3();
    usage_of_static_v_class_4();

    //usage_of_non_static_class();

    //usage_of_static_class();
    //usage_of_static_functions();

    return 0;
}