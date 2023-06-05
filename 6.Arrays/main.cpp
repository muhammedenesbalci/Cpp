#include <iostream>
/*
 * */
using namespace std;

int print_array(int anArray[], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        cout << "my_array[" << i << "]: " << anArray[i] << endl;
    }
}


int main() {
    cout << "Arrays-------------------------------------------------------------------------------------------" << endl;
    //int my_array[5]{0, 1, 2, 3, 4};
    int my_array[5] = {0, 1, 2, 3, 4};
    // int my_array[]{0, 1, 2, 3, 4};
    // int my_array[] = {0, 1, 2, 3, 4};

    cout << "my_array[3]: " << my_array[3] << endl;
    cout << "my_array[4]: " << my_array[4] << endl;

    my_array[3] = 7;
    cout << "my_array[3]: " << my_array[3] << endl;

    cout << "Arrays with loops--------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "my_array[" << i << "]: " << my_array[i] << endl;
    }

    int my_array2[] = {0, 1, 2, 3, 4, 5};

    int len_array = 0;

    //Another method
    for (int i: my_array2) {
        ++len_array;
        cout << i << endl;
    }

    cout << "length of array: " << len_array << endl;

    len_array = 0;

    for (auto i: my_array2) {
        ++len_array;
        cout << i << endl;
    }
    cout << "length of array: " << len_array << endl;

    cout << "Arrays with functions----------------------------------------------------------------------------" << endl;

    int my_Array3[3] = {0, 1, 2};
    print_array(my_Array3, 3);

    return 0;
}