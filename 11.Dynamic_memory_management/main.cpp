#include <iostream>
#include <stdlib.h>

using namespace std;

//C examples ##############################################################
// malloc -----------------------------------------------------------------
int* dynamic_array_ex() {
    int size = 5;
    int *ptr = (int*)malloc(5 * sizeof(int));

    for (int n = 0; n < size; ++n) {
            ptr[n] = n + 1;
        }
    return ptr;
}

void malloc_example() {
    int* ptr;
    int i;

    i = 5;

    ptr = (int*)malloc(i * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return;
    } else {
        printf("Memory successfully allocated using malloc.\n");
        for (int n = 0; n < i; ++n) {
            printf("************************\n");
            printf("ptr + %d = %p\n", n, ptr + n);
            printf("*(ptr + %d) = %d\n", n, *(ptr + n));
            printf("ptr[%d] = %d\n", n, ptr[n]);
        }
    }

    printf("Dynamic array ex*********************\n");

    int *ptr_array = dynamic_array_ex();

    for (int n = 0; n < 5; ++n) {
            printf("************************\n");
            printf("ptr_array + %d = %p\n", n, ptr_array + n);
            printf("*(ptr_array + %d) = %d\n", n, *(ptr_array + n));
            printf("ptr_array[%d] = %d\n", n, ptr_array[n]);
        }

    free(ptr);
    free(ptr_array);
}

// calloc -----------------------------------------------------------------
void calloc_example() {
    int* ptr;
    int i;

    i = 5;

    ptr = (int*)calloc(i, sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return;
    } else {
        printf("Memory successfully allocated using calloc.\n");
        for (int n = 0; n < i; ++n) {
            printf("************************\n");
            printf("ptr + %d = %p\n", n, ptr + n);
            printf("*(ptr + %d) = %d\n", n, *(ptr + n));
            printf("ptr[%d] = %d\n", n, ptr[n]);
        }
    }
    free(ptr);
}

// realloc -----------------------------------------------------------------
void realloc_example() {

    int* ptr;
    int i;

    i = 5;

    ptr = (int*)malloc(i * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return;
    } else {
        printf("Memory successfully allocated using malloc.\n");
        for (int n = 0; n < 10; ++n) {

            if(n < 5) {
                ptr[n] = n + 1;
            }
    
            printf("************************\n");
            printf("ptr + %d = %p\n", n, ptr + n);
            printf("*(ptr + %d) = %d\n", n, *(ptr + n));
            printf("ptr[%d] = %d\n", n, ptr[n]);
        }
    }

    printf("realloc process\n");
    i = 10;
    ptr = (int*)realloc(ptr, i * sizeof(int));

    for (int n = 5; n < i; ++n) {
        ptr[n] = n + 1;
    }

    for (int n = 0; n < 10; ++n) {

        printf("************************\n");
        printf("ptr + %d = %p\n", n, ptr + n);
        printf("*(ptr + %d) = %d\n", n, *(ptr + n));
        printf("ptr[%d] = %d\n", n, ptr[n]);
    }

    free(ptr);
}

//C examples ##############################################################
// New Operator
// basic -----------------------------------------------------------------
void basic_data_type_ex() {
    int* ptr;

    // allocating memory for integer
    ptr = new int;

    // assigning value using dereference operator
    *ptr = 10;

    // printing value and address
    cout << "Address: " << ptr << endl;
    cout << "Value: " << *ptr << endl;

    delete ptr;
}

// array -----------------------------------------------------------------
void array_ex() {
    int* arr = new int[5]; // 5 elemanlı bir int dizisi için bellek tahsis eder

    cout << "başlangıç değerleri\n";

    for (int i = 0; i < 5; ++i) {
        printf("************************\n");
        printf("arr + %d = %p\n", i, arr + i);
        printf("*(arr + %d) = %d\n", i, *(arr + i));
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < 5; ++i) {
        printf("************************\n");
        printf("arr + %d = %p\n", i, arr + i);
        printf("*(arr + %d) = %d\n", i, *(arr + i));
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    delete[] arr; // Belleği serbest bırakır

}

// class -----------------------------------------------------------------
class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
    void display() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
};

void class_ex() {
    // Tek bir nesne için bellek tahsisi
    MyClass* obj = new MyClass();
    obj->display();
    delete obj; // Belleği serbest bırakır ve yıkıcıyı çağırır

    // Dizi için bellek tahsisi
    MyClass* objArray = new MyClass[3];
    for (int i = 0; i < 3; ++i) {
        objArray[i].display();
    }
    delete[] objArray; // Belleği serbest bırakır ve yıkıcıları çağırır
}

// nothrow -----------------------------------------------------------------

void nothrow_ex() {
    // Bellek tahsisi yap ve başarısız olursa nullptr döndür
    int *p = new(std::nothrow) int;
    
    if (p == nullptr) {
        std::cerr << "Memory allocation failed" << std::endl;
    } else {
        // Bellek tahsisi başarılı oldu, p kullanıma hazır
        *p = 42;
        std::cout << "Value: " << *p << std::endl;

        // Belleği serbest bırak
        delete p;
    }

    // Büyük bir bellek bloğu tahsis etmeye çalış
    int *largeArray = new(std::nothrow) int[1000000000000];
    
    if (largeArray == nullptr) {
        std::cerr << "Large array memory allocation failed" << std::endl;
    } else {
        // Bellek tahsisi başarılı oldu, largeArray kullanıma hazır
        // ... burada largeArray ile işler yapılabilir ...

        // Belleği serbest bırak
        delete[] largeArray;
    }
}
int main() {

    cout << "C examples ############################################\n";
    cout << "\nmalloc ------------------------------------------------\n";
    malloc_example();

    cout << "\ncalloc ------------------------------------------------\n";
    calloc_example();

    cout << "\nrealloc ------------------------------------------------\n";
    realloc_example();

    cout << "\nCpp examples ############################################\n";
    cout << "\nbasic data type ex ------------------------------------------------\n";
    basic_data_type_ex();

    cout << "\narray ex ------------------------------------------------\n";
    array_ex();

    cout << "\nclass ex ------------------------------------------------\n";
    class_ex();

    cout << "\nnothrow_ex ------------------------------------------------\n";
    nothrow_ex();

    return 0;
}