# this Pointer
- "this" pointer, C++ gibi nesne yönelimli programlama (OOP) dillerinde kullanılan özel bir göstergedir. Bu göstergenin amacı, bir sınıfın üyesi olan bir işlevin, kendisini çağıran nesneyi işaret etmesini sağlamaktır. Bu şekilde, sınıfın üyesi olan işlevler, kendilerini çağıran nesneye erişebilir ve onun üyeleriyle çalışabilirler. "this" pointer hakkında daha ayrıntılı bilgi verelim. objenin kendisini temslil eden bir pointer. sınıfın içinde o anki oluşturulan objeyi temsil eder.
- **Tanım**
    - "this" pointer, bir sınıfın üyesi olan her işlevin gizli bir parametresidir.
    - sınıfın içinde o anki oluşturulan objeyi temsil eder. onun pointerini tutar.
    - Bu gösterge, işlevin çağrıldığı nesnenin adresini içerir.
-  **Kullanım Alanları**
    - Nesnenin Üyelerine Erişim: "this" pointer, sınıfın üyesi olan işlevlerin, çağrıldığı nesnenin üyelerine erişmesini sağlar. (Yani local değişkenlere ulaşmamıza olanak sağlar böylece değişken ismi karışıklılığının önüne geçmiş oluruz)
        ```cpp
        class MyClass {
        public:
            int value;
            void setValue(int value) {
                this->value = value;
            }
        };
        ```
        - Yukarıdaki örnekte, this->value(classon value si funcitonun değil) ifadesi, çağrılan nesnenin value üyesini ifade eder.
    
    - Fonksiyon Zincirleme: Bir işlevin çağrıldığı nesneyi döndürmek için kullanılabilir, bu da fonksiyon zincirleme (function chaining) olarak bilinir.(mesela). Her fonksiyon o an kullanılan objenin kendisini döndürüyor bu yüzde . kullanarak ard arda özellikler tanımlayabilirsin.
        ```cpp
        #include <iostream>
        #include <string>

        class Person {
        public:
            // Set the name and return the current object
            Person& setName(const std::string& name) {
                this->name = name;
                return *this;
            }

            // Set the age and return the current object
            Person& setAge(int age) {
                this->age = age;
                return *this;
            }

            // Print the name and age
            void print() const {
                std::cout << "Name: " << name << ", Age: " << age << std::endl;
            }

        private:
            std::string name;
            int age;
        };

        int main() {
            Person p;
            p.setName("John").setAge(30).print(); // Chained function calls
            return 0;
        }
        ```
- **Sabit ve Sabit Olmayan "this" Pointer**
    - "const" anahtar kelimesi bir üye fonksiyonunun sonuna eklendiğinde, bu fonksiyonun, çağrıldığı nesnenin üye değişkenlerini değiştiremeyeceği anlamına gelir. Bu tür fonksiyonlar genellikle yalnızca nesnenin durumunu okuma amaçlı kullanılır.
    - Bir üye fonksiyon const olarak tanımlandığında, bu fonksiyonun içinde kullanılan "this" pointer da const bir pointer olur. Bu, "this" pointer'ın işaret ettiği nesnenin değiştirilemez olduğunu belirtir. Böylece, const üye fonksiyonlar yalnızca okuma işlemleri yapabilirler.

    - const_cast: const_cast kullanarak "this" pointerın sabitliğini kaldırmak mümkündür, ancak bu, dikkatle ve nadiren kullanılmalıdır.
        ```cpp
        #include <iostream>
        #include <string>

        class Person {
        public:
            // Constructor
            Person(const std::string& name, int age) : name(name), age(age) {}

            // Const member function to print the person's details
            void print() const {
                std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
                // this->age = 30; // Hata: 'this' pointer const olduğundan değişkenler değiştirilemez
            }

            // Non-const member function to set the person's age
            void setAge(int age) {
                this->age = age;
            }

        private:
            std::string name;
            int age;
        };

        int main() {
            Person p("John", 25);
            p.print(); // Name: John, Age: 25
            p.setAge(30);
            p.print(); // Name: John, Age: 30

            const Person cp("Jane", 22);
            cp.print(); // Name: Jane, Age: 22
            // cp.setAge(28); // Hata: Const nesne olduğundan non-const üye fonksiyon çağrılamaz

            return 0;
        }
        ```
        - Const Üye Fonksiyon (print):
            - print fonksiyonu, const olarak tanımlanmıştır. Bu nedenle, bu fonksiyon içinde this pointer, const Person* türündedir.
            - Bu fonksiyon, this->name ve this->age üyelerine yalnızca okuma erişimi sağlar.
            - Fonksiyon içinde this->age = 30 gibi bir atama yapılırsa derleme hatası oluşur çünkü this pointer const olduğu için üyeler değiştirilemez.

        - Non-Const Üye Fonksiyon (setAge): 
            - setAge fonksiyonu, nesnenin yaşını değiştirmek için kullanılır. Bu fonksiyon const olarak tanımlanmadığı için this pointer normal bir Person* türündedir ve nesne üyeleri değiştirilebilir. 
    - **Özet**
        - Const Üye Fonksiyonlar: Nesnenin üyelerini değiştirmezler. Bu fonksiyonlar this pointer'ı const bir pointer olarak kullanır.
        - This Pointer in Const Üye Fonksiyonlar: const üye fonksiyonlar içinde this pointer, const olarak değerlendirilir ve nesnenin üyeleri değiştirilemez.

- **Sınırlamalar ve Yanlış Kullanımlar**
    - Dizilerde Kullanım: "this" pointer dizilerde doğrudan kullanılmaz.
    - Statik Üye Fonksiyonlarda: Statik üye fonksiyonlar sınıfın belirli bir örneğine ait olmadığından, "this" pointera sahip değildirler.
    - İşaretçilerde Yanlış Erişim: "this" pointer yanlış kullanıldığında işaretçi hatalarına ve bellek erişim ihlallerine yol açabilir.

- **Özet**
    - "this" pointer, nesne yönelimli programlamada sınıf üyelerine erişim ve manipülasyon için kritik öneme sahiptir. Nesnenin bağlamını işlevlere taşıyarak, sınıfın üye işlevlerinin daha anlamlı ve güvenli bir şekilde çalışmasını sağlar.

## returning refernce from a function
- Daha karmaşık veri yapılarına sahip sınıflarla referans döndüren fonksiyonlar, nesne yönetimini ve değişiklikleri kolaylaştırır. burada direkt o anki objenin kendisini döndürüyor böyle yapmasaydık kopyasını oluştururdu. Yani return değerinde ki bu depğişiklik kopyasının mı yoksa referansının mı döndüreleceğini belirityor.
    ```cpp
    #include <iostream>
    #include <vector>

    class Matrix {
    public:
        Matrix(int rows, int cols) : rows(rows), cols(cols) {
            data.resize(rows, std::vector<int>(cols, 0));
        }

        // Access an element and return a reference to it
        int& at(int row, int col) {
            return data[row][col];
        }

        // Print the matrix
        void print() const {
            for (const auto& row : data) {
                for (int val : row) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
        }

    private:
        int rows, cols;
        std::vector<std::vector<int>> data;
    };

    int main() {
        Matrix mat(3, 3);
        mat.at(1, 1) = 5; // Set element at (1, 1) to 5
        mat.print();
        return 0;
    }
    ```

## Scope Resolution Operator (`::`) ve `this` Pointer C++'da
- C++'da, Scope Resolution Operator (`::`) ve `this` pointer, nesne yönelimli programlamada farklı bağlamlarda kullanılan önemli araçlardır. Bu iki yapının farklarını ve doğru kullanım alanlarını anlamak, verimli ve temiz kod yazmak için kritik öneme sahiptir.

### Scope Resolution Operator (`::`)

- **Amacı**
    Scope Resolution Operator (`::`), bir sınıfın, ad alanının veya küresel kapsamın üyelerine erişmek için kullanılır. Kapsamı belirlemek ve isim çakışmalarını önlemek için kullanılır.

- **Kullanım Alanları**
    1. Sınıf Üye Fonksiyonlarını Sınıf Dışında Tanımlama
        ```cpp
        class MyClass {
        public:
            void myFunction();
        };

        void MyClass::myFunction() {
            // Fonksiyon tanımı
        }
        ```

    2. Ad Alanı (Namespace) Üyelerine Erişim
        ```cpp
        namespace MyNamespace {
            int value = 42;
        }

        int main() {
            int myValue = MyNamespace::value; // MyNamespace içindeki value değişkenine erişim
            return 0;
        }
        ```

    3. Küresel Kapsama Erişim
        ```cpp
        int value = 10; // Global değişken

        int main() {
            int value = 20; // Yerel değişken
            std::cout << ::value << std::endl; // Global değişkene erişim, çıktı: 10
            return 0;
        }
        ```

    4. Sınıf Sabitlerine ve Statik Üyelerine Erişim
        ```cpp
        class MyClass {
        public:
            static const int constantValue = 100;
        };

        int main() {
            int value = MyClass::constantValue; // Sınıf sabitine erişim veya static öğesine aslında
            return 0;
        }
        ```

### `this` Pointer

- **Amacı**
    - `this` pointer, tüm non-static üye fonksiyonlar içinde bulunan özel bir işaretçidir. Bu işaretçi, üye fonksiyonun çağrıldığı nesneyi işaret eder.

- **Kullanım Alanları**
    1. Üye Fonksiyonlarda Üyelere Erişim
        ```cpp
        class MyClass {
        public:
            void setValue(int value) {
                this->value = value; // Üye değişkene erişim
            }
        private:
            int value;
        };
        ```

    2. Fonksiyon Zincirleme (Method Chaining)
        ```cpp
        class MyClass {
        public:
            MyClass& setValue(int value) {
                this->value = value;
                return *this; // Mevcut nesneyi döndür
            }

            void print() const {
                std::cout << value << std::endl;
            }

        private:
            int value;
        };

        int main() {
            MyClass obj;
            obj.setValue(10).print(); // Fonksiyon zincirleme
            return 0;
        }
        ```

    3. Nesnenin Adresini Döndürme
        ```cpp
        class MyClass {
        public:
            MyClass* getPointer() {
                return this; // Mevcut nesnenin adresini döndür
            }
        };
        ```

### Farklılıklar

1. **Amaç ve Bağlam**
   - Scope Resolution Operator (`::`): Kapsamı belirtmek ve sınıf üyelerine, ad alanlarına ve küresel kapsam öğelerine erişmek için kullanılır.
   - **`this` Pointer:** Üye fonksiyonlar içinde, çağrıldığı nesnenin üyelerine erişmek ve nesnenin adresini almak için kullanılır.

2. **Kullanıldığı Yerler**
   - Scope Resolution Operator (`::`): Sınıf tanımlamaları dışında, ad alanları ve küresel kapsam erişimlerinde kullanılır.
   - `this` Pointer: Sadece sınıfın üye fonksiyonları içinde kullanılır.

3. **İşlevsellik**
   - Scope Resolution Operator (`::`): Sınıf üyelerine, ad alanlarındaki öğelere erişim sağlar ve isim çakışmalarını çözer.
   - `this` Pointer: Nesneye özgü işlemleri gerçekleştirmek ve nesneye özgü verilere erişmek için kullanılır.

### Özet
- Scope Resolution Operator (`::`) ve `this` pointer, C++'da farklı amaçlara hizmet eder. Scope Resolution Operator, kapsamı belirlemek ve sınıf üyelerine, ad alanlarına ve küresel kapsam öğelerine erişim sağlamak için kullanılır. `this` pointer ise üye fonksiyonlarda, çağrıldığı nesnenin üyelerine erişmek ve nesnenin adresini almak için kullanılır.

- Bu araçların doğru kullanımı, daha okunabilir, bakımı kolay ve verimli C++ kodları yazmanıza yardımcı olur.
