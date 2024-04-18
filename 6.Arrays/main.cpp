#include <iostream>

using namespace std;

//-----------------------------------------------------------------
void print_array(int anArray[], int lengthOfArray) {
    for (int i = 0; i < lengthOfArray; i++) {
        cout << "my_array[" << i << "]: " << anArray[i] << endl;
    }
}

void old_lectures() {
    cout << "Arrays----------------------------------------------" << endl;
    //int my_array[5]{0, 1, 2, 3, 4};
    int my_array[5] = {0, 1, 2, 3, 4};
    // int my_array[]{0, 1, 2, 3, 4};
    // int my_array[] = {0, 1, 2, 3, 4};

    cout << "my_array[3]: " << my_array[3] << endl;
    cout << "my_array[4]: " << my_array[4] << endl;

    my_array[3] = 7;
    cout << "my_array[3]: " << my_array[3] << endl;

    cout << "Arrays with loops-----------------------------------------" << endl;
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

}

//-----------------------------------------------------------------
#include <stdio.h>

// function to initialize array pointer olarak verdiğimiz için return etmemize gerek yok
void initialize(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// function to print an array
void printArray(int size)
{
    // variable length array
    int arr[size];
    initialize(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void use_of_variable_length_arrays() {
    int n = 5;
    printArray(n);
}

//-----------------------------------------------------------------
void first_element_pointer_and_all_array_pointer() {
    // Pointer to an integer
    int *p; 
        
    // Pointer to an array of 5 integers
    int (*ptr)[5]; 
    int arr[5] = {1, 2, 3, 4, 5};
        
    // Points to 0th element of the arr.
    p = arr;
        
    // Points to the whole array arr.
    ptr = &arr; 
        
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
    printf("**ptr = %d\n", **ptr);
        
    p++; 
    ptr++;
        
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
    printf("**ptr = %d\n", **ptr);
}

//-----------------------------------------------------------------
void first_element_pointer_and_all_array_pointer_2() {
    int arr[] = { 3, 5, 6, 7, 9 };
    int *p = arr;
    int (*ptr)[5] = &arr;
     
    printf("p = %p, ptr = %p\n", p, ptr);
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
     
    printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",
                          sizeof(p), sizeof(*p));
    printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", 
                        sizeof(ptr), sizeof(*ptr));
}

//-----------------------------------------------------------------
void three_dim_array() {
int arr[2][3][2] = {
                    {
                        {5, 10},
                        {6, 11},
                        {7, 12},
                    },
                    {
                        {20, 30},
                        {21, 31},
                        {22, 32},
                    }
                    };
  int i, j, k;
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
       for (k = 0; k < 2; k++)
         printf("%d\t", *(*(*(arr + i) + j) +k));
       printf("\n");
    }
  }
}

//-----------------------------------------------------------------
void two_dim_array() {
    int ptr[3][4] = { 
                    {10, 11, 12, 13}, 
                    {20, 21, 22, 23}, 
                    {30, 31, 32, 33} 
                    };

    printf("ptr = %p | ptr + 1 = %p | ptr + 2 = %p\n", ptr, ptr + 1, ptr + 2);
    printf("*ptr = %p | *(ptr + 1) = %p | *(ptr + 2) = %p\n", *ptr, *(ptr + 1), *(ptr + 2));
    printf("**ptr = %d | *(*(ptr + 1) + 2) = %d  | *(*(ptr + 2) + 3) =  %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));
    printf("ptr[0][0] = %d | ptr[1][2] = %d | ptr[2][3] = %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);
    }
  
//-----------------------------------------------------------------
void findSize(int arr[]) 
{ 
  cout << sizeof(arr) << endl; 
}
void use_of_findSize() {
    int a[10];
    cout << sizeof(a) << " ";
    findSize(a);
}

//-----------------------------------------------------------------
void func(int arr[8])
{
    printf("Size of arr[] in func(): %d bytes",
        sizeof(arr));
}
void checking_size_after_passing_array_as_parameter() {
    int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    
        printf("Size of arr[] in main(): %dbytes\n",
            sizeof(arr));
    
        func(arr);
}

//-----------------------------------------------------------------
void printString(char* str) {
    printf("Array of Characters: ");
 
    int i = 0;
    while (str[i] != '\0') {
        printf("%c ", str[i]);
        i++;
    }
}

void printing_array_of_Characters_using_function() {
    char arr[] = "Nesibe Gümüş <3";
 
    printString(arr);
}

//-----------------------------------------------------------------
void pDecay(int (*p)[7])
{
    // Printing size of array
    cout << "Modified size of array by "
            "passing by pointer: ";
    cout << sizeof(p) << endl;
}

void pass_by_reference_array() {
    int a[7] = { 1, 2, 3, 4, 5, 6, 7 };

    // Printing original size of array
    cout << "Actual size of array is: ";
    cout << sizeof(a) << endl;

    // Passing a pointer to array
    pDecay(&a);
}

//-----------------------------------------------------------------
int main() {
    cout << "use_of_variable_length_arrays-----------------------------\n";
    use_of_variable_length_arrays();

    cout << "first_element_pointer_and_all_array_pointer-----------------------------\n";
    first_element_pointer_and_all_array_pointer();

    cout << "first_element_pointer_and_all_array_pointer - 2-----------------------------\n";
    first_element_pointer_and_all_array_pointer_2();

    cout << "three_dim_array -----------------------------\n";
    three_dim_array();

    cout << "two_dim_array -----------------------------\n";
    two_dim_array();

    cout << "findSize -----------------------------\n";
    use_of_findSize();

    cout << "checking_size_after_passing_array_as_parameter -----------------------------\n";
    checking_size_after_passing_array_as_parameter();

    cout << "printing_array_of_Characters_using_function----------------------------------\n";
    printing_array_of_Characters_using_function();

    return 0;
}