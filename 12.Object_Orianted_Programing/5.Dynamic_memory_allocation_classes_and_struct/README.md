# Dynamic Memory Allocation Classes and Struct
## -> operatörü
- -> operatörü, C++ gibi nesne yönelimli programlama dillerinde kullanılan bir gösterici (pointer) üye erişim operatörüdür. Bu operatör, bir işaretçinin işaret ettiği nesnenin üye elemanlarına (veri üyeleri veya üye fonksiyonlar) erişmek için kullanılır. -> operatörü, işaretçiyi dereference etmek (*) ve ardından üye erişim operatörünü (.) kullanmanın kısayoludur.
    ```bash
    pointer->member
    ```
    - Burada pointer, bir nesneyi işaret eden bir işaretçidir ve member, bu nesnenin bir üyesidir (veri üyesi veya üye fonksiyon).
- -> operatörü, işaretçinin işaret ettiği nesnenin adresini dereference eder ve ardından üye erişim operatörünü (.) kullanarak bu nesnenin üyelerine erişir. Yani, pointer->member ifadesi, (*pointer).member ifadesiyle eşdeğerdir.
    ```cpp
    Person* pPerson = &person;

    // aşağıdakilerin ikiside aynı şey
    pPerson->name = "Bob";
    (*pPerson).name = "Bob"; 
    ```

## Kullanım Alanları
- classın içinde
- class veya structun addresini alıp bir pointera attığımızda
- memory allocate ettiğimizde pointerlarla işlem yapıyoruz ya aynı şey.
1. Sınıflar (Classes)
    - Sınıflar, nesne yönelimli programlamanın temel yapı taşlarıdır. Sınıf üyelerine ve üye fonksiyonlarına erişim sağlamak için işaretçiler kullanıldığında -> operatörü kullanılır.
        ```cpp
        #include <iostream>
        #include <string>

        class Person {
        public:
            std::string name;
            int age;

            void display() {
                std::cout << "Name: " << this.name << ", Age: " << this.age << std::endl;
            }
        };

        int main() {
            Person person;
            Person* pPerson = &person;

            pPerson->name = "Alice";
            pPerson->age = 30;
            pPerson->display();

            return 0;
        }
        ```

2. Yapılar (Structs)
    - Yapılar, C ve C++'ta veri gruplarını bir araya getiren veri yapılarıdır. Yapı üyelerine erişmek için işaretçiler kullanıldığında -> operatörü kullanılır.
        ```cpp
        #include <iostream>

        struct Point {
            int x;
            int y;
        };

        int main() {
            Point p;
            Point* pPoint = &p;

            pPoint->x = 10;
            pPoint->y = 20;

            std::cout << "Point: (" << pPoint->x << ", " << pPoint->y << ")" << std::endl;

            return 0;
        }
        ```
- Dinamik Bellek Yönetimi veya obje ye işaret eden pointer lar: Dinamik olarak ayrılmış belleği kullanırken, işaretçilerle çalışılır ve -> operatörü, bu işaretçilerin işaret ettiği veri yapılarının üyelerine erişmek için kullanılır.
- **Dikkat**: Dynamic olara memory allocate ettiğinde new ile. new operatörü objeyi başlatır yani sadece alan ayırmakla kalmaz objeyi de oluşturur. Bu yüzden constructor çağırlır. Şimdi bu objeyi biz dynamic olarak allocate ettiğimiz için delete etmemiz gerekiyor. delete operatörü direkt destructoru kullanır o yüzden dikkatli ol.
    