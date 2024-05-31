# Polymorphism
- Polymorphism, Object-Oriented Programming (OOP) kavramları arasında yer alan ve "çok biçimlilik" olarak da adlandırılan önemli bir prensiptir. Polymorphism, bir nesnenin farklı şekillerde işlem görmesini sağlar ve bu esneklik, yazılımın daha modüler, genişletilebilir ve bakımının kolay olmasını sağlar. Polymorphism, iki ana kategoriye ayrılır: 
    - Compile-time Polymorphism (Static Polymorphism)
        - function overloading
        - operator overloading
    - Runtime Polymorphism (Dynamic Polymorphism).
        - virtual function 
        - function overriding

## Content
- [Static Polymorphism or Compile-time Polymorphism](#static-polymorphism-or-compile-time-polymorphism)
    - [Function Overloading](#function-overloading)
    - [Operator Overloading](#operator-overloading )
- [Dynamic Polymorphism or Runtime Polymorphism](#dynamic-polymorphism-or-runtime-polymorphism)
    - [virtual functions](#virtual-functions)
    - [funciton overriding](#funciton-overriding)
- [Difference function overloading and overriding](#difference-function-overloading-and-overriding)

## Static Polymorphism or Compile-time Polymorphism
- Compile-time polymorphism, derleme zamanında çözümlenir ve genellikle function overloading (fonksiyon aşırı yükleme) ve operator overloading (operatör aşırı yükleme) ile gerçekleştirilir. (Aynı sınıf içiinde olan kavramlar)

### Function Overloading
- Aynı isimde birden fazla fonksiyon tanımlanabilir ancak bu fonksiyonlar farklı parametre listelerine sahip olmalıdır. Derleyici, hangi fonksiyonun çağrılacağını parametrelerin sayısı ve türlerine göre belirler. Fonksiyon içerikleri de farklı olabilir.(Constrcutorlarda olukça fazla kullanıyoruz)

    ```cpp
    class Math {
    public:
        int add(int a, int b) {
            return a + b;
        }

        double add(double a, double b) {
            return a + b;
        }
    };

    Math math;
    int result1 = math.add(5, 3);        // int add(int, int) çağrılır
    double result2 = math.add(2.5, 3.5); // double add(double, double) çağrılır
    ```

### Operator Overloading
- Operator Overloading : C++ dilinde mevcut olan operatörlerin, kullanıcı tanımlı veri türleri için nasıl davranacağını belirlemek mümkündür. Bu, sınıflar için daha doğal bir kullanım sağlar. Normal operatörlerin bizim yazdığımız şekilde çalışması. mesela + operatörünü * operatörüne çevirebilirsin.
    ```cpp
    class Complex {
    private:
        double real;
        double imag;

    public:
        Complex(double r, double i) : real(r), imag(i) {}

        Complex operator + (const Complex& other) {
            return Complex(real + other.real, imag + other.imag);
        }
    };

    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);
    Complex c3 = c1 + c2; // operator + çağrılır
    ```
## Dynamic Polymorphism or Runtime Polymorphism
- Runtime polymorphism, çalışma zamanında çözümlenir ve genellikle inheritance (kalıtım) ve virtual functions (sanal fonksiyonlar) aracılığıyla gerçekleştirilir. Bu tür polymorphism, aynı taban sınıfı paylaşan farklı nesnelerin, aynı arayüz üzerinden farklı davranışlar sergilemesini sağlar. (Farklı classlar arasında kullanılır, Inheritence ile)

## virtual functions
- Taban sınıfta virtual olarak tanımlanan bir fonksiyon, türemiş sınıflarda yeniden tanımlanabilir. Çalışma zamanında, hangi fonksiyonun çağrılacağı nesnenin gerçek türüne bağlı olarak belirlenir. 
- Bir fonksiyonun override edilebilmesi için virtual anahtar kelimesi kullanmalısın. eğer dümdüz yazarsan o overriding değildir. aynı isimle yeni bir fonksiyon çağırmış olursun.
- override edilebilir fonksiyonlar yazmak istiyorsan virtual kullan ana classda.
    ```cpp
    class Animal {
    public:
        virtual void makeSound() const {
            std::cout << "Some generic animal sound" << std::endl;
        }
    };

    class Dog : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Woof" << std::endl;
        }
    };

    class Cat : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Meow" << std::endl;
        }
    };

    void makeAnimalSound(const Animal& animal) {
        animal.makeSound();
    }

    Animal a;
    Dog d;
    Cat c;

    makeAnimalSound(a); // "Some generic animal sound"
    makeAnimalSound(d); // "Woof"
    makeAnimalSound(c); // "Meow"
    ```
## funciton overriding
- Türemiş sınıf, taban sınıfta tanımlanan bir sanal(virtual) fonksiyonu yeniden tanımladığında geçersiz kılma (overriding) gerçekleşir. Overriding, taban sınıfta tanımlanan bir fonksiyonun, türemiş sınıfta farklı bir şekilde davranmasını sağlar.(virtual fonksiyonlardan yapılabilir sadece). 
- Aslında virtual ile overriding konuları iç içe. 
- Overriding için virtual gerekli. Virtual olursa da her türlü overriding yapıyoruz ya da yazabiliyoruz. override etmek istediğin fonksiyonların başına virtual koy. 
- bu kelimetyi kullanmak zorunlu değil fakat öneriliyor. Overriding de yazamasak yine de override edilir.
- ama sen kullan.
    ```cpp
    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function" << std::endl;
        }
    };

    class Derived : public Base {
    public:
        void show() override {
            std::cout << "Derived class show function" << std::endl;
        }
    };

    void display(Base& obj) {
        obj.show();
    }

    Base baseObj;
    Derived derivedObj;

    display(baseObj);      // "Base class show function" çağrılır
    display(derivedObj);   // "Derived class show function" çağrılır
    ```

## Difference function overloading and overriding
- Function Overloading
    - Derleme Zamanı Polimorfizmi (Compile-Time Polymorphism) altında yer alır.
    - Bir fonksiyon birden fazla kez overload edilebilir, çünkü derleme zamanında çözülür.
    - Kalıtım olmadan da gerçekleştirilebilir.
    - Aynı kapsamda (scope) bulunurlar.
- Function Overriding
    - Çalışma Zamanı Polimorfizmi (Runtime Polymorphism) altında yer alır.
    - Bir fonksiyon birden fazla kez override edilemez(aynı scope da), çünkü çalışma zamanında çözülür.
    - Kalıtım olmadan gerçekleştirilemez.
    - Farklı kapsamda (scope) bulunurlar (base class ve derived class).

###
- virtual kullanan birde virtual kullanmadan overriding yapmaya çalışan classların farkını göstericem