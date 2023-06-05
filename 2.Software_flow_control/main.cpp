#include <iostream>

using namespace std;

int main() {
    cout << "Boolean -----------------------------------------------------------------------------------------" << endl;

    // true --> 1
    // false --> 0

    cout << "4 < 5: " << (4 < 5) << endl;
    cout << "5 < 4: " << (5 < 4) << endl;

    cout << "6 >= 5: " << (6 >= 5) << endl;
    cout << "5 <= 5: " << (5 <= 5) << endl;

    cout << "1 == 1: " << (1 == 1) << endl;
    cout << "1 == -1: " << (1 == -1) << endl;

    cout << "1 != 1: " << (1 != 1) << endl;
    cout << "1 != -1: " << (1 != -1) << endl;

    cout << "!(1 == 1): " << !(1 == 1) << endl;
    cout << "!(1 == -1): " << !(1 == -1) << endl;

    //Logical Operators
    //AND
    cout << "4 < 5 && 4 < 5: " << ((4 < 5) && (4 < 5)) << endl;
    cout << "4 < 5 && 5 < 4: " << ((4 < 5) && (5 < 4)) << endl;
    cout << "5 < 4 && 5 < 4: " << ((5 < 4) && (5 < 4)) << endl;

    //OR
    cout << "4 < 5 || 4 < 5: " << ((4 < 5) || (4 < 5)) << endl;
    cout << "4 < 5 || 5 < 4: " << ((4 < 5) || (5 < 4)) << endl;
    cout << "5 < 4 || 5 < 4: " << ((5 < 4) || (5 < 4)) << endl;

    //if-elseif-else
    cout << "\nif/else-if/else -------------------------------------------------------------------------------" << endl;
    if (true) {
        cout << "working if block-1" << endl;
    } else {
        cout << "working else block-1" << endl;
    }

    if (false) {
        cout << "working if block-2" << endl;
    } else {
        cout << "working else block-2" << endl;
    }

    if (true) {
        cout << "working if block-3" << endl;
    } else if (true) {
        cout << "working else if block-3" << endl;
    } else {
        cout << "working else block-3" << endl;
    }

    if (true) {
        cout << "working if block-4" << endl;
    } else if (false) {
        cout << "working else if block-4" << endl;
    } else {
        cout << "working else block-4" << endl;
    }

    if (false) {
        cout << "working if block-5" << endl;
    } else if (true) {
        cout << "working else if block-5" << endl;
    } else {
        cout << "working else block-5" << endl;
    }

    if (false) {
        cout << "working if block-6" << endl;
    } else if (false) {
        cout << "working else if block-6" << endl;
    } else {
        cout << "working else block-6" << endl;
    }

    cout << "\nif/else alternative ---------------------------------------------------------------------------" << endl;
    int x = 5;
    int y = 4;

    string str = (x < y) ? "x < y : true" : "x > y : false";
    cout << str << endl;

    cout << "\nSwitch-Case -----------------------------------------------------------------------------------" << endl;

    int num = 2;

    switch (num) {
        case 1:
            cout << "num : 1";
            break;
        case 2:
            cout << "num : 2";
            break;
        case 3:
            cout << "num : 3";
            break;

        default:
            cout << "none of them" << endl;
    }

    cout << "\nWhile loop-------------------------------------------------------------------------------------" << endl;

    int i = 0;
    while (i < 5) {
        cout << "i: " << i << endl;
        ++i;
    }

    int j = 0;
    while (true) {
        cout << "j: " << j << endl;

        ++j;

        if (j == 5) {
            break;
        }
    }
    int m = 0;

    do {
        m++;
        cout << "m: " << m << endl;
    } while (m < 5);

    m = 0;

    do {
        cout << "m: " << m << endl;
        m++;
    } while (m < 5);


    cout << "\nFor loop---------------------------------------------------------------------------------------" << endl;

    for (int l = 0; l <= 5; l++) {
        cout << "l: " << l << endl;
    }


    return 0;
}