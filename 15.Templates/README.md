# Templates
- C++ dilinde şablonlar (templates) güçlü ve esnek bir özellik olup, genel programlama (generic programming) yapabilmenizi sağlar. Bu özellik, kodun yeniden kullanılabilirliğini artırır
- farklı veri türleri için aynı kodu yazmamıza gerek kalmaması için veri türünü parametre olarak iletmektir. 
- mesela float itn double için overloading yapmamıza gerek yok artık bunu kullanabiliriz direkt.
- türden bağımsız olarak çalışabilen fonksiyonlar ve sınıflar yazmanıza olanak tanır.
- Fonksiyon Şablonları
- Sınıf Şablonları

# Content
- [Parameters](#parameters)
- [Function Templates](#function-templates)
- [Class Templates](#class-templates)
- [Full Template Specialization](#full-template-specialization)
- [Partial Template Specialization](#partial-template-specialization)
- [Default Argumennts](#default-argumennts)
- [Differences Function Overloading and Function Templates](#Differences-function-overloading-and-function-templates)
- [Static variable with Template functions](#static-variable-with-template-functions)
- [Passing primitive data types](#passing-primitive-data-types)
- [Templates and SFINAE Substitution Failure Is Not An Error](#templates-and-sfinae-substitution-failure-is-not-an-error)
- [Templates and Inheritence](#templates-and-inheritence)
- [Struct](#struct)

## Parameters
- şablonlarda hem tek tür parametre hem de farklı tür parametreler kullanarak nasıl veri yapıları oluşturabileceğinizi göstereyim.
    - Tek Tür
        ```cpp
        #include <iostream>

        // Tek tür parametreli şablon yapı
        template <typename T>
        struct SingleTypeContainer {
            T value;

            SingleTypeContainer(T val) : value(val) {}

            void display() const {
                std::cout << "Value: " << value << std::endl;
            }
        };

        int main() {
            SingleTypeContainer<int> intContainer(100);
            SingleTypeContainer<double> doubleContainer(10.5);
            SingleTypeContainer<std::string> stringContainer("Hello");

            intContainer.display();    // Output: Value: 100
            doubleContainer.display(); // Output: Value: 10.5
            stringContainer.display(); // Output: Value: Hello

            return 0;
        }
        ```
        
    - Farklı Tür
        ```cpp
        #include <iostream>
        #include <string>

        // Farklı tür parametreli şablon yapı
        template <typename T1, typename T2>
        struct Pair {
            T1 first;
            T2 second;

            Pair(T1 f, T2 s) : first(f), second(s) {}

            void display() const {
                std::cout << "First: " << first << ", Second: " << second << std::endl;
            }
        };

        int main() {
            Pair<int, std::string> p1(1, "one");
            Pair<double, char> p2(2.5, 'A');

            p1.display(); // Output: First: 1, Second: one
            p2.display(); // Output: First: 2.5, Second: A

            return 0;
        }
        ```
## Function Templates
- Fonksiyon şablonları, belirli bir işlemi gerçekleştiren ve bu işlemi farklı veri türleriyle yapabilen fonksiyonlar tanımlamanıza olanak tanır.
- classlarda overloading yaparken kullanabilirsin.
- constrctorlarda kullanabilirsin.
- syntax
    ```cpp
    template <typename T>
    T add(T a, T b) {
        return a + b;
    }
    ```
    - template <typename T>: Bu satır, T adında bir tür parametresi tanımlar. T herhangi bir tür olabilir. template <class T> de olabilirdi ama genellikle typename kullanılır.
    - T add(T a, T b): Bu, T türünde iki parametre alan ve T türünde bir değer döndüren bir fonksiyon şablonudur.
- kullanırekn tür belirtmemize çok gerek yok fonksiyonlar otomatik anlayabiliyor ama belirtebilirsinde.
- fonksiyonun içine verirken T ler farklı türlere sahip olamaz unutma. ikiside T yani ikiside ya int olucak ya da float ya da başka bir şey.template <typename T> bu şekilde kullanıyosan.
- template <typename T1, typename T2> dersek iki farklı türü kullanabiliriz artık. istersek aynı da verebilirz.

## Class Templates
- Sınıf şablonları, veri üyeleri ve üye fonksiyonları farklı türlerde olabilen sınıflar tanımlamanıza olanak tanır.
- syntax
    ```cpp
    template <typename T>
    class MyClass {
    private:
        T data;
    public:
        MyClass(T d) : data(d) {}
        void display() {
            std::cout << data << std::endl;
        }
    };
    ```
    - template <typename T>: Bu satır, T adında bir tür parametresi tanımlar.
    - class MyClass: Bu, T türünde bir veri üyesi olan ve T türünde bir parametre alan bir kurucuya sahip bir sınıf şablonudur.
- cpp 11 ile 17 arasında tür belirtmek zorundayız. 17 ve üstü için tür belirtmemize gerek yok kullanırken.

## Full Template Specialization
- Şablonlar ayrıca özel durumlar (specialization) için de kullanılabilir. Bu, belirli türler için şablonların farklı bir şekilde davranmasını sağlar. mesela int verirsen farklı float verirsen farklı gibisinden.
- hem fonksiyonlar hemde classlar için kullanılabilir.
- önce genel bir şablon yazıyoruz sonra özelleştirilmiş hallerini yazıyoruz.
- eğer içine verdiğin paremetre özelleştiridklerinden hiçbirine uymuyorsa default template gider.
- template<> böyle yazarak hangi template türünü ayzdığımızı belirityoruz aslında.

## Partial Template Specialization
- Bu, tam şablon özelleştirmeden (full template specialization) farklıdır çünkü kısmi şablon özelleştirme, şablonun bazı parametreleri belirli türlere sabitlenirken diğer parametrelerin genel kalmasını sağlar. 
- birden fazla paremetre alırken kullanıyoruz genellikle. 
- diğer tür için özel template yazmazken diğer için yazıyoruz.
- classlar için geçerlidir. fonksiynlarda kullanılmaz
- template<typname> burada ise özelliştrmek istemediğimiz değişkenin adını yazıyoruz.

- genel olarak iksiide içinde geçerli olmuş oluyor mantıken. özelleştirmek istemediğimizi içine yazıyoruz.

## Default Argumennts
- template paremetreleri de default argümanlara sahip olabilir.
    ```cpp
    using namespace std;

    template <class T, class U = char> class A {
    public:
        T x;
        U y;
        A() { cout << "Constructor Called" << endl; }
    };

    int main()
    {
        // This will call A<int, char>
        A<int> a;

        return 0;
    }
    ```

## Differences Function Overloading and Function Templates
- Tür Çözümlemesi:
    - Fonksiyon Overloading: Derleyici, fonksiyonun hangi versiyonunun çağrılacağını parametre türlerine bakarak belirler.
    - Fonksiyon Şablonları: Derleyici, çağrılan türlerden yola çıkarak şablonun hangi türle örnekleneceğini (instantiate) belirler.
- Kod Tekrarı:
    - Fonksiyon Overloading: Aynı işlevselliği farklı türlerle gerçekleştirmek için aynı fonksiyonu tekrar tekrar yazmanız gerekir.
    - Fonksiyon Şablonları: Genel bir fonksiyon tanımlayarak kod tekrarını önleyebilirsiniz.

- Esneklik:
    - Fonksiyon Overloading: Belirli türler için özel işlevsellik sağlayabilir.
    - Fonksiyon Şablonları: Herhangi bir türle çalışabilen genel bir çözüm sağlar.

- Özelleştirme:
    - Fonksiyon Overloading: Belirli türler için özelleştirilmiş davranışlar tanımlamak daha doğrudan ve açıktır.
    - Fonksiyon Şablonları: Şablonları belirli türler için özelleştirmek (tam şablon özelleştirme) mümkündür, ancak daha karmaşık olabilir.

- **birlikte kullanımı**
    - full template spec ile aynı aslında sadece template<> eklemniyoruz.
        ```cpp
        #include <iostream>

        template <typename T>
        void print(T value) {
            std::cout << "Generic template: " << value << std::endl;
        }

        void print(int value) {
            std::cout << "Specialized for int: " << value << std::endl;
        }

        void print(double value) {
            std::cout << "Specialized for double: " << value << std::endl;
        }

        int main() {
            print(42);            // Çıktı: Specialized for int: 42
            print(3.14);          // Çıktı: Specialized for double: 3.14
            print("Hello");       // Çıktı: Generic template: Hello
            return 0;
        }
        ```

## Static variable with Template functions
-  C++'ta şablon fonksiyonlar (template functions) statik veri (static data) içerirse, bu statik veri her şablon örneği (template instantiation) için ayrı ayrı oluşturulur. Statik veri, fonksiyonun çağrıldığı tür için ayrı bir depolama alanına sahip olur. Bu, her farklı tür için ayrı bir statik değişkenin olması anlamına gelir.

## Templates and SFINAE Substitution Failure Is Not An Error
- SFINAE, C++ şablonlarının derleme zamanı sırasında tür eşleştirmesi sırasında başarısız olursa hata vermemesini sağlar. Bu özellik, tür özelliklerine dayalı olarak şablonları etkinleştirmek veya devre dışı bırakmak için kullanılır.
    ```cpp
    #include <iostream>
    #include <type_traits>

    // Şablon sadece tamsayı türleri için etkin
    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
    T add(T a, T b) {
        return a + b;
    }

    int main() {
        std::cout << add(3, 4) << std::endl;       // Çalışır, çünkü int tamsayı türüdür
        // std::cout << add(3.5, 4.5) << std::endl; // Derleme hatası verir, çünkü double tamsayı türü değildir
        return 0;
    }
    ```
- enable_if ile SFINAE Kullanımı
    ```cpp
    #include <iostream>
    #include <type_traits>

    // Şablon sadece tamsayı türleri için etkin
    template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
    T add(T a, T b) {
        return a + b;
    }

    int main() {
        std::cout << add(3, 4) << std::endl;       // Çalışır, çünkü int tamsayı türüdür
        // std::cout << add(3.5, 4.5) << std::endl; // Derleme hatası verir, çünkü double tamsayı türü değildir
        return 0;
    }
    ```

## Templates and Inheritence
- templates, inheritence ile birlikte kullanılabilir, bu da daha karmaşık yapılar oluşturmanıza olanak tanır.
    ```cpp
    #include <iostream>

    // Taban sınıf (Template Base Class)
    template <typename T>
    class Base {
    protected:
        T value;
    public:
        Base(T val) : value(val) {}
        virtual void display() const {
            std::cout << "Base value: " << value << std::endl;
        }
    };

    // Türetilmiş sınıf (Derived Class from Template Base Class)
    template <typename T>
    class Derived : public Base<T> {
    public:
        Derived(T val) : Base<T>(val) {}
        void display() const override {
            std::cout << "Derived value: " << this->value << std::endl;
        }
    };

    int main() {
        Base<int> baseObj(10);
        Derived<int> derivedObj(20);

        baseObj.display();       // Output: Base value: 10
        derivedObj.display();    // Output: Derived value: 20

        return 0;
    }
    ```

- Şablon Tabanlı Temel Sınıf (Base):
    - Base sınıfı bir şablon sınıfıdır ve tür bağımsız olarak kullanılabilir.
    - Base sınıfı, bir değer (value) depolar ve bu değeri display() fonksiyonu ile görüntüler.
    - display() fonksiyonu sanal (virtual) olarak tanımlanmıştır, bu da türetilmiş sınıfların bu fonksiyonu geçersiz kılmasına (override) olanak tanır.

- Türetilmiş Sınıf (Derived):
    - Derived sınıfı, Base sınıfından türetilmiştir ve aynı tür parametresini (T) kullanır.
    - Derived sınıfı, Base sınıfının kurucusunu çağırarak temel sınıfın (Base) değerini (value) başlatır.
    - display() fonksiyonu, türetilmiş sınıfta geçersiz kılınmıştır ve temel sınıfın (Base) değerini görüntüler.

- Kullanım:
    - Base<int> ve Derived<int> nesneleri oluşturulur.
    - display() fonksiyonu her iki nesne için de çağrılır ve uygun değerler görüntülenir.

## Struct
- struct lar ile de kullanılabilir.
    ```cpp
    #include <iostream>
    #include <string>

    // Şablonlu çift yapı (Template Pair Struct)
    template <typename T1, typename T2>
    struct Pair {
        T1 first;
        T2 second;

        Pair(T1 f, T2 s) : first(f), second(s) {}

        void display() const {
            std::cout << "First: " << first << ", Second: " << second << std::endl;
        }
    };

    int main() {
        // Farklı türde verileri depolayan Pair örnekleri
        Pair<int, std::string> p1(1, "one");
        Pair<double, char> p2(2.5, 'A');

        // Verileri görüntüle
        p1.display(); // Output: First: 1, Second: one
        p2.display(); // Output: First: 2.5, Second: A

        return 0;
    }
    ```