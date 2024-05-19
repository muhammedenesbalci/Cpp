#include <iostream>
#include <string>

#include "basic_static_member_class/basic_static_member_class.h"

#include "static_class_object/static_class_object.h"

#include "static_function_class/static_function_class.h"

using namespace std;

//Static Variable in a function ex ------------------------------------------------------------
void static_variable_in_function_ex() {
    static int count = 0;

    count++;

    cout << "count: " << count << endl;
    cout << "count address: " << &count << endl;
}

void static_variable_in_function_ex_2() {
    static int count = 0;

    count++;

    cout << "count: " << count << endl;
    cout << "count address: " << &count << endl;

}

void static_variable_in_function_ex_usage() {
    //count++;
    for (int i = 0; i < 5; i++){
        cout << i << ": " << endl;
        static_variable_in_function_ex();
        }

    for (int i = 0; i < 5; i++){
        cout << i << ": " << endl;
        static_variable_in_function_ex_2();
        }
    //count++;
}
//Static Global Variable ex ------------------------------------------------------------
static int static_global_count = 0;
void static_global_variable_ex() {
    static_global_count++;

    cout << "count: " << static_global_count << endl;
    cout << "count address: " << &static_global_count << endl;
}

void static_global_variable_ex_2() {
    static_global_count++;

    cout << "count: " << static_global_count << endl;
    cout << "count address: " << &static_global_count << endl;
}

void static_global_variable_ex_usage() {
    for (int i = 0; i < 5; i++){
        cout << i << ": " << endl;
        static_global_variable_ex();
        }
        
    for (int i = 0; i < 5; i++){
        cout << i << ": " << endl;
        static_global_variable_ex_2();
        }
}

//Static variables in a class-------------------------------------------------------------------
void usage_of_static_v_class_1() {
    GfG obj1;
    GfG obj2;

    cout << obj1.static_member_not_initialized << " " << obj2.static_member_not_initialized << endl;
    obj1.static_member_not_initialized = 2;
    
    cout << obj1.static_member_not_initialized << " " << obj2.static_member_not_initialized << endl;
    obj2.static_member_not_initialized = 3;
 
    cout << obj1.static_member_not_initialized << " " << obj2.static_member_not_initialized;
}
/*
void usage_of_static_v_class_2() {
    int GfG::static_member_not_initialized = 1; //hatayı görmek için yorum ifadesini sil
    GfG obj;
    // prints value of i
    cout << obj.static_member_not_initialized;
}
*/

//int GfG::static_member_not_initialized = 1; // bu şekilde de bir değer atama yapabilrdik ama biz zaten cpp dosayının içinde değer atama yaptık
void usage_of_static_v_class_3() {
    GfG obj;
    // prints value of i
    cout << obj.static_member_not_initialized <<endl;

    cout << GfG::static_member_not_initialized << endl;

    GfG::static_member_not_initialized = 5; // bu şekilde de ulaşabilriz
    
    cout << GfG::static_member_not_initialized << endl;
}

void usage_of_static_v_class_4() {
    GfG obj;
    // prints value of i
    GfG::static_member_not_initialized = 9;
    cout << obj.static_member_not_initialized <<endl;
    cout << GfG::static_member_not_initialized << endl;
    GfG::static_member_not_initialized = 5;
    cout << GfG::static_member_not_initialized << endl;
}

//Non Static class objects -------------------------------------------------------------------
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

void usage_of_static_functions() {
    Efe::printMsg();

    Efe efe;
    efe.printMsg();
}

int main() {   
    cout << "\nstatic variable in a function ex-------------------------------------------\n";
    static_variable_in_function_ex_usage();

    cout << "\nstatic global variable ex-------------------------------------------\n";
    static_global_variable_ex_usage();

    cout << "\nstatic variables in a class ex-----------------------------------------------\n";

    cout << "\nusage_of_static_v_class_1++++++++++++++++++++++++++++++++++++++++++\n";
    usage_of_static_v_class_1();

    //usage_of_static_v_class_2();

    cout << "\nusage_of_static_v_class_3++++++++++++++++++++++++++++++++++++++++++\n";
    usage_of_static_v_class_3();

    cout << "\nusage_of_static_v_class_4++++++++++++++++++++++++++++++++++++++++++\n";
    usage_of_static_v_class_4();

    cout << "\nNon Static class objects-----------------------------------------------\n";
    usage_of_non_static_class();

    cout << "\nStatic class objects-----------------------------------------------\n";
    usage_of_static_class();

    cout << "\nStatic function in a class----------------------------------------------\n";
    usage_of_static_functions();

    return 0;
}