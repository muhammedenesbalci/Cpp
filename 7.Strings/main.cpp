#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    cout << "General string ----------------------------------------------------------------------------------" << endl;
    /*
     In a C-style string, '\0' denotes the null terminator; it's used to mark the end of the string
    */

    char characterArray[] = "Hello C++";
    cout << characterArray << endl;

    char characterArray2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << characterArray2 << endl;

    string myString = "string variable";
    cout << myString << endl;

    cout << "input string ------------------------------------------------------------------------------------" << endl;
    char name[30];
    cout << "Enter a neme: ";

    // if you type more than one word, it takes just first word.
    // cin >> name;
    // cout << "name: " << name << endl;

    // it gets 30 character
    cin.getline(name, 30);
    cout << "name: " << name << endl;

    cout << "Length, combining, copying-----------------------------------------------------------------------" << endl;

    char myString2[] = "HELLO ";
    char myString3[] = "C++";

    cout << myString2 << endl;

    cout << "length: " << strlen(myString2) << endl;

    strcat(myString2, myString3);
    cout << "myString2: " << myString2 << " myString3: " << myString3 << endl;

    strcpy(myString2, myString3);
    cout << "myString2: " << myString2 << " myString3: " << myString3 << endl;

    return 0;
}