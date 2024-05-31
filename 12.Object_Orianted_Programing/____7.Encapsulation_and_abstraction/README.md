# Encapsulation and Absraction
- [Encapsulation](#encapsulation)
- [Abstraction](#abstraction)
- [Difference absract class and interface](#difference-absrac-class-and-interface)

## Encapsulation
- Encapsulation, nesne yönelimli programlamanın (OOP) temel prensiplerinden biridir. Nesnelerin durumunu (veri üyeleri veya değişkenler) ve bu durum üzerinde çalışan davranışlarını (metotlar veya fonksiyonlar) tek bir birim (sınıf) içinde bir araya getirir. Bu prensip, verilerin dışarıdan doğrudan erişimini sınırlandırarak veri bütünlüğünü ve güvenliğini sağlamayı amaçlar.

- özellikle data member ların doğrudan erişimini kısıtlayp metotlar aracılığıyla değiştirilmesini sağlamak.

- private, protected, public yani acces modifiers kullanımı. private veya protected kısımlarda data member ları tanımlarız. Bunlara ulaşabilmek için de getter ve setter dediğimiz kavram. Yani public fonksiyonlar bu private değişkenle ulaşabilmek için kullanırız. Acces modoifiers ve getter ve setter ana kavramı bunlardır. Bu yöntem verileri değiştiriken yanlışlıkla değilde isteyerek değiştirmemiz için var(getter ve setter lar ile).

- bu getter ve setter fonksiyonları sadece data member ları kullanmalı o zaman tam bir encapsulation yapmış oluruz. başka parametreler almamalı.

- classes and object bölümünde acces specifiersler yer alıyor.
- Private: Private access specifier means that the member function or data member can only be accessed by other member functions of the same class.
- Protected: A protected access specifier means that the member function or data member can be accessed by other member functions of the same class or by derived classes.
- Public: Public access specifier means that the member function or data member can be accessed by any code.
- eğer acces specifier belirtmezsen default olarak private'dır.

- **Encapsulation'ın Temel Unsurları**
    - Data Hiding (Veri Gizleme):
        - Sınıfın içindeki data members genellikle private veya protected erişim belirteçleri ile tanımlanır, böylece sınıf dışından doğrudan erişim engellenir.
    - Public Methods (Açık Metotlar):
        - Sınıfın dış dünyayla etkileşime geçmesini sağlayan public metotlar oluşturulur. Bu metotlar aracılığıyla sınıfın veri üyelerine erişim ve bu veriler üzerinde işlem yapılması sağlanır.
- **Encapsulation'ın Avantajları**
    - Veri Güvenliği ve Bütünlüğü:
        - Veri üyeleri yalnızca sınıf içindeki belirli metotlar aracılığıyla erişilebilir olduğundan, veri üzerinde yanlış veya beklenmedik değişiklikler yapılmasının önüne geçilir.
    - Bakım Kolaylığı:
        - Kodun bir bölümünde yapılan değişikliklerin diğer bölümleri etkileme olasılığı azalır. Sınıfın iç yapısı değiştirildiğinde, dış dünyayla olan arayüz aynı kaldığı sürece, bu değişiklikler diğer kodları etkilemez.
    - Modülerlik:
        - Kodun farklı bölümleri daha bağımsız ve modüler hale gelir. Bu da kodun okunabilirliğini ve yeniden kullanılabilirliğini artırır.
- **example explanation**:
    - Veri euğGizleme (Data Hiding):
        pwyeuğ width ve height veri üyeleri private olarak tanımlanmıştır, böylece dışarıdan t,doğrudan erişim engellenmiştir.
    - Public Methods (Açık Metotlar):

        - setWidth(double w) ve setHeight(double h): Genişlik ve yükseklik değerlerini ayarlamak için kullanılır. Pozitif olmayan değerler için bir hata mesajı verir.
        - getWidth() const ve getHeight() const: Genişlik ve yükseklik değerlerini döner.
        - getArea() const: Dikdörtgenin alanını hesaplayıp döner.

    - Veri Güvenliği ve Bütünlüğü:
        wy Geğenişlik ve yükseklik yalnızca pozitif değerlerle ayarlanabilir, böylece dörtgenin geçerli boyutlara sahip olması sağlanır.

## Abstraction
- ayrıntıısnı inheritenceden sonra işleyeceğiz. burada bir önizleme var sadece
- Abstraction (Soyutlama), nesne yönelimli programlamanın (OOP) temel prensiplerinden biridir. Abstraction, karmaşıklığı azaltmak ve gereksiz ayrıntıları gizlemek amacıyla kullanılır. Bu prensip, kullanıcıların yalnızca bir nesnenin veya sistemin ne yaptığını bilmesini sağlar, nasıl yaptığını değil. Başka bir deyişle, abstraction, bir nesnenin veya sistemin iç işleyiş detaylarını gizleyerek, sadece temel işlevselliği ortaya koyar.

- **Abstraction'ın Temel Unsurları**:
    - Karmaşıklığı Gizleme:
        - Kullanıcıya yalnızca gerekli ve önemli bilgileri sunar, ayrıntılı iç işleyişi gizler.
        - Kullanıcı, nesnenin veya sistemin nasıl çalıştığını bilmek zorunda kalmadan, onunla etkileşime girebilir.

    - Interface and Absract classes:

        - Abstraction, genellikle arayüzler (interfaces) ve soyut sınıflar (abstract classes) kullanılarak gerçekleştirilir.
        - Interface, bir nesnenin ne yapabileceğini tanımlar, ancak bu işlevlerin nasıl gerçekleştirileceği soyutlanır.
        - Absract sınıflar, bazı temel işlevleri tanımlayabilir ve alt sınıfların bu işlevleri kendilerine özgü şekilde uygulamasını zorunlu kılar.

- **Abstraction'ın Avantajları**
    - Karmaşıklığı Azaltır:
        - Kullanıcının veya geliştiricinin yalnızca gerekli bilgileri bilmesini sağlayarak, karmaşıklığı yönetilebilir hale getirir.

    - Bakım ve Genişletme Kolaylığı:
        - Soyutlama sayesinde, sistemin iç işleyişi değiştirilse bile, dışarıya sunulan arayüz aynı kaldığı sürece, diğer bileşenler etkilenmez.

    - Kodun Yeniden Kullanımı:
        - Abstraction, genel işlevlerin yeniden kullanılabilir olmasını sağlar. Farklı sınıflar, aynı arayüzü veya soyut sınıfı kullanarak, bu işlevleri kendi ihtiyaçlarına göre uygulayabilir.

    - örnek
        ```cpp
        #include <iostream>

        // Abstract class
        class Shape {
        public:
            // Pure virtual function providing interface framework.
            virtual void draw() = 0;
        };

        // Concrete class implementing Shape interface
        class Circle : public Shape {
        public:
            void draw() override {
                std::cout << "Drawing a Circle" << std::endl;
            }
        };

        // Concrete class implementing Shape interface
        class Square : public Shape {
        public:
            void draw() override {
                std::cout << "Drawing a Square" << std::endl;
            }
        };

        int main() {
            Circle circle;
            Square square;

            Shape* shapes[] = { &circle, &square };

            for (Shape* shape : shapes) {
                shape->draw();
            }

            return 0;
        }
        ```
    - açıklama
        - Soyut Sınıf (Shape):
            - Shape sınıfı soyut bir sınıftır ve draw isimli saf (pure) sanal (virtual) fonksiyon içerir. Bu, Shape sınıfının alt sınıflarının draw fonksiyonunu uygulamasını zorunlu kılar.
        - Alt Sınıflar (Circle ve Square):
            - Circle ve Square sınıfları, Shape sınıfından türetilmiştir ve draw fonksiyonunu kendilerine özgü şekilde uygularlar.
        - Polimorfizm:
            - main fonksiyonunda, Shape türünde bir dizi (array) kullanarak, farklı şekillerin draw fonksiyonları polimorfizm ile çağrılır.
        
        - Bu örnekte, abstraction kullanılarak şekillerin nasıl çizildiği gizlenmiş ve yalnızca şekil çizme işlemi için gerekli olan draw fonksiyonu sunulmuştur. Bu, kullanıcıların veya diğer sistem bileşenlerinin yalnızca draw fonksiyonunu bilerek, şekil çizme işlemi yapabilmesini sağlar.

## Difference absract class and interface
### Abstract Class (Soyut Sınıf)
- Bir soyut sınıf, bazı veya tüm metotları soyut (abstract) olan bir sınıftır. Soyut metotlar, yalnızca imzası tanımlanan ve alt sınıflar tarafından uygulanması gereken metotlardır. Soyut sınıflar genellikle temel sınıf olarak kullanılır ve alt sınıflara ortak bir arayüz sağlar.
    ```cpp
    class AbstractClass {
    public:
        virtual void abstractMethod() = 0; // Pure virtual function
        void concreteMethod() {
            // Normal method
        }
    };
    ```
- Özellikleri:
    - Soyut Metotlar ve Normal Metotlar:
        - Soyut sınıflar, hem soyut (pure virtual) metotlar hem de normal (non-abstract) metotlar içerebilir.
        - Soyut metotların gövdesi olmaz ve alt sınıflar tarafından uygulanmak zorundadır.
        - veri üyeleride içerebilir ama çok kullanılmaz.

    - Çoklu Kalıtım:
        - çoklu kalıtıma olanak tanır.

    - Uygulama Zorunluluğu:
        - Abstract sınıfından türetilen sınıflar, Abstract tanımlanan tüm methodları uygulamasına gerek yok. Sadece pure virtual olanlar uygulanmak zorundadır. normal fonkiyonlar direkt kullanılabilir.

    - Nesne Oluşturulamaz:
        - Soyut sınıflardan doğrudan nesne oluşturulamaz. Sadece alt sınıfları türetilerek kullanılabilir.



### Interface Class (Arayüz Sınıfı)
- Arayüz sınıfı, yalnızca soyut metotların (pure virtual functions) bulunduğu bir sınıftır. Arayüzler, sınıflar arasında bir sözleşme sağlar ve belirli metotların uygulanmasını zorunlu kılar.
    ```cpp
    class Interface {
    public:
        virtual void method1() = 0; // Pure virtual function
        virtual void method2() = 0; // Pure virtual function
    };
    ```
- Özellikleri:
    - Sadece Soyut Metotlar:
        - Arayüz sınıfları sadece soyut metotlar içerir ve bu metotların gövdesi olmaz.
        - Veri üyeleri veya normal metotlar içermez.

    - Çoklu Kalıtım:
        - C++'ta, bir sınıf birden fazla arayüzden (interface) türetilebilir, bu da çoklu kalıtıma olanak tanır.

    - Uygulama Zorunluluğu:
        - Arayüz sınıfından türetilen sınıflar, arayüzde tanımlanan tüm metotları uygulamalıdır.

    - Nesne Oluşturulamaz:
        - Soyut sınıflardan doğrudan nesne oluşturulamaz. Sadece alt sınıfları türetilerek kullanılabilir.
    
- **Abstract Class ve Interface Class Arasındaki Farklar**
- Metotlar ve Veri Üyeleri:
    - absract Sınıf: Hem soyut hem de normal metotlar içerebilir. Ayrıca veri üyeleri de olabilir.
    - interface Sınıfı: Yalnızca soyut metotlar içerir, normal metotlar ve veri üyeleri içermez.

- Kalıtım (Inheritance):
    - absract Sınıf: Tekli veya çoklu kalıtımda kullanılabilir. Alt sınıflar, soyut sınıfın hem soyut hem de normal metotlarını ve veri üyelerini miras alır.
    - interface Sınıfı: Çoklu kalıtım için idealdir. Bir sınıf, birden fazla arayüzden türetilebilir.
- Nesne Oluşturma:

    - absract Sınıf: Soyut sınıflardan doğrudan nesne oluşturulamaz.
    - interface Sınıfı: Arayüzlerden doğrudan nesne oluşturulamaz.

- Amaç:
    - absract Sınıf: Temel işlevselliği paylaşmak ve ortak davranışı uygulamak için kullanılır.
    - interface Sınıfı: Sınıflar arasında bir sözleşme sağlamak ve belirli bir işlevselliği zorunlu kılmak için kullanılır.

- aslında ikiside aynı en temel fark absract classlar normal veri üyeleri ve normal fonksiyonlar içerebilir. Interface ler normal veri üyeleri ve normal fonksyionlar içeremez.

- absract example
    ```cpp
    #include <iostream>

    class Animal {
    public:
        virtual void makeSound() = 0; // Pure virtual function

        void breathe() {
            std::cout << "Breathing" << std::endl;
        }
    };

    class Dog : public Animal {
    public:
        void makeSound() override {
            std::cout << "Woof!" << std::endl;
        }
    };

    int main() {
        Dog dog;
        dog.makeSound(); // Output: Woof!
        dog.breathe();   // Output: Breathing
        return 0;
    }
    ```

- interface example
    ```cpp
    #include <iostream>

    class Printable {
    public:
        virtual void print() = 0; // Pure virtual function
    };

    class Document : public Printable {
    public:
        void print() override {
            std::cout << "Printing Document" << std::endl;
        }
    };

    class Image : public Printable {
    public:
        void print() override {
            std::cout << "Printing Image" << std::endl;
        }
    };

    int main() {
        Document doc;
        Image img;
        
        doc.print(); // Output: Printing Document
        img.print(); // Output: Printing Image
        return 0;
    }
    ```

