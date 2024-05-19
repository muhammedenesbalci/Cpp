#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// function to print values passed as parameter in loop 
void printValues(int i) { cout << i << " " << endl; } 
void range_based_loops_extra_ex() {
    // Iterating over whole array
    vector<int> v = { 0, 1, 2, 3, 4, 5 };
    for (auto i : v)
        cout << i << ' ';

    cout << '\n';

    // the initializer may be a braced-init-list
    for (int n : { 0, 1, 2, 3, 4, 5 })
        cout << n << ' ';

    cout << '\n';

    // Iterating over array
    int a[] = { 0, 1, 2, 3, 4, 5 };
    for (int n : a)
        cout << n << ' ';

    cout << '\n';

    // Just running a loop for every array
    // element
    for (int n : a)
        cout << "In loop" << ' ';

    cout << '\n';

    // Printing string characters
    string str = "Geeks";
    for (char c : str)
        cout << c << ' ';

    cout << '\n';

    // Printing keys and values of a map
    map<int, int> MAP({ { 1, 1 }, { 2, 2 }, { 3, 3 } });
    for (auto i : MAP)
        cout << '{' << i.first << ", " << i.second << "}\n";
}

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

    cout << "\ndo While loop-----------------------------------------------------------------------------------" << endl;

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

    cout << "-----------------------------\n";
    int arr[] {40, 50, 60, 70, 80, 90, 100}; 
    for (auto element : arr){ 
    cout << element << " ";
    }
    cout << endl;

    cout << "-----------------------------\n";
    for (int i = 0, j = 10, k = 20; (i + j + k) < 100;
         j++, k--, i += k) {
        cout << i << " " << j << " " << k << "\n";
    }
    cout << endl;

    cout << "-----------------------------\n";
    // loop having multiple variable and updations 
    for (int m = 1, n = 1; m <= 5; m += 1, n += 2) { 
        cout << "iteration " << m << endl; 
        cout << "m is: " << m << endl; 
        cout << "n is: " << n << endl; 
    } 
    cout << endl;

    cout << "-----------------------------\n";
    int a = 99;
    for (int a = 0; a < 5; a++) {
        cout << a << "\t";
    }
    cout << "\n" << a;
    std::cout << std::endl;

    cout << "-----------------------------\n";
    vector<int> v = { 1, 2, 3, 4, 5 };
    for (vector<int>::iterator it = v.begin();
         it != v.end(); it++) {
        cout << *it << "\t";
    }
    std::cout << std::endl;

    cout << "-----------------------------\n";
    vector<int> numbers = {1, 2, 3, 4, 5};

    // auto kullanarak vektördeki elemanlara erişim
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    cout << "-----------------------------\n";
    // auto ile vektörün türünü otomatik belirleme
    auto myVector = std::vector<double>{3.14, 2.71, 1.61};
    for (auto value : myVector) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    cout << "\nInfinite loops---------------------------------------------------------------------------------------" << endl;
    i = 10;
    cout << "-----------------------------\n";
    // This is an infinite for loop as the condition
    // expression is blank
    for (;;) {
        cout << "This loop will run forever.\n";
        break;
    }
 
    // This is an infinite for loop as the condition
    // given in while loop will keep repeating infinitely
    cout << "-----------------------------\n";
    while (i != 0)
    {
        i-- ;
        cout << "This loop will run forever.\n";
        break;
    }
    
    // This is an infinite for loop as the condition
    // given in while loop is "true"
    cout << "-----------------------------\n";
    while (true)
    {
        cout << "This loop will run forever.\n";
        break;
    }

    cout << "-----------------------------\n";
    //first way is to decrement in the condition itself
    x=5;
    while(x--){
      cout<<x<<" ";
    }

    cout<<endl;
    //second way is to decrement inside the loop till i is 0
    cout << "-----------------------------\n";
    x=5;
    while(x){
    cout<<x<<" ";
    x--;
    }

    cout << "\nfor_each Loop ---------------------------------------------------------------------------------------" << endl;
    // initializing vector 
    vector<int> v_2 = { 1, 2, 3, 4, 5 }; 
  
    // iterating using for_each loop 
    for_each(v_2.begin(), v_2.end(), printValues); 

    cout << "\nrange based Loops ex ---------------------------------------------------------------------------------------" << endl;
    range_based_loops_extra_ex();
    return 0;
}