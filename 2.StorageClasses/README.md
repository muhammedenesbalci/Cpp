# Storage Classes 
- C++ Storage Classes are used to describe the characteristics of a variable/function. It determines the lifetime, visibility, default value, and storage location which helps us to trace the existence of a particular variable during the runtime of a program. Storage class specifiers are used to specify the storage class for a variable.
- Syntax
    - To specify the storage class for a variable, the following syntax is to be followed:
        ```cpp
        storage_class var_data_type var_name;
        ```
- C++ uses 6 storage classes, which are as follows:

    - auto Storage Class
    - register Storage Class
    - extern Storage Class
    - static Storage Class
    - mutable Storage Class
    - thread_local Storage Class   

## Content
- [auto Storage Clas](#auto-storage-class)
- [extern Storage Class](#extern-storage-class)
- [static Storage Class](#static-storage-class)
- [Differences static and extern](#differences-static-and-extern)
- [register Storage Class](#register-storage-class)
- [mutable Storage Class](#mutable-storage-class)
- [thread_local Storage Class](#thread_local-storage-class)

## auto Storage Class
- The auto storage class is the default class of all the variables declared inside a block. The auto stands for automatic and all the local variables that are declared in a block automatically belong to this class.
- properties of auto Storage Class Objects
    - Scope: Local
    - Default Value: Garbage Value
    - Memory Location: RAM
    - Lifetime: Till the end of its scope
- Note: Earlier in C++, we could use the auto keyword to declare the auto variables explicitly but after C++11, the meaning of auto keyword is changed and we could no longer use it to define the auto variables.

## extern Storage Class
- farklı dosyalardaki değişkenlere veya fonksiyonlara ulaşmak istiyorsak bunu kullanmalıyız
- değişkenin değerini değiştirebiliyoruz ve son hali kalıyor
- C++ programında, farklı dosyalardaki değişkenlere veya fonksiyonlara erişmek için extern anahtar kelimesi kullanılabilir. Bu şekilde, bir dosyada tanımlanan ve başka bir dosyada kullanılacak olan değişken veya fonksiyonun bildirimi (declaration) yapılarak, program derlenirken bu değişkenin veya fonksiyonun başka dosyalardaki tanımına referans verilir.
    1. Değişkenin Tanımı (Definition):
        - İlk olarak, bir dosyada değişkeni tanımlamalısınız. Bu tanım, değişkenin bellekteki yerini ayrıştırır. Örnek olarak:
            ```cpp
            // my_variable.cpp
            int my_variable = 42; // Değişken tanımı
            ```
    2. Değişkenin Bildirimi (Declaration):
        - Diğer dosyalarda (örneğin başka bir .cpp veya .h dosyasında), değişkenin bildirimi (extern anahtar kelimesi ile) yapılmalıdır. Bu, değişkenin başka bir yerde tanımlandığını ve kullanılabileceğini belirtir.
            ```cpp
            // other_file.cpp veya other_file.h
            extern int my_variable; // Değişken bildirimi
            ```
    3. Değişken Kullanımı:
        - Artık extern ile bildirilen değişkeni diğer dosyalarda kullanabilirsiniz. Derleyici, bu değişkenin tanımını (definition) bildirildiği dosyada bulacaktır.
            ```cpp
            // other_file.cpp veya other_file.h
            #include <iostream>

            extern int my_variable; // Değişken bildirimi

            void usage_of_my_variable() {
                std::cout << "Value of my_variable: " << my_variable << std::endl;
            }
            ```
- Yukarıdaki örnekte, my_variable değişkeni my_variable.cpp dosyasında tanımlanmıştır. other_file.cpp veya other_file.h dosyasında ise extern int my_variable; şeklinde sadece değişkenin bildirimi yapılmıştır. Bu şekilde, usage_of_my_variable() fonksiyonu içinde my_variable değişkenine erişilebilir.

- Bu yöntemle, C++ programınızda farklı dosyalardaki değişkenler arasında veri paylaşımı sağlayabilirsiniz. extern anahtar kelimesi, derleyiciye değişkenin başka yerlerde tanımlı olduğunu ve oradan alınması gerektiğini bildirir.

- tanım yapıldı extern kullanıldığı dosyadaki son değeri alır hep bizim değişkenimiz. Her zamanm bir mainimiz olduğu için extern kullandığımızda son değer neyse o değer kullanılır hep.

- Son bir örnmek
    1. Başlık Dosyası (Header File) Oluşturma:
        - İlk olarak, ortak değişkenin bildirimini (declaration) içeren bir başlık dosyası oluşturun. Bu başlık dosyası, değişkenin var olduğunu ve diğer dosyalara extern anahtar kelimesiyle bildirilerek erişilebileceğini belirtir.

        - Örneğin, common_variable.h adında bir başlık dosyası oluşturalım:
            ```cpp
            // common_variable.h
            #ifndef COMMON_VARIABLE_H
            #define COMMON_VARIABLE_H

            extern int common_variable; // Ortak değişkenin bildirimi

            #endif // COMMON_VARIABLE_H
            ```
    2. Değişkenin Tanımı (Definition):
        - Değişkenin tanımını (definition) bir kaynak dosyasında yapın. Bu dosyada değişkenin başlangıç değerini belirleyebilirsiniz.
        - Örneğin, common_variable.cpp adında bir kaynak dosyası oluşturalım:
            ```cpp
            // common_variable.cpp
            #include "common_variable.h"

            int common_variable = 42; // Ortak değişkenin tanımı, başlangıç değeri 42
            ```
    3. Değişkene Erişim:
        - Değişkeni kullanmak istediğiniz herhangi bir dosyada, common_variable.h başlık dosyasını dahil ederek değişkene erişebilirsiniz. Bu dosyada extern anahtar kelimesiyle değişkenin bildirimini yapmanız yeterlidir.

        - Örneğin, file1.cpp ve file2.cpp adında farklı dosyalarda common_variable değişkenine erişebilirsiniz:
            ```cpp
            // file1.cpp
            #include <iostream>
            #include "common_variable.h"

            void function_in_file1() {
                std::cout << "common_variable değeri (file1): " << common_variable << std::endl;
                common_variable = 100; // common_variable'ın değerini 100 olarak değiştir
            }
            ```
            ```cpp
            // file2.cpp
            #include <iostream>
            #include "common_variable.h"

            void function_in_file2() {
                std::cout << "common_variable değeri (file2): " << common_variable << std::endl;
            }
            ```
    4. Programı Derleme ve Çalıştırma:
        - Tüm bu dosyaları birlikte derleyerek programınızı oluşturabilirsiniz. common_variable değişkeni common_variable.cpp dosyasında tanımlandığı için bu değişkene diğer dosyalardan erişebilirsiniz. Değişken üzerinde yapılan değişiklikler tüm dosyalara yansır.

        - Örneğin, main.cpp dosyasında file1.cpp ve file2.cpp dosyalarındaki fonksiyonları çağırarak common_variable'ı kullanabilirsiniz:

            ```cpp
            // main.cpp
            #include "common_variable.h"
            #include "file1.cpp"
            #include "file2.cpp"

            int main() {
                function_in_file1(); // common_variable'ın değerini 100 olarak değiştir ve yazdır (file1.cpp)
                function_in_file2(); // common_variable'ın güncellenmiş değerini yazdır (file2.cpp)
                return 0;
            }
            ```
    - Bu şekilde, extern anahtar kelimesini kullanarak common_variable gibi bir değişkene programınızın farklı dosyalarından erişebilir ve bu değişken üzerinde yapılan değişikliklerin tüm dosyalara yansımasını sağlayabilirsiniz. common_variable değişkeni common_variable.cpp dosyasında tanımlanmış ve common_variable.h başlık dosyası aracılığıyla diğer dosyalara bildirilmiştir. Bu sayede common_variable değişkenine programınızın farklı bölümlerinden erişilebilirsiniz.
    - extern i sadece header de kullandık ve daha sonra sürekli belirtmek zorunda kalmadık

- **With const**:
    ```cpp
    //-----------------------------------------------------------
    // constants.h
    #ifndef CONSTANTS_H
    #define CONSTANTS_H

    extern const int MY_CONSTANT;  // Sabit değişkenin bildirimi

    #endif // CONSTANTS_H


    //-----------------------------------------------------------
    // constants.cpp
    #include "constants.h"

    const int MY_CONSTANT = 100;  // Sabit değişkenin tanımı


    //-----------------------------------------------------------
    // file1.cpp
    #include <iostream>
    #include "constants.h"

    void printConstant() {
        std::cout << "MY_CONSTANT: " << MY_CONSTANT << std::endl;
    }


    //-----------------------------------------------------------
    // main.cpp
    #include "constants.h"
    #include "file1.cpp"

    int main() {
        printConstant();  // Sabit değişkenin değerini yazdırır
        return 0;
    }
    ```
- Bu yöntemle, const ve extern anahtar kelimelerini kullanarak, sabit bir değeri programın farklı dosyaları arasında paylaşabilir ve bu değerin değiştirilemez olmasını sağlayabilirsiniz.

- **Memory Behavior**
    - extern ile tanımlanan bir değişken, hafızada sabit bir adresi olan global bir değişkendir. extern anahtar kelimesi, bir değişkenin tanımının (definition) programın başka bir yerinde yapıldığını belirtir, ama asıl önemli olan bu değişkenin hafızada tek bir yer kaplaması ve bu yerin tüm program boyunca sabit kalmasıdır.
    - Global Olarak Tanımlanma:
        - extern ile bildirilen değişken global olarak tanımlandığından, bu değişkenin programın çalışması boyunca hafızada ayrılan bir bölgeye sahiptir. Bu bölge, programın başında ayrılır ve program sonlanana kadar korunur.
    - Sabit Adres:
        - extern değişkenlerin hafızada sabit bir adresi vardır. Bu adres, değişken tanımlandığında (genellikle programın yükleme zamanında) belirlenir ve programın çalışma süresi boyunca değişmez. Bu sabitlik, farklı dosyalardan ve fonksiyonlardan bu değişkene tutarlı ve tahmin edilebilir bir şekilde erişilmesini sağlar.

    - Linker Tarafından Yönetilme:
        - extern değişkenler, derleme sürecinde değil, linkleme sürecinde ele alınır. Çeşitli dosyalarda extern anahtar kelimesiyle bildirilen değişkenlerin asıl tanımları linkleme sürecinde bağlanır. Bu, değişkenin tüm dosyalar arasında ortak olarak kullanılmasını ve tek bir hafıza alanında saklanmasını sağlar.
    - Optimizasyon:
        - Modern derleyiciler ve bağlayıcılar (linker), bu tür global değişkenlerin kullanımını optimize edebilir. Örneğin, kullanılmayan bir extern değişkenin hafızadan kaldırılması veya programın farklı bölümleri tarafından yoğun bir şekilde kullanılan bir değişkenin erişim süresini kısaltmak için özel hafıza bölümlerine alınması gibi optimizasyonlar yapılabilir.
### From Internet
- The extern storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used (i.e. external linkage). Basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well. An extern variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere.

- A normal global variable can be made extern as well by placing the ‘extern’ keyword before its declaration/definition in any function/block. The main purpose of using extern variables is that they can be accessed between two different files which are part of a large program.
- Properties of extern Variable in C
    - When we write extern some_data_type some_variable_name;  no memory is allocated. Only the property of the variable is announced.
    - Multiple declarations of extern variable is allowed within the file. This is not the case with automatic variables.
    - The extern variable says to the compiler  “Go outside my scope and you will find the definition of the variable that I declared.”
    - The compiler believes that whatever that extern variable said is true and produces no error. Linker throws an error when it finds no such variable exists.
    - When an extern variable is initialized, then memory for this is allocated and it will be considered defined.
- Properties of extern Storage Class Objects
    - Scope: Global
    - Default Value: Zero
    - Memory Location: RAM
    - Lifetime: Till the end of the program.

## static Storage Class
- The static storage class is used to declare static variables which are popularly used while writing programs in C++ language. Static variables have the property of preserving their value even after they are out of their scope! Hence, static variables preserve the value of their last use in their scope.

- We can say that they are initialized only once and exist until the termination of the program. Thus, no new memory is allocated because they are not re-declared. 

- Properties of static Storage Class
    - Scope: Local
    - Default Value: Zero
    - Memory Location: RAM
    - Lifetime: Till the end of the program
- Note: Global Static variables can be accessed in any function. global olması o dosya içinde global olduğu anlamına geliyor
    ```cpp
    // C++ program to illustrate the static storage class
    // objects
    #include <iostream>
    using namespace std;
    
    // Function containing static variables
    // memory is retained during execution
    int staticFun()
    {
        cout << "For static variables: ";
        static int count = 0;
        count++;
        return count;
    }
    
    // Function containing non-static variables
    // memory is destroyed
    int nonStaticFun()
    {
        cout << "For Non-Static variables: ";
    
        int count = 0;
        count++;
        return count;
    }
    
    int main()
    {
    
        // Calling the static parts
        cout << staticFun() << "\n";
        cout << staticFun() << "\n";
        
    
        // Calling the non-static parts
    
        cout << nonStaticFun() << "\n";
        
        cout << nonStaticFun() << "\n";
        
        return 0;
    }
    ```

    ```bash
    For static variables: 1
    For static variables: 2
    For Non-Static variables: 1
    For Non-Static variables: 1
    ```
## Differences static and extern
- static: static anahtar kelimesi, farklı bağlamlarda değişkenler ve fonksiyonlar için farklı anlamlar taşır:
    1. Dosya Kapsamında Kullanım (Global Değişkenler ve Fonksiyonlar):
        - Bir global değişken veya fonksiyon static olarak tanımlandığında, bu değişken veya fonksiyon sadece tanımlandığı dosya (derleme birimi) içinde erişilebilir olur. Yani, diğer dosyalardan erişilemez.
            ````cpp
            // global.cpp

            // Static global variable (internal linkage)
            static int globalVar = 10;

            // Static global function (internal linkage)
            static void staticFunction() {
                // Function definition
            }
            ```
    2. Sınıf Üyeleri (Static Sınıf Üyeleri):
        - Bir sınıf üyesi (static veri üyesi veya static fonksiyon), sınıfın tüm örnekleri için aynıdır. Yani, bir sınıfın tüm örnekleri için ayrı ayrı bellek alanı ayrılmaz.
        - static veri üyeleri sınıfın bir parçası olarak değil, sınıfın kendisi olarak kabul edilir ve sınıf ismiyle erişilir.
            ```cpp
            class MyClass {
            public:
                static int staticVar;
                static void staticMethod() {
                    // Method definition
                }
            };

            // Definition of static member variable (outside the class)
            int MyClass::staticVar = 20;
            ```

- extern: extern anahtar kelimesi ise genellikle bir değişkenin veya fonksiyonun farklı bir dosyada tanımlanmış olduğunu belirtmek için kullanılır:
    1. Değişken ve Fonksiyon Tanımlaması:
        - extern kullanılarak bir değişken veya fonksiyonun tanımlanması, bu değişkenin veya fonksiyonun daha önce başka bir dosyada veya derleme biriminde tanımlandığını belirtir.
        - Bu, derleyiciye bu değişkenin veya fonksiyonun başka bir yerde tanımlandığını aramasını söyler.
            ```cpp
            // file1.cpp

            extern int globalVariable;  // Declaration (definition is in another file)
            extern void someFunction(); // Declaration (definition is in another file)
            ```
    2. Header Dosyalarında Kullanım:
        - extern anahtar kelimesi genellikle header dosyalarında kullanılır. Bir değişkenin veya fonksiyonunun tanımının başka bir dosyada olduğunu belirtmek için header dosyalarında extern kullanılır ve tanımın gerçekleştirildiği dosyada bu değişken veya fonksiyon extern anahtar kelimesi olmadan tanımlanır.
            ```cpp
            //----------------------------------------------------------------------
            // header.h

            extern int globalVariable; // Declaration (definition is in another file)
            void someFunction();       // Declaration (definition is in another file)

            //----------------------------------------------------------------------
            // file1.cpp

            #include "header.h"

            int globalVariable = 10;   // Definition of the global variable
            void someFunction() {
                // Function definition
            }
            ```
- Özet:
    - static anahtar kelimesi, değişken veya fonksiyonun sadece tanımlandığı dosya (derleme birimi) içinde erişilebilir olduğunu belirtir.
    - extern anahtar kelimesi, değişken veya fonksiyonun tanımının başka bir dosyada veya derleme biriminde olduğunu belirtir ve bu tanımın referansını sağlar.

    - Bir değişken global olarak tanımlandığında ve static ya da extern belirteçlerinden herhangi biri kullanılmazsa, bu değişken varsayılan olarak dış bağlantılıdır (extern). Bu, başka dosyalardan bu global değişkene erişilebileceği anlamına gelir, yani başka dosyalardaki kodlar bu global değişkeni kullanabilir. Ancak bu erişimi sağlamak için başka dosyalarda bu global değişkenin extern ile bildirimini yapmak gerekir.

    - Eğer global değişken static anahtar kelimesi ile tanımlanırsa, bu değişken yalnızca tanımlandığı dosya içinde erişilebilir olur ve bu dosya dışından erişilemez. Yani, static değişkenin erişim kapsamı sadece tanımlandığı dosya ile sınırlıdır. fonksiyon veya main dışında değişkenleri tanımladığımızda global oluyor bunu static olarak tanımlarsak sadece o dosyada kullanılabilir olduğunu ifade ederiz. Diğer türlü diğer dosyalardan da erişilebilir extern ifadesi kullanılarak bunun önüne geçmiş oluyoruz aslında

    - Bu yüzden, bir global değişkenin başka dosyalardan erişilebilir olup olmamasını static kullanarak kontrol edebilirsiniz (erişimi sınırlamak için). Eğer bir global değişkene dosya dışından erişmek istiyorsanız ve o değişken diğer bir dosyada tanımlanmışsa, o değişkeni extern anahtar kelimesi ile başka dosyalarda bildirmeniz gerekir.

## register Storage Class
- The register storage class declares register variables using the ‘register’ keyword which has the same functionality as that of the auto variables. The only difference is that the compiler tries to store these variables in the register of the microprocessor if a free register is available. This makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program. If a free register is not available, these are then stored in the memory only. 

- An important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers.
- properties of register Storage Class Objects
    - Scope: Local
    - Default Value: Garbage Value
    - Memory Location: Register in CPU or RAM
    - Lifetime: Till the end of its scope

- register anahtar kelimesi, derleyiciye belirli bir değişkenin CPU'nun genel amaçlı kayıtlarından birine yerleştirilmesini istediğinizi belirtmek için kullanılır. Ancak, modern derleyiciler genellikle register anahtar kelimesini dikkate almazlar ve bu nedenle register anahtar kelimesini kullanmak, derleyici tarafından tamamen göz ardı edilebilir.

- register anahtar kelimesi, bir değişkenin bellekte değil, CPU kayıtlarında saklanmasını sağlamak amacıyla C dilinde eklenmiştir. Böylece, bu değişkenin erişimi daha hızlı olabilir. Ancak, modern derleyiciler genellikle, derleyici optimizasyonları ve CPU'nun kendi veri önbelleği yönetimi gibi faktörler nedeniyle, register anahtar kelimesini görmezden gelirler.

- Bununla birlikte, bir değişkenin register anahtar kelimesiyle belirtilmesi, derleyiciye bu değişkenin sıkça kullanılacağını ve mümkünse kayıtlara yerleştirilmesi gerektiğini belirtir. Ancak, derleyicinin bu talebi yerine getirmesi tamamen tercihine bağlıdır ve register anahtar kelimesi bir zorunluluk değildir.

- Modern C ve C++ kodlarında, register anahtar kelimesi yerine, derleyicinin kendisi en uygun optimizasyonları yapmasına izin vermek genellikle daha iyidir. Bu nedenle, register anahtar kelimesini kullanmanın genellikle gereksiz olduğu kabul edilir

    ```cpp
    // C++ Program to illustrate the use of register variables
    #include <iostream>
    using namespace std;
    
    void registerStorageClass()
    {
    
        cout << "Demonstrating register class\n";
    
        // declaring a register variable
        register char b = 'G';
    
        // printing the register variable 'b'
        cout << "Value of the variable 'b'"
            << " declared as register: " << b;
    }
    int main()
    {
    
        // To demonstrate register Storage Class
        registerStorageClass();
        return 0;
    }
    ```
    ```bash
    Demonstrating register class
    Value of the variable 'b' declared as register: G
    ```
- Note: The register keyword is deprecated in C++17 onwards.

## mutable Storage Class
- Bir sınınftan obje oluşturuken const olarak oluşturudğumuzda onun member datalarını değiştiremeyiz. ama değiştirilebilir verilerde oluşturmak istiyorsak mutable keywordunu kullanmalıyız.
- Sometimes there is a requirement to modify one or more data members of class/struct through the const function even though you don’t want the function to update other members of class/struct. This task can be easily performed by using the mutable keyword. The keyword mutable is mainly used to allow a particular data member of a const object to be modified. 

- When we declare a function as const, this pointer passed to the function becomes const. Adding a mutable to a variable allows a const pointer to change members.

- Properties of mutable Storage Class
The mutable specifier does not affect the linkage or lifetime of the object. It will be the same as the normal object declared in that place.

    ```cpp
    // C++ program to illustrate the use of mutalbe storage
    // class specifiers
    #include <iostream>
    using std::cout;
    
    class Test {
    public:
        int x;
    
        // defining mutable variable y
        // now this can be modified
        mutable int y;
    
        Test()
        {
            x = 4;
            y = 10;
        }
    };
    
    int main()
    {
        // t1 is set to constant
        const Test t1;
    
        // trying to change the value
        t1.y = 20;
        cout << t1.y;
    
        // Uncommenting below lines
        // will throw error
        // t1.x = 8;
        // cout << t1.x;
        return 0;
    }
    ```

    ```bash
    20
    ```

## thread_local Storage Class
- The thread_local Storage Class is the new storage class that was added in C++11. We can use the thread_local storage class specifier to define the object as thread_local. The thread_local variable can be combined with other storage specifiers like static or extern and the properties of the thread_local object changes accordingly.

- Properties of thread_local Storage Class
    - Memory Location: RAM
    - Lifetime: Till the end of its thread

    ```cpp
    // C++ program to illustrate the use of thread_local storage
    // sprecifier
    #include <iostream>
    #include <thread>
    using namespace std;
    
    // defining thread local variable
    thread_local int var = 10;
    
    // driver code
    int main()
    {
        // thread 1
        thread th1([]() {
            cout << "Thread 1 var Value: " << (var += 18) << '\n';
        });
    
        // thread 2
        thread th2([]() {
            cout << "Thread 2 var Value: " << (var += 7) << '\n';
        });
    
        // thread 3
        thread th3([]() {
            cout << "Thread 3 var Value: " << (var += 13) << '\n';
        });
    
        th1.join();
        th2.join();
        th3.join();
    
        return 0;
    }
    ```
    ```bash
    Thread 1 var Value: 28
    Thread 2 var Value: 17
    Thread 3 var Value: 23
    ```

- As we can see, each thread got its own copy of the thread_local variable and was only assigned the value that was specified in its callable.

- eğer kullanmazsak
    - Paylaşılan Durumların Güvenliği Sorunları:
        - thread_local değişkenler, çoklu iş parçacığı (multithreaded) ortamlarda güvenli bir şekilde veri paylaşımını sağlar. Eğer thread_local kullanmazsanız, aynı değişkeni farklı iş parçacıklarında paylaşmaya çalışmak standart değişkenlerle oluşabilecek yarış durumlarına (race condition) ve veri bütünlüğü sorunlarına neden olabilir.
    - Bağımsız İş Parçacıkları Arasında İletişim:
        - thread_local değişkenler, aynı işlemi yapan farklı iş parçacıkları arasında iletişim veya durum paylaşımını kolaylaştırır. Bu sayede her iş parçacığı kendi kopyası üzerinde çalışabilir.
        - thread_local kullanmazsanız, iş parçacıkları arasında bilgi veya durum paylaşımını sağlamak zorlaşabilir ve senkronizasyon işlemleri gerekebilir.
    - İş Parçacığı Güvenliği ve İzolasyonu:
        - thread_local değişkenler, iş parçacıklarının birbirinden bağımsız çalışmasını ve bir iş parçacığının diğerine müdahale etmemesini sağlar.
        - Eğer thread_local kullanmazsanız, iş parçacıkları arasında istenmeyen etkileşimler ve paylaşılan durumların karmaşıklığıyla başa çıkmak zorunda kalabilirsiniz.
    - Performans ve Bellek Kullanımı:
        - thread_local değişkenler, her iş parçacığı için ayrı bellek alanı ayrıldığından dolayı performans optimizasyonlarına da katkıda bulunabilir.
        - Ancak thread_local kullanmazsanız, iş parçacıkları arasında veri kopyalamaları veya senkronizasyon işlemleri gerekebilir, bu da performansı etkileyebilir.