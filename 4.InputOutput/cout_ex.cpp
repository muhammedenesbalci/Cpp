#include <iostream>

using namespace std;

void ex_1() {
    cout << "ex1-----------------------------------\n";

    // Print standard output
    // on the screen
    cout << "Welcome to GFG";
}

void ex_2() {
    cout << "ex2-----------------------------------\n";
    string name = "Akshay";
    int age = 18;

    // Print multiple variable on
    // screen using cout
    cout << "Name : " << name << endl
            << "Age : " << age << endl;
}

void ex_3() {
    cout << "ex3-----------------------------------\n";
    char gfg[] = "Welcome at GFG";
    char ch = 'e';

    // Print first 6 characters
    cout.write(gfg, 6);

    // Print the character ch
    cout.put(ch);
}

void ex_4() {
    cout << "ex4-----------------------------------\n";

    double pi = 3.14159783;
    
    // Set precision to 5
    cout.precision(5);

    // Print pi
    cout << pi << endl;

    // Set precision to 7
    cout.precision(7);

    // Print pi
    cout << pi << endl;
}

int main()
{   ex_1();
    ex_2();
    ex_3();
    ex_4();
    return 0;
}