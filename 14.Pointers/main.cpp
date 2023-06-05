#include<iostream>

using namespace std;

void fill_array(int array[], int dim) {

    for (int i = 0; i < dim; i++) {
        array[i] = i;
    }

}

void print_Array(int array[], int dim) {
    cout << "array: " << endl;
    for (int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << " \n";
}


int main() {
    cout << "-------------------------------------------------------------" << endl;
    int x;
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "-------------------------------------------------------------" << endl;

    int *addressOfx;
    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;

    cout << "-------------------------------------------------------------" << endl;

    addressOfx = &x;
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;

    cout << "-------------------------------------------------------------" << endl;

    x = 10;
    addressOfx = &x;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;


    cout << "-------------------------------------------------------------" << endl;

    x = 11;
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;

    cout << "-------------------------------------------------------------" << endl;

    *addressOfx = 13;
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;

    cout << "-------------------------------------------------------------" << endl;
    int *extraPointer;

    extraPointer = addressOfx;

    *extraPointer = 14;

    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    cout << "addressOfx: " << addressOfx << endl;
    cout << "*addressOfx: " << *addressOfx << endl;

    cout << "extraPointer: " << extraPointer << endl;
    cout << "*extraPointer: " << *extraPointer << endl;

    cout << "Dynamic variables or nameless ------------------------------------------------------------------" << endl;

    int *a;
    a = new int(5);

    cout << "a: " << a << endl;
    cout << "*a: " << *a << endl;

    delete a;

    //delted dynamic variable
    cout << "a: " << a << endl;
    cout << "*a: " << *a << endl;

    //arrays behave like call by reference
    cout << "Dynamic arrays ----------------------------------------------------------------------------------" << endl;

    int *dynamicArray = new int[5];

    fill_array(dynamicArray, 5);

    print_Array(dynamicArray, 5);

    dynamicArray[2] = 38;

    print_Array(dynamicArray, 5);

    delete[] dynamicArray;

    print_Array(dynamicArray, 89);

    cout << "Normal arrays ----------------------------------------------------------------------------------" << endl;
    int normalArray[5];

    fill_array(normalArray, 5);

    print_Array(normalArray, 5);

    normalArray[0] = 755;

    print_Array(normalArray, 5);

    cout << "first element address : " << normalArray << endl;
    cout << "first element value : " << *normalArray << endl;


    cout << "Dynamic Arrays arithmetic------------------------------------------------------------------------" << endl;

    int *dynamicArray2 = new int[5];

    for (int i = 0; i < 5; i++) {
        dynamicArray2[i] = i;
    }
    /*
     Each integer takes up 4 bytes of value. That's why the addresses are increasing 4 by 4.
     When we add a normal 1 integer to the address, 4 increases logically.
     */

    cout << "first element address : " << dynamicArray2 << endl;
    cout << "first element value : " << *dynamicArray2 << endl;

    for (int i = 0; i < 5; i++) {
        cout << dynamicArray + i << ": ";
        cout << *(dynamicArray2 + i) << endl;
    }
    cout << " \n";

    delete[] dynamicArray2;


    return 0;
}