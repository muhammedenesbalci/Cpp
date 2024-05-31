# Destructure
## Content
- Destructor, C++'ta bir sınıfın nesnesi ömrünü tamamladığında otomatik olarak çağrılan özel bir üye fonksiyondur. Destructor, nesne tarafından kullanılan kaynakları serbest bırakmak ve temizleme işlemlerini gerçekleştirmek için kullanılır. Destructor'lar sınıfın ismiyle aynı isme sahip olup, önünde tilde (~) karakteri bulunur. Destructor'lar geri dönüş değeri veya parametre almazlar.
- **Destructor'ın Özellikleri**:
    - Kaynak Yönetimi: Dinamik olarak tahsis edilen bellek, dosya tanıtıcıları, ağ bağlantıları gibi kaynakları serbest bırakmak için kullanılır.
    - Otomatik Çağrılma: Nesne ömrünü tamamladığında otomatik olarak çağrılır.
    - Tek: Bir sınıfın yalnızca bir destructor'ı olabilir.
    - Overload Edilemez: Destructor'lar overload edilemez, yani bir sınıfın birden fazla destructor'ı olamaz.
    - Geri Dönüş Değeri ve Parametre: Destructor'lar geri dönüş değeri veya parametre almaz.      
    - new ile obje oluşturudğunda veya classın içinde bir yerde new ile dynmaic memory allocate ettiğinde. Destructorun içinde onu delete etmelisin.
    - LIFO yu unutma, stack bellekte(last in first out).
    - static veya const olamaz
    - virtual olabilir.
    - general syntax of a destrcture
    - pointer olarak bir obje oluşturudğumuzda yani dinamik bellek tahsisinden bahsediyorum. Dinamik bellek bölgesini silerken o objenin destructoru çağrılır.
        ```cpp
        class MyClass {
        public:
            // Constructor
            MyClass() {
                // Kaynak tahsisi
            }

            // Destructor
            ~MyClass() {
                // Kaynak serbest bırakma
            }
        };
        ```
    - private, protected, public olabilir.
    - private olursa normal tanımlayamazsın. Dynamic olarak memory allocate etmelisin.
        - The below program fails in the compilation. The compiler notices that the local variable ‘t’ cannot be destructed because the destructor is private. 
            ```cpp
            //yanlış-----------------------------
            #include <iostream>
            using namespace std;
            
            class Test {
            private:
                ~Test() {}
            };
            int main() { Test t; }
            /*
            prog.cpp: In function ‘int main()’:
            prog.cpp:8:5: error: ‘Test::~Test()’ is private
                ~Test() {}
                ^
            prog.cpp:10:19: error: within this context
            int main() { Test t; }
            */
            ```
        - The below program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”, so nothing is destructed.
            ```cpp
            // doğru --------------------------------------
            #include <iostream>
            using namespace std;
            
            class Test {
            private:
                ~Test() {}
            };
            int main() { Test* t; }

            ```
        
        - The above program also works fine. When something is created using dynamic memory allocation, it is the programmer’s responsibility to delete it. So compiler doesn’t bother. 
            ```cpp
            #include <iostream>
            using namespace std;
            
            class Test {
            private:
                ~Test() {}
            };
            int main() { Test* t = new Test; }
            ```
        
        - In the case where the destructor is declared private, an instance of the class can also be created using the malloc() function. The same is implemented in the below program. 
            ```cpp
            #include <bits/stdc++.h>
            using namespace std;
            
            class Test {
            public:
                Test() // Constructor
                {
                    cout << "Constructor called\n";
                }
            
            private:
                ~Test() // Private Destructor
                {
                    cout << "Destructor called\n";
                }
            };
            
            int main()
            {
                Test* t = (Test*)malloc(sizeof(Test));
                return 0;
            }
        ```

    - However, The below program fails in the compilation. When we call delete, destructor is called. 
        ```cpp
        #include <iostream>
        using namespace std;
        
        class Test {
        private:
            ~Test() {}
        };
        
        // Driver Code
        int main()
        {
            Test* t = new Test;
            delete t;
        }
        ```
    - We noticed in the above programs when a class has a private destructor, only dynamic objects of that class can be created. Following is a way to create classes with private destructors and have a function as a friend of the class. The function can only delete the objects.  

    - Another way to use private destructors is by using the class instance method. 
        ```cpp
        #include <iostream>

        using namespace std;

        class parent {
            // private destructor
            ~parent() { cout << "destructor called" << endl; }

        public:
            parent() { cout << "constructor called" << endl; }
            void destruct() { delete this; }
        };

        int main()
        {
            parent* p;
            p = new parent;
            // destructor called
            p->destruct();

            return 0;
        }
        //constructor called
        //destructor called
        ```