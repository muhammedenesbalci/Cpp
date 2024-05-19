#include <iostream>

using namespace std;

void extern_usage_fun() {
    cout << "Extern Function file\n";
    extern int my_variable;
    cout << "addres of myVariable: " << &my_variable <<endl;
 
    // printing the extern variables 'x'
    cout << "Value of the variable 'my_variable'"
         << "declared, as extern: " << my_variable << "\n";
 
    // value of extern variable x modified
    my_variable = 100;
 
    // printing the modified values of
    // extern variables 'x'
    cout << "Modified value of the variable 'my_variable'"
         << " declared as extern: \n"
         << my_variable << endl;
}