#include <iostream>
#include <string>

using namespace std;

//Classic description of a function
void noneReturnBasicFunc() {
    cout << "No return value basic func" << endl;
}

void noneReturnBasicFuncWithParameter(string strParameter) {
    cout << "No return value basic func with a parameter. Parameter is : " << strParameter << endl;
}

string stringReturnBasicFunc() {
    return "this function return a string";
}

int intReturnBasicFuncWithParameter(int a, int b) {
    cout << "this function takes two parameter and return multiple of them a*b" << endl;
    return a * b;
}

//Another description of a function function prototype
// we just define function names and then create blocks after the main
int another_described_function();


int main() {
    cout << "Classic description of a function ---------------------------------------------------------------" << endl;
    noneReturnBasicFunc();
    noneReturnBasicFuncWithParameter("FUNC PARAMETER");

    string str = stringReturnBasicFunc();
    cout << str << endl;

    int mul = intReturnBasicFuncWithParameter(4, 5);
    cout << mul << endl;

    cout << "Another description of a function ---------------------------------------------------------------" << endl;
    another_described_function();
    return 0;
}

int another_described_function() {
    cout << "Another function description." << endl;
    return 0;
}
