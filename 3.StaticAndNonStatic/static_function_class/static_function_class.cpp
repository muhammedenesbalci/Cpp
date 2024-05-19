#include "static_function_class.h"

//int Efe::non_static_variable = 10; static olmayan değişkenler dışarıda tanımlanamaz

void Efe::printMsg() { 
    
    cout << "Welcome to Efe!\n"; 
    cout << "static variable: " << static_variable << endl;
    //cout << "non static variable: " << Efe::non_static_variable << endl;

    Efe efe;
    cout << "non static variable: " << efe.non_static_variable << endl;   
}