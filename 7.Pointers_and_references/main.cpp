// C++ program to illustrate Pointers 
#include <iostream> 
#include <vector>

using namespace std; 

void basic_ex_0() {

    int* myptr; // pointer variable
    cout << "myptr: " << myptr << endl;
    cout << "*myptr: " << *myptr << endl;

    int* myptr_2 = NULL; // pointer variable
    cout << "myptr_2: " << myptr_2 << endl;
    //cout << "*myptr_2: " << *myptr_2 << endl; segmentation fAULT

    int* myptr_3 = nullptr; // pointer variable
    cout << "myptr_3: " << myptr_3 << endl;
    //cout << "*myptr_3: " << *myptr_3 << endl; segmentation fault
}

//-------------------------------------------------------------------------
void basic_ex_1() {
    int x = 10; // variable declared
    int* myptr; // pointer variable
 
    // storing address of x in pointer myptr
    myptr = &x;
 
    cout << "Value of x is: ";
    cout << x << endl;
 
    // print the address stored in myptr pointer variable
    cout << "Address stored in myptr is: ";
    cout << myptr << endl;

    cout << "Address x is: ";
    cout << &x << endl;
 
    // printing value of x using pointer myptr
    cout << "Value of x using *myptr is: ";
    cout << *myptr << endl;
}

//-------------------------------------------------------------------------
void basic_ex_2() { 
    int var = 20; 
  
    // declare pointer variable 
    int* ptr; 
  
    // note that data type of ptr and var must be same 
    ptr = &var; 
  
    // assign the address of a variable to a pointer 
    cout << "Value at ptr = " << ptr << "\n"; 
    cout << "Value at var = " << var << "\n"; 
    cout << "Value at *ptr = " << *ptr << "\n"; 
} 
//-------------------------------------------------------------------------
// Pass-by-Value 
int square1(int n) 
{ 
    // Address of n in square1() is not the same as n1 in 
    // main() 
    cout << "address of n1 in square1(): " << &n << "\n"; 
  
    // clone modified inside the function 
    n *= n; 
    return n; 
} 

void use_of_pass_by_value() {
    // Call-by-Value 
    int n1 = 8; 
    cout << "address of n1 in main(): " << &n1 << "\n"; 
    cout << "Square of n1: " << square1(n1) << "\n"; 
    cout << "No change in n1: " << n1 << "\n"; 
}

//-------------------------------------------------------------------------
// Pass-by-Reference with Pointer Arguments 
void square2(int* n) 
{ 
    // Address of n in square2() is the same as n2 in main() 
    cout << "address of n2 in square2(): " << n << "\n"; 
  
    // Explicit de-referencing to get the value pointed-to 
    *n *= *n; 
} 

void use_of_pass_by_pointer() {
    // Call-by-Reference with Pointer Arguments 
    int n2 = 8; 
    cout << "address of n2 in main(): " << &n2 << "\n"; 
    square2(&n2); 
    cout << "Square of n2: " << n2 << "\n"; 
    cout << "Change reflected in n2: " << n2 << "\n";  
}

//-------------------------------------------------------------------------
// Pass-by-Reference with Reference Arguments 
void square3(int& n) 
{ 
    // Address of n in square3() is the same as n3 in main() 
    cout << "address of n3 in square3(): " << &n << "\n"; 
  
    // Implicit de-referencing (without '*') 
    n *= n; 
}

void use_of_pass_by_reference() {
    // Call-by-Reference with Reference Arguments 
    int n3 = 8; 
    cout << "address of n3 in main(): " << &n3 << "\n"; 
    square3(n3); 
    cout << "Square of n3: " << n3 << "\n"; 
    cout << "Change reflected in n3: " << n3 << "\n"; 
}

//-------------------------------------------------------------------------
void array_name_as_pointers() {
    // Declare an array 
    int val[3] = { 5, 10, 20 }; 
  
    // declare pointer variable 
    int* ptr; 
  
    // Assign the address of val[0] to ptr 
    // We can use ptr=&val[0];(both are same) 
    ptr = val; 
    cout << "Elements of the array are: "; 
    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
    cout << ptr + 0 << " " << ptr + 1 << " " << ptr + 2 << endl; 
    cout << *(ptr + 0) << " " << *(ptr + 1) << " " << *(ptr + 2) << endl; 
}   

void use_of_array_name_as_pointers() {
    array_name_as_pointers();
}

//-------------------------------------------------------------------------
void behavior_of_sizeof_operator() {
    int arr[] = { 10, 20, 30, 40, 50, 60 }; 
        int* ptr = arr; 
    
        // sizof(int) * (number of element in arr[]) is printed 
        cout << "Size of arr[] " << sizeof(arr) << "\n"; 
    
        // sizeof a pointer is printed which is same for all 
        // type of pointers (char *, void *, etc) 
        cout << "Size of ptr " << sizeof(ptr) << endl; 
}

//-------------------------------------------------------------------------
void array_pointer_arithmetic_1() {
    int arr[] = { 10, 20, 30, 40, 50, 60 }; 
    int* ptr = arr; 
    cout << "arr[2] = " << arr[2] << "\n"; 
    cout << "*(arr + 2) = " << *(arr + 2) << "\n"; 
    cout << "ptr[2] = " << ptr[2] << "\n"; 
    cout << "*(ptr + 2) = " << *(ptr + 2) << "\n"; 
}

//-------------------------------------------------------------------------
void array_pointer_arithmetic_2() {
    // Declare an array 
    int v[3] = { 10, 100, 200 }; 
  
    // declare pointer variable 
    int* ptr; 
  
    // Assign the address of v[0] to ptr 
    ptr = v; 
  
    for (int i = 0; i < 3; i++) { 
        cout << "Value at ptr = " << ptr << "\n"; 
        cout << "Value at *ptr = " << *ptr << "\n"; 
  
        // Increment pointer ptr by 1 
        ptr++; 
    } 
}
//-------------------------------------------------------------------------
int fun(int ptr[])  { //*ptr
    int x = 10; 
    
    // Size of a pointer is printed 
    cout << "sizeof(ptr) = " 
        << (int)sizeof(*ptr)  
        << endl; 

    // This allowed because ptr is a  
    // pointer, not array 
    ptr = &x; 

    cout <<"*ptr =  " << *ptr << endl;; 

    return 0; 
} 

void array_pointer_function_input() {
    int arr[] = { 10, 20, 30, 40, 50, 60 }; 
        
    // Size of a array is printed 
    cout << "sizeof(arr) = " 
        << (int)sizeof(arr) 
        << endl; 
        
    fun(arr); 
}

//-------------------------------------------------------------------------
void use_of_dynamic_mem_allocation_pointer_to_pointer() {
    /*
        matrix (int**)
    |
    |---> [0] --> [0] --> (int) 0x...   [1] --> (int) 0x...   [2] --> (int) 0x...   [3] --> (int) 0x...
    |               ^                       ^                       ^                       ^
    |               |                       |                       |                       |
    |               0                       0                       0                       0
    |
    |---> [1] --> [0] --> (int) 0x...   [1] --> (int) 0x...   [2] --> (int) 0x...   [3] --> (int) 0x...
    |               ^                       ^                       ^                       ^
    |               |                       |                       |                       |
    |               0                       0                      42                       0
    |
    |---> [2] --> [0] --> (int) 0x...   [1] --> (int) 0x...   [2] --> (int) 0x...   [3] --> (int) 0x...
                    ^                       ^                       ^                       ^
                    |                       |                       |                       |
                    0                       0                       0                       0
    */
    // Dynamically allocate an array of pointers to integers
    int** matrix = new int*[3]; // matrix is a pointer to pointers
    /*
    Bu satır, matrix adında, 3 adet int* (integer pointer) 
    içeren bir dizi oluşturur. Yani matrix, 3 adet satır için bellekte yer ayırır.
    */

    // Allocate memory for each row of the matrix
    for (int i = 0; i < 3; ++i) {
        matrix[i] = new int[4]; // Each matrix[i] points to an array of integers
    }
    /*
    Bu döngü, her bir satır için 4 adet int içeren bir dizi oluşturur. 
    Yani her satır, 4 sütun için bellekte yer ayırır.
    */

    // Initialize and use the matrix
    matrix[1][2] = 42; // Accessing and modifying elements using double pointers

    cout << "size: " << sizeof(matrix)<< endl;


    for(int i = 0; i < 3 ; i++) {
        for(int j = 0; j < 4; j++) {
            cout << "matrix" << "[" << i << "]" << "[" << j << "]" << "= " << matrix[i][j] << " address " << &matrix[i][j] <<endl; 
        }
    }
}

//-------------------------------------------------------------------------
void modifyPointer(int** ptr) {
    *ptr = new int(10); // Allocate memory for an integer and store its address
}

void use_of_pointer_to_pointer_function_parameters() {
    int* ptr = nullptr;
    modifyPointer(&ptr); // Pass the address of ptr to modifyPointer

    std::cout << *ptr << std::endl; // Outputs 10
}
//-------------------------------------------------------------------------

void multi_dim_array() {
    // Dynamic allocation of a 2D array using pointer to pointers
    int rows = 2;
    int cols = 3;
    int** grid = new int*[rows];

    for (int row = 0; row < rows; ++row) {
        grid[row] = new int[cols]; // Each grid[i] points to a row of integers
    }

    // Access and modify elements in the grid
    grid[1][2] = 5;

    for(int i = 0; i < rows ; i++) {
        for(int j = 0; j < cols; j++) {
            cout << "grid" << "[" << i << "]" << "[" << j << "]" << "= " << grid[i][j] << " address " << &grid[i][j] <<endl; 
        }
    }
}

//-------------------------------------------------------------------------
void use_of_string_literals() {
    char* str1 = "Hello";
    char str2[] = "World";

    cout << str1 << " " << str2 << endl;  // Çıktı: Hello World

    for (int i = 0; i < 5; i++) {
        //*(str1 + i) = 'e'; hata verir çünkü sabit olarak saklıyor stringleri
        cout << (*(str1 + i)) << endl;
    }
    for (int i = 0; i < 5; i++) {
        //str2[i] = 'e'; hata verir çünkü sabit olarak saklıyor stringleri
        cout << str2[i] << endl;
    }

    cout << str1 << " " << str2 << endl;  // Çıktı: Hello World
}

//-------------------------------------------------------------------------
void printValue_void_ptr(void* ptr, char type) {
    switch (type) {
        case 'i':
            std::cout << "Value (int): " << *(int*)ptr << std::endl;
            break;
        case 'f':
            std::cout << "Value (float): " << *(float*)ptr << std::endl;
            break;
        case 'c':
            std::cout << "Value (char): " << *(char*)ptr << std::endl;
            break;
        default:
            std::cout << "Unsupported type" << std::endl;
            break;
    }
}

void use_of_void_pointers() {
    int intValue = 42;
    float floatValue = 3.14f;
    char charValue = 'A';

    printValue_void_ptr(&intValue, 'i');  // void pointer olarak int işaretçisi
    printValue_void_ptr(&floatValue, 'f'); // void pointer olarak float işaretçisi
    printValue_void_ptr(&charValue, 'c');  // void pointer olarak char işaretçisi
}

//-------------------------------------------------------------------------
void calculateSumAndProduct(int a, int b, int* sumResult, int* productResult) {
        *sumResult = a + b;       // Store sum in sumResult pointer
        *productResult = a * b;   // Store product in productResult pointer
    }

void use_of_multiple_values_return() {
    int x = 5, y = 3;
    int sum, product;

    // Call the function and pass pointers to sum and product variables
    calculateSumAndProduct(x, y, &sum, &product);

    // Display the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;
}

//-------------------------------------------------------------------------
int* fun_wrong() {
    // x is local variable and goes out of
    // scope after an execution of fun() is
    // over.
    int x = 5;

    return &x;
}
void dangling_ex_wrong() {
    int* p = fun_wrong();
    //fflush(stdin);

    // p points to something which is not
    // valid anymore
    printf("%d", *p);
}

//-------------------------------------------------------------------------
int* fun_right() {
    // x now has scope throughout the program
    static int x = 5;
    x++;
    return &x;
}

void dangling_ex_right() {
    int* p = fun_right();

    // Not a dangling pointer as it points
    // to static variable.
    printf("%d\n", *p);

    fun_right();
    printf("%d\n", *p);

    fun_right();
    printf("%d\n", *p);

    fun_right();
    printf("%d\n", *p);

    *p =  *p + 5;
    printf("%d\n", *p);
}

//-------------------------------------------------------------------------
void reference_ex() {
    int x = 10;
    int &ref = x; // x değişkeninin referansı olan 'ref' tanımlama

    cout << "x = " << x << endl; // x'in değeri
    cout << "ref = " << ref << endl; // ref'in değeri

    ref = 20; // ref'i kullanarak x'in değerini değiştirme
    cout << "x = " << x << endl; // x'in yeni değeri (20)
    cout << "ref = " << ref << endl; // ref'in değeri (20)

    x = 30;
    cout << "x = " << x << endl; 
    cout << "ref = " << ref << endl; 
}

//-------------------------------------------------------------------------
void swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}
void function_reference_ex() {
    // Variables declared
    int a = 2, b = 3;
 
    // function called
    swap(a, b);
 
    // changes can be seen
    // printing both variables
    cout << a << " " << b << endl;;
}

//-------------------------------------------------------------------------
struct Student {
    string name;
    string surname;
    int rollNo;
};
// If we remove & in below function, a new
// copy of the student object is created. 
// We use const to avoid accidental updates
// in the function as the purpose of the function
// is to print s only.
void use_structure(const Student &s) {
    cout << s.name << "  " << s.surname << "  " << s.rollNo << endl;
}
void avoid_copy_large_structures() {
    struct Student my_student;

    my_student.name = "enes";
    my_student.surname = "balci";
    my_student.rollNo = 3;
    use_structure(my_student);
}

//-------------------------------------------------------------------------
void for_each_reference_ex() {
    vector<int> vect{ 10, 20, 30, 40 };

    // Printing elements
    for (int x : vect) {
        cout << x << " ";
    }
    cout << '\n';
    // We can modify elements if we
    // use reference
    for (int& x : vect) {
        x = x + 5;
    }
 
    // Printing elements
    for (int x : vect) {
        cout << x << " ";
    }
    cout << '\n';
}

//-------------------------------------------------------------------------
void for_each_reference_ex_2() {
    // Declaring vector
    vector<string> vect{ "geeksforgeeks practice",
                         "geeksforgeeks write",
                         "geeksforgeeks ide" };
 
    // We avoid copy of the whole string
    // object by using reference.
    for (const auto &x : vect) {
        cout << x << '\n';
    }

    cout << '\n';
}

//-------------------------------------------------------------------------
void reference_pointer_ex_2() {
    // simple or ordinary variable.
    int i = 10;
 
    // single pointer
    int* p = &i;
 
    // double pointer
    int** pt = &p;
 
    // triple pointer
    int*** ptr = &pt;
 
    // All the above pointers differ in the value they store
    // or point to.
    cout << "i = " << i << "\t"
         << "p = " << p << "\t"
         << "pt = " << pt << "\t"
         << "ptr = " << ptr << '\n';
    
    cout << "i = " << i << "\t"
         << "*p = " << *p << "\t"
         << "*pt = " << *pt << "\t"
         << "*ptr = " << *ptr << '\n';
 
    // simple or ordinary variable
    int a = 5;
    int& S = a;
    int& S0 = S;
    int& S1 = S0;
 
    // All the references do not differ in their
    // values as they all refer to the same variable.
    cout << "a = " << a << "\t"
         << "S = " << S << "\t"
         << "S0 = " << S0 << "\t"
         << "S1 = " << S1 << '\n';

    S0 = 30;

    cout << "a = " << a << "\t"
         << "S = " << S << "\t"
         << "S0 = " << S0 << "\t"
         << "S1 = " << S1 << '\n';
}
//-------------------------------------------------------------------------
int& multiplyByTwo(int &x) {
    x *= 2;
    return x;
}

void returning_reference() {
    int num = 5;

    std::cout << "Before: num = " << num << std::endl;
    // Fonksiyon, num'un değerini 2 ile çarparak aynı referansı döndürüyor.
    int& result = multiplyByTwo(num);
    std::cout << "After: num = " << num << std::endl;

    int result_2 = multiplyByTwo(num);
    std::cout << "After: num = " << num << std::endl;

    std::cout << "After: num = " << num << std::endl;
    std::cout << "Result: result = " << result << std::endl;
    std::cout << "Result: result = " << result_2 << std::endl;
}

//-------------------------------------------------------------------------
void array_pointer_returning(int *arr, int size) { //int a[] olarakda tanımlayabildrik hiç bir farkı yok
    //fonksiyona içinde arrayi paramtere olarak aldığımızda range based loop kullanamıyoruz
    for(int i = 0; i < size ; i++) {
        arr[i] = arr[i]+5;
        //*(arr + i) +=1; aynı şey
    }
}

void use_of_array_pointer_returning() {
    int arr[5] = {1, 2, 3, 4, 5};

    cout << "before-------------------------------------------\n";
    int a = 0;
    for(int i : arr) {
        cout << "arr" << "[" << a << "]" << "= " << arr[a] << endl; 
        a+=1;
    }

    array_pointer_returning(arr, 5);

    a = 0;
    cout << "after---------------------------------------------\n";
    for(int i : arr) {
        cout << "arr" << "[" << a << "]" << "= " << arr[a] << endl; 
        a+=1;
    }
}

//-------------------------------------------------------------------------

int* create_and_return_array() {
    int *arr = new int[5];
    
    for (int i = 0; i < 5; i ++) {
        *(arr+i) = i;
    }
    return arr;
}
void use_of_create_and_return_array() {
    int *arr = create_and_return_array();

    for(int i = 0; i < 5; i++) {
        cout << "arr" << "[" << i << "]" << "= " << arr[i] << endl; 
    }
}

//-------------------------------------------------------------------------

int* create_and_return_array_with_static_keyword() {
    static int arr_1[5];
    
    for (int i = 0; i < 5; i ++) {
        *(arr_1+i) = i;
    }
    return arr_1;
}
void use_of_create_and_return_array_with_static_keyword() {
    int *arr_1 = create_and_return_array();

    for(int i = 0; i < 5; i++) {
        cout << "arr" << "[" << i << "]" << "= " << arr_1[i] << endl; 
    }
}
int main()  {
    cout << "\nbasic example 0 ------------------------------------------------\n";
    basic_ex_0();

    cout << "\nbasic example 1 ------------------------------------------------\n";
    basic_ex_1();  

    cout << "\nbasic example ------------------------------------------------\n";
    basic_ex_2(); 

    cout << "\npass by value ------------------------------------------------\n";
    use_of_pass_by_value();

    cout << "\npass by pointer ------------------------------------------------\n";
    use_of_pass_by_pointer();

    cout << "\npass by reference ------------------------------------------------\n";
    use_of_pass_by_reference();

    cout << "\narray_name_as_pointers ------------------------------------------------\n";
    use_of_array_name_as_pointers();

    cout << "\nBehavior of sizeof operator ------------------------------------------------\n";
    behavior_of_sizeof_operator();

    cout << "\nArray members are accessed using pointer arithmetic-------------------------\n";
    array_pointer_arithmetic_1();

    cout << "\nArray members are accessed using pointer arithmetic-------------------------\n";
    array_pointer_arithmetic_2();

    cout << "\nArray parameters are always passed as pointers, even when we use square brackets------\n";
    array_pointer_function_input();
    
    cout << "\nuse_of_dynamic_mem_allocation_pointer_to_pointer ------------------------------------------------\n";
    use_of_dynamic_mem_allocation_pointer_to_pointer();

    cout << "\nuse_of_pointer_to_pointer_function_parameters ------------------------------------------------\n";
    use_of_pointer_to_pointer_function_parameters();

    cout << "\nmulti_dim_array ------------------------------------------------\n";
    multi_dim_array();

    cout << "\nuse_of_string_literals ------------------------------------------------\n";
    use_of_string_literals();

    cout << "\nuse_of_void_pointers ------------------------------------------------\n";
    use_of_void_pointers();

    cout << "\nmultiple values ------------------------------------------------\n";
    use_of_multiple_values_return();

    cout << "\ndangling_ex_wrong ------------------------------------------------\n";
    //dangling_ex_wrong(); //hata veriyor

    cout << "\ndangling_ex_right ------------------------------------------------\n";
    dangling_ex_right();

    cout << "\nreference example ------------------------------------------------\n";
    reference_ex();

    cout << "\nfunction_reference_ex ------------------------------------------------\n";
    function_reference_ex();

    cout << "\navoid_copy_large_structures ------------------------------------------------\n";
    avoid_copy_large_structures();

    cout << "\nfor_each_ex ------------------------------------------------\n";
    for_each_reference_ex();

    cout << "\nfor_each_ex 2 ------------------------------------------------\n";
    for_each_reference_ex_2();

    cout << "\nreference_pointer_ex_2 ------------------------------------------------\n";
    reference_pointer_ex_2();

    cout << "\nreturning_reference ------------------------------------------------\n";
    returning_reference();

    cout << "\nuse_of_array_pointer_returning ------------------------------------------------\n";
    use_of_array_pointer_returning();

    cout << "\nuse_of_create_and_return_array ------------------------------------------------\n";
    use_of_create_and_return_array();

    cout << "\nuse_of_create_and_return_array_with_static_keyword ------------------------------------------------\n";
    use_of_create_and_return_array_with_static_keyword();

    return 0;
}