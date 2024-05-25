# Dynamic Memory Management
-  Dinamik bellek tahsisi (dynamic memory allocation), programın çalışma zamanında (runtime) bellek bloğu ayırma işlemidir. Bu, programın statik bellek tahsisi sırasında (derleme zamanında) ihtiyaç duyulan bellek miktarını bilmediği durumlarda özellikle faydalıdır. Dinamik bellek tahsisi, bellek kullanımını daha esnek ve verimli hale getirir, çünkü bellek miktarı programın çalışma zamanındaki ihtiyaçlarına göre ayarlanabilir. Hesap de bellek ayırır.

- memory i daha efektif kullanabiliyoruz. Mesela normal şekilde veri oluşturudğumuzda program bitene kadar veri silinmiyor. ama dynamic oluşturunca biz direkt silip hafızayı daha efektif kullanmış oluyoruz.

- Stack: Fonksiyon çağrıları ve yerel değişkenler için kullanılan bellek bölgesidir. Bellek tahsisi ve serbest bırakma işlemleri LIFO (Last In, First Out) düzeninde otomatik olarak yönetilir.
- Heap: Dinamik bellek tahsisi için kullanılan bellek bölgesidir. Bellek, programcı tarafından yönetilir ve malloc, calloc, realloc, free (C için) veya new, delete (C++ için) fonksiyonları/operatörleri ile tahsis ve serbest bırakma işlemleri yapılır.

### Kullanım Alanları
- Esnek Veri Yapıları
    - Bağlantılı Listeler (Linked Lists):
        - Dinamik bellek tahsisi, düğümler arasında bağlantılar kurarak veri yapısının esnek bir şekilde büyümesini sağlar.
    - Ağaçlar (Trees):
        - İkili ağaçlar, AVL ağaçları, kırmızı-siyah ağaçlar gibi veri yapılarında her düğüm dinamik olarak tahsis edilir.
    - Grafikler (Graphs):
        - Grafikteki düğümler ve kenarlar dinamik olarak tahsis edilerek, esnek ve değiştirilebilir grafik yapıları oluşturulur.
- Büyük Verilerin Yönetimi
    - Diziler (Arrays):
        - Büyük ve değişken boyutlu diziler dinamik olarak tahsis edilerek, programın çalışma zamanındaki bellek gereksinimlerine uyum sağlanır. 
        - Aynı zamanda fonksiyon içinden array döndürükende kullanılabilir. Local oluşturulan arrayleri döndüremiyoruz çünkü

## Content
- [Dynamic Memory Allocation in C](#dynamic-memory-allocation-in-c)
    - [malloc](#malloc)
    - [calloc](#calloc)
    - [free](#free)
    - [realloc](#realloc)
- [Dynamic Memory Allocation in Cpp](#dynamic-memory-allocation-in-cpp)
    - [new and delete operator](#new-and-delete-operator)
- [Differences new and malloc](#differences-new-and-malloc)
- [Memory Leaks](#memory-leaks)
- [Difference between Static and Dynamic Memory Allocation](#difference-between-static-and-dynamic-memory-allocation)

## Dynamic Memory Allocation in C
- Since C is a structured language, it has some fixed rules for programming. One of them includes changing the size of an array. An array is a collection of items stored at contiguous memory locations. 
    - think about an array with size 9.
        - if there is a situation where only 5 elements are needed to be entered in this array. In this case, the remaining 4 indices are just wasting memory in this array. So there is a requirement to lessen the length (size) of the array from 9 to 5.
        - Take another situation. In this, there is an array of 9 elements with all 9 indices filled. But there is a need to enter 3 more elements in this array. In this case, 3 indices more are required. So the length (size) of the array needs to be changed from 9 to 12.

- This procedure is referred to as Dynamic Memory Allocation in C.
- Therefore, C Dynamic Memory Allocation can be defined as a procedure in which the size of a data structure (like Array) is changed during the runtime.
- C provides some functions to achieve these tasks. There are 4 library functions provided by C defined under <stdlib.h> header file to facilitate dynamic memory allocation in C programming. 
    - malloc()
    - calloc()
    - free()
    - realloc()

## malloc
- C malloc() method
    - The “malloc” or “memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size. It returns a pointer of type void which can be cast into a pointer of any form. It doesn’t Initialize memory at execution time so that it has initialized each block with the default garbage value initially. 
    ```c
    //ptr = (cast-type*) malloc(byte-size)
    ptr = (int*) malloc(100 * sizeof(int));
    ```
        - Since the size of int is 4 bytes, this statement will allocate 400 bytes of memory. And, the pointer ptr holds the address of the first byte in the allocated memory.
    - If space is insufficient, allocation fails and returns a NULL pointer.

    - malloc_ex: int türüne cast ettik o yüzden ayırdığı alanları 4 er li 4 er li görüyoruz(pointer arithmetic)
    - default elemanlar garbage.

## calloc
- “calloc” or “contiguous allocation” method in C is used to dynamically allocate the specified number of blocks of memory of the specified type. it is very much similar to malloc() but has two different points and these are:
- It initializes each block with a default value ‘0’.
- It has two parameters or arguments as compare to malloc().
- malloc la neredeyse aynı. biz eleman sayısıyla çarpıyorduk burda ise parametre olarak ekliyoruz. birde default eleman 0
    ```c
    //ptr = (cast-type*)calloc(n, element-size);
    //here, n is the no. of elements and element-size is the size of each element.
    ptr = (float*) calloc(25, sizeof(float));
    //This statement allocates contiguous space in memory for 25 elements each with the size of the float.
    ```
    - If space is insufficient, allocation fails and returns a NULL pointer.

## free
- C free() method
    - “free” method in C is used to dynamically de-allocate the memory. The memory allocated using functions malloc() and calloc() is not de-allocated on their own. Hence the free() method is used, whenever the dynamic memory allocation takes place. It helps to reduce wastage of memory by freeing it.

## realloc
- C realloc() method
    - “realloc” or “re-allocation” method in C is used to dynamically change the memory allocation of a previously allocated memory. In other words, if the memory previously allocated with the help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory. re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.

## Dynamic Memory Allocation in Cpp
- Dynamic memory allocation in C/C++ refers to performing memory allocation manually by a programmer. Dynamically allocated memory is allocated on Heap, and non-static and local variables get memory allocated on Stack.
- One use of dynamically allocated memory is to allocate memory of variable size, which is not possible with compiler allocated memory except for variable-length arrays.
- The most important use is the flexibility provided to programmers. We are free to allocate and deallocate memory whenever we need it and whenever we don’t need it anymore. There are many cases where this flexibility helps. Examples of such cases are Linked List, Tree, etc.
- How is it different from memory allocated to normal variables?
    - For normal variables like “int a”, “char str[10]”, etc, memory is automatically allocated and deallocated. For dynamically allocated memory like “int *p = new int[10]”, it is the programmer’s responsibility to deallocate memory when no longer needed. If the programmer doesn’t deallocate memory, it causes a memory leak (memory is not deallocated until the program terminates).
- How is memory allocated/deallocated in C++? 
    - C uses the malloc() and calloc() function to allocate memory dynamically at run time and uses a free() function to free dynamically allocated memory. C++ supports these functions and also has two operators new and delete, that perform the task of allocating and freeing the memory in a better and easier way.
## new and delete operator
- The new operator denotes a request for memory allocation on the Free Store. If sufficient memory is available, a new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable. 
- Syntax to use new operator
    ```cpp
    pointer-variable = new data-type;
    ```
- Here, the pointer variable is the pointer of type data-type. Data type could be any built-in data type including array or any user-defined data type including structure and class. 
- basic data types
    ```cpp
    // Pointer initialized with NULL
    // Then request memory for the variable
    int *p = NULL; 
    p = new int;   

                OR

    // Combine declaration of pointer 
    // and their assignment
    int *p = new int;
    ```
- Arrays
- Class and Structure. Consturctor olması lazım bunlarda kullanabilmek için. Genellikle olur yani.
- Yeniden alan tahsis etme yok realloc için onun için aiağıdaki gibi bir yöntem izleyebilirsin. aynı pointerin üzerine tekrar new ile yazmak memory leaks e sebeb olcuaktır(kayıp pointer aşağıda anlattık)
    ```cpp
    #include <iostream>
    #include <algorithm> // std::copy için gerekli

    int main() {
        // Başlangıçta küçük bir dizi tahsis et
        int* array = new int[5];
        int size = 5;

        // Diziyi bazı değerlerle doldur
        for (int i = 0; i < size; ++i) {
            array[i] = i * 10;
        }

        // Diziyi yazdır
        std::cout << "Original array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        // Diziyi yeniden boyutlandırmak istiyoruz (büyütmek)
        int newSize = 10;
        int* newArray = new int[newSize];

        // Eski dizinin elemanlarını yeni diziye kopyala
        std::copy(array, array + size, newArray);

        // Yeni elemanlara başlangıç değeri ver (optional)
        for (int i = size; i < newSize; ++i) {
            newArray[i] = i * 10; // veya başka bir başlangıç değeri
        }

        // Eski dizinin belleğini serbest bırak
        delete[] array;

        // Yeni diziye işaretçiyi ata
        array = newArray;
        size = newSize;

        // Yeni diziyi yazdır
        std::cout << "Resized array: ";
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        // Belleği serbest bırak
        delete[] array;

        return 0;
    }
    ```

## What if enough memory is not available during runtime?
- nothrow sürümü, bellek tahsisi başarısız olduğunda std::bad_alloc istisnası fırlatmak yerine nullptr döner. Bu şekilde, bellek tahsisinin başarısız olup olmadığını kontrol etmek daha kolay olabilir.

## Differences new and malloc
- new ve malloc operatörleri C++'ta dinamik bellek tahsisi için kullanılır, ancak aralarında önemli farklar vardır. Bu farklar, özellikle nesne yönelimli programlama ve C++ dilinin özellikleriyle ilgilidir.
### new ve delete
- Bellek Tahsisi: new operatörü, belirli bir türde bir nesne veya dizi için bellek tahsis eder ve bu bellek bloğunun başlangıç adresini döner.
- Başlatma (Initialization): new, tahsis edilen belleği başlatır. Temel veri türleri için varsayılan değerle başlatılırken, sınıf nesneleri için yapıcı (constructor) çağrılır.
- Tür Güvenliği: new operatörü tür güvenlidir. Bellek tahsisi yapılan tür otomatik olarak belirlenir ve döndürülen işaretçi bu türe cast edilmez.
- Özel Durumlar (Exceptions): new operatörü bellek tahsisi başarısız olursa std::bad_alloc istisnası fırlatır. std::nothrow seçeneği kullanılarak bu davranış değiştirilebilir.
- Belleği Serbest Bırakma: delete operatörü, new ile tahsis edilen belleği serbest bırakır ve sınıf nesneleri için yıkıcı (destructor) çağrılır.
    ```cpp
    #include <iostream>
    #include <new> // std::nothrow için gerekli

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

    int main() {
        // Tek bir nesne için bellek tahsisi
        MyClass* obj = new MyClass(); // Constructor çağrılır
        obj->display();

        // Belleği serbest bırakma
        delete obj; // Destructor çağrılır

        // Dizi için bellek tahsisi
        MyClass* arr = new MyClass[3]; // Her bir eleman için constructor çağrılır

        // Belleği serbest bırakma
        delete[] arr; // Her bir eleman için destructor çağrılır

        return 0;
    }

    /*
    Constructor called
    Hello from MyClass!
    Destructor called
    Constructor called
    Constructor called
    Constructor called
    Destructor called
    Destructor called
    Destructor called
    */
    ```

### malloc ve free Kullanımı
- Bellek Tahsisi: malloc fonksiyonu, belirtilen bayt sayısında bellek tahsis eder ve bu bellek bloğunun başlangıç adresini void* türünde döner.
- Başlatma (Initialization): malloc, tahsis edilen belleği başlatmaz. Bellek blokları rastgele değerler içerebilir.
- Tür Güvenliği: malloc tür güvenli değildir. Döndürülen void* işaretçi, uygun türe manuel olarak cast edilmelidir.
- Özel Durumlar (Exceptions): malloc bellek tahsisi başarısız olursa NULL döner. İstisna fırlatmaz.
- Belleği Serbest Bırakma: free fonksiyonu, malloc ile tahsis edilen belleği serbest bırakır. Yıkıcı çağrılmaz çünkü malloc nesne başlatma işlemi yapmaz.

- yani malloc türü önemsemez sadece uygun boşluğu ayarlar. new ise türü önemser ve sadece o tür için alan açar

    ```cpp
    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        int data;
    } MyStruct;

    int main() {
        // Tek bir yapı için bellek tahsisi
        MyStruct* obj = (MyStruct*)malloc(sizeof(MyStruct));
        if (obj == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        obj->data = 42;
        printf("Data: %d\n", obj->data);

        // Belleği serbest bırakma
        free(obj);

        // Dizi için bellek tahsisi
        MyStruct* arr = (MyStruct*)malloc(3 * sizeof(MyStruct));
        if (arr == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        for (int i = 0; i < 3; ++i) {
            arr[i].data = i * 10;
            printf("arr[%d].data = %d\n", i, arr[i].data);
        }

        // Belleği serbest bırakma
        free(arr);

        return 0;
    }
    ```

### `new` ve `delete`
1. **Bellek Tahsisi**: Tür belirterek bellek tahsisi yapar.
2. **Başlatma**: Nesneleri başlatır (constructor çağırır).
3. **Tür Güvenliği**: Tür güvenlidir.
4. **Özel Durumlar (Exceptions)**: Başarısız olursa `std::bad_alloc` fırlatır.
5. **Belleği Serbest Bırakma**: Belleği serbest bırakır ve destructor çağırır.

### `malloc` ve `free`
1. **Bellek Tahsisi**: Belirtilen bayt sayısında bellek tahsisi yapar.
2. **Başlatma**: Belleği başlatmaz (rastgele değerler içerir).
3. **Tür Güvenliği**: Tür güvenli değildir (`void*` döner).
4. **Özel Durumlar (Exceptions)**: Başarısız olursa `NULL` döner.
5. **Belleği Serbest Bırakma**: Belleği serbest bırakır (destructor çağırmaz).

## Memory Leaks
- Bellek sızıntıları (memory leaks), bir programın çalışması sırasında tahsis edilen belleğin serbest bırakılmaması sonucu meydana gelir. Bellek sızıntıları, programın zamanla daha fazla bellek kullanmasına neden olur ve sonunda sistem belleğinin tükenmesine yol açabilir. Bu, programın performansını düşürebilir veya programın çökmesine neden olabilir.

    - Serbest Bırakılmayan Bellek: Bir bellek bloğu dinamik olarak tahsis edilir (malloc, new vb. ile) ancak programın sonunda veya belirli bir noktada free veya delete ile serbest bırakılmazsa, bu bellek bloğu bellek sızıntısına neden olur.
    - Kayıp pointers: Dinamik olarak tahsis edilen belleği gösteren işaretçi üzerine yazılır veya işaretçi başka bir değere atanırsa, orijinal bellek bloğuna erişim kaybolur ve bu bellek serbest bırakılamaz.
        ```cpp
        int* ptr = new int[10];
        ptr = new int[20]; // Önceki bellek bloğuna erişim kaybolur ve sızar
        delete[] ptr;
        ```
    - Karmaşık Veri Yapıları: Karmaşık veri yapıları (bağlantılı listeler, ağaçlar, grafikler vb.) kullanıldığında, her bir düğüm için dinamik olarak tahsis edilen belleğin serbest bırakılması unutulursa bellek sızıntısı oluşabilir.

- Bellek Sızıntılarını Önleme Yöntemleri
    - Bellek Serbest Bırakma:Dinamik olarak tahsis edilen belleği kullanmayı bitirdiğinizde free (C) veya delete / delete[] (C++) kullanarak belleği serbest bırakın.
    - Akıllı İşaretçiler (Smart Pointers): C++'ta akıllı işaretçiler (std::unique_ptr, std::shared_ptr gibi) kullanarak bellek yönetimini otomatik hale getirin. Bu işaretçiler, bellek sızıntılarını önler çünkü bellek otomatik olarak serbest bırakılır.
    ```cpp
    #include <memory>

    void example() {
        std::unique_ptr<int[]> ptr(new int[10]);
        // ... kullan ...
    } // ptr out of scope, bellek otomatik olarak serbest bırakılır
    ```
- RAII (Resource Acquisition Is Initialization):
    - Kaynak edinme ve serbest bırakma işlemlerini bir sınıfın yapıcısı ve yıkıcısı ile yönetin. Bu, kaynak yönetimini daha güvenli hale getirir.
    ```cpp
    class Resource {
    private:
        int* data;
    public:
        Resource(size_t size) {
            data = new int[size];
        }
        ~Resource() {
            delete[] data;
        }
    };
    ```
- Bellek Kontrol Araçları Kullanımı: Bellek sızıntılarını tespit etmek için araçlar kullanın. Örneğin, Valgrind, Dr. Memory ve AddressSanitizer gibi araçlar bellek sızıntılarını ve diğer bellek sorunlarını tespit etmenize yardımcı olabilir.

## Difference between Static and Dynamic Memory Allocation
- Memory Allocation: Memory allocation is a process by which computer programs and services are assigned with physical or virtual memory space. The memory allocation is done either before or at the time of program execution. There are two types of memory allocations: 
    - Compile-time or Static Memory Allocation
    - Run-time or Dynamic Memory Allocation
- Static Memory Allocation: Static Memory is allocated for declared variables by the compiler. The address can be found using the address of operator and can be assigned to a pointer. The memory is allocated during compile time. (Stackda alınan alan)

- Dynamic Memory Allocation: Memory allocation done at the time of execution(run time) is known as dynamic memory allocation. Functions calloc() and malloc() support allocating dynamic memory. In the Dynamic allocation of memory space is allocated by using these functions when the value is returned by functions and assigned to pointer variables.(heap de alınan alan) 

### Static Memory Allocation
1. **Kalıcı Bellek Tahsisi**: Statik bellek tahsisinde, değişkenler programın çalıştığı sürece veya fonksiyon çağrısı bitene kadar kalıcı olarak tahsis edilir.
2. **Programdan Önce Tahsis**: Statik bellek tahsisi program yürütülmeden önce yapılır.
3. **Yığın Kullanımı**: Statik bellek tahsisi yığın (stack) kullanılarak yönetilir.
4. **Verimlilik**: Statik bellek tahsisi daha az verimlidir.
5. **Bellek Yeniden Kullanımı Yok**: Statik bellek tahsisinde bellek yeniden kullanılamaz ve bellek serbest bırakılmaz.
6. **Bellek Boyutu Değişmez**: Bellek tahsisi yapıldıktan sonra bellek boyutu değiştirilemez.
7. **Bellek Yeniden Kullanımı**: Kullanılmayan bellek yeniden kullanılamaz.
8. **Hız**: Statik bellek tahsisi dinamik bellek tahsisine göre daha hızlıdır.
9. **Derleme Zamanında Bellek Tahsisi**: Bellek derleme zamanında tahsis edilir.
10. **Başlangıçtan Sona Kadar Bellek**: Tahsis edilen bellek programın başlangıcından sonuna kadar kalır.
11. **Örnek**: Statik bellek tahsisi genellikle diziler (arrays) için kullanılır.

### Dynamic Memory Allocation
1. **Geçici Bellek Tahsisi**: Dinamik bellek tahsisinde, değişkenler yalnızca program birimi etkin olduğunda tahsis edilir.
2. **Program Sırasında Tahsis**: Dinamik bellek tahsisi program yürütülürken yapılır.
3. **Yığın Kullanımı**: Dinamik bellek tahsisi yığın (heap) kullanılarak yönetilir.
4. **Verimlilik**: Dinamik bellek tahsisi daha verimlidir.
5. **Bellek Yeniden Kullanımı**: Dinamik bellek tahsisinde bellek yeniden kullanılabilir ve gerektiğinde bellek serbest bırakılabilir.
6. **Bellek Boyutu Değişebilir**: Bellek tahsisi yapıldıktan sonra bellek boyutu değiştirilebilir.
7. **Bellek Yeniden Kullanımı**: Kullanılmayan bellek yeniden kullanılabilir. Kullanıcı gerektiğinde daha fazla bellek tahsis edebilir ve gerekmediğinde bellek serbest bırakabilir.
8. **Hız**: Dinamik bellek tahsisi statik bellek tahsisine göre daha yavaştır.
9. **Çalışma Zamanında Bellek Tahsisi**: Bellek çalışma zamanında tahsis edilir.
10. **Herhangi Bir Zaman Bellek Serbest Bırakma**: Tahsis edilen bellek programın herhangi bir anında serbest bırakılabilir.
11. **Örnek**: Dinamik bellek tahsisi genellikle bağlantılı listeler (linked lists) için kullanılır.