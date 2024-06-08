# Polymorphism
- Polymorphism, nesne yönelimli programlamanın (OOP) dört temel prensibinden biridir ve "birçok biçim" anlamına gelir. 
- Polymorphism, bir nesneye veya bir fonksiyona farklı şekillerde davranabilme yeteneği sağlar. 
- Bu, aynı isimdeki metodların veya operatörlerin farklı şekillerde çalışabilmesi anlamına gelir. 
- Polymorphism, kodun esnek, genişletilebilir ve yeniden kullanılabilir olmasını sağlar.

## Content
- [Polymorphism Types](#polymorphism-types)
- [Compile-Time Polymorphism](#compile-time-polymorphism)
- [Runtime Polymorphism](#runtime-polymorphism)
- [Polymorphism Advantages](#polymorphism-advantages)
- [Virtual Keyword](#virtual-keyword)
- [Polymorphism ve Inheritence](#polymorphism-ve-inheritence)
- [Diamond Problem ve Virtual Base Classes](#diamond-problem-ve-virtual-base-classes)
- [Multilevel and virtual function](#multilevel-and-virtual-function)
- [Overriding rules](#overriding-rules)
- [Covariant Return Type](#covariant-return-type)
- [VTable-Virtual Table and VPtr-Virtual Pointer](#vtable-virtual-table-and-vptr-virtual-pointer)
- [RTTI Run-Time Type Information](#rtti-run-time-type-information)

## Polymorphism Types
- Polymorphism, genel olarak iki ana türe ayrılır: 
    - derleme zamanı (compile-time)(static polymorphism)
    - çalışma zamanı (runtime) polymorphism.(dynmaic polymorphism)

## Compile-Time Polymorphism
- Compile-time polymorphism, metod veya operatör aşırı yükleme (overloading) yoluyla gerçekleştirilir. Bu tür polymorphism, derleme zamanında çözülür.
- (Method Overloading): Aynı sınıf içinde aynı isimde ancak farklı parametre listesine sahip metodların tanımlanmasıdır.
- (Operator Overloading): C++'da mevcut operatörlerin, kullanıcı tanımlı türler için yeniden tanımlanmasıdır.
- function overloading example
    ```cpp
    #include <iostream>

    class Print {
    public:
        void show(int i) {
            std::cout << "Integer: " << i << std::endl;
        }
        void show(double d) {
            std::cout << "Double: " << d << std::endl;
        }
        void show(std::string s) {
            std::cout << "String: " << s << std::endl;
        }
    };

    int main() {
        Print obj;
        obj.show(10);        // Output: Integer: 10
        obj.show(10.5);      // Output: Double: 10.5
        obj.show("Hello");   // Output: String: Hello
        return 0;
    }
    ```
- operator overloading:
    ```cpp
    #include <iostream>

    class Complex {
    private:
        double real;
        double imag;

    public:
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

        // Overload the + operator
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        void display() const {
            std::cout << "Real: " << real << ", Imaginary: " << imag << std::endl;
        }
    };

    int main() {
        Complex c1(3.0, 4.0);
        Complex c2(1.0, 2.0);
        Complex c3 = c1 + c2;  // Using overloaded + operator
        c3.display();  // Output: Real: 4, Imaginary: 6
        return 0;
    }
    ```

## Runtime Polymorphism
- Runtime polymorphism, genellikle inheritence ve virtual fonksiyonlar (virtual functions) aracılığıyla gerçekleştirilir. 
- Bu tür polymorphism, çalışma zamanında çözülür(run time de karar verilir) ve temel sınıf işaretçileri veya referansları kullanılarak gerçekleştirilir. 
- data memberlarına bu geçerli değildir her zaman base classın özelliğini söyler aynı member da osla bile.
    - (Virtual Functions): Temel sınıfta tanımlanan ve türetilmiş sınıflar tarafından geçersiz kılınabilen fonksiyonlardır.
    - (Method Overriding): Türetilmiş sınıfta, temel sınıftaki sanal fonksiyonun yeniden tanımlanmasıdır.

- example: funciton overriding
    ```cpp
    #include <iostream>

    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function." << std::endl;
        }
        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        void show() override {
            std::cout << "Derived class show function." << std::endl;
        }
    };

    int main() {
        Base* basePtr;
        Derived derivedObj;
        basePtr = &derivedObj;

        basePtr->show();  // Output: Derived class show function.
        return 0;
    }
    ```
- example: data member
    ```cpp
    #include <bits/stdc++.h>
    using namespace std;
    
    //  base class declaration.
    class Animal {
    public:
        string color = "Black";
    };
    
    // inheriting Animal class.
    class Dog : public Animal {
    public:
        string color = "Grey";
    };
    
    // Driver code
    int main(void)
    {
        Animal d = Dog(); // accessing the field by reference
                        // variable which refers to derived
        cout << d.color; // output: Black
    }
    ```
## Polymorphism Advantages
- Esneklik ve Genişletilebilirlik: Polymorphism, kodun esnek ve genişletilebilir olmasını sağlar. Yeni sınıflar eklenerek mevcut yapı kolayca genişletilebilir.
- Kodun Yeniden Kullanılabilirliği: Ortak arayüzlerin ve metodların kullanılması, kodun yeniden kullanılabilirliğini artırır.
- Bakım Kolaylığı: Polymorphism, kodun bakımını ve güncellenmesini kolaylaştırır. Temel sınıfta yapılan değişiklikler, tüm türetilmiş sınıfları etkiler.
- Base clas ptr kullanrak türetilmiş sınıfları oluştupu bunları saklayabiliyoruz ya.şöyle bir avantaj olur. Base classından 3 tane derived tanımladın diyelim. hepsini base pointeri ile kullanırsan. bu 3 derivedi aynı arrayin içinde tutabilirsin mesela.

## Polymorphism ile İlgili Temel Kavramlar
- Virtual Functions (Sanal Fonksiyonlar): Temel sınıfta tanımlanır ve türetilmiş sınıflar tarafından geçersiz kılınabilir. Sanal fonksiyonlar, çalışma zamanında çağrılır ve dinamik bağlama (dynamic binding) kullanılır.
- Pure Virtual Functions (Saf Sanal Fonksiyonlar): Temel sınıfta sadece imzası tanımlanmış ve = 0 ile belirtilen fonksiyonlardır. Bu fonksiyonlar, türetilmiş sınıflar tarafından mutlaka geçersiz kılınmalıdır.
- Virtual Destructors (Sanal Yıkıcılar): Temel sınıfta tanımlanır ve türetilmiş sınıfların yıkıcılarının doğru şekilde çağrılmasını sağlar. Bellek sızıntılarını önlemek için sanal yıkıcılar kullanılır.

## Virtual Keyword
- virtual anahtar kelimesi, C++'da virtual fonksiyonlar, pure virtual fonksiyonlar ve virtual destructors oluşturmak için kullanılır. Kalıtım sırasında dinamik bağlama (dynamic binding) sağlamak için önemli bir rol oynar. 

- **Virtual Functions**:
    - Virtual fonksiyonlar, temel (base) sınıfta tanımlanan ve türetilmiş (derived) sınıflarda override edilebilen fonksiyonlardır. virtual fonksiyonlar, çalışma zamanında hangi fonksiyonun çağrılacağını belirlemek için dinamik bağlama kullanır.
    - virtual bir fonksiyonu sadece aynı class tarafından sadece bir kere override edebilirsin.
    - static olamaz
    - polymorphism mi kullanabilmek için ptr ları kullanmalısın.
    - virtual fonksiyonda default paremetre girebilirsin. bunu override ederken tekrar girmek zorunda değilsin.
    - inline olamazlar. Çünkü inline fonksiyonların kullanılıp kullanılmayacağını complier complile time da karar veriyor. virtuallar ise runtime de bind edilir.
    - code daki örnekte hem normal classlar hemde virtual fonksiyonlar kullanarak örnekler yazdım.
        - normal classlarda:
            - normal derived çağrımında show u düzgün çağırabiliyor.
            - normal ptr kullanırsan constrcutor ve destructor olması gereken sırayla çağrılıyor.(base kullanarak oluşturursan)
            - normal ptr show fonksiyonu hangisini kullancağını tam çözemeyip base classın showunu kullanıyor.(base kullanarak oluşturursan)
            - dynmaic memory allocation da destrcutor çağrılışında sadece base classın ki çağrılıyor. (base kullanarak oluşturursan). 
            - show fonksiyonu base i çağırıyor.
        - virtual fonksiyon kullanırsak:
            - normal derived çağrımında show u düzgün çağırabiliyor.
            - normal ptr kullanırsan constrcutor ve destructor olması gereken sırayla çağrılıyor. 
            - show fonksiyonu hangisini kullanacağını anlayabiliyor.
            - dynmaic memory allocation da destrcutor çağrılışında önce derived sonra base çağırlıyor tam olması gereken sıra.
            - show düzgün çağrılıyor.

    - bu virtual fonksiyonlar özellikle ptr veya dynmaic memory kullanacağın zaman kesinlikle kullanmalısın.
    - fonksiyon definitonunda bir kere override demen yeterlidir. declaration yaparken demene gerek yok.
    

    - **Pure Virtual Functions**: 
        - Pure Virtual fonksiyonlar, temel sınıfta sadece imzası bulunan ve = 0 ile tanımlanan fonksiyonlardır. Bu fonksiyonlar, türetilmiş sınıflar tarafından mutlaka override edilmelidir. Pure Virtual fonksiyonlar, bir sınıfı soyut (abstract) yapmak için kullanılır. ve bunu içeren classlardan direkt obje oluşturulamaz. pointerler yarıdmıyla alt sınıflar oluşturulabilir sadece.

            ```cpp
            #include <iostream>

            class Shape {
            public:
                virtual void draw() const = 0;  // Saf sanal fonksiyon
                virtual ~Shape() {}
            };

            class Circle : public Shape {
            public:
                void draw() const override {
                    std::cout << "Drawing a circle." << std::endl;
                }
            };

            int main() {
                Shape* shape = new Circle();
                shape->draw();  // Output: Drawing a circle.
                delete shape;
                return 0;
            }
            ```

        - Destrcutorlar de pure virtual olabilir. ama bodsy sinie ayrı şekilde tanımlamalısın örnek aşağıda. burada ayrı dosyalar oluşturman lazım ve bodysini cpp dosyasında yazman lazım.
        ```cpp
        //Abstact class
        #include <iostream>

        class AbstractBase {
        public:
            // Pure virtual destructor
            virtual ~AbstractBase() = 0;

            // Pure virtual function
            virtual void pureVirtualFunction() = 0;
        };

        // Destructor tanımı
        AbstractBase::~AbstractBase() {
            std::cout << "AbstractBase pure virtual destructor called\n";
        }

        // Derived class
        class Derived : public AbstractBase {
        public:
            // Constructor
            Derived() {
                std::cout << "Derived constructor called\n";
            }

            // Destructor
            ~Derived() override {
                std::cout << "Derived destructor called\n";
            }

            // Override pure virtual function
            void pureVirtualFunction() override {
                std::cout << "Derived pureVirtualFunction called\n";
            }
        };

        //kullanım
        int main() {
            AbstractBase* obj = new Derived();
            
            obj->pureVirtualFunction();
            
            delete obj;

            return 0;
        }

        /*
        Derived constructor called
        Derived pureVirtualFunction called
        Derived destructor called
        AbstractBase pure virtual destructor called
        */
        ```
        - Açıklamalar:
            - AbstractBase Sınıfı:
                - AbstractBase soyut sınıfı, saf sanal bir destructor tanımlar (virtual ~AbstractBase() = 0).
                - Destructor'ın tanımı sınıf dışında yapılır (AbstractBase::~AbstractBase()).
                - pureVirtualFunction adında bir saf sanal fonksiyon içerir.
            - Derived Sınıfı:
                - Derived sınıfı, AbstractBase sınıfından türetilir.
                - Derived sınıfı kendi destructor'ını tanımlar ve override anahtar kelimesi ile geçersiz kılar.
                - pureVirtualFunction fonksiyonunu geçersiz kılar ve işlevsellik sağlar.
            - Main Fonksiyonu:
                - AbstractBase sınıfı işaretçisi, Derived nesnesine işaret eder.
                - pureVirtualFunction fonksiyonu çağrılır.
                - delete operatörü kullanılarak nesne yok edilir ve destructor çağrılır.
    - **Virtual Destructors**
        - Sanal yıkıcılar, türetilmiş sınıfların yıkıcılarının doğru şekilde çağrılmasını sağlamak için kullanılır. Bellek sızıntılarını ve kaynak yönetimi sorunlarını önlemek için sanal yıkıcılar önemlidir.
        - Base ptr kullandığımızda dynmaic olarak allocate edersek, delete classının destrctorunu çağırmıyor ama virtual destrcutorlar kullanırsak çağırıyor.


            ```cpp
            #include <iostream>

            class Base {
            public:
                virtual ~Base() {  // Sanal yıkıcı
                    std::cout << "Base class destructor." << std::endl;
                }
            };

            class Derived : public Base {
            public:
                ~Derived() {
                    std::cout << "Derived class destructor." << std::endl;
                }
            };

            int main() {
                Base* basePtr = new Derived();
                delete basePtr;  // Output: Derived class destructor. Base class destructor.
                return 0;
            }
            ```
        - Pure virtual destrcutors:
            - pure virtual olarak tanımlayabilirsin ama bodysini de ayrı bir şekilde yazman lazım unutma.
            - C++'ta, saf sanal (pure virtual) yıkıcı (destructor), bir sınıfın soyut sınıf (abstract class) olmasını sağlamak ve bu sınıfın türetilmiş sınıflarının yıkıcılarını polimorfik olarak çağırabilmek için kullanılır. Bir sınıfın en az bir saf sanal fonksiyonu varsa, o sınıf soyut bir sınıf olur ve bu sınıftan doğrudan nesne oluşturulamaz.
                ```cpp
                #include <iostream>

                class Base {
                public:
                    virtual ~Base() = 0; // Pure virtual destructor

                    virtual void someFunction() = 0; // Pure virtual function
                };

                // Pure virtual destructor definition
                Base::~Base() {
                    std::cout << "Base destructor called" << std::endl;
                }

                class Derived : public Base {
                public:
                    ~Derived() {
                        std::cout << "Derived destructor called" << std::endl;
                    }

                    void someFunction() override {
                        std::cout << "Derived implementation of someFunction" << std::endl;
                    }
                };

                int main() {
                    Base* obj = new Derived();
                    obj->someFunction();
                    delete obj;

                    return 0;
                }
                    ```
## Polymorphism ve Inheritence
- Polymorphism, bir temel sınıf işaretçisi veya referansının, türetilmiş sınıflara ait fonksiyonları çağırabilmesini sağlar. Bu, çalışma zamanında hangi fonksiyonun çağrılacağını belirlemek için dinamik bağlama (dynamic binding) kullanır. Bu sayede, aynı işaretçi veya referans, farklı türetilmiş sınıfların fonksiyonlarını çağırabilir.
    ```cpp
    #include <iostream>

    class Animal {
    public:
        virtual void makeSound() const {  // Sanal fonksiyon
            std::cout << "Animal sound" << std::endl;
        }
    };

    class Dog : public Animal {
    public:
        void makeSound() const override {  // Geçersiz kılma
            std::cout << "Bark" << std::endl;
        }
    };

    class Cat : public Animal {
    public:
        void makeSound() const override {  // Geçersiz kılma
            std::cout << "Meow" << std::endl;
        }
    };

    int main() {
        Animal* animal1 = new Dog();
        Animal* animal2 = new Cat();

        animal1->makeSound();  // Output: Bark
        animal2->makeSound();  // Output: Meow

        delete animal1;
        delete animal2;

        return 0;
    }
    ```
    - Açıklama:
        - Temel Sınıf (Animal): Animal sınıfında makeSound adında bir sanal fonksiyon tanımlanmıştır.
        - Türetilmiş Sınıflar (Dog ve Cat): Dog ve Cat sınıfları, Animal sınıfından türetilmiştir ve makeSound fonksiyonunu geçersiz kılmıştır (override).
        - Polymorphism Kullanımı: Animal sınıfı işaretçileri animal1 ve animal2, sırasıyla Dog ve Cat nesnelerine işaret eder. animal1->makeSound() ve animal2->makeSound() çağrıları, dinamik bağlama sayesinde doğru türetilmiş sınıf fonksiyonlarını çağırır.

## Diamond Problem ve Virtual Base Classes 
- C++'da çoklu kalıtım sırasında, virtual anahtar kelimesi sanal taban sınıflar (virtual base classes) oluşturmak için kullanılabilir. Bu, elmas kalıtım sorununu (diamond problem) çözmek için kullanılır.
    ```cpp
    #include <iostream>

    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function." << std::endl;
        }
        virtual ~Base() {}
    };

    class Derived1 : virtual public Base {
    public:
        void show() override {
            std::cout << "Derived1 class show function." << std::endl;
        }
    };

    class Derived2 : virtual public Base {
    public:
        void show() override {
            std::cout << "Derived2 class show function." << std::endl;
        }
    };

    class Final : public Derived1, public Derived2 {
    public:
        void show() override {
            std::cout << "Final class show function." << std::endl;
        }
    };

    int main() {
        Final obj;
        obj.show();  // Output: Final class show function.
        return 0;
    }
    ```
## Multilevel and virtual function
- kullanımı aşağıdaki gibidir.
    ```cpp
    #include <iostream>

    // Taban sınıf
    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function." << std::endl;
        }
        virtual ~Base() {}
    };

    // Derived1 sınıfı, Base sınıfından türetilir
    class Derived1 : public Base {
    public:
        void show() override {
            std::cout << "Derived1 class show function." << std::endl;
        }
    };

    // Derived2 sınıfı, Derived1 sınıfından türetilir
    class Derived2 : public Derived1 {
    public:
        void show() override {
            std::cout << "Derived2 class show function." << std::endl;
        }
    };

    int main() {
        Base* basePtr;
        Derived2 derived2Obj;

        basePtr = &derived2Obj;
        basePtr->show();  // Output: Derived2 class show function.

        return 0;
    }
    ```
## Overriding rules
- inheritence de copy assignment de bunun örneğini yaptık.
- C++'da bir fonksiyonun türetilmiş bir sınıfta temel sınıftaki aynı isimdeki bir fonksiyonun yerini almasına (geçersiz kılma veya overriding) ilişkin belirli kurallar vardır. 

- Fonksiyon İmzalarının Aynı Olması:
    - override edilen fonksiyonun (fonksiyon adı, dönüş tipi ve parametre listesi) temel sınıftaki virtual fonksiyonun imzasıyla aynı olmalıdır. paremetresi tamamen aynı olucak dönüş değeri alt tür olabilir. (operator overload ı override ederken birebir aynı olmalı)
- Erişim Belirleyicileri:
    - Geçersiz kılınan fonksiyonun erişim belirleyicisi (public, protected veya private) temel sınıftaki fonksiyonun erişim belirleyicisiyle aynı veya daha geniş olmalıdır.
- virtual Anahtar Kelimesi:
    - Geçersiz kılınan fonksiyon, temel sınıfta virtual olarak tanımlanmış olmalıdır. Türetilmiş sınıfta virtual anahtar kelimesinin kullanılması zorunlu değildir, ancak okunabilirliği artırmak için override anahtar kelimesi kullanılabilir.
- Dönüş Tipi:
    - Geçersiz kılınan fonksiyonun dönüş tipi, temel sınıftaki fonksiyonun dönüş tipi ile aynı olmalıdır. Ancak, dönüş tipi türetilmiş sınıflar (covariant return types) için farklı olabilir. (dönüş tipleri pointer iken bunu yapabiliyoruz)
- const, volatile ve ref-kalifikasyonlar (ref-qualifiers):
    - Temel sınıftaki fonksiyon eğer const, volatile veya ref-kalifikasyonları (&, &&) içeriyorsa, türetilmiş sınıftaki geçersiz kılınan fonksiyon da aynı nitelikleri içermelidir.

## Covariant Return Type
- Covariant return type, türetilmiş bir sınıfta geçersiz kılınan (override edilen) bir sanal fonksiyonun dönüş tipinin, temel sınıftaki aynı fonksiyonun dönüş tipinin bir alt türü (derived type) olabilmesine izin verir. Bu, C++ dilinde türetilmiş sınıfların daha özel dönüş tipleri kullanmasına olanak tanır, böylece polimorfizm ve tür güvenliği korunur.

- Temel Sınıfta Sanal Fonksiyon (Virtual Function):
    - Temel sınıfta tanımlanan sanal fonksiyonun dönüş tipi bir sınıf türü olmalıdır.
- Türetilmiş Sınıfta Geçersiz Kılma (Overriding) Fonksiyonu:
    - Türetilmiş sınıfta geçersiz kılınan fonksiyonun dönüş tipi, temel sınıftaki fonksiyonun dönüş tipinin bir alt türü (derived type) olmalıdır. 
- (Önemli bilgi!!!!!!!): bu tür dönüşümü operator overloadingleri için geçerli değildir. Onda bu tarz yazamazsın. onda birebir aynı olmalıdır override ederken.
- dikkat ettiysen pointer döndürüyoruz farklı biçilerini yazabilmek için.(bu yüzden operator overloading vs yaparken farklı tür giremiyoruz işte)
    ```cpp
    #include <iostream>

    class Base {
    public:
        virtual Base* getInstance() {
            return new Base();
        }
        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        Derived* getInstance() override {  // Covariant return type
            return new Derived();
        }
    };

    int main() {
        Base* basePtr = new Derived();
        Base* newBase = basePtr->getInstance();

        // Çıktıyı kontrol edelim
        std::cout << "Base pointer type: " << typeid(basePtr).name() << std::endl;
        std::cout << "New Base pointer type: " << typeid(newBase).name() << std::endl;

        delete basePtr;
        delete newBase;
        return 0;
    }
    ```

    - derivedden dönen tür Base de olabilir. Ama return ettiğimiz değer derived türünde olmalıdır.
        ```cpp
        #include <iostream>

        class Base {
        public:
            virtual Base* getInstance() {
                std::cout << "Base::getInstance called." << std::endl;
                return new Base();
            }
            virtual ~Base() {}
        };

        class Derived : public Base {
        public:
            Base* getInstance() override {  // Aynı dönüş tipi (Base*)
                std::cout << "Derived::getInstance called." << std::endl;
                return new Derived();
            }
        };

        int main() {
            Base* basePtr = new Derived();
            Base* newBase = basePtr->getInstance();

            // Çıktıyı kontrol edelim
            std::cout << "Base pointer type: " << typeid(basePtr).name() << std::endl;
            std::cout << "New Base pointer type: " << typeid(newBase).name() << std::endl;

            delete basePtr;
            delete newBase;
            return 0;
        }
        ```
## VTable-Virtual Table and VPtr-Virtual Pointer
- C++ dilinde polimorfizm (çok biçimlilik) ve sanal fonksiyonlar (virtual functions) kullanıldığında, dinamik bağlama (dynamic binding) mekanizmasını sağlayan iki temel yapı vardır: VTable (Virtual Table) ve VPtr (Virtual Pointer). Bu yapılar, sanal fonksiyonların doğru şekilde çağrılmasını ve türetilmiş sınıfların temel sınıf referansları veya işaretçileri kullanılarak yönetilmesini sağlar.
### VTable (Virtual Table)
- VTable, bir sınıfın sanal fonksiyonlarının adreslerini içeren bir tablo (dizi) olarak düşünülebilir. Bu tablo, sınıfın her sanal fonksiyonu için bir giriş (entry) içerir ve her giriş, ilgili sanal fonksiyonun adresini (işaretçisini) gösterir. Sınıfın tüm nesneleri, bu tabloyu paylaşır.

### VPtr (Virtual Pointer)
- VPtr, bir nesnenin VTable'ını işaret eden bir işaretçidir. Her nesne, kendisine ait bir VPtr içerir ve bu işaretçi, nesnenin sınıfına ait VTable'ı gösterir. Bu sayede, sanal fonksiyon çağrıları dinamik olarak doğru fonksiyonun adresine yönlendirilir.

- **Çalışma Şekli**
- VTable Oluşturma:
    - Derleyici, her sınıf için bir VTable oluşturur. Bu tabloda, sınıfın sanal fonksiyonlarının adresleri bulunur.
    - Türetilmiş sınıflar, kendi VTable'larını oluşturur ve eğer sanal fonksiyonları geçersiz kılarsa, kendi VTable'larında ilgili girişleri bu yeni fonksiyonlarla doldurur.
- VPtr Atama:
    - Her nesne, kendi sınıfının VTable'ını işaret eden bir VPtr içerir. Bu işaretçi, nesne oluşturulduğunda otomatik olarak atanır.
    - Türetilmiş sınıf nesneleri, kendi sınıflarına ait VTable'ı işaret eden VPtr'lere sahiptir.

- Sanal Fonksiyon Çağrısı:
    - Sanal fonksiyon çağrısı yapıldığında, derleyici VPtr'yi kullanarak ilgili VTable girişine ulaşır ve doğru fonksiyon adresine yönlenir.

- ex: 
    ```cpp
    #include <iostream>

    class Base {
    public:
        virtual void show() {
            std::cout << "Base class show function called\n";
        }

        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        void show() override {
            std::cout << "Derived class show function called\n";
        }
    };

    void callShow(Base* b) {
        b->show();
    }

    int main() {
        Base* b = new Base();
        Derived* d = new Derived();

        // Base pointer pointing to Base object
        callShow(b);  // Output: Base class show function called

        // Base pointer pointing to Derived object
        callShow(d);  // Output: Derived class show function called

        delete b;
        delete d;

        return 0;
    }
    ```
- Açıklama
- Base Sınıfı:
    - Base sınıfı show adında bir sanal fonksiyon içerir.
    - Base sınıfının VTable'ı, Base::show fonksiyonunun adresini içerir.
- Derived Sınıfı:
    - Derived sınıfı Base sınıfından türetilir ve show fonksiyonunu geçersiz kılar.
    - Derived sınıfının VTable'ı, Derived::show fonksiyonunun adresini içerir.
- Fonksiyon Çağrıları:
    - callShow fonksiyonu, Base* türünde bir işaretçi alır ve show fonksiyonunu çağırır.
    - b işaretçisi Base nesnesini işaret eder ve Base::show çağrılır.
    - d işaretçisi Derived nesnesini işaret eder ve Derived::show çağrılır.
- Çalışma Mantığı:
    - Nesne Oluşturma:
        - new Base() ile oluşturulan b nesnesi, Base sınıfının VTable'ını işaret eden bir VPtr içerir.
        - new Derived() ile oluşturulan d nesnesi, Derived sınıfının VTable'ını işaret eden bir VPtr içerir.
- Fonksiyon Çağrısı:
    - b->show() çağrısı, b işaretçisinin VPtr'sini kullanarak Base sınıfının VTable'ına yönlenir ve Base::show çağrılır.
    - d->show() çağrısı, d işaretçisinin VPtr'sini kullanarak Derived sınıfının VTable'ına yönlenir ve Derived::show çağrılır.
- Sonuç
    - VTable ve VPtr, C++'da sanal fonksiyonlar ve polimorfizm mekanizmalarını destekler. VTable, sınıfın sanal fonksiyonlarının adreslerini içerirken, VPtr her nesnenin bu tabloyu işaret etmesini sağlar. Bu yapı, türetilmiş sınıfların sanal fonksiyonlarını dinamik olarak çağırmak için kullanılır.
## RTTI Run-Time Type Information
- RTTI (Run-Time Type Information) yani Çalışma Zamanı Tür Bilgisi, C++'da çalışma zamanında bir nesnenin türünü belirlemek için kullanılan bir mekanizmadır. RTTI, özellikle polimorfizm (çok biçimlilik) ve sanal fonksiyonlar (virtual functions) ile çalışırken faydalıdır. RTTI, C++ dilinde iki anahtar sözcükle desteklenir: dynamic_cast ve typeid.
- RTTI'nin Temel Kullanım Alanları
    - dynamic_cast:
        - Belirli bir türdeki işaretçiyi veya referansı, hiyerarşide başka bir türdeki işaretçiye veya referansa dönüştürmek için kullanılır.
        - Aşağıya doğru tür dönüşümleri (downcasting) yaparken güvenli bir şekilde kullanılabilir.
        - Sanal bir taban sınıfa sahip olmayı gerektirir. Ptr lar ile işlem yapıyoruz ya polymorhisme sahip olmalı.
        ```cpp
        #include <iostream>
        #include <typeinfo>

        class Base {
        public:
            virtual ~Base() = default; // Sanal yıkıcı, RTTI gereksinimi
        };

        class Derived : public Base {
        public:
            void derivedFunction() {
                std::cout << "Derived function called\n";
            }
        };

        int main() {
            Base* basePtr = new Derived();

            // Aşağıya doğru tür dönüşümü (downcasting)(objeyi kedni öz türüne döndürüyoruz aslında)
            Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
            if (derivedPtr) {
                derivedPtr->derivedFunction(); // Output: Derived function called
            } else {
                std::cout << "dynamic_cast failed\n";
            }

            delete basePtr;
            return 0;
        }
        ```
    - typeid:
        - Bir nesnenin türü hakkında bilgi edinmek için kullanılır.
        - Türü temsil eden bir type_info nesnesi döner.
        - Hem işaretçiler hem de referanslarla çalışır.
        - normal objelerde de çalışır ptr vs olmayan
        - primitive data type lar ile de çalışır.
        ```cpp
        #include <iostream>
        #include <typeinfo>

        class Base {
        public:
            virtual ~Base() = default; // Sanal yıkıcı, RTTI gereksinimi
        };

        class Derived : public Base {};

        int main() {
            Base* basePtr = new Derived();

            // `typeid` ile tür bilgisi edinme
            std::cout << "Type of basePtr: " << typeid(*basePtr).name() << std::endl; // Output: Type of basePtr: Derived (Derleyiciye bağlı olabilir)

            delete basePtr;
            return 0;
        }
        ```
- RTTI Kullanımı ve Önemli Noktalar
    - Güvenli Aşağıya Doğru Tür Dönüşümü (Downcasting):
        - dynamic_cast, bir türün başka bir türe güvenli bir şekilde dönüştürülmesini sağlar. Dönüşüm başarısız olursa, işaretçiler için nullptr, referanslar için std::bad_cast istisnası atar.

    - Tür Bilgisini Edinme:
        - typeid operatörü, bir nesnenin türü hakkında bilgi edinmenizi sağlar. Bu, özellikle polimorfik hiyerarşilerde faydalıdır.
    
    - virtual fonkisyon Gerekir:
        - RTTI kullanımı için, sınıfın en az bir sanal fonksiyonu (genellikle sanal yıkıcı) olmalıdır. Bu, tür bilgisinin saklanmasını ve erişilmesini sağlar.

    - Performans ve Kullanım:
        - RTTI kullanımı, tür kontrolü ve dönüştürme işlemleri sırasında bir miktar performans kaybına neden olabilir. Bu nedenle, performans kritik uygulamalarda dikkatli kullanılmalıdır.

- RTTI, C++ dilinde çalışma zamanında tür bilgisi edinmeyi ve güvenli tür dönüşümleri yapmayı sağlayan güçlü bir mekanizmadır. dynamic_cast ve typeid operatörleri, RTTI'nin temel bileşenleridir ve polimorfik sınıf hiyerarşilerinde doğru tür kontrolü ve dönüşümü yapmanızı sağlar. RTTI'nin doğru ve etkin kullanımı, C++ programlarındaki tür güvenliğini ve esnekliği artırır.