## Arrays

**Content**

- Array creation and using.

## Informations

- ***Array*** is a container that holds a fixed number of elements of the same type. It provides a way to store and access a collection of values in a contiguous memory block.

## Variable Length Arrays (VLAs) in C
- In C, variable length arrays (VLAs) are also known as runtime-sized or variable-sized arrays. The size of such arrays is defined at run-time.

- Variably modified types include variable-length arrays and pointers to variable-length arrays. Variably changed types must be declared at either block scope or function prototype scope.

- Variable length arrays are a feature where we can allocate an auto array (on stack) of variable size. It can be used in a typedef statement. C supports variable-sized arrays from the C99 standard. For example, the below program compiles and runs fine in C

- Note: In C99 or C11 standards, there is a feature called flexible array members, which works the same as the above. 
    ```c
    void fun(int size){
        int arr[size];
        // code
    }
    ```
- Explanation in code main.cpp: The above program illustrate how to create a variable size array in a function in C program. This size is passed as parameter and the variable array is created on the stack memory.

    ## Pointer to an Array | Array Pointer
    ```c
    #include<stdio.h>
    
    int main()
    {
    int arr[5] = { 1, 2, 3, 4, 5 };
    int *ptr = arr;
    
    printf("%p\n", ptr);
    return 0;
    }
    ```
    - In the above program, we have a pointer ptr that points to the 0th element of the array. Similarly, we can also declare a pointer that can point to whole array instead of only one element of the array. This pointer is useful when talking about multidimensional arrays. 

    ```c
    data_type (*var_name)[size_of_array];
    ```
    - data_type is the type of data that the array holds.
    - var_name is the name of the pointer variable.
    - size_of_array is the size of the array to which the pointer will point.

    - Here ptr is pointer that can point to an array of 10 integers. Since subscript have higher precedence than indirection, it is necessary to enclose the indirection operator and pointer name inside parentheses. Here the type of ptr is ‘pointer to an array of 10 integers.

    - Note: The pointer that points to the 0th element of array and the pointer that points to the whole array are totally different. The following program shows this: 

    ```c
    // C program to understand difference between 
    // pointer to an integer and pointer to an
    // array of integers. 
    #include<stdio.h>
    
    int main()
    {
        // Pointer to an integer
        int *p; 
        
        // Pointer to an array of 5 integers
        int (*ptr)[5]; 
        int arr[5];
        
        // Points to 0th element of the arr.
        p = arr;
        
        // Points to the whole array arr.
        ptr = &arr; 
        
        printf("p = %p, ptr = %p\n", p, ptr);
        
        p++; 
        ptr++;
        
        printf("p = %p, ptr = %p\n", p, ptr);
        
        return 0;
    }
    ```
        - Here, p is pointer to 0th element of the array arr, while ptr is a pointer that points to the whole array arr. 

        - The base type of p is int while base type of ptr is ‘an array of 5 integers’.

        - We know that the pointer arithmetic is performed relative to the base size, so if we write ptr++, then the pointer ptr will be shifted forward by 20 bytes.

    - On dereferencing a pointer expression we get a value pointed to by that pointer expression. The pointer to an array points to an array, so on dereferencing it, we should get the array, and the name of the array denotes the base address. So whenever a pointer to an array is dereferenced, we get the base address of the array to which it points.
    ```c
    // C program to illustrate sizes of
    // pointer of array
    #include<stdio.h>
    
    int main()
    {
        int arr[] = { 3, 5, 6, 7, 9 };
        int *p = arr;
        int (*ptr)[5] = &arr;
        
        printf("p = %p, ptr = %p\n", p, ptr);
        printf("*p = %d, *ptr = %p\n", *p, *ptr);
        
        printf("sizeof(p) = %lu, sizeof(*p) = %lu\n",
                            sizeof(p), sizeof(*p));
        printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", 
                            sizeof(ptr), sizeof(*ptr));
        return 0;
    }
    ```

## Pointer to Multidimensional Arrays
- https://www.geeksforgeeks.org/pointer-array-array-pointer/?ref=lbp
1. Pointers and Two-Dimensional Arrays
    - In a two-dimensional array, we can access each element by using two subscripts, where the first subscript represents the row number and the second subscript represents the column number. The elements of 2-D array can be accessed with the help of pointer notation also. Suppose arr is a 2-D array, we can access any element arr[i][j] of the array using the pointer expression *(*(arr + i) + j). Now we’ll see how this expression can be derived. 
    - Since memory in a computer is organized linearly it is not possible to store the 2-D array in rows and columns. The concept of rows and columns is only theoretical, actually, a 2-D array is stored in row-major order i.e rows are placed next to each other. 
    - Each row can be considered as a 1-D array, so a two-dimensional array can be considered as a collection of one-dimensional arrays that are placed one after another. In other words, we can say that 2-D dimensional arrays that are placed one after another. So here arr is an array of 3 elements where each element is a 1-D array of 4 integers. 
    - We know that the name of an array is a constant pointer that points to 0th 1-D array and contains address 5000. Since arr is a ‘pointer to an array of 4 integers’, according to pointer arithmetic the expression arr + 1 will represent the address 5016 and expression arr + 2 will represent address 5032. 

    - **arr + i  Points to ith element of arr -> Points to ith 1-D array**
    - Since arr + i points to ith element of arr, on dereferencing it will get ith element of arr which is of course a 1-D array. Thus the expression *(arr + i) gives us the base address of ith 1-D array.
    - We know, the pointer expression *(arr + i) is equivalent to the subscript expression arr[i]. So *(arr + i) which is same as arr[i] gives us the base address of ith 1-D array.
    - To access an individual element of our 2-D array, we should be able to access any jth element of ith 1-D array.
    - Since the base type of *(arr + i) is int and it contains the address of 0th element of ith 1-D array, we can get the addresses of subsequent elements in the ith 1-D array by adding integer values to *(arr + i).
    - For example *(arr + i) + 1 will represent the address of 1st element of 1stelement of ith 1-D array and *(arr+i)+2 will represent the address of 2nd element of ith 1-D array.
    - Similarly *(arr + i) + j will represent the address of jth element of ith 1-D array. On dereferencing this expression we can get the jth element of the ith 1-D array.
2. Pointers and Three Dimensional Arrays 
    ```cpp
    int arr[2][3][2] = { {{5, 10}, {6, 11}, {7, 12}}, {{20, 30}, {21, 31}, {22, 32}} };
    ```
    - In a three dimensional array we can access each element by using three subscripts. Let us take a 3-D array- We can consider a three dimensional array to be an array of 2-D array i.e each element of a 3-D array is considered to be a 2-D array. The 3-D array arr can be considered as an array consisting of two elements where each element is a 2-D array. The name of the array arr is a pointer to the 0th 2-D array. 
    - Thus the pointer expression *(*(*(arr + i ) + j ) + k) is equivalent to the subscript expression arr[i][j][k]. 
    - We know the expression *(arr + i) is equivalent to arr[i] and the expression *(*(arr + i) + j) is equivalent arr[i][j]. So we can say that arr[i] represents the base address of ith 2-D array and arr[i][j] represents the base address of the jth 1-D array. 

## Subscripting Pointer to an Array
- Suppose arr is a 2-D array with 3 rows and 4 columns and ptr is a pointer to an array of 4 integers, and ptr contains the base address of array arr. 
    ```c
    int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};
    int (*ptr)[4];
    ptr = arr;
    ```
- Since ptr is a pointer to the first row 2-D array i.e. array of 4 integers, ptr + i will point to ith row. On dereferencing ptr + i, we get base address of ith row. To access the address of jth element of ith row we can add j to the pointer expression *(ptr + i). So the pointer expression *(ptr + i) + j gives the address of jth element of ith row and the pointer expression *(*(ptr + i)+j) gives the value of the jth element of ith row. 

- We know that the pointer expression *(*(ptr + i) + j) is equivalent to subscript expression ptr[i][j]. So if we have a pointer variable containing the base address of 2-D array, then we can access the elements of array by double subscripting that pointer variable. 

## How to print size of array parameter
```cpp
// A C++ program to show that it is wrong to 
// compute size of an array parameter in a function
#include <iostream>
using namespace std;
 
void findSize(int arr[]) 
{ 
  cout << sizeof(arr) << endl; 
}
 
int main()
{
    int a[10];
    cout << sizeof(a) << " ";
    findSize(a);
    return 0;
}
```
- The above output is for a machine where the size of an integer is 4 bytes and the size of a pointer is 8 bytes.
- The cout statement inside main() prints 40, and cout in findSize() prints 8. The reason for different outputs is that the arrays always pass pointers in functions. Therefore, findSize(int arr[]) and findSize(int *arr) mean exact same thing. Therefore the cout statement inside findSize() prints the size of a pointer.

## Pass Array to Functions
- In C, the whole array cannot be passed as an argument to a function. However, you can pass a pointer to an array without an index by specifying the array’s name.
- Arrays in C are always passed to the function as pointers pointing to the first element of the array.
    - In C, we have three ways to pass an array as a parameter to the function. In the function definition, use the following syntax:
        ```c
        return_type foo ( array_type array_name[size], ...);
        ```
    - Mentioning the size of the array is optional. So the syntax can be written as:
        ```c
        return_type foo ( array_type array_name[], ...);
        ```

    - in both of the above syntax, even though we are defining the argument as array it will still be passed as a pointer. So we can also write the syntax as:
    ```c
    return_type foo ( array_type* array_name, ...);
    ```

- Example 1: Checking Size After Passing Array as Parameter
    ```cpp
    // C program to pass the array as a function and check its size
    #include <stdio.h>
    #include <stdlib.h>
    
    // Note that arr[] for fun is just a pointer even if square
    // brackets are used. It is same as
    // void fun(int *arr) or void fun(int arr[size])
    void func(int arr[8])
    {
        printf("Size of arr[] in func(): %d bytes",
            sizeof(arr));
    }
    
    // Drive code
    int main()
    {
        int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    
        printf("Size of arr[] in main(): %dbytes\n",
            sizeof(arr));
    
        func(arr);
    
        return 0;
    }
    ```
        - The size of the arr[] in the main() function (where arr[] is declared) is 32 bytes which is = sizeof(int) * 8 = 4 * 8 = 32 bytes.
        - But in the function where the arr[] is passed as a parameter, the size of arr[] is shown as 8 bytes (which is the size of a pointer in C).

- It is due to the fact that the array decays into a pointer after being passed as a parameter. One way to deal with this problem is to pass the size of the array as another parameter to the function. This is demonstrated in the below example.
    ```c
    // C program to illustrate the use of sizeof operator in C
    #include <stdio.h>
    
    // function to print array
    void printArray(int arr[], int size)
    {
        printf("Array Elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    }
    
    // driver code
    int main()
    {
        int arr[8] = { 12, 4, 5, 3, 7, 8, 11, 45 };
    
        // getting the size of array
        int size = sizeof(arr) / sizeof(arr[0]);
    
        printArray(arr, size);
    
        return 0;
    }
    ```
- This size parameter may not be needed only in the case of ‘\0’ terminated character arrays as size can be determined by checking the end of the string character. The below example demonstrates the following.

## What is Array Decay in C++? How can it be prevented?
### What is Array Decay? 
- The loss of type and dimensions of an array is known as decay of an array.This generally occurs when we pass the array into function by value or pointer. What it does is, it sends first address to the array which is a pointer, hence the size of array is not the original one, but the one occupied by the pointer in the memory.

    ```cpp
    // C++ code to demonstrate array decay
    #include <iostream>
    using namespace std;

    // Driver function to show Array decay
    // Passing array by value
    void aDecay(int* p)
    {
        // Printing size of pointer
        cout << "Modified size of array is by "
                " passing by value: ";
        cout << sizeof(p) << endl;
    }

    int main()
    {
        int a[7] = {
            1, 2, 3, 4, 5, 6, 7,
        };

        // Printing original size of array
        cout << "Actual size of array is: ";
        cout << sizeof(a) << endl;

        // Passing a pointer to array
        aDecay(a);

        return 0;
    }

    //Actual size of array is: 28
    //Modified size of array is by  passing by value: 8
    ```
    - In the above code, the actual array has 7 int elements and hence has 28 size. But by calling by value and pointer, array decays into pointer and prints the size of 1 pointer i.e. 8 (4 in 32 bit).

### How to prevent Array Decay? 
- A typical solution to handle decay is to pass size of array also as a parameter and not use sizeof on array parameters 
- Another way to prevent array decay is to send the array into functions by reference. This prevents conversion of array into a pointer, hence prevents the decay.

    ```cpp
    // C++ code to demonstrate prevention of
    // decay of array
    #include<iostream>
    using namespace std;

    // A function that prevents Array decay
    // by passing array by reference
    void fun(int (&p)[7])
    {
        // Printing size of array
        cout << "Modified size of array by "
                "passing by reference: ";
        cout << sizeof(p) << endl;
    }

    int main()
    {
        int a[7] = {1, 2, 3, 4, 5, 6, 7,};

        // Printing original size of array
        cout << "Actual size of array is: ";
        cout << sizeof(a) <<endl;

        // Calling function by reference
        fun(a);

        return 0;
    }

    //Actual size of array is: 28
    //Modified size of array by passing by reference: 28
    ```
    - But in this case, we will have to treat the array in the function as 2d array and to access the value stored in the array, we have to access it like this: arr[0][1], arr[0][3],