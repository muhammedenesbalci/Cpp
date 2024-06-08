# Exception Handling
- C++'ta exception handling, programın normal akışını bozan hataları veya istisnai durumları ele almak için kullanılan bir mekanizmadır. Bu mekanizma, hataların düzgün bir şekilde yönetilmesini ve programın çökmeden hatalardan kurtulmasını sağlar. C++'ta exception handling, üç ana anahtar kelime kullanılarak gerçekleştirilir: try, throw ve catch.

## Content
- [Temel Kavramlar](#temel-kavramlar)
- [General Behavior](#general-behavior)
- [Exception Types](#exception-types)
- [Custom Exception Class](#custom-exception-class)
- [Stack Unwinding](#stack-unwinding)
- [RAII Resource Acquisition Is Initialization](#raii-resource-acquisition-is-initialization)

## Temel Kavramlar
1. try: Hata olasılığı bulunan kod bloğu try anahtar kelimesi ile tanımlanır. Bu blokta bir hata meydana geldiğinde, bu hata bir exception olarak "fırlatılır".
- syntax:
    ```cpp
    try {
        // Hata olasılığı bulunan kod buraya gelir
    }
    ```
2. throw: Bir hata meydana geldiğinde throw anahtar kelimesi kullanılarak bir exception fırlatılır. throw ifadesi ile birlikte, fırlatılan exception'ın türü veya hata mesajı belirtilir. herhangi primitive tür de atabilirsin int gibi. if koşulu kullanarak.
- syntax: 
    ```cpp
    if (some_error_condition) {
        throw std::runtime_error("Bir hata oluştu!");
    }
    ```
3. catch: Fırlatılan exception, catch bloğunda yakalanır ve işlenir. catch bloğu, try bloğunun hemen ardından gelir ve belirli türdeki exception'ları yakalar. birdean fazla catch bloklarıyla farklı türde throwlar atabiliriz.
- syntax:
    ```cpp
    try {
        // Hata olasılığı bulunan kod
    } catch (const std::exception& e) {
        // Hata yakalandı ve işleniyor
        std::cerr << "Hata: " << e.what() << std::endl;
    }
    ```

- example code: 
    ```cpp
    #include <iostream>
    #include <stdexcept>

    void divide(int a, int b) {
        if (b == 0) {
            throw std::invalid_argument("Bölen sıfır olamaz!");
        }
        std::cout << "Sonuç: " << a / b << std::endl;
    }

    int main() {
        try {
            divide(10, 0);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Hata: " << e.what() << std::endl;
        }

        return 0;
    }
    ```
## General Behavior
- Genel catch bloğu her türlü hatayı yakalar ama türü belli değildir. catch_call (catch(...))
- exceptionlar throw atarken implict tür dönüşümü yoktur. direkt uygununu atmalısn.
    ```cpp
    int main()
    {
        try {
            throw 'a';
        }
        catch (int x) {
            cout << "Caught " << x;
        }
        catch (...) {
            cout << "Default Exception\n";
        }
        return 0;
    }
    // Default Exception
    ```
- bir exception atıldı ama hiç bir catch bloğuna uygun değilse program abnormal bir şekilde durur.
    ```cpp
    int main()
    {
        try {
            throw 'a';
        }
        catch (int x) {
            cout << "Caught ";
        }
        return 0;
    }
    // terminate called after throwing an instance of 'char'
    ```
- bir fonksiyon hata fırlatıyorsa 'throw' keywordunu kullanabilirsin. ama modern cpp de bu keyword fonksiyonlarların yanına konması kaldırılmıştır. eğer hata fırlattığı değilde hata fırlatmadığını belirtmek istiyorsan 'noexcept' keywordu kullanılır.
- iç içe try catch yazılabilir.
- try bloğunun içinde bir obje oluşturuyorsan be throw a denk geldiysen trydan çıkmadan önce objenin destructoru çağrılır.
    ```cpp
    #include <iostream>
    using namespace std;
    
    // Define a class named Test
    class Test {
    public:
        // Constructor of Test
        Test() { cout << "Constructor of Test " << endl; }
        // Destructor of Test
        ~Test() { cout << "Destructor of Test " << endl; }
    };
    
    int main()
    {
        try {
            // Create an object of class Test
            Test t1;
    
            // Throw an integer exception with value 10
            throw 10;
        }
        catch (int i) {
            // Catch and handle the integer exception
            cout << "Caught " << i << endl;
        }
    }
    /*
    Constructor of Test 
    Destructor of Test 
    Caught 10
    */
    ```
## Exception Types
- exception kütüphanesini include etmeyi unutma.
- **Compile time**
- derleme zamanı (compile time) hataları genellikle syntax hataları olarak bilinir. Derleme zamanı hataları, kodunuzun derleyici tarafından derlenirken tespit edilen hatalardır. Bu hatalar, derleyicinin kodunuzu çalıştırılabilir bir programa dönüştürmesini engeller ve genellikle kodunuzda yazım, sözdizimi veya dil kurallarına uymayan bir sorun olduğunda meydana gelir.
    - Syntax Hataları
        ```cpp
        int main() {
            std::cout << "Hello, World!" // Eksik noktalı virgül
        }
        ```
    - tür Uyumsuzlukları
        ```cpp
        int main() {
            int a = "string"; // int yerine string atanmış
        }
        ```
    - Tanımsız Değişken veya Fonksiyon Kullanımı:
        ```cpp
        int main() {
            std::cout << value; // value değişkeni tanımlanmamış
        }

        ```
    - Erişim Hataları:
        ```cpp
        class MyClass {
        private:
            int privateValue;
        };

        int main() {
            MyClass obj;
            std::cout << obj.privateValue; // privateValue private olarak tanımlanmış
        }

        ```
    - Eksik Header Dosyaları:
        ```cpp
        int main() {
            std::cout << "Hello, World!"; // <iostream> header dosyası dahil edilmemiş
        }
        ```
- **Ana Exception Sınıfı**
    - std::exception: Tüm standart exception sınıflarının temel sınıfıdır. Genellikle doğrudan kullanılmaz, ancak tüm exception türlerini yakalamak için kullanılabilir.
    -throw dedikten sonra içine bir hata mesajı verebiliriz. e.what() diyerek bunu yazdırabiliriz.
- **Logical Errors**
    - std::logic_error: Mantıksal hataların temel sınıfıdır.
    - std::invalid_argument: Geçersiz bir argüman sağlandığında kullanılır.
    - std::domain_error: Matematiksel bir işlevin geçersiz bir argümanla çağrılması durumunda kullanılır.
    - std::length_error: Bir konteynerin uzunluğunun aşılması durumunda kullanılır.
    - std::out_of_range: Geçersiz bir dizin veya indis erişimi durumunda kullanılır.
- **Runtime Errors**
    - std::runtime_error: Çalışma zamanı hatalarının temel sınıfıdır.
    - std::range_error: Matematiksel işlemlerde geçersiz bir aralık kullanıldığında kullanılır.
    - std::overflow_error: Bir aritmetik taşma durumunda kullanılır.
    - std::underflow_error: Bir aritmetik alt taşma durumunda kullanılır.
- **Memory Management Errors**
    - std::bad_alloc: Bellek tahsisi başarısız olduğunda kullanılır. Genellikle new operatörü tarafından fırlatılır.
    - std::bad_array_new_length: new[] operatörü ile geçersiz bir dizi uzunluğu sağlandığında kullanılır.
    - std::bad_cast: dynamic_cast ile başarısız bir tür dönüşümü olduğunda kullanılır.
    - std::bad_typeid: typeid operatörü ile geçersiz bir tür bilgisi elde edilmeye çalışıldığında kullanılır.
    - std::bad_exception: Bir exception türü beklenmedik olduğunda kullanılır
- **Input/Output**
    - std::ios_base::failure: Giriş/çıkış işlemlerinde bir hata meydana geldiğinde kullanılır.
- **C++11 ve Sonrası**
    - std::system_error: Sistemle ilgili hataları temsil eder.
    - std::filesystem_error: Dosya sistemi işlemlerinde meydana gelen hatalar için kullanılır. (C++17)
    - std::regex_error: Düzenli ifade işlemlerinde bir hata meydana geldiğinde kullanılır. (C++11)
    - std::future_error: Asenkron işlemler ve std::future ile ilgili hatalar için kullanılır. (C++11)
    - std::bad_function_call: Geçersiz bir std::function çağrısı yapıldığında kullanılır. (C++11)
    - std::bad_weak_ptr: Geçersiz bir std::weak_ptr kullanıldığında kullanılır. (C++11)
    - std::bad_variant_access: Geçersiz bir std::variant erişimi yapıldığında kullanılır. (C++17)
    - std::bad_optional_access: Geçersiz bir std::optional erişimi yapıldığında kullanılır. (C++17)
    
## Custom Exception Class
- Kendi özel exception sınıflarınızı tanımlayabilirsiniz:
    ```cpp
    class MyException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Özel bir hata meydana geldi!";
        }
    };

    int main() {
        try {
            throw MyException();
        } catch (const MyException& e) {
            std::cerr << "Hata: " << e.what() << std::endl;
        }

        return 0;
    }
    ```

## Stack Unwinding
- içe içe fonksiyonlar yazarken karşımıza çıkıyor. atılan hata direkt yakalanmadığında ama iç içe fonksiyonlardan ilk çağrılan fonksiyon try catch içinde yazıldığında meydana gelir.
- Stack unwinding, C++'ta bir exception fırlatıldığında ve yakalanmadığında, çağrı yığınındaki fonksiyonların geri alınması işlemidir. Bu süreçte, exception fırlatılmadan önce çağrılmış olan fonksiyonlar sırasıyla geri döner ve her birinin yerel değişkenleri ve kaynakları düzgün bir şekilde temizlenir. Bu, destructors (yıkıcılar) ve RAII (Resource Acquisition Is Initialization) mekanizmaları aracılığıyla gerçekleştirilir.
    1. Exception Fırlatılır: Bir exception fırlatıldığında, çağrı yığınındaki mevcut fonksiyon derhal durur ve kontrol üst fonksiyona geçer.
    2. Destructors Çağrılır: Çağrı yığınındaki her bir fonksiyonun yerel değişkenleri ve kaynakları, bu fonksiyonlardan çıkılırken temizlenir. Bu, destructors tarafından gerçekleştirilir.
    3. Catch Bloğuna Kadar Devam Eder: Exception, çağrı yığınında uygun bir catch bloğu bulunana kadar yukarı doğru hareket eder. Uygun bir catch bloğu bulunduğunda, exception yakalanır ve işlenir.
    4. Uncaught Exception: Eğer çağrı yığınında uygun bir catch bloğu bulunamazsa, program std::terminate fonksiyonunu çağırarak sonlanır.

- example exp: 
    - main fonksiyonu functionA fonksiyonunu çağırır.
    - functionA, Resource nesnesi resA oluşturur.
    - functionA, functionB fonksiyonunu çağırır.
    - functionB, Resource nesnesi resB oluşturur.
    - functionB, functionC fonksiyonunu çağırır.
    - functionC, Resource nesnesi resC oluşturur ve ardından bir std::runtime_error exception'ı fırlatır.
    - functionC fonksiyonu exception fırlatıldığı anda durur ve destructors çağrılır: resC yok edilir.
    - functionB exception'ı yakalamadığı için geri döner ve destructors çağrılır: resB yok edilir.
    - functionA exception'ı yakalar ve destructors çağrılır: resA yok edilir.
    - Exception functionA tarafından yakalanır ve hata mesajı ekrana yazdırılır.

## RAII Resource Acquisition Is Initialization
- RAII (Resource Acquisition Is Initialization), C++'ta kaynak yönetimi için kullanılan bir idiomdur. Bu idiom, bir nesnenin ömrü boyunca kaynakların tahsis edilmesini ve serbest bırakılmasını garanti eder. RAII, bir nesne oluşturulduğunda kaynakların tahsis edilmesini ve nesne yok edildiğinde kaynakların serbest bırakılmasını sağlar.

- **RAII'nin Temel İlkeleri**
    - Kaynakların Tahsisi (Acquisition): Bir kaynak (bellek, dosya, kilit, vb.) bir nesnenin yapıcısı (constructor) tarafından tahsis edilir.
    - Kaynakların Serbest Bırakılması (Release): Kaynaklar, nesnenin yıkıcısı (destructor) tarafından serbest bırakılır.

- Bu sayede, nesneler kapsamdan çıktığında (örneğin, bir fonksiyondan döndüklerinde veya bir blok sonlandığında), kaynaklar otomatik olarak serbest bırakılır. Bu, bellek sızıntıları ve diğer kaynak yönetimi sorunlarını önler.
- RAII'nin Kullanım Alanları
    - Dinamik bellek yönetimi (std::unique_ptr, std::shared_ptr)
    - Dosya işlemleri (std::ifstream, std::ofstream)
    - Kilitler ve eşzamanlama (std::lock_guard, std::unique_lock)
    - Grafik kaynakları (OpenGL, DirectX gibi grafik API'lerinde kullanılan kaynak yönetimi sınıfları)
    - temel veri türleri
    - dynamic olmayan strcut class objelerimiz.