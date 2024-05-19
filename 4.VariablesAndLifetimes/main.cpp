#include <iostream>

using namespace std;

int globalVar = 0; // Destroyed when the program ends.

void test_func() {
    int localVar = 1; // Destroyed when the function ends.
    static int staticVar = 1; // Destroyed when the program ends.

    {
        int local_val2 = 2; // Destroyed when the block ends.
    }
}

void static_and_local_variable_ex() {
    static int a = 0; // biir kere tanımlıyoruz sonrasında direkt değiştirmediğimiz sürece bunu 0 a eşitlemiyor
    int b = 0;

    a++;
    b++;
    
    cout << "static a: " << a << endl;
    cout << "static b: " << b << endl;
}

int main() {
    int local_val3 = 3; // Destroyed when the block or program ends.

    if (true) {
        int local_val = 4; // Destroyed when the block or program ends.
    }

    test_func();

    return 0;
}