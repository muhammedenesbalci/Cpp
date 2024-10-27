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
- [constexpr](#constexpr)

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
- struct lar ile de kullanılabilir. mesela hep aynı tür structu tutarsın ama template yardımıyla içinde farklı data type lar saklarım.
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

## constexpr
- constexpr, C++11 ile tanıtılan bir anahtar kelimedir ve derleme zamanı (compile-time) sabit ifadeler oluşturmak için kullanılır. constexpr fonksiyonları ve değişkenleri, derleyicinin hesaplamaları derleme zamanında yapmasına olanak tanır, bu da performansı artırabilir ve kodun doğruluğunu kontrol edebilir.
- constexpr Anahtar Kelimesi Kullanım Alanları
    - Değişken Tanımlama:
        - constexpr anahtar kelimesi ile tanımlanan değişkenler derleme zamanında sabit olmalıdır.
        - Bu değişkenler, sabit ifadelere atanan değerler olmalıdır.

    - Fonksiyon Tanımlama:
        - constexpr fonksiyonlar, derleme zamanında değerlendirilebilen fonksiyonlardır.
        - Bu fonksiyonlar, derleme zamanı sabit ifadeler döndürmelidir.
        - Bu fonksiyonlar, sadece sabit ifadeler içermelidir ve sınırlı bir yapılandırmaya sahip olmalıdır (örneğin, döngüler ve koşullar sınırlıdır).

- constexpr Değişken Örneği
    ```cpp
    #include <iostream>

    int main() {
        constexpr int size = 10; // Derleme zamanında sabit bir ifade
        int array[size];         // 'size' değeri sabit olduğundan dizi boyutu olarak kullanılabilir

        std::cout << "Array size: " << size << std::endl;

        return 0;
    }
    ```

- constexpr Fonksiyon Örneği
    ```cpp
    #include <iostream>

    // constexpr fonksiyon tanımı
    constexpr int factorial(int n) {
        return (n <= 1) ? 1 : (n * factorial(n - 1));
    }

    int main() {
        constexpr int result = factorial(5); // Derleme zamanında hesaplanır

        std::cout << "Factorial of 5 is: " << result << std::endl;

        return 0;
    }
    ```

- **constexpr ve const Farkı**
- const: Derleme zamanında veya çalışma zamanında sabit olabilir. Derleme zamanı sabit olma zorunluluğu yoktur.
- constexpr: Derleme zamanında sabit olmalıdır. Derleyici tarafından sabit ifade olarak değerlendirilir. kesinlikle sabit olduğu anlamına geliyor.
    ```cpp
    #include <iostream>

    int main() {
        const int a = 10; // a is a constant, but not necessarily a compile-time constant
        constexpr int b = 20; // b is a compile-time constant

        int array1[a]; // This may not be allowed in some compilers because 'a' is not guaranteed to be a compile-time constant
        int array2[b]; // This is allowed because 'b' is guaranteed to be a compile-time constant

        std::cout << "a: " << a << ", b: " << b << std::endl;

        return 0;
    }
    ```

- C++14 ile birlikte, constexpr fonksiyonlar daha karmaşık yapılandırmalara izin verir. Örneğin, döngüler ve dallanma ifadeleri içerebilirler. bu fonkisyon runtime da değil compile time da sonucu hesaplanır. ve sabit gibi davranır sonucu. fakat böyle olması için fonkisyonun sonucunuda constexpr bir değişkene atmalıyız.
    ```cpp
    #include <iostream>

    // C++14 ile birlikte, daha karmaşık constexpr fonksiyonlar tanımlanabilir
    constexpr int fibonacci(int n) {
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return n == 0 ? a : b;
    }

    int main() {
        constexpr int result = fibonacci(10); // Derleme zamanında hesaplanır

        std::cout << "Fibonacci of 10 is: " << result << std::endl;

        return 0;
    }
    ```
- constexpr Kullanımının Faydaları
    - Performans Artışı: Derleme zamanında yapılan hesaplamalar, çalışma zamanındaki performansı artırabilir.
    - Sabit İfadelerin Doğruluğu: Derleme zamanında sabit ifadeler oluşturmak, kodun doğruluğunu ve güvenilirliğini artırır.
    - Sabit Veri Yapıları: constexpr kullanarak sabit boyutlu diziler ve diğer veri yapılarını tanımlayabilirsiniz.
- Özet
    - constexpr, derleme zamanında sabit ifadeler oluşturmak için kullanılır.
    - constexpr değişkenler ve fonksiyonlar, derleme zamanında değerlendirilebilir olmalıdır.
    - constexpr, performansı artırabilir ve kodun doğruluğunu kontrol edebilir.
    - C++14 ile birlikte, constexpr fonksiyonlar daha karmaşık yapılandırmalara izin verir.

- **templateleri ile kullanılıyor**
    ```cpp
    #include <iostream>

    // constexpr şablon fonksiyon tanımı
    template <typename T>
    constexpr T factorial(T n) {
        return (n <= 1) ? 1 : (n * factorial(n - 1));
    }

    int main() {
        // Derleme zamanında hesaplanır
        constexpr int result = factorial(5);

        std::cout << "Factorial of 5 is: " << result << std::endl;

        // Çalışma zamanında hesaplanır
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;
        int runtimeResult = factorial(num);

        std::cout << "Factorial of " << num << " is: " << runtimeResult << std::endl;

        return 0;
    }
    ```

- ++14 ve sonrasında, constexpr fonksiyonlar daha karmaşık yapılara ve daha uzun kodlara izin verir. C++11'de, constexpr fonksiyonlar yalnızca tek bir return ifadesine sahip olmalıydı ve basit olmalıydı. Ancak C++14 ile birlikte, constexpr fonksiyonlarda döngüler, koşullu ifadeler ve hatta lokal değişkenler kullanılabilir.
- her zaman compile time da değil burada biz 5 i kodu derlemeden önce veriyoruz bu hesaplanabilir ama mesela içine verdiğimiz değişkeni runtime da vericek isek normal const gibi davranır.
    ```cpp
    #include <iostream>

    // C++14 ve sonrasında daha karmaşık constexpr fonksiyonlar tanımlanabilir
    template <typename T>
    constexpr T factorial(T n) {
        T result = 1;
        for (T i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    int main() {
        // Derleme zamanında hesaplanan faktöriyel
        constexpr int compileTimeFactorial = factorial(5); // Derleme zamanında hesaplanır

        std::cout << "Factorial of 5 (compile-time): " << compileTimeFactorial << std::endl;

        // Çalışma zamanında hesaplanan faktöriyel
        int runtimeInput;
        std::cout << "Enter a number: ";
        std::cin >> runtimeInput;
        int runtimeFactorial = factorial(runtimeInput); // Çalışma zamanında hesaplanır

        std::cout << "Factorial of " << runtimeInput << " (runtime): " << runtimeFactorial << std::endl;

        return 0;
    }
    ```