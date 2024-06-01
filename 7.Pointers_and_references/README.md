
,# Pointers and References
- In C++ pointers and references both are mechanisms used to deal with memory, memory address, and data in a program. Pointers are used to store the memory address of another variable whereas references are used to create an alias for an already existing variable.
- Pointers in C++ are a symbolic representation of addresses. They enable programs to simulate call-by-reference, call by pointer and create and manipulate dynamic data structures. Pointers store the address of variables or a memory location. 

## Content
- [First example](#first-example)
- [Application of Pointers](#application-of-pointers)
- [Features and Use of Pointers](#features-and-use-of-pointers)
- [this Pointer ](#this-pointer)
- [How to use a pointer](#how-to-use-a-pointer)
- [References and Pointers](#references-and-pointers)
- [Array Name as Pointers](#array-name-as-pointers)
- [Return pointer](#return-pointer)
- [Advanced Pointer Notation](#advanced-pointer-notation)
- [Pointers and String literals](#pointers-and-string-literals)
- [Void Pointers](#void-pointers)
- [nullptr](#nullptr)
- [Invalid pointers](#invalid-pointers)
- [Advantages of Pointers](#advantages-of-pointers)
- [References](#references)
- [Return reference](#return-reference)
- [Applications of Reference](#applications-of-reference)
- [References vs Pointers](#references-vs-pointers)
- [Limitations of References](#limitations-of-references)
- [Advantages of using References](#advantages-of-using-references)
- [Can References Refer to Invalid Location](#can-references-refer-to-invalid-location)
- [When do we pass arguments by pointer](#when-do-we-pass-arguments-by-pointer)
- [const with pointers](#const-with-pointers)
- [const with references](#const-with-references)

## First example
- Explanation(basic_ex_1): The above program declares an integer variable ‘x’ initialized with value 10 and a pointer variable named ‘myptr’. The memory address of x is assigned to myptr. Then it prints the value of x, the address stored in myptr, and the value of x obtained by dereferencing the pointer myptr.
    ```cpp
    datatype *var_name; 
    int *ptr;   // ptr can point to an address which holds int data
    ```

## Application of Pointers
- To pass arguments by reference: Passing by reference serves two purposes
    - For accessing array elements: The Compiler internally uses pointers to access array elements.
    - To return multiple values: For example in returning square and the square root of numbers.
- Dynamic memory allocation: We can use pointers to dynamically allocate memory. The advantage of dynamically allocated memory is, that it is not deleted until we explicitly delete it.
- To implement data structures.
- To do system-level programming where memory addresses are useful.

### C examples
1. Passing Arguments by Reference(pass by pointer in cpp)
    ```cpp
    // C program to demonstrate that we can change
    // local values of one function in another using pointers.
    
    #include <stdio.h>
    
    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    
    int main()
    {
        int x = 10, y = 20;
        swap(&x, &y);
        printf("%d %d\n", x, y);
        return 0;
    }
    // 20 10
    ```
2. For Efficiency Purpose
    ```cpp
    #include <stdio.h>
 
    // function to print an array by passing reference to array
    void printArray(int* arr, int n)
    {
        // here array elements are passed by value
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    
    int main()
    {
        int arr[5] = { 1, 2, 3, 4, 5 };
        printArray(arr, 5);
        return 0;
    }
    //1 2 3 4 5 
    ```
        - Note: Passing large structure without reference would create a copy of the structure (hence wastage of space). 

3. For Accessing Array Elements
    ```cpp
    // C program to demonstrate that compiler
    // internally uses pointer arithmetic to access
    // array elements.
    
    #include <stdio.h>
    
    int main()
    {
        int arr[] = { 100, 200, 300, 400 };
    
        // Compiler converts below to *(arr + 2).
        printf("%d ", arr[2]);
    
        // So below also works.
        printf("%d\n", *(arr + 2));
    
        return 0;
    }
    ```

4. To Return Multiple Values
    ```cpp
    // C program to demonstrate that using a pointer
    // we can return multiple values. aslında tam olarak return etme değil adresdeki değere ulaşarak o değeri değiştiriyoruz direkt
    
    #include <math.h>
    #include <stdio.h>
    
    void fun(int n, int* square, double* sq_root)
    {
        *square = n * n;
        *sq_root = sqrt(n);
    }
    
    int main()
    {
    
        int n = 100;
        int sq;
        double sq_root;
        fun(n, &sq, &sq_root);
    
        printf("%d %f\n", sq, sq_root);
        return 0;
    }
    // 10000 10
    ```
5. For dynamic memory Allocation
    ```cpp
    // C program to dynamically allocate an
    // array of given size.
    
    #include <stdio.h>
    #include <stdlib.h>
    int* createArr(int n)  // array döndürürken pointer döndürüyoruz aslında
    {
        int* arr = (int*)(malloc(n * sizeof(int)));
        return arr;
    }
    
    int main()
    {
        int* pt = createArr(10); // array döndürürken pointer döndürüyoruz aslında
        return 0;
    }
    ```
## Features and Use of Pointers
- The Pointers have a few important features and uses like it saves memory space, they are used to allocate memory dynamically, it is used for file handling, etc. Pointers store the address of variables or a memory location. 
- Example: pointer “ptr” holds the address of an integer variable or holds the address of memory whose value(s) can be accessed as integer values through “ptr”.
    ```cpp
    int *ptr;
    ```
## this Pointer 
- this pointer'i C++ programlama dilinde sınıf üyeleri içinde kullanılan özel bir işaretçidir. this, bir sınıfın bir örneğini işaret eden bir pointer'dır ve sınıfın içindeki fonksiyonlar aracılığıyla o anki nesneye erişim sağlar. (ilerde ayrıntılı işleyeceğiz oop de)

- The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name). Even if only one member of each function exists which is used by multiple objects, the compiler supplies an implicit pointer along with the names of the functions as ‘this’. 

## How to use a pointer
- Define a pointer variable
- Assigning the address of a variable to a pointer using the unary operator (&) which returns the address of that variable.
- Accessing the value stored in the address using unary operator (*) which returns the value of the variable located at the address specified by its operand.
- The reason we associate data type with a pointer is that it knows how many bytes the data is stored in. When we increment a pointer, we increase the pointer by the size of the data type to which it points.(mesela int dğerinde bir değişkenin adresini tutan pointerin değeriini ptr++ yaparsak 4 byte olarak artar. arraylarda çok iş görüyor)

## References and Pointers
- There are 3 ways to pass C++ arguments to a function:
    - Call-By-Value
    - Call-By-Reference with a Pointer Argument
    - Call-By-Reference with a Reference Argument
- In C++, by default arguments are passed by value and the changes made in the called function will not reflect in the passed variable. The changes are made into a clone made by the called function. If wish to modify the original copy directly (especially in passing huge object or array) and/or avoid the overhead of cloning, we use pass-by-reference. Pass-by-Reference with Reference Arguments does not require any clumsy syntax for referencing and dereferencing.
- Difference pass by Reference and Pass by Value
    - Benzerlikler
        - Ortak Amaç: Hem "pass by reference" hem de "pass by pointer", bir fonksiyona değişkenin orijinalini ileterek, değişkenin değerini fonksiyon içinde değiştirmeyi sağlar.
        - Veri Paylaşımı: Her iki yaklaşım da fonksiyonlar arasında veri paylaşımını ve etkileşimi sağlar.
        - Her ikisi de bir fonksiyona değişkenin adresini ileterek, fonksiyonun orijinal değişken üzerinde değişiklik yapmasını sağlar. Ancak aralarında bazı önemli farklar bulunmaktadır.
    - Farklar
        - Semantik Farklılıklar:
            - Pass by Reference: Referans ile parametre geçme, dilin sağladığı özel bir dil özelliğidir. Referanslar, bir değişkenin başka bir adı olarak görülür ve işlev çağrısında değişkenin kendisi ile çalışılır.
            - Pass by Pointer: İşaretçiler (pointers), değişkenin bellek adresini tutar ve bu adres üzerinden değişkenin değerine erişilir.
    - Dil Özellikleri:
        - Pass by Reference: C++ dilinde özgün bir özelliktir. Referanslar, işaretçilerin daha okunaklı ve güvenli bir alternatifidir.
        - Pass by Pointer: C ve C++ dillerinde kullanılabilir. İşaretçiler daha genel amaçlıdır ve daha düşük seviyeli bellek manipülasyonlarına izin verir.
    - Null İşaretçi (Null Pointer) Kullanımı:
        - Pass by Reference: Referanslar, null değerini alamazlar. Dolayısıyla, işlevlere geçirilen referans parametreler her zaman geçerli bir değişkeni temsil eder.
        - Pass by Pointer: İşaretçiler null değerini alabilirler. Bu nedenle, işlevlere geçirilen işaretçi parametreleri, işlevin geçerli bir değişkeni temsil edip etmediğini kontrol etmelidir.
    - C++ Tercihi: C++ dilinde, genellikle "pass by reference" kullanımı tavsiye edilir. Referanslar, işaretçilere kıyasla daha güvenli ve okunabilir bir kod sağlar.

    - C Dilinde: C dilinde ise, işaretçiler daha yaygın olarak kullanılır. Ancak C dilinde de referans benzeri işlevsellikler sağlayacak teknikler bulunmaktadır.

## Array Name as Pointers
- An array name contains the address of the first element of the array which acts like a constant pointer. It means, the address stored in the array name can’t be changed. For example, if we have an array named val then val and &val[0] can be used interchangeably. 
### Difference between Arrays and Pointers
- The array and pointers are derived data types that have lots of differences and similarities. In some cases, we can even use pointers in place of an array, and arrays automatically get converted to pointers when passed to a function. So, it is necessary to know about the differences between arrays and pointers to properly utilize them in our program.
- What is an Array?
    - an array is a data structure that represents a collection of elements of the same type stored in contiguous memory locations. It provides a way to store and access multiple values of the same data type using a single variable name.
    - it stores a homogeneous collection of data.
    - Its size can be decided by the programmer.
    - It provides random access.
- The array is one of the most used data types in many programming languages due to its simplicity and capability.

- What is a Pointer?
    - A pointer is a variable that holds the memory address of another variable. Pointers can be used for storing addresses of dynamically allocated arrays and for arrays that are passed as arguments to functions.
    - This size of the pointer is fixed and only depends upon the architecture of the system.

- Pointers are one of the core concepts that provide a lot of unique and useful features in our program.

### Difference between Arrays and Pointers
- pointers
    - It is declared as -: *var_name;
    - It is a variable that stores the address of another variable.
    - We can create a pointer to an array.
    - A pointer variable can store the address of only one variable at a time.
    - Pointer allocation is done during runtime.
    - The nature of pointers is dynamic. The size of a pointer in C can be resized according to user requirements which means the memory can be allocated or freed at any point in time.
- Array
    - It is declared as -: data_type var_name[size];
    - It is the collection of elements of the same data type.
    - We can create an array of pointers.
    - An array can store a number of elements the same size as the size of the array variable.
    - Array allocation is done during compile runtime.
    - The nature of arrays is static. During runtime, the size of an array in C cannot be resized according to user requirements.

### Distinguishing Features of Arrays and Pointers
1. Behavior of sizeof operator
    - When used with arrays, sizeof operator returns the size in bytes occupied by the entire array whereas when used with pointers, it returns the size in bytes of the pointer itself regardless of the data types it points to.
    ```cpp
    // 1st program to show that array and pointers are different 
    #include <iostream> 
    using namespace std; 
    
    int main() 
    { 
        int arr[] = { 10, 20, 30, 40, 50, 60 }; 
        int* ptr = arr; 
    
        // sizof(int) * (number of element in arr[]) is printed 
        cout << "Size of arr[] " << sizeof(arr) << "\n"; 
    
        // sizeof a pointer is printed which is same for all 
        // type of pointers (char *, void *, etc) 
        cout << "Size of ptr " << sizeof(ptr); 
        return 0; 
    }
    //Size of arr[] 24
    //Size of ptr 8
    ```
### Properties of Array that Make it Resemble Pointers
- Although array and pointer are different concepts, the following properties of array make them look similar. 
1. Array name gives the address of the first element of the array
    - When we use the array name in the program, it implicitly represents the memory address of the first element in the array.
    ```cpp
    // 1st program to show that array and pointers are different 
    #include <iostream> 
    using namespace std; 
    int main() 
    { 
        int arr[] = { 10, 20, 30, 40, 50, 60 }; 
    
        // Assigns address of array to ptr 
        int* ptr = arr; 
        cout << "Value of first element is " << *ptr; 
        return 0; 
    }
    //Value of first element is 10
    ```
2. Array members are accessed using pointer arithmetic.
    - The compiler uses pointer arithmetic to access the array elements. For example, an expression like “arr[i]” is treated as *(arr + i) by the compiler. That is why the expressions like *(arr + i) work for array arr, and expressions like ptr[i] also work for pointer ptr.
    ```cpp
    #include <iostream> 
    using namespace std; 
    
    int main() 
    { 
        int arr[] = { 10, 20, 30, 40, 50, 60 }; 
        int* ptr = arr; 
        cout << "arr[2] = " << arr[2] << "\n"; 
        cout << "*(arr + 2) = " << *(arr + 2) << "\n"; 
        cout << "ptr[2] = " << ptr[2] << "\n"; 
        cout << "*(ptr + 2) = " << *(ptr + 2) << "\n"; 
        return 0; 
    }
    //arr[2] = 30
    //*(arr + 2) = 30
    //ptr[2] = 30
    //*(ptr + 2) = 30
    ```
3. Array parameters are always passed as pointers, even when we use square brackets
    - When an array is passed as a parameter to a function, the array name is converted to a pointer to its first element and the function receives the pointer that points to the first element of the array instead of the entire array. *ptr olarak da tanımlayabilirdik
    ```cpp
    #include <bits/stdc++.h> 
    using namespace std; 
    
    int fun(int ptr[]) 
    { 
        int x = 10; 
        
        // Size of a pointer is printed 
        cout << "sizeof(ptr) = " 
            << (int)sizeof(*ptr)  
            << endl; 
    
        // This allowed because ptr is a  
        // pointer, not array 
        ptr = &x; 
    
        cout <<"*ptr =  " << *ptr; 
    
        return 0; 
    } 
    
    // Driver code 
    int main() 
    { 
        int arr[] = { 10, 20, 30, 40, 50, 60 }; 
        
        // Size of a array is printed 
        cout << "sizeof(arr) = " 
            << (int)sizeof(arr) 
            << endl; 
            
        fun(arr); 
        
        return 0; 
    } 
    //sizeof(arr) = 24
    //sizeof(ptr) = 4
    //*ptr = 10 
    ```
- Note: Pointer arithmetic is meaningless unless performed on an array.

## Return pointer
- benim bilidğim 4 farklı şekilde array pointeri döndürebilirz. örnekleri en sonda. ve fonksiyonlar bölümünde.
    - pass by pointer dışarıdan gelen değerler
    - pass by value dışarıdan gelen değerler
    - static array içeride oluşturulan array(örnekler hem burada hem static not static de var )
    - memory allocation içeride oluşturulan array
    - aynısı char arrayleri içinde geçerli olması lazım

## Advanced Pointer Notation
- C++ programlama dilinde "pointer to pointers" veya "double pointers" olarak adlandırılan yapı, bir pointer'ın başka bir pointer'ın adresini tutmasıdır. Bu konsept, bellek yönetimini dinamik olarak yapmak veya pointer dizileri üzerinde işlem yapmak gibi durumlarda oldukça kullanışlıdır. Pointer to pointers (iki katlı pointerlar), daha ileri seviye C++ programlamada özellikle karmaşık veri yapıları veya dinamik bellek yönetimiyle uğraşırken önemli bir kavramdır.

### Pointer to Pointers 
- C++'da, bir pointer to pointer (veya double pointer) iki tane asterisk (**) kullanılarak tanımlanır. Bu tür bir pointer, başka bir pointer'ın bellek adresini tutar ve bu adres aracılığıyla dolaylı olarak bellekteki veriye erişim sağlar.
    ```cpp
    int** ptr_to_ptr;
    ```
    - Burada ptr_to_ptr, bir int* pointer'ının adresini tutan bir double pointer'dır.

- Kullanım Senaryoları:
    - Pointer to Pointers ile Dinamik Bellek Yönetimi:
    - Fonksiyon Parametreleri ile Kullanım:
    - Çok Boyutlu Dizilerle Çalışma(string arrays):
    - returning pointer to pointer variable

## Pointers and String literals
- String Literals (Dize Sabitleri): Dize sabitleri (string literals), C ve C++ gibi dillerde kullanılan sabit karakter dizileridir. Dize sabitleri çift tırnak içinde belirtilirler ve bellekte programın kod segmentinde (read-only bellek bölgesinde) saklanırlar. Dize sabitleri değiştirilemezler (immutable) ve program çalışma zamanında değiştirilmemelidir. (önemli bilgi değiştrebilmek için özel fonksiyonlar kullanmamız gerekiyor)

- normal (statik veya otomatik) dizilerde, dizi ismi bir işaretçiye dönüşür ve ilk elemanın adresini temsil eder. Ancak std::cout kullanırken, bir karakter dizisini doğrudan yazdırmak istediğinizde, işaretçinin işaret ettiği dizenin tamamı yazdırılır (null karakterine kadar).(Stringlere veya character stringlerine özel)

## Void Pointers
- void işaretçiler (void pointers), C ve C++ gibi dillerde kullanılan özel işaretçi türleridir. void işaretçiler, herhangi bir türdeki veriyi gösteren genel bir işaretçi türüdür ve verinin türünü belirtmez. Bu nedenle, herhangi bir veri türünden işaretçileri void işaretçileriyle tutabilir ve geçirebilirsiniz.

- void işaretçileri, özellikle belirli bir türle ilgili olmayan veya birden fazla veri türüyle çalışmak istediğiniz durumlarda kullanışlıdır. Bu işaretçiler, genellikle bellek tahsisi ve serbest bırakma fonksiyonları gibi daha genel işlevlerle kullanılır.

- This is a special type of pointer available in C++ which represents the absence of type. Void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties). This means that void pointers have great flexibility as they can point to any data type. There is a payoff for this flexibility. These pointers cannot be directly dereferenced. They have to be first transformed into some other pointer type that points to a concrete data type before being dereferenced. 
- Note: Void pointers cannot be dereferenced. It can however be done using typecasting the void pointer. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

## nullptr
- nullptr ve normal bir pointer arasındaki farkları anlamak için öncelikle normal bir pointer ve null pointer (null işaretçi) kavramlarını açıklamak gerekmektedir.
- Normal Pointer: C++ dilinde bir işaretçi (pointer), bir değişkenin bellek adresini tutan bir değişkendir. İşaretçiler, * operatörüyle derecelendirilir ve bu operatör, işaretçinin gösterdiği bellek adresindeki değeri döndürür. 
    ```cpp
    int value = 42;
    int* ptr = &value;  // ptr, 'value' değişkeninin bellek adresini tutar
    std::cout << *ptr;   // ptr'nin gösterdiği bellek adresindeki değeri yazdırır (42)
    ```
- Null Pointer: Null pointer (null işaretçi), bir işaretçinin hiçbir şeyi göstermediğini ifade eden özel bir değerdir. Normal bir işaretçi, bir nesnenin bellek adresini tutarken, null pointer herhangi bir nesneyi göstermez. C++ dilinde null pointer, nullptr anahtar kelimesi ile temsil edilir. 
    ```cpp
    int* ptr = nullptr;  // Null pointer tanımı
    ```
    - Bu tanım, ptr isimli işaretçinin hiçbir şeyi göstermediğini belirtir.
- nullptr ve Null Pointer Farkı: nullptr C++11 standardıyla birlikte tanıtılmıştır ve C++'ın önceki versiyonlarında kullanılan NULL veya 0 ile karşılaştırıldığında daha güvenli bir alternatiftir. nullptr, bir işaretçinin null olduğunu belirtir ve sadece işaretçilere özgü bir değerdir. Önceki C++ versiyonlarında, NULL veya 0 kullanılarak null pointer ifade edilirdi, ancak bu yaklaşım bazı durumlarda sorunlara yol açabilirdi (örneğin, işaretçi ve tamsayıların karıştırılması).
    ```cpp
    //new
    int* ptr = nullptr;

    //old
    int* ptr = NULL;
    // veya
    int* ptr = 0;
    ```
- Kısacası, nullptr, C++'ın null pointer kavramını güvenli ve standart bir şekilde temsil eden özel bir anahtar kelimedir. Bu, işaretçilerle ilgili kodun daha okunabilir ve güvenli olmasını sağlar.
- Eğer bir işaretçi (pointer) değişkenini başlangıç değeri vermeden tanımlarsanız (örneğin int *ptr;), o değişkenin değeri rastgele olacaktır. İşaretçi değişkeni başlangıçta herhangi bir belirli bellek adresini göstermeyecektir. Bu durumda, bu işaretçiyi kullanarak bellek üzerindeki değerlere erişmeye çalışmak veya dereferans yapmak (yani *ptr) tanımsız davranışlara (undefined behavior) neden olabilir.

### NULL and nullptr
- NULL ve nullptr C++ programlama dilinde farklı amaçlar için kullanılan iki farklı değerdir.
1. NULL
    - NULL, genellikle C dilinden gelen bir makro tanımıdır.
    - NULL, tam olarak 0 olarak tanımlanır. Bazı durumlarda beklenmedik davranışlara neden olabilir. Örneğin, bir tam sayı ile karşılaştırılırsa, 0 olan NULL işaretçisi olarak yorumlanabilir.
    - NULL, bir işaretçinin (pointer) boş olduğunu veya hiçbir nesneyi göstermediğini belirtmek için kullanılır.
    - Ancak C++ dilinde NULL kullanımı, modern C++ standartlarında önerilmemektedir. Bunun yerine nullptr tercih edilmektedir.
        ```cpp
        int *ptr = NULL; // İşaretçi başlangıçta hiçbir nesneyi göstermiyor
        ```
2. nullptr
    - nullptr, C++11 standartlarıyla birlikte C++ diline eklenen özel bir anahtar sözcüktür.
    - nullptr, bir null pointer değerini ifade eder.
    - nullptr, işaretçi (pointer) türündeki değişkenlerde kullanılır ve hiçbir nesneyi göstermediğini belirtmek için tercih edilir.
    - nullptr, tür güvenliği sağlar; yani nullptr'ı bir işaretçiye atamak, C dilindeki NULL'un yanlış kullanımlarını engeller.
        ```cpp
        int *ptr = nullptr; // İşaretçi başlangıçta hiçbir nesneyi göstermiyor
        ```
### extra about NULL
- C++ dilinde, null değeri yalnızca işaretçiler (pointers) için anlamlıdır ve kullanılabilir. Null değeri, işaretçilerin belirli bir nesneye (hedefe) işaret etmediği veya geçersiz olduğu durumları ifade etmek için kullanılır. Diğer veri tipleri veya nesneler için "null" bir kavramları yoktur.
- Diğer veri tipleri (int, float, char, bool, vs.) için "null" bir değer tanımı yoktur.
- Örneğin, bir int veya float değişkeni için "null" değeri yoktur. Bu türler için bir değer atanmadığında, değerleri tanımsız veya rastgele olabilir.

    ```cpp
    int x; // Tanımsız değer, "null" değil
    float f; // Tanımsız değer, "null" değil
    ```
- Sonuç olarak, C++ dilinde "null" kavramı yalnızca işaretçiler (pointers) için geçerlidir. Diğer veri tipleri veya nesneler için "null" bir değer tanımı yoktur ve bunlar "tanımsız" veya "belirsiz" olabilirler. İşaretçilerin dışında, diğer veri tipleri veya nesneler için "null" kavramı geçerli değildir.

- Tanımsız (Undefined):
    - Bir değişkenin veya nesnenin "tanımsız" olması, o değişkenin veya nesnenin bir değere sahip olmaması veya ne olduğunun belirsiz olması anlamına gelir.
    - C++ dilinde, bir değişken tanımlanırken başlangıç değeri atanmadığında, bu değişkenin "tanımsız" olduğu söylenir.
    - Tanımsız değişkenlerin değeri tahmin edilemez ve kullanıldıklarında istenmeyen davranışlara neden olabilirler.
- Belirsiz (Indeterminate):
    - "Belirsiz" kavramı, değişkenin veya nesnenin başlangıç değerinin belirsiz veya tanımlanamaz olduğu durumu ifade eder.
    - Belirsiz değişkenlerin değeri, programcının kontrolü dışında rastgele veya tahmin edilemez olabilir.
        ```cpp
        int x; // x isimli değişken tanımlı, ancak başlangıç değeri atanmadığı için "tanımsız"
        std::cout << x; // "x" değişkeni tanımsız olduğu için bu ifade istenmeyen sonuçlar verebilir
        ```
## Invalid pointers
- "Invalid pointer" terimi, genellikle programlama dillerinde veya bellek yönetiminde kullanılan bir terimdir ve geçersiz veya tanımsız bir bellek adresini ifade eder. Bir işaretçi (pointer) geçersiz olduğunda, işaret ettiği bellek alanı programın tanımlı davranışını aşar veya beklenmeyen sonuçlara yol açabilir.
    - Dangling Pointers (Sarkan İşaretçiler): Bellek alanı serbest bırakıldıktan sonra (örneğin delete kullanılarak), işaretçi hâlâ bu bellek alanını göstermeye devam eder. Bu durumda, işaretçi geçersizdir ve bu işaretçiyle bellek alanına erişmeye çalışmak tanımsız davranışa neden olur.
        - ex1
            ```cpp
            int* ptr = new int(5);
            delete ptr;  // Bellek serbest bırakıldı
            *ptr = 10;   // Geçersiz işlem, çünkü ptr artık geçersizdir
            ```
        - ex2, Function Call: When the local variable is not static and the function returns a pointer to that local variable. The pointer pointing to the local variable becomes dangling pointer.
        - The below example demonstrates a dangling pointer when the local variable is not static. burad abu kod çalışır ama istediğimiz gibi çalışmöaz çünkü işaret ettiği yer artık ulaşılabilir değil saçma sonuçlar verir
            ```cpp
            // C program to demonstrate the pointer pointing to local
            // variable becomes dangling when local variable is not
            // static.
            #include <stdio.h>
            
            int* fun()
            {
                // x is local variable and goes out of
                // scope after an execution of fun() is
                // over.
                int x = 5;
            
                return &x;
            }
            
            // Driver Code
            int main()
            {
                int* p = fun();
                fflush(stdin);
            
                // p points to something which is not
                // valid anymore
                printf("%d", *p);
                return 0;
            }
            //output 0
            
            ```
            - In the above example, p becomes dangling as the local variable (x) is destroyed as soon as the value is returned by the pointer. This can be solved by declaring the variable x as a static variable as shown in the below example. illa malloc veya new kullanmaya gerek yok yani.

            ```cpp
            // The pointer pointing to local variable doesn't
            // become dangling when local variable is static.
            #include <stdio.h>
            
            int* fun()
            {
                // x now has scope throughout the program
                static int x = 5;
            
                return &x;
            }
            
            int main()
            {
                int* p = fun();
                fflush(stdin);
            
                // Not a dangling pointer as it points
                // to static variable.
                printf("%d", *p);
            }

            // output 5
            ```

    - Wild Pointers (Savruk İşaretçiler): Başlangıçta hiçbir bellek alanını göstermeyen veya tanımsız bir bellek alanını gösteren işaretçilere denir. Bunlar genellikle başlatılmamış veya tanımlanmamış işaretçiler olabilir.
        ```cpp
        int* ptr;    // Başlangıçta tanımsız bir değer içerir (wild pointer)
        *ptr = 10;   // Geçersiz işlem, çünkü ptr hâlâ tanımsızdır
        ```
    - NULL Pointer Dereferencing (NULL İşaretçiye Erişim): Bir işaretçi NULL değerini gösteriyorsa ve bu işaretçiye erişilmeye çalışılırsa, bu geçersiz bir işlemdir ve çoğu durumda programın çökmesine veya hata vermesine neden olur.
        ```cpp
        int* ptr = nullptr;
        *ptr = 10;   // Geçersiz işlem, çünkü ptr NULL'a işaret ediyor
        ```
    - Scope Dışında Kalmış İşaretçiler: Bir işaretçi, sahip olduğu değişkenin kapsamı dışına çıktığında geçersiz hale gelebilir. Bu durumda, işaretçi hâlâ eski bellek alanını gösterir, ancak bu alan artık geçerli değildir.
        ```cpp
        int* ptr;
        {
            int value = 42;
            ptr = &value;
        }  // value'nun kapsamı burada sona erer
        *ptr = 10;  // Geçersiz işlem, çünkü ptr artık geçerli bir bellek alanını göstermiyor
        ```
    - Geçersiz Bellek Yönetimi: Bellek yönetimi işlemleri sırasında hata yapılması (örneğin, yanlış bellek alanını serbest bırakmak veya aynı bellek alanını birden fazla kez serbest bırakmak) sonucu işaretçiler geçersiz hale gelebilir.
        ```cpp
        int *ptr1 = 0;
        int *ptr2 = NULL;
        ```
## Advantages of Pointers
- Pointers reduce the code and improve performance. They are used to retrieve strings, trees, arrays, structures, and functions.
- Pointers allow us to return multiple values from functions.
    ```cpp
    #include <iostream>

    // Function to calculate sum and product of two numbers
    void calculateSumAndProduct(int a, int b, int* sumResult, int productResult) {
        *sumResult = a + b;       // Store sum in sumResult pointer
        *productResult = a * b;   // Store product in productResult pointer
    }

    int main() {
        int x = 5, y = 3;
        int sum, product;

        // Call the function and pass pointers to sum and product variables
        calculateSumAndProduct(x, y, &sum, &product);

        // Display the results
        std::cout << "Sum: " << sum << std::endl;
        std::cout << "Product: " << product << std::endl;

        return 0;
    }
    ```
- In addition to this, pointers allow us to access a memory location in the computer’s memory.

# References 
- Referanslar (references), C++ programlama dilinde kullanılan ve bir değişkenin başka bir isimle anılmasını sağlayan özel bir yapıdır. Referanslar, bir değişkenin var olan adını başka bir isim altında kullanmamızı sağlar ve bu sayede değişken üzerinde işlem yaparken alternatif bir yol sunar.
    1. **Başka bir isimle erişim sağlar**: Bir referans, bir değişkenin başka bir ismi olarak kullanılır. Bu şekilde, bir değişkene hem asıl adıyla hem de referans adıyla erişilebilir. direkt 10 gibi bir değer atayamayız.
    2. **Bir kez tanımlandıktan sonra değiştirilemez**: Bir referans tanımlandıktan sonra başka bir değişkene veya değere bağlanamaz. Yani, referans bir kez belirli bir değişkeni temsil etmeye başladığında, başka bir değişkene bağlanamaz veya başka bir değere atanamaz.
    3. **Adres operatörü (&) ile tanımlanır**: Bir referans tanımlamak için değişkenin isminin önüne "&" (adres operatörü) eklenir.
- Referanslar özellikle fonksiyonlara parametre geçirirken veya fonksiyonlardan geri dönüş alırken kullanılarak bellek ve performans tasarrufu sağlar. Ayrıca, referanslar C++ dilinde nesne tabanlı programlamada önemli bir yapıdır ve sıklıkla kullanılır.

- Tanımlama: Bir referans, bir değişkenin başka bir ismi olarak tanımlanır. Referanslar adres operatörü (&) kullanılarak tanımlanır. 
- Değişken Erişimi: Referanslar, ilgili değişkenin yerini temsil eder. Yani, referans aracılığıyla değişkenin kendisi değil, içeriği (değeri) erişilir veya değiştirilir.
- Değişkeni İzleme: Bir referans tanımlandığında, ilgili değişkenin başka bir adı haline gelir. Referans üzerinden yapılan herhangi bir değişiklik, asıl değişkene de yansır.
- Fonksiyonlarda Kullanım: Referanslar, fonksiyonlara parametre olarak geçirilirken kullanılır. Bu şekilde, fonksiyonlar üzerinde doğrudan değişkenin kendisi üzerinde işlem yapılabilir, böylece değeri kopyalamak yerine doğrudan orijinal değişken üzerinde çalışılabilir.
- **(Önemli)** referanslar kesinlikle boş başlatılmamalı bir değere initialize ederek başlatılmalıdır. constlar da aynı şekilde.
- referanslara direkt değer atılamaz normalde. ama const olarak tanımlarsan direkt refarans atayabilirsin. const with references kısmına bakabilirsin en altta.
    ```cpp
    int x = 10;
    int& ref = x; // 'ref', 'x' değişkeninin referansı olarak tanımlanıyor

    cout << "x = " << x << endl; // 'x' değişkeninin değeri yazdırılır
    cout << "ref = " << ref << endl; // 'ref', 'x' değişkeninin değerini yansıtır

    ref = 20; // 'ref' üzerinden 'x' değişkeninin değeri 20 olarak değiştirilir
    cout << "x = " << x << endl; // 'x' değişkeninin yeni değeri (20) yazdırılır
    ```
    ```cpp
    //yanlış kullanım
    int& ref = 10;

    int& ref; // Hata: referans oluşturulurken başlatılmalıdır
    ref = 10; // Bu ifade geçersizdir, çünkü ref'in bağlanacağı bir değişken yoktur
    ```
## Return reference
- ayrıntılar fonksiyon bölümünde
## Applications of Reference
- There are multiple applications for references in C++, a few of them are mentioned below:
    - Modify the passed parameters in a function
    - Avoiding a copy of large structures
    - In For Each Loop to modify all objects
    - For Each Loop to avoid the copy of objects

1. Modify the passed parameters in a function: 
    - If a function receives a reference to a variable, it can modify the value of the variable. For example, the following program variables are swapped using references. 

2. Avoiding a copy of large structures: 
    - Imagine a function that has to receive a large object. If we pass it without reference, a new copy of it is created which causes a waste of CPU time and memory. We can use references to avoid this. 

3. In For Each Loop to modify all objects:
    -  We can use references for each loop to modify all elements.

4. For Each Loop to avoid the copy of objects: 
    - We can use references in each loop to avoid a copy of individual objects when objects are large.  

## References vs Pointers
- Both references and pointers can be used to change the local variables of one function inside another function. Both of them can also be used to save copying of big objects when passed as arguments to functions or returned from functions, to get efficiency gain. Despite the above similarities, there are the following differences between references and pointers.

1. A pointer can be declared as void but a reference can never be void For example
    ```cpp
    int a = 10;
    void* aa = &a; // it is valid
    void& ar = a;  // it is not valid
    ```
2. The pointer variable has n-levels/multiple levels of indirection i.e. single-pointer, double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of indirection. The following code reveals the mentioned points

3. Reference variables cannot be updated(yani başka bi veri yazılamaz a verisine referan tnaımldayısan b verisini atayamazsın).

4. Reference variable is an internal pointer.

5. Declaration of a Reference variable is preceded with the ‘&’ symbol ( but do not read it as “address of”).
### extra
- Referanslar (&) ve pointerlar (*) C++ dilinde benzer işlevlere sahip olmakla birlikte, bazı önemli farklar vardır. İşte referanslar ile pointerların ana farkları:
    - Syntax (Sözdizimi):
        - Referanslar: Referanslar, değişkenin tipi önüne & işareti konularak tanımlanır Örneğin: int &ref = variable;
        - Pointerlar: Pointerlar ise değişkenin tipi önüne * işareti konularak tanımlanır. Örneğin: int *ptr = &variable;
    - Null Değer:
        - Referanslar: Referanslar, tanımlandıkları anda bir değişkene bağlanmalıdır. Null değeri alamazlar ve başka bir değişkene yeniden bağlanamazlar.
        - Pointerlar: Pointerlar null değer alabilir ve farklı zamanlarda farklı değişkenlere işaret edebilirler.
    - Dereferans ve Erişim:
        - Referanslar: Referanslar, tanımladıkları değişkenin kendisine başka bir isim verirler. Bu nedenle referans üzerinden doğrudan değişkenin değerlerine ve alanlarına erişilebilir. Dereferans (*) operatörü kullanılmaz.
        - Pointerlar: Pointerlar, bir bellek adresini tutarlar ve bu adresi kullanarak bellekteki verilere erişiriz. Değerlere erişmek için dereferans (*) operatörü kullanılır.
    - Yeniden Atama:
        - Referanslar: Referanslar bir kez tanımlandıktan sonra başka bir değişkene yeniden atanamazlar. Tanımlandıkları değişkenin bir referansı olmaya devam ederler.
        - Pointerlar: Pointerlar başka bir bellek adresine yönlendirilebilir veya null değer alabilirler.
    - Null Referans ve Null Pointer:
        - Referanslar: C++'da null referans kavramı yoktur. Bir referans her zaman bir değişkeni temsil eder.
        - Pointerlar: Pointerlar null değeri alabilir ve bu durumda hiçbir bellek adresine işaret etmezler.
    - Pointer Aritmetiği:
        - Referanslar: Referanslar üzerinde matematiksel işlemler yapılamaz. Bir referans, o referansa bağlanan değişkenin ta kendisidir.
        - Pointerlar: Pointerlar üzerinde aritmetik işlemler yapılabilir. Pointerlar adresleri taşır ve bellekteki farklı konumlara işaret edebilirler.

- rerefernces ler aslında adreslerden yararlanır, sadece  bizlere daha rahat bir yapı sunuyor
### extra - 2
1. Initialization: A pointer can be initialized in this way: We can declare and initialize pointer at same step or in multiple line.
    ```cpp
    int a = 10;
    int *p = &a;
    // OR 
    int *p;
    p = &a;
    ```
2. While in references
    ```cpp
    int a = 10;
    int &p = a; // It is correct
    // but
    int &p;
    p = a; // It is incorrect as we should declare and initialize references at single step
    ```

3. Reassignment: A pointer can be re-assigned. This property is useful for the implementation of data structures like a linked list, a tree, etc. See the following example: 
    ```cpp
    int a = 5;
    int b = 6;
    int *p;
    p = &a;
    p = &b;
    ```
4. On the other hand, a reference cannot be re-assigned, and must be assigned at initialization.
    ```cpp
    int a = 5;
    int b = 6;
    int &p = a;
    int &p = b; // This will throw an error of "multiple declaration is not allowed" normal değer atayabilirsin ama başka bir değişkeni atayamazsın.

    // However it is valid statement,
    int &q = p;
    ```

5. Memory Address: A pointer has its own memory address and size on the stack, whereas a reference shares the same memory address with the original variable and takes up no space on the stack.
    ```cpp
    int &p = a;
    cout << &p << endl << &a;
    ```

6. NULL value: A pointer can be assigned NULL directly, whereas a reference cannot be. The constraints associated with references (no NULL, no reassignment) ensure that the underlying operations do not run into an exception situation.

7. Indirection: You can have a pointer to pointer (known as a double pointer) offering extra levels of indirection, whereas references only offer one level of indirection. 
    ```cpp
    In Pointers,
    int a = 10;
    int *p;
    int **q; // It is valid.
    p = &a;
    q = &p;

    // Whereas in references,
    int &p = a;
    int &&q = p; // It is reference to reference, so it is an error
    ```

8. Arithmetic operations: Various arithmetic operations can be performed on pointers, whereas there is no such thing called Reference Arithmetic (however, you can perform pointer arithmetic on the address of an object pointed to by a reference, as in &obj + 5). 

### When to use What
- The performances are exactly the same as references are implemented internally as pointers. But still, you can keep some points in your mind to decide when to use what:  
- Use references: 
    - In function parameters and return types.
- Use pointers: 
    - If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays (Note that accessing an array is implemented using pointer arithmetic).
    - To implement data structures like a linked list, a tree, etc. and their algorithms. This is so because, in order to point to different cells, we have to use the concept of pointers.

## Limitations of References
- Once a reference is created, it cannot be later made to reference another object; it cannot be reset. This is often done with pointers. 
- References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing. 
-  reference must be initialized when declared. There is no such restriction with pointers.

- Due to the above limitations, references in C++ cannot be used for implementing data structures like Linked List, Tree, etc. In Java, references don’t have the above restrictions and can be used to implement all data structures. References being more powerful in Java is the main reason Java doesn’t need pointers.

## Advantages of using References
- Safer: Since references must be initialized, wild references like wild pointers are unlikely to exist. It is still possible to have references that don’t refer to a valid location
- Easier to use: References don’t need a dereferencing operator to access the value. They can be used like normal variables. The ‘&’ operator is needed only at the time of declaration. Also, members of an object reference can be accessed with the dot operator (‘.’), unlike pointers where the arrow operator (->) is needed to access members.

## Can References Refer to Invalid Location
- Reference Variables: You can create a second name for a variable in C++, which you can use to read or edit the original data contained in that variable. While this may not sound appealing at first, declaring a reference and assigning it a variable allows you to treat the reference as if it were the original variable for the purposes of accessing and modifying the value of the original variable
- even if the second name (the reference) is in a different scope. This means that if you make your function arguments references, you’ll be able to essentially change the data given into the function. This is in contrast to how C++ generally works, in which function parameters are copied into new variables. It also helps to save time.(rakes refernce variables funciton)
- In C++, Reference variables are safer than pointers because reference variables must be initialized and they cannot be changed to refer to something else once they are initialized. But there are exceptions where we can have invalid references.

1. Reference to Value at the Uninitialized Pointer
    ```cpp
    int *ptr;
    int &ref = *ptr; // Reference to value at 
                 // some random memory location
    ```
2. Reference to a Local Variable is Returned
    ```cpp
    int& fun() {
    int a = 10;
    return a;
    }
    ```
    - Once fun() returns, the space allocated to it on the stack frame will be taken back. So the reference to a local variable will not be valid.
    - bu fonksiyon düzgün çalışmaz çünkü local veri yok olacaktır. doğru kullanımı aşağıdaki gibidir
    - static değişkenin referansını döndürürsek artık o fonksiyonun içindeki static veriye dışarıdan da ulaşabilir oluyoruz. aynısını pointerlar ile de yapabilirsin.
        ```cpp
        int& fun() {
            static int a = 10; // static olarak tanımlanmış bir değişken kullanılıyor
            return a; // static değişkenin referansını döndürüyor
        }
        ```
## When do we pass arguments by pointer?
- To Modify Local Variables of the Function
    - A pointer allows the called function to modify a local variable of the caller function.

- For Passing Large-Sized Arguments
    - If an argument is large, the pass-by pointer is more efficient because only an address is really passed, not the entire object.

- To Achieve Run Time Polymorphism in a Function
    - We can make a function polymorphic by passing objects as a pointer to it.

- To Return Multiple Values
    - When you want to return multiple values from a function, passing pointers as function parameters allows us to modify the values of variables passed to the function.

- To Modify the Content of Dynamically Allocated Memory.
    - By passing arguments by pointer to a function we can do modification in the content of dynamically allocated memory. It is mainly used when you want to allocate memory dynamically (by using functions like malloc, calloc, or realloc).
    
## const with pointers
- const anahtar kelimesinin pointer (işaretçi) ile kullanımı, işaretçinin ve işaret ettiği değerin değiştirilebilirliği konusunda önemli farklar yaratır. Aşağıda, const anahtar kelimesinin pointer ile farklı kullanımlarını ve anlamlarını açıklayan örnekler bulunmaktadır.
1. const Değişkenler
Bir değişkeni const olarak tanımlamak, bu değişkenin değerinin değiştirilemez olduğunu belirtir.
2. Sabit Bir Değeri İşaret Eden Değiştirilebilir Pointer (Pointer to const)
    - Bu kullanımda, pointer (işaretçi) değiştirilebilir, ancak işaret ettiği değerin değiştirilmesine izin verilmez. (tutulan pointer aracılığı ile)
    ```cpp
    const int* ptr;
    int a = 5;
    int b = 10;

    ptr = &a; // ptr'yi a'ya işaret ettik
    ptr = &b; // ptr'yi b'ye işaret ettik

    // *ptr = 15; // Hata: ptr'nin işaret ettiği değeri değiştiremezsiniz
    ```
3. Sabit Pointer (const Pointer)
    - Bu kullanımda, pointerın kendisi sabittir ve başka bir adresi işaret edemez, ancak işaret ettiği değerin değiştirilmesine izin verir. (tutulan pointer aracılığı ile)
    ```cpp
    int* const ptr = &a; // ptr'yi a'ya işaret eden sabit pointer olarak tanımladık

    *ptr = 20; // ptr'nin işaret ettiği değeri değiştirebiliriz
    // ptr = &b; // Hata: ptr'yi başka bir adresi işaret edecek şekilde değiştiremeyiz
    ```
4. Sabit Bir Değeri İşaret Eden Sabit Pointer (const Pointer to const)
    - Bu kullanımda, pointer da sabittir ve işaret ettiği değer de sabittir. Hem pointerın adresi hem de işaret ettiği değer değiştirilemez. 
    
    ```cpp
    const int* const ptr = &a; // ptr, a'ya işaret eden sabit bir pointerdır ve a'nın değeri değiştirilemez

    // *ptr = 20; // Hata: ptr'nin işaret ettiği değeri değiştiremeyiz
    // ptr = &b; // Hata: ptr'yi başka bir adresi işaret edecek şekilde değiştiremeyiz
    ```


## const with references
- const Referanslar
    - const referanslar, referans alınan değerin değiştirilmesini engeller. Bu, geçici değerlere (temporary values), literal sabitlere ve değişkenlere referans oluşturmaya olanak tanır. const referansların bazı önemli özellikleri şunlardır:
    - Geçici Değerlerle Kullanım:
        - const referanslar, geçici değerlere bağlanabilir ve onların ömrünü referansın ömrü boyunca uzatır.
            ```cpp
            #include <iostream>

            int main() {
                const int& ref = 10; // Geçici değere const referans
                std::cout << "Value of ref: " << ref << std::endl; // 10

                // ref = 20; // Derleme hatası: const referans ile işaret edilen değer değiştirilemez
                return 0;
            }
            ```

    - const refeerence:
        - Sabit değerlere referans oluşturabilir ve onların değiştirilemezliğini korur.
            ```cpp
            #include <iostream>

            int main() {
                int a = 20;
                const int& ref = a; // Değişkene const referans

                std::cout << "Value of ref: " << ref << std::endl; // 20

                // ref = 30; // Derleme hatası: const referans ile işaret edilen değer değiştirilemez
                a = 30; // Geçerli: a'nın değeri değiştirilebilir
                std::cout << "New value of a: " << a << std::endl; // 30
                std::cout << "Value of ref: " << ref << std::endl; // 30

                return 0;
            }
            ```
        - Bu örnekte, const int& ref = a; ifadesi a değişkenine const referans oluşturur. ref aracılığıyla a'nın değeri değiştirilemez, ancak a'nın kendisi doğrudan değiştirilebilir. 

    - Fonksiyon Parametreleri:
        - Büyük veri yapıları veya objeler için fonksiyon parametresi olarak kullanılabilir, böylece kopyalama maliyetinden kaçınılır ve verinin değiştirilemezliği garanti edilir.
            ```cpp
            #include <iostream>

            void printValue(const int& value) {
                std::cout << "Value: " << value << std::endl;
            }

            int main() {
                int a = 40;
                printValue(a); // Değişken ile çalışır
                printValue(50); // Geçici değer ile çalışır

                return 0;
            }
            ```
    - sabitlere reference: const bir değişkene referans olabilnmek için referansında const olması lazım.
        ```cpp
        #include <iostream>

        int main() {
            const int a = 10;       // a bir const değişken
            const int& ref = a;     // ref, a'nın const referansı
            // int& ref2 = a;       // Derleme hatası: const olmayan referans, const bir değişkene bağlanamaz

            std::cout << "Value of a: " << a << std::endl;       // 10
            std::cout << "Value of ref: " << ref << std::endl;   // 10

            // ref = 20; // Derleme hatası: const referans ile işaret edilen değer değiştirilemez

            return 0;
        }
        ```
