#include <iostream>
#include <ios> // used to get stream size 
#include <limits> // used to get numeric limits 
        
using namespace std;

void ex_1() {
    cout << "ex1-------------------------------\n";
    string s; 
    
    // Take input using cin 
    cin >> s; 

    // Print output 
    cout << s; 
}

void ex_2() {
    cout << "ex2-------------------------------\n";
    string name; 
    int age; 

    // Take multiple input using cin 
    cin >> name >> age; 

    // Print output 
    cout << "Name : " << name << endl; 
    cout << "Age : " << age << endl; 
}

void ex_3() {
    cout << "ex3-------------------------------\n";
    char name[5]; 
        
    // Reads stream of 5 
    // characters 
    cin.getline(name, 3); 

    // Print output 
    cout << name << endl; 
}

void ex_4() {
    
    cout << "ex4-------------------------------\n";
    char ch[25]; 
    cin.get(ch, 25); 

    // Print ch 
    cout << ch; 
    
}

void ex_5() {
    cout << "ex5-------------------------------\n";
    char gfg[20]; 
    
    // Reads stream of characters 
    cin.read(gfg, 10); 

    // Print output 
    cout << gfg << endl; 
}

void ex_6() {
    cout << "ex6-------------------------------\n";
    int x; 
    char str[80]; 
    cout << "Enter a number andstring:\n"; 
    cin >> x; 

    // clear buffer before taking 
    // new line 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Input a string 
    cin.getline(str, 80); 
    cout << "You have entered:\n"; 
    cout << x << endl; 
    cout << str << endl; 
}

void ex_7() {
    cout << "ex6-------------------------------\n";
    int x; 
    char str[80]; 
    cout << "Enter a number andstring:\n"; 
    cin >> x; 

    // Input a string 
    cin.getline(str, 80); 
    cout << "You have entered:\n"; 
    cout << x << endl; 
    cout << str << endl; 
}

int main()
{   // tek tek çalışitırmak en mantıklısı
    //ex_1();
    //ex_2();
    //ex_3();
    //ex_4();
    //ex_5();
    //ex_6();
    ex_7();
    return 0;
}