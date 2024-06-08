# Encapsulation and Abstraction
- [Encapsulation](#encapsulation)
- [Abstraction](#abstraction)
- [Abstract Class](#abstract-class)
- [Interface](#interface)
- [Interface and Abstract Differences](#interface-and-abstract-differences)


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
    - Veri Gizleme (Data Hiding):
        width ve height veri üyeleri private olarak tanımlanmıştır, böylece dışarıdan,doğrudan erişim engellenmiştir.
    - Public Methods (Açık Metotlar):
        - setWidth(double w) ve setHeight(double h): Genişlik ve yükseklik değerlerini ayarlamak için kullanılır. Pozitif olmayan değerler için bir hata mesajı verir.
        - getWidth() const ve getHeight() const: Genişlik ve yükseklik değerlerini döner.
        - getArea() const: Dikdörtgenin alanını hesaplayıp döner.
    - Veri Güvenliği ve Bütünlüğü:
        Genişlik ve yükseklik yalnızca pozitif değerlerle ayarlanabilir, böylece dörtgenin geçerli boyutlara sahip olması sağlanır.

## Abstraction
- (Önemli) Bu kısmı daha sonra ayrıntıluı işleyeceğiz virtual ve polymorphism konularını öğrendiketen sonra.
- Abstraction, nesne yönelimli programlamanın (OOP) dört temel prensibinden biridir ve sistemin veya nesnenin yalnızca önemli ve temel özelliklerini vurgulamak için kullanılır. Bu, kullanıcıların veya diğer programcıların karmaşık detaylardan kaçınarak, yalnızca ilgili işlevselliklere odaklanmasını sağlar. 
- Abstract Classes:
    - Tanım: Soyut sınıflar, yalnızca diğer sınıfların türetildiği, doğrudan örneklenemeyen sınıflardır. Bir soyut sınıf, en az bir soyut metoda (pure virtual function) sahip olmalıdır.
    - Amaç: Ortak özellikleri ve metodları bir araya getirerek, alt sınıfların bu özellikleri ve metodları yeniden tanımlamasını zorunlu kılmak.
- Interfaces 
    - Tanım: Arayüzler, yalnızca metod bildirimlerini içeren ve hiçbir metodun gerçeklemesini barındırmayan yapılar olarak düşünülebilir.
    - Amaç: Bir sınıfın hangi metodları uygulaması gerektiğini belirtmek. C++'da bu, saf sanal fonksiyonlar (pure virtual functions) aracılığıyla gerçekleştirilir.

- Abstract Methods(pure virtual)
    - Tanım: Soyut metodlar, bir sınıfta yalnızca imzası belirtilmiş, ancak gerçeklemesi yapılmamış metodlardır. Bu metodlar, türetilmiş sınıflarda geçersiz kılınmalıdır (override).
    - Amaç: Türetilmiş sınıfların, soyut sınıfın belirlediği belirli işlevleri uygulamasını zorunlu kılmak.

- Generalization and Specialization
    - Tanım: Genelleme, ortak özellikleri ve işlevleri üst sınıflarda toplamak, özelleştirme ise bu ortak özelliklerin alt sınıflarda detaylandırılmasıdır.
    - Amaç: Kodun daha esnek ve yeniden kullanılabilir olmasını sağlamak.

- Bilgi Gizleme (Information Hiding)
    - Tanım: Sınıfın iç detaylarının, yalnızca sınıfın kendisi tarafından kullanılabilmesini sağlamak.
    - Amaç: Dışarıdan erişimi sınırlayarak, veri bütünlüğünü korumak ve güvenliği artırmak.

- Abstraction and Concretion
    - Tanım: Soyutlama, sistemin veya nesnenin sadece temel ve önemli özelliklerini vurgularken, somutlama bu soyutlamanın belirli bir biçimde uygulanmasıdır.
    - Amaç: Genel kavramları ve işlevleri tanımlamak ve bu tanımları belirli uygulamalarda hayata geçirmek.

## Abstract Class
- Soyut sınıflar (abstract classes), nesne yönelimli programlamada (OOP) temel kavramlardan biridir. Bir soyut sınıf, en az bir soyut metoda (pure virtual function) sahip olan ve doğrudan örneklenemeyen bir sınıftır. Soyut sınıflar, alt sınıfların belirli işlevleri kendi ihtiyaçlarına göre uygulamasını zorunlu kılar.
- Soyut Sınıfların Temel Özellikleri
    - Saf Sanal Fonksiyonlar (Pure Virtual Functions)
        - Bir soyut sınıf, en az bir pure virtual fonksiyon içermelidir. Bu fonksiyonlar yalnızca metod imzasına sahiptir ve = 0 ifadesi ile belirtilir.
        - pure virtual fonksiyonlar, alt sınıflar tarafından geçersiz kılınmak zorundadır.
    - Örneklenemezlik (Cannot Be Instantiated)
        - Soyut sınıflar doğrudan örneklenemez. Yani, bir soyut sınıfın nesnesi doğrudan oluşturulamaz.
        - (Önemli !!)Ancak, soyut sınıfların işaretçileri veya referansları kullanılabilir. yani bundan türetilmiş classları tutmak için absract classın poinrterini kullanabilirsin.
    - Polymorphism Sağlama
        - Soyut sınıflar, polymorphism (çok biçimlilik) sağlar. Bu, aynı temel sınıfın işaretçisi veya referansı ile farklı alt sınıfların metodlarının çağrılabilmesi anlamına gelir.
    - Türetme ve Geçersiz Kılma (Inheritance and Overriding)
        - Alt sınıflar, soyut sınıftan türetilir ve pure virtual fonksiyonları kendi işlevleriyle geçersiz kılarlar (override).
    - constructor veya destructor içerebilir.
    - ex:
        ```cpp
        #include <iostream>
        #include <vector>

        // Abstract base class
        class Shape {
        public:
            // Pure virtual function
            virtual void draw() const = 0;

            // Non-abstract method
            void display() const {
                std::cout << "Displaying the shape." << std::endl;
            }

            // Virtual destructor
            virtual ~Shape() {}
        };

        // Derived class Circle
        class Circle : public Shape {
        public:
            void draw() const override {
                std::cout << "Drawing a circle." << std::endl;
            }
        };

        // Derived class Square
        class Square : public Shape {
        public:
            void draw() const override {
                std::cout << "Drawing a square." << std::endl;
            }
        };

        int main() {
            std::vector<Shape*> shapes;
            shapes.push_back(new Circle());
            shapes.push_back(new Square());

            for (const Shape* shape : shapes) {
                shape->draw();      // Output: Drawing a circle. Drawing a square.
                shape->display();   // Output: Displaying the shape.
            }

            // Clean up
            for (Shape* shape : shapes) {
                delete shape;
            }

            return 0;
        }
        ```
        - Açıklamalar:
            - Shape Sınıfı: Shape soyut bir sınıftır ve draw adında bir saf sanal fonksiyon içerir. Bu sınıf doğrudan örneklenemez.
            - Circle ve Square Sınıfları: Circle ve Square sınıfları, Shape sınıfından türetilmiştir ve draw metodunu geçersiz kılmışlardır.
            - Polymorphism: main fonksiyonunda, Shape türünde bir işaretçi vektörü kullanılarak Circle ve Square nesneleri depolanır ve draw metodları çağrılır.

- Soyut Sınıfların Avantajları ve Dezavantajları
    - Avantajlar:
        - Kodun Yeniden Kullanılabilirliği: Ortak işlevsellikleri bir arada toplar ve alt sınıfların bu işlevsellikleri tekrar kullanmasını sağlar.
        - Esneklik ve Genişletilebilirlik: Yeni alt sınıflar eklenerek mevcut sistem kolayca genişletilebilir.
        - Polymorphism: Farklı sınıfların aynı arayüzü kullanarak farklı şekillerde davranmasını sağlar.
    - Dezavantajlar:
        - Karmaşıklık: Soyut sınıflar ve saf sanal fonksiyonlar, özellikle büyük ve karmaşık projelerde, öğrenme eğrisini artırabilir.
        - Performans: Sanal fonksiyon çağrıları, doğrudan fonksiyon çağrılarından daha yavaştır ve bu da performans kaybına yol açabilir.

## Interface
- Arayüzler (interfaces), nesne yönelimli programlamada (OOP) soyutlamayı gerçekleştirmek için kullanılan önemli yapılardır. Arayüzler, bir sınıfın hangi metodları uygulaması gerektiğini belirler, ancak bu metodların nasıl uygulanacağını belirtmez. Arayüzler, pure virtual fonksiyonlardan oluşur ve herhangi bir veri üyesi veya işlev gövdesi içermez.

- Arayüzlerin Temel Özellikleri
    - Tamamen Soyut Yapı
        - Arayüzler, tamamen soyut olup, yalnızca metod imzalarından oluşur. İşlev gövdeleri içermezler.
        - Bir arayüzde tanımlanan tüm metodlar, saf sanal fonksiyonlardır (pure virtual functions).

    - Gerçeklemenin (Implementation) Alt Sınıflara Bırakılması
        - Arayüzler, bir sınıfın belirli işlevleri uygulamasını zorunlu kılar. Alt sınıflar bu metodları kendi ihtiyaçlarına göre uygular.
        - Bu sayede, bir arayüzü implemente eden (uygulayan) sınıflar, bu arayüzde tanımlanan tüm metodları geçersiz kılmak (override) zorundadır.
        - Çoklu Kalıtım (Multiple Inheritance) Desteği

    - Arayüzler, C++ gibi bazı dillerde çoklu kalıtım sorunlarını çözmek için kullanılır. 
        - Bir sınıf, birden fazla arayüzü implemente edebilir.
        - Bu, sınıfın birden fazla arayüzden metodları miras almasını sağlar.

    - Polymorphism (Çok Biçimlilik)
        - Arayüzler, polymorphism sağlar. Bu, aynı arayüzü implemente eden farklı sınıfların, aynı metodları farklı şekillerde uygulayabilmesi anlamına gelir.
        - Bu sayede, aynı arayüz işaretçisi veya referansı ile farklı sınıfların metodları çağrılabilir.

- Arayüzlerin Kullanım Alanları
    - Ortak Davranışları Belirlemek
        - Farklı sınıflar arasında ortak davranışları tanımlamak için kullanılır. Örneğin, bir Drawable arayüzü, tüm çizilebilir nesneler için bir draw metodunu tanımlayabilir.
    - Bağımlılıkları Azaltmak
        - Arayüzler, bağımlılıkları azaltır ve sınıflar arasındaki bağları gevşetir (loose coupling). Bu, yazılımın daha modüler ve esnek olmasını sağlar.
    - Test Edilebilirlik
        - Arayüzler, birim testlerde (unit testing) kullanılır. Bir sınıfın belirli bir arayüzü implemente ettiğini varsayarak, bu arayüz için mock veya stub nesneler oluşturulabilir.

- ex:
    ```cpp
    #include <iostream>
    #include <vector>

    // Interface (Abstract class) for Drawable
    class Drawable {
    public:
        // Pure virtual function
        virtual void draw() const = 0;

        // Virtual destructor
        virtual ~Drawable() {}
    };

    // Concrete class Circle implementing Drawable
    class Circle : public Drawable {
    public:
        void draw() const override {
            std::cout << "Drawing a circle." << std::endl;
        }
    };

    // Concrete class Square implementing Drawable
    class Square : public Drawable {
    public:
        void draw() const override {
            std::cout << "Drawing a square." << std::endl;
        }
    };

    int main() {
        std::vector<Drawable*> shapes;
        shapes.push_back(new Circle());
        shapes.push_back(new Square());

        for (const Drawable* shape : shapes) {
            shape->draw();  // Output: Drawing a circle. Drawing a square.
        }

        // Clean up
        for (Drawable* shape : shapes) {
            delete shape;
        }

        return 0;
    }
    ```
- Açıklamalar:
    - Drawable Arayüzü: Drawable arayüzü, draw adında bir saf sanal fonksiyon içerir. Bu, Drawable arayüzünü implemente eden tüm sınıfların bu fonksiyonu geçersiz kılması gerektiği anlamına gelir.
    - Circle ve Square Sınıfları: Circle ve Square sınıfları, Drawable arayüzünü implemente eder ve draw metodunu kendi spesifik işlevleriyle geçersiz kılarlar.
    - Polymorphism: main fonksiyonunda, Drawable türünde bir işaretçi vektörü kullanılarak Circle ve Square nesneleri depolanır ve draw metodları çağrılır. Bu, polymorphism'in bir örneğidir; aynı Drawable işaretçisi farklı şekillerin draw metodunu çağırabilir.

- Arayüzlerin Avantajları ve Dezavantajları
    - Avantajlar:
        - Esneklik ve Genişletilebilirlik: Arayüzler, sınıfların esnek ve genişletilebilir olmasını sağlar. Yeni sınıflar eklenerek mevcut yapıya kolayca yeni işlevler eklenebilir.
        - Modülerlik ve Bağımsızlık: Arayüzler, yazılımın daha modüler olmasını sağlar ve sınıflar arasındaki bağımlılıkları azaltır.
        - Test Edilebilirlik: Arayüzler, birim testlerde kolayca mock nesneler oluşturmayı sağlar, bu da yazılımın test edilebilirliğini artırır.
    - Dezavantajlar:
        - Karmaşıklık: Çok sayıda arayüz ve implementasyon, özellikle büyük projelerde karmaşıklığı artırabilir.
        - Performans: Sanal fonksiyon çağrıları, doğrudan fonksiyon çağrılarından daha yavaştır ve bu da performans kaybına yol açabilir.
        - Yüksek Öğrenme Eğrisi: Yeni başlayanlar için arayüzlerin ve soyutlamanın anlaşılması zor olabilir.

## Interface and Abstract Differences
- Tanım ve Amaç:
    - Arayüzler (Interfaces): C++'da resmi olarak "interface" anahtar kelimesi yoktur. Ancak, yalnızca saf sanal fonksiyonlar (pure virtual functions) içeren bir soyut sınıf, C++'da bir arayüz olarak kabul edilir. Arayüzlerin amacı, belirli bir işlevselliği tanımlamak ve bu işlevselliği sağlayacak sınıfların, bu metodları implemente etmesini zorunlu kılmaktır.
    - Soyut Sınıflar (Abstract Classes): En az bir saf sanal fonksiyon içeren sınıflardır. Hem gerçekleştirilmiş (implemented) hem de saf sanal fonksiyonlar içerebilirler. Soyut sınıflar, alt sınıflar için ortak davranışları ve özellikleri tanımlar.

- Metodlar:
    - Arayüzler: Sadece saf sanal fonksiyonlardan oluşur. İşlev gövdeleri içermez. Tüm metodlar = 0 ile belirtilir.
    - Soyut Sınıflar: Hem saf sanal fonksiyonlar hem de işlev gövdeleri olan metodlar içerebilir. Yani, bir soyut sınıfın bazı metodları gerçekleştirilmiş olabilir.

- Veri Üyeleri:
    - Arayüzler: Veri üyeleri içermezler. Sadece metod imzalarından oluşur.
    - Soyut Sınıflar: Veri üyeleri içerebilirler. Alt sınıflar için ortak veri üyelerini tanımlayabilirler.

- Erişim Belirleyicileri:
    - Arayüzler: Tüm metodlar varsayılan olarak public'dir ve arayüzlerde erişim belirleyicileri değiştirilmez.
    - Soyut Sınıflar: Metodlar ve veri üyeleri için public, protected ve private erişim belirleyicileri kullanılabilir.
- Çoklu Kalıtım:
    - Arayüzler: Bir sınıf birden fazla arayüzü implemente edebilir. Bu, çoklu kalıtım sorunlarını çözmek için kullanışlıdır.
    - Soyut Sınıflar: Bir sınıf yalnızca bir soyut sınıftan türetilebilir, ancak birden fazla soyut sınıftan türetmek de mümkündür (çoklu kalıtım desteklenir), ancak dikkatle kullanılmalıdır.

- Data members
    - Interface ler data member içermez.
    - Abtsract metodlar içerebilir.

- cpp
    - aslında ınteface diye direkt bir kavram yok. Absract classlar yazıyorz biz opradaki fonksiyonlarun pure virtual olup olmamamsına göre adlandırıyoruz.