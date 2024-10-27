# Construcors
## Content
- [Constructor](#constructor)
- [Characteristics of Constructors](#characteristics-of-constructors)
- [Types of Constructor](#types-of-constructor)
- [Default Constructor](#default-constructor)
- [Parameterized Constructor](#parameterized-constructor)
- [Default Arguments and Overloading Constructors](#Default-arguments-and-overloading-constructors)
- [Copy Constructor](#copy-constructor)
- [Move Constrcutor](#move-constrcutor)
- [Difference move and copy constructor](#difference-move-and-copy-constructor)
- [Temporary Objects](#temporary-objects)
- [RVO and NRVO](#rvo-and-nrvo)
- [Constrcutor Initilizaiton List](#constrcutor-initilizaiton-list)
- [Delegating Construcors](#delegating-construcors)
- [Member Data and their initilizations with classes](#member-data-and-their-initilizations-with-classes)

## Constructor
- C++'ta constructor (yapıcı), nesne oluşturulurken otomatik olarak çağrılan özel bir yöntemdir. Genellikle, yeni nesnelerin veri üyelerini başlatmak için kullanılır. C++'ta constructor, sınıfın veya yapının adıyla aynı isme sahiptir. Constructor, nesne için veri sağlar, yani nesnenin değerlerini oluşturur, bu yüzden constructor olarak bilinir.

## Characteristics of Constructors
- Constructor'ın adı, sınıf adıyla aynı olan bir fonksiyodur.
- Constructor, bir sınıfın nesnesi oluşturulduğunda, o nesnenin veri üyelerini otomatik olarak başlatmak için kullanılan özel bir üye fonksiyon türüdür.
- Constructor'lar değer döndürmez, dolayısıyla dönüş türleri yoktur. void bile olamaz.
- Constructor, sınıfın nesnesi oluşturulduğunda otomatik olarak ilk çağrılan fonksiyondur.
- Constructor'lar genellikle sınıfın public bölümünde ilan edilir, ancak sınıfın private bölümünde de ilan edilebilirler.
- private ın altında tanımlanırsa bu classdan bu classın dışında obje oluşturulamaz.
- Constructor'lar overload edilebilir.
- static veya const olamaz.
- Bir constructor sanal (virtual) olarak ilan edilemez.
- Bir constructor miras alınamaz (Inheritence alınmaz). C++'da, yapıcılar (constructors) doğrudan miras alınamaz. Ancak, bir temel sınıfın (base class) constructor u, türetilmiş sınıfın (derived class) constructor u tarafından çağrılabilir. Bu, türetilmiş sınıfın bir örneği oluşturulduğunda, temel sınıfın uygun constructor un çağrılmasını sağlar. Bu işlem genellikle türetilmiş sınıfın constructor initialization listesi kullanılarak yapılır.
- new ve delete operatörleri kullanıldığında constructor(new) ve destructor(delete) çağrılır.yani dynanamic olarak alan allocate ederken objeyi aslında oluşturuyoruz.
- Not: Sınıf dışında tanımlanan constructor'ı, sınıf içi tanımlamayla eşdeğer hale getirmek için inline yapabiliriz. Ancak, inline'ın derleyiciye verilen bir talimat olmadığını, sadece bir istek olduğunu ve derleyicinin bu isteği, koşullara bağlı olarak yerine getirip getirmeyeceğini unutmamak gerekir.

- syntax
    ```
    <class-name> (list-of-parameters);
    ```
- Constructor classın içinde veya dışında tanımlanabilir.(fonksiyonların definition ile declarationunun ayrı yazılması)
    - Syntax for Defining the Constructor Within the Class
        ```
        <class-name> (list-of-parameters)
        {
            // constructor definition
        }
        ```
    - Syntax for Defining the Constructor Outside the Class. Bunu kullanabilmek için classın içinde öncelikle constructorun definitionunu yapmak lazım.
        ```
        <class-name>: :<class-name>(list-of-parameters)
        {
            // constructor definition
        }
        ```

## Types of Constructor 
- Default Constructor
- Parameterized Constructor
- Copy Constructor
- Move Constructor

## Default Constructor
- Parametre almayan constructor'dır. Eğer sınıfta herhangi bir constructor tanımlanmazsa, derleyici tarafından otomatik olarak sağlanır.
- Bu şekilde parametre almayan class tanımlarken dikkat etmen gereken bir şey var.
    ```cpp
    Person person() // yanlış
    Person person; // doğru
    ```
    - ikinci seçenek normal objeyi oluşturur. ilk örnek ise Person class ını döndüren bir fonksiyonun declarationunu yapar. Dikkat et buna.

## Parameterized Constructor
- Parametreli constructor, bir sınıfın nesnesi oluşturulurken belirli parametreler alarak bu parametrelerle nesnenin veri üyelerini başlatan constructor türüdür. Bu tür constructor'lar, nesneleri özel başlangıç değerleriyle başlatmak için kullanılır ve genellikle sınıfın iç durumunu tanımlamak için gerekli olan değerleri alır.
- Bir class parametreli constructor ile oluşturulduğunda ve constructorun parametresiz versiyonu yazılmadığında(Default constructor). objeyi oluşturuken parametreleri vermek zorundayız.
- Önemli Not: Bir sınıf için bir veya daha fazla non-default constructor (parametreli) tanımladığımızda, bir default constructor (parametresiz) da açıkça tanımlanmalıdır çünkü bu durumda derleyici bir default constructor sağlamayacaktır. Ancak bu zorunlu değildir, fakat her zaman default constructor tanımlamak en iyi uygulama olarak kabul edilir. Çünkü parametresiz bir obje oluşturmaya çalıştığında sıkıntı yaşarsın.
- Not: Parametre isimleri ile classın data memberslarının ismi farklı olmalı yoksa hatalara yol açabilir. İlla aynı kullanmak istiyorsan this pointerini kullanmalısın ilerleyen zamanlarda işleyeceğiz.
- Alınan parametreleri illa bir data member a eklemek zorunda değilsin. sadece o anda kullanmak istediğin değişkenleri data member olarak tanımlamana gerek yok, sadece paremetre olarak al. DSA array construcotruna bakabilirsin.

- **Constructor Overloading**
    - Aynı fonksiyon adını kullanarak, farklı parametre listelerine sahip birden fazla fonksiyon tanımlamaktır. Derleyici, fonksiyon çağrısı sırasında hangi fonksiyonun çağrılacağını, argümanların sayısı ve türüne göre belirler.
    - Constructor overloading, bir sınıf içinde birden fazla constructor tanımlama işlemidir. Her constructor, farklı parametre listelerine sahiptir. Bu, nesne oluşturulurken farklı başlatma senaryolarını desteklemek için kullanılır. Constructor overloading, programcılara aynı sınıftan farklı şekillerde nesneler oluşturma esnekliği sağlar.

- **Default Arguments**: 
    - Constructor larda default argümentler içerebilir. Böylece overloading de yapmana gerek kalmayabilir. Hem default hemde parameterized gibi çalışır.Ama bazı karışıklıklara yol açar
    - burada dikkat etmen gereken bir şey var. Funciton overloading yaparken default parametreleri Function declarationunda(function prototype)' da vermemelisin. Default parametreleri definitionda vermelisin.

## Default Arguments and Overloading Constructors
- constructor fonksiyonlara varsayılan argümanlar vermek ve constructor fonksiyonlarını overload etmek farklı kullanımlar ve davranışlara yol açabilir. Bu iki özelliğin birlikte kullanılması bazı durumlarda karışıklığa neden olabilir.
- Varsayılan argümanlar ve overlaoded constructors birlikte kullanıldığında, doğru yapıcı fonksiyonun çağrılmasını belirlemek bazen karmaşık olabilir. Derleyici, çağrı sırasında en uygun yapıcıyı seçmeye çalışır. Ancak, bu durum bazı potansiyel çakışmalara yol açabilir.

```cpp
#include <iostream>

class MyClass {
public:
    // Varsayılan argümanlı yapıcı (iki parametreli)
    MyClass(int x = 0, int y = 0) {
        std::cout << "MyClass(int x = 0, int y = 0) called" << std::endl;
        this->x = x;
        this->y = y;
    }

    // Tek parametreli yapıcı, varsayılan argüman ile
    MyClass(int x = 0) {
        std::cout << "MyClass(int x = 0) called" << std::endl;
        this->x = x;
        this->y = 0;
    }

    void print() const {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }

private:
    int x;
    int y;
};

int main() {
    MyClass obj1;          // Karışıklık: Hangi yapıcı çağrılacak?
    MyClass obj2(10);      // Karışıklık: Hangi yapıcı çağrılacak?
    MyClass obj3(10, 20);  // İki parametreli yapıcı çağrılır

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}
```
- Açıklama
    - Varsayılan Argümanlarla Yapıcı:
        - MyClass(int x = 0, int y = 0): Bu yapıcı, iki varsayılan argümanla tanımlanmıştır. Eğer hiçbir argüman verilmezse x ve y sırasıyla 0 ve 0 değerini alır.

    - Tek Parametreli Yapıcı, Varsayılan Argüman ile:
        - MyClass(int z = 0): Bu yapıcı, bir varsayılan argümanla tanımlanmıştır. Eğer argüman verilmezse z değeri 0 olur.

    - Davranış:
        - MyClass obj1;: Bu durumda derleyici hangi yapıcıyı çağıracağına karar veremez, çünkü hem MyClass(int x = 0, int y = 0) hem de MyClass(int z = 0) uygun gözükür. Bu bir derleme hatasına neden olur.
        - MyClass obj2(10);: Benzer şekilde, bu durumda da derleyici hangi yapıcıyı çağıracağına karar veremez, çünkü hem MyClass(int x = 0, int y = 0) hem de MyClass(int z = 0) uygun gözükür. Bu da bir derleme hatasına neden olur.
        - MyClass obj3(10, 20);: Bu durumda derleyici net bir şekilde MyClass(int x = 0, int y = 0) yapıcısını çağırır, çünkü iki argüman verilmiştir.

- Çözüm
    - Bu tür karışıklıkları önlemek için, yapıcıların net ve belirgin olmasını sağlamak önemlidir. Aşağıda, karışıklığı önlemek için explicit anahtar kelimesi kullanılarak çözüm sağlanabilir.
        ```cpp
        #include <iostream>

        class MyClass {
        public:
            // Varsayılan argümanlı yapıcı (iki parametreli)
            MyClass(int x = 0, int y = 0) {
                std::cout << "MyClass(int x = 0, int y = 0) called" << std::endl;
                this->x = x;
                this->y = y;
            }

            // Tek parametreli yapıcı, varsayılan argüman ile
            explicit MyClass(int z) {
                std::cout << "MyClass(int z) called" << std::endl;
                this->x = z;
                this->y = 0;
            }

            void print() const {
                std::cout << "x: " << x << ", y: " << y << std::endl;
            }

        private:
            int x;
            int y;
        };

        int main() {
            MyClass obj1;          // MyClass(int x = 0, int y = 0) çağrılır
            MyClass obj2(10);      // MyClass(int z) çağrılır
            MyClass obj3(10, 20);  // MyClass(int x, int y) çağrılır

            obj1.print();
            obj2.print();
            obj3.print();

            return 0;
        }
        ```
- Açıklama
    - explicit Anahtar Kelimesi:
        - explicit anahtar kelimesi, tek parametreli yapıcıların sadece açık çağrılmasını zorunlu kılar. Bu, otomatik tür dönüşümlerini ve dolayısıyla karışıklıkları önler.
        - tek parametreli yapıcılar, otomatik tür dönüşümlerini önlemek için explicit olarak işaretlenebilir. Bu, sınıfın yanlışlıkla tür dönüşümü amacıyla kullanılmasını engeller.
    - Net Davranış:
        - MyClass obj1;: Varsayılan argümanları olan iki parametreli yapıcı çağrılır.
        - MyClass obj2(10);: explicit olarak tanımlanmış tek parametreli yapıcı çağrılır.
        - MyClass obj3(10, 20);: İki parametreli yapıcı çağrılır.

- genel olarak sıkıntı yaratıyor. İlla default argümanlı constructor olmasını istiyorsan tek constructor yaz.
- ya da overloading yaparak constructorları yaz ve constructorların body sinde default argümanları ekle.

## Copy Constructor
- Copy constructor, bir nesnenin başka bir nesne aynı classdan kullanılarak kopyalanmasını sağlayan özel bir constructor türüdür.     
    - Bir nesne başka bir nesne kullanılarak başlatıldığında.
        ```cpp
        MyClass obj1;
        MyClass obj2 = obj1;  // Copy constructor çağrılır
        ```

    - Bir nesne fonksiyona argüman olarak geçirildiğinde. çünkü referanlsa vs geçirmezsek asıl değeri bozmamak için kopyalıyordu hatırla.
        ```cpp
        void function(MyClass obj) {
            // ...
        }

        int main() {
            MyClass obj1;
            function(obj1);  // Copy constructor çağrılır
            return 0;
        }
        ```
    - Bir nesne fonksiyondan değer olarak döndürüldüğünde.
        ```cpp
        MyClass function() {
            MyClass obj;
            return obj;  // Copy constructor çağrılır
        }

        int main() {
            MyClass obj1 = function();  // Copy constructor çağrılır
            return 0;
        }
        ```

    - (dikkat !!!!)Atama İşlemi (Assignment) ile Çağırma: Atama operatörü (=) kullanıldığında copy constructor değil, copy assignment operatörü çağrılır. Ancak nesne başlatma sırasında = kullanımı copy constructor'ı çağırır.
        ```cpp
        MyClass obj1;
        MyClass obj2;
        obj2 = obj1;  // Bu durumda copy assignment operatörü çağrılır, copy constructor değil.
        ```
    - Geçici Nesneler (Temporary Objects) ile Çağırma: Bir nesne geçici (temporary) bir nesne olarak kullanıldığında copy constructor çağrılabilir. Bir fonksiyondan dönen objeler geçici nesnelerdir. move yazılmasıyda sadece copy varsa copy constructoru kullanır. move önceliklidir ama.

    - Başka bir kopyalama tarzı.
        ```cpp
        MyClass temp1;  
        MyClass temp2(temp1);
        ```

- Eğer biz kendimiz bir copy constructor tanımlamazsak, C++ derleyicisi otomatik olarak bir varsayılan (default) copy constructor sağlar. Bu varsayılan copy constructor, yüzeysel kopyalama (shallow copy) yapar. Yüzeysel kopyalama, nesnenin tüm veri üyelerinin bit düzeyinde kopyalanması anlamına gelir. Bu, basit veri türleri (int, float, vb.) ve pointer'lar için geçerlidir, ancak dinamik bellek yönetimi ve diğer karmaşık yapılar için sorunlara yol açabilir.Shallow copy yapar çünkü.

- copy yi kullanırken. normal constrcutor çağırılmaz çünkü copy constrcutoru kullanıyor değer atamak için.

- copy constructor private, protected üyelere ulaşabilir objenin.

- copy consturctor syntax:
    ```cpp
    class ClassName {
    public:
        ClassName(const ClassName &obj);
    };
    ```
- Fonksiyona parametre alırken referanslar veya pointer ile alırsan mantıken kopyalama yapmaz.

- Fonksiyona argüman olarak verdiğimizde. Fonksiyondan çıkarken destructor çağırılıyor. kopya obje oluşturuluyor ya o yok ediliyor.

- copy constructor kullanırken destructor ve assignemnt operatörü içinde fonksiyonlar yazmak mantıklı olucaktır.

- copy constructor da private olabilir. Private olursa bu onun kopyalanamayacağı anlama gelir. yada classın dışında kopyalanamayacağı anlama gelir.

- (Önemli)Dinamik bellek yönetimi, doğru kopyalama gibi önemli yararları var(Deep Copy ile).

- private tanımlanabilir normal constrcutorlar ile aynı mantık kopyalanamayacağı anlamına gelir.

- burada this bizim lvalue mizi temsil eder. Fonksiyon içine gelen obje ise rvalue yi temsil eder. biz rvalue yi lvalue ye kopyalıyoruz işlemlerini ona göre yap.

- constrcutorların dönüş değeri olmaz unutma.

- virtual olamaz.

### Shallow copy and Deep Copy
- **Shallow copy**: Shallow copy, bir nesnenin veri üyelerinin bit düzeyinde kopyalanmasıdır. Bu, nesnenin tüm veri üyelerinin aynı değerlerle kopyalanması anlamına gelir. Ancak, eğer nesne içinde pointer'lar veya dinamik bellek kullanılıyorsa, shallow copy sadece bu pointer'ların adreslerini kopyalar, belleğin kendisini değil. Bu, iki nesnenin aynı bellek alanını paylaşmasına neden olur ve bellek yönetimi sorunlarına yol açabilir.
- Copy constructorunun defaultu Shallow copy dir.
    ```cpp
    #include <iostream>
    using namespace std;

    class Shallow {
    public:
        int* data;

        Shallow(int value) {
            data = new int(value);
        }

        // Varsayılan copy constructor kullanılır
        void display() {
            cout << "Değer: " << *data << endl;
        }

        ~Shallow() {
            delete data;
        }
    };

    int main() {
        Shallow obj1(5);
        Shallow obj2 = obj1;  // Varsayılan copy constructor kullanılır

        obj1.display();
        obj2.display();

        // obj1 ve obj2 aynı bellek adresini paylaşır, bu da sorunlara yol açabilir
        return 0;
    }
    ```

- **Deep Copy**: Deep copy, bir nesnenin veri üyelerinin derinlemesine kopyalanmasıdır. Bu, nesne içindeki tüm dinamik olarak tahsis edilmiş bellek alanlarının ve pointer'ların yeni bellek alanlarına kopyalanması anlamına gelir. Bu yöntem, her nesnenin kendi bağımsız bellek alanına sahip olmasını sağlar ve bellek yönetimi sorunlarını önler.(örnek kodda). pointerleri kopyalarken pointerin kendisini değil pointerin gösteridiği bellek alanını kopyalarız. (Biz kendi copy constructorumuzu yaparken pointerler kullandığımız örneklerde deep copy yapmış olduk)

- **Shallow Copy vs Deep Copy**
    - Shallow Copy (Yüzeysel Kopyalama):
        - Bellek adreslerini kopyalar, nesnenin içeriğini değil.
        - Nesneler aynı bellek alanını paylaşır.
        - Bellek yönetimi sorunlarına yol açabilir (örneğin, bir nesne serbest bırakıldığında diğer nesne geçersiz hale gelir).
    - Deep Copy (Derin Kopyalama):
        - Bellek içeriğini derinlemesine kopyalar.
        - Her nesne kendi bağımsız bellek alanına sahiptir.
        - Bellek yönetimi sorunlarını önler (her nesne kendi belleğini yönetir).

- **Shallow Copy ve Deep Copy'nin Kullanım Alanları***
    - Shallow Copy: Genellikle basit veri yapılarında veya dinamik bellek kullanılmayan durumlarda kullanılır.
    - Deep Copy: Dinamik bellek tahsisi yapılan sınıflarda, karmaşık veri yapılarında ve kaynak yönetimi gerektiren durumlarda kullanılır.

### Copy constructor vs Assignment Operator
- Copy Constructor ve Assignment Operator arasındaki temel fark, Copy Constructor her çağrıldığında yeni bir bellek alanı oluştururken, Assignment Operator yeni bir bellek alanı oluşturmaz.
- Bir copy constructor, yeni bir nesne mevcut bir nesneden kopya olarak oluşturulduğunda çağrılır. Assignment operatörü, zaten başlatılmış bir nesneye başka bir mevcut nesneden yeni bir değer atandığında çağrılır.

- syntax
    ```cpp
    //Copy constructor çağırılır çünkü obje yeni oluşturuluyor
    MyClass my_class;
    MyClass my_class2 = my_class

    // assignment operatörü çağrılır çünkü zaten olyuşturulmuş iki obje var. bunları sonradan brinden birine kopyalıyoruz
    MyClass my_class;
    MyClass my_class2;
    my_class = my_class2;
    ```

- Copy Constructor:
    - Bir mevcut nesneden yeni bir nesne oluşturulduğunda, mevcut nesnenin kopyası olarak çağrılır.
    - Yeni nesne için ayrı bir bellek bloğu oluşturur.
    - overload edilmiş bir constructor'dır.
    - Sınıfta copy constructor tanımlanmadıysa, C++ derleyicisi bir copy constructor sağlar.

- Assignment Operator:
    - Zaten başlatılmış bir nesneye, başka bir mevcut nesneden yeni bir değer atandığında çağrılır.
    - Ayrı bir bellek bloğu veya yeni bir bellek alanı oluşturmaz.
    - Bitwise (bit düzeyinde) bir operatördür.
    - Assignment operator overload edilmezse, bitwise copy oluşturulur.

## Move Constrcutor
- Move constructor, C++11'de tanıtılan bir özellik olup, bir nesnenin kaynaklarını başka bir nesneye taşımak için kullanılır. Bu, özellikle büyük veri yapıları veya dinamik bellek kullanan nesneler için performansı artırmak amacıyla kullanılır. Move constructor, bir nesnenin kaynaklarını diğerine "taşıyarak" kopyalama maliyetini en aza indirir.
- burada this bizim lvalue mizi temsil eder. Fonksiyon içine gelen obje ise rvalue yi temsil eder. biz rvalue yi lvalue ye taşıyoryz işlemlerini ona göre yap.
- constrcutorların dönüş değeri olmaz unutma.
- virtual olamaz.

- syntax
    ```cpp
    className(className&& other) noexcept {
        // body
    }

    className obj1;
    className obj2 = std::move(obj1);
    ```

    - noexcept anahtar kelimesi, bir fonksiyonun (veya constructor'ın) herhangi bir istisna atmayacağını belirtmek için kullanılır. Bu, özellikle move constructor'lar ve move assignment operatörleri gibi kaynak transferi işlemlerinde performans optimizasyonları ve güvenlik açısından önemlidir.
        - noexcept Anlamı:
            - noexcept ile belirtilen bir fonksiyon, istisna fırlatmaz. Bu, derleyicinin ve standard library'nin daha agresif optimizasyonlar yapmasına olanak tanır.
            - noexcept kullanımı, move işlemlerinin garanti altına alınmasını sağlar, bu da STL konteynerlerinin (örneğin, std::vector, std::list) performansını artırabilir.
        - noexcept Kullanımı Şart mı?
            - noexcept kullanımı zorunlu değildir, ancak kullanılması tavsiye edilir. Özellikle büyük veri yapıları veya performans kritik uygulamalar için move işlemlerinde noexcept kullanımı faydalıdır.
            - noexcept kullanılmadığında, move işlemi sırasında exception fırlatma riski vardır ve bu durumda derleyici bazı optimizasyonları gerçekleştiremeyebilir.

- Move Constructor'ın Özellikleri:
    - Move constructor, sağ taraf değer referansı (rvalue reference) alır. yani içine verdiğimiz obje, ifadenin sağ tarafındaki objedir biz onun içini boşaltıyoruz.
    - Move constructor, kaynakların taşındığı nesnenin içeriğini boşaltır, böylece kaynaklar iki nesne arasında paylaşılmaz.
    - içini boşalltığın objenin dynmaic memorysini silme çünkü artık onu diğer nesne kullanıyor.
    
- Avantajları:
    - Performans Artışı:
        - Move constructor, kaynakları taşır (move) yerine kopyalar (copy), bu da genellikle çok daha hızlıdır. Kopyalama, kaynakları yeniden tahsis etmek ve veri kopyalamak gibi maliyetli işlemleri içerirken, taşımak bu işlemleri gerektirmez.

    - Kaynak Yönetimi:
        - Move constructor, dinamik bellek veya diğer kaynakları yöneten sınıfların kaynaklarını etkili bir şekilde taşır. Bu, bellek ve diğer kaynakların gereksiz yere çoğaltılmasını önler.

    - Verimli Bellek Kullanımı:
        - Move constructor, büyük veri yapıları veya dinamik bellek tahsisi gerektiren nesnelerin yönetimini daha verimli hale getirir. Bu, büyük konteynerlerin taşınmasında veya fonksiyon döndürme işlemlerinde bellek kullanımı optimize eder.

    - Geçici Nesnelerin Yönetimi:
        - Geçici (temporary) nesneler, move constructor ile verimli bir şekilde yönetilebilir. Bu nesneler, fonksiyonlar tarafından döndürülen veya geçici olarak oluşturulan nesnelerdir. Move ve copy ikisi de yazıldıysa fonksiyondan değer döndürürken move constructorunu kullanıyor.
- Kullanım Alanları:
    - Standard Template Library (STL) Konteynerleri:
        - STL konteynerleri (örneğin, std::vector, std::list, std::map) move constructor ve move assignment operatörlerini kullanarak öğeleri verimli bir şekilde taşıyabilir.
    - Fonksiyon Döndürme:
        - Bir fonksiyonun büyük bir nesneyi döndürmesi gerektiğinde, move constructor kullanılarak performans optimize edilebilir. Bu, nesnenin kopyalanması yerine taşınmasını sağlar. (dewfault olarak da move kullanabilir sende o şekilde döndürebilirsin istersen fonksiyondan). Direkt böyle kendin vermek onun kullanılcağını garanti eder daha iyi.
        ```cpp
        Base_7 test_copy_constructor_Base_7(Base_7 obj) {
            return std::move(obj);
        }
        ```
    - Geçici Nesneler:
        - Geçici nesneler, move constructor kullanılarak verimli bir şekilde taşınabilir. Bu, geçici nesnelerin ömrünü yönetmek için önemlidir. Fonksiyondan dönen nesneler geçici nesnelerdir. geçici nesneler için öncelik move dur. ama std::move diye belritmek her zaman en iyi yöntem.
            ```cpp
            MyClass obj = MyClass(20);
            ```

    - Büyük Veri Yapıları:
        - Büyük veri yapıları ve kaynak yoğun nesneler için move constructor, bellek yönetimi ve performans açısından kritik önem taşır.
    - manuel olarak move constrcutoru çağırma. copy yerine move u kullanmak istediğimizde.
        ```cpp
        MyClass obj2 = std::move(obj1); // Move constructor çağrılır obj1 i boşaltır
        ```
    - Başka bir move tarzı.
        ```cpp
        MyClass temp1;  
        MyClass temp2(std::move(temp1));
        ```

## Difference move and copy constructor
- **Copy Constructor**
    - Amaç: Mevcut bir nesneden yeni bir nesne oluşturur ve kaynakları kopyalar.
    - Kaynak Yönetimi: Kaynakları (bellek, dosya tanıtıcıları vb.) kopyalar, yani her iki nesne de kendi bağımsız kaynaklarına sahip olur.
    - Performans: Kaynakların kopyalanması gerektiği için genellikle daha yavaş ve daha fazla bellek kullanır.
    - Çağrılma Durumu: Bir nesne başka bir nesneden kopyalandığında çağrılır:
        ```cpp
        MyClass obj2 = obj1; // Copy constructor çağrılır
        ```
    - Kaynak Kullanımı Sonrası Durum: Kopyalanan nesne ve orijinal nesne bağımsız kaynaklara sahip olur ve normal şekilde kullanılabilir.
    - Uygulama:
        ```cpp
        MyClass(const MyClass& other) {
            data = new int(*(other.data));
        }
        ```
    - Varsayılan Sağlanma: Sınıfta tanımlanmadıysa, derleyici tarafından otomatik olarak sağlanır.
    - C++ Standart: C++'ın ilk sürümlerinden itibaren mevcut.

- **Move Constructor**
    - Amaç: Mevcut bir nesneden yeni bir nesne oluşturur ve kaynakları taşır.
    - Kaynak Yönetimi: Kaynakları taşır, yani orijinal nesnenin kaynaklarını yeni nesneye aktarır ve orijinal nesnenin kaynaklarını geçersiz kılar.
    - Performans: Kaynaklar taşındığı için genellikle daha hızlı ve daha az bellek kullanır.
    - Çağrılma Durumu: Bir nesne başka bir nesneden taşındığında çağrılır. Yukarıda daha ayrıntılı senaryolar var.
        ```cpp
        MyClass obj2 = std::move(obj1); // Move constructor çağrılır obj1 i boşaltır copy yerine move kullanmak istediğimizde.
        ```
    - Kaynak Kullanımı Sonrası Durum: Taşınan nesnenin kaynakları geçersiz hale gelir ve artık kullanılmamalıdır. fakat delete etmiyourz farkettiysen adı üstünde taşıma bu.
    - Uygulama:
        ```cpp
        MyClass(MyClass&& other) noexcept {
            this->data = other.data;
            other.data = nullptr;
        }
        ```
    - Varsayılan Sağlanma: Sınıfta tanımlanmadıysa, derleyici tarafından yalnızca bazı koşullar altında otomatik olarak sağlanır.
    - C++ Standart: C++11 ile tanıtılmıştır.

## Temporary Objects
- geçici nesne (temporary object) genellikle fonksiyonlardan dönen objeler için kullanılan bir terimdir, ancak daha geniş bir anlamı vardır. Geçici nesne, genellikle kısa ömürlü olup, geçici bir hesaplamanın veya ifadenin sonucu olarak ortaya çıkan ve genellikle ifade sonlandığında yok edilen nesnelerdir. 
- Move ve copy aynı anda varsa move constructorunu çağırır. 
- sadece copy constructoru yazıldıysa da copy i çağırır.
-  yani copy constrcutoru ikinci planda. move daha öncelikli.

1. Fonksiyonlardan Dönen Nesneler: Bir fonksiyon geçici bir nesne döndürdüğünde, bu nesne geçici bir nesne olarak kabul edilir. Bir obje oluşturmadan direkt constructor yardımıyla döndürüyor dikkat ettiysen.
    ```cpp
    MyClass createObject() {
        return MyClass(10); // Geçici nesne döndürülüyor
    }
    ```
2. Geçici İfadeler: Bir ifade sonucu olarak geçici bir nesne oluşturulabilir.
    ```cpp
    MyClass obj = MyClass(20);  
    ```
3. Geçici Değerlerin Kullanımı: Geçici nesneler genellikle sağ taraf değeri (rvalue) olarak kabul edilir ve move semantics ile taşınabilirler.
    ```cpp
    MyClass obj = std::move(createObject()); // Geçici nesne std::move ile taşınıyor
    ```

## RVO and NRVO
- RVO ve NRVO, fonksiyonlar döndürdükleri nesneleri doğrudan çağıran fonksiyonun kapsamına yerleştirerek constructor ve destructor çağrılarını optimize eder. Bu optimizasyonlar sayesinde kopyalama veya taşıma işlemi tamamen atlanabilir.
- örnek:
    ```cpp
    Myclass fun() {
        MyClass obj; 
        return obj
    }
    ```
    - optimmizasyon uygulanmazsa
    ```cpp
    MyClass fun() {
        MyClass obj; // Local object
        return obj;  // RVO/NRVO olabilir, olmazsa move constructor çağrılır
        }
    ```
- Ne Zaman Move Constructor, Ne Zaman Copy Constructor Çağrılır?
    - RVO/NRVO Uygulanırsa:
        - Derleyici RVO/NRVO uyguladığında, move veya copy constructor çağrılmadan nesne doğrudan main fonksiyonundaki obj değişkenine yerleştirilir.
    - RVO/NRVO Uygulanmazsa:
        - C++11 ve sonrası: Move constructor çağrılır.
        - C++11 öncesi: Copy constructor çağrılır.

- Örnek2:
    ```cpp
    #include <iostream>
    #include <utility> // std::move için gerekli
    using namespace std;

    class MyClass {
    public:
        int* data;

        // Parametreli constructor
        MyClass(int value = 0) {
            data = new int(value);
            cout << "Parametreli constructor called with value: " << value << endl;
        }

        // Copy constructor
        MyClass(const MyClass& other) {
            data = new int(*(other.data));
            cout << "Copy constructor called" << endl;
        }

        // Move constructor
        MyClass(MyClass&& other) noexcept {
            data = other.data; // Kaynakları taşı
            other.data = nullptr; // Diğer nesneyi geçersiz hale getir
            cout << "Move constructor called" << endl;
        }

        // Destructor
        ~MyClass() {
            delete data;
            cout << "Destructor called" << endl;
        }

        void display() const {
            if (data)
                cout << "Value: " << *data << endl;
            else
                cout << "Value: null" << endl;
        }
    };

    MyClass fun() {
        MyClass obj(10); // Local object
        return obj;  // RVO/NRVO olabilir, olmazsa move constructor çağrılır
    }

    int main() {
        MyClass obj = fun(); // Return value is assigned to obj
        obj.display(); // Değer: 10
        return 0;
    }
    ```
    - RVO/NRVO uygulanırsa:
        ```
        Parametreli constructor called with value: 10
        Destructor called
        Value: 10
        Destructor called
        ```
    - RVO/NRVO uygulanmaz ve move constructor çağrılırsa(cpp 11 sonrasında):
        ```
        Parametreli constructor called with value: 10
        Move constructor called
        Destructor called
        Value: 10
        Destructor called
        ```

## Constrcutor Initilizaiton List
- Constructor Initialization List (Yapıcı Başlatma Listesi), C++'da bir sınıfın veri üyelerini, yapıcı fonksiyonun gövdesine girmeden önce başlatmanın bir yoludur. Bu, özellikle sabit (const) veya referans (&) veri üyeleri gibi, doğrudan atama ile başlatılamayan veri üyeleri için önemlidir. Ayrıca, performans açısından da avantajlı olabilir çünkü veri üyeleri doğrudan başlatılır, bu da gereksiz varsayılan başlatmaları ve sonradan atamaları önler.
- dışarıdan veya içeriden değer alarak başlatmak için kullanıyoruz.
- const ve ref üyeleri kesinnlike başlatılmalıdır o yüzden doğru constructları yazmayı unutma. bunları doğrudan başlatamazsın const int = 5; diyerek. her türlü initilazion list kullanmalısın. yada düz parametre alıp eşitlemek de saçma çünkü const bir değişken sonradan değer atayamazsın.
- illa dışarıdan değer almak zorunda değilsin içerideki değerleri de direkt birbirinie atayabilrsin ya da kendin değer verebiliyorsan verebilirsin.(kodda örnek var)
- syntax (Genel syntaxı aşağıdaki gibi) (declaration ve definition ayrı ayrı yapmak istersen koda bak)
- ayrı ayrı yaptığında initilazison list declaration da belirtilmez aynı defaault paremetreler gibi o da öyleydi. initilization list i definitionda verirsin.
    ```cpp
    class MyClass {
    public:
        MyClass(int a, int b) : x(a), y(b) {
            // Gövde
        }

    private:
        int x;
        int y;
    };
    ```

- **Neden Kullanılır?**
    - Sabit ve Referans Üyeleri Başlatma: const ve referans üyeler yalnızca bir kez başlatılabilir ve doğrudan atama ile değiştirilemezler.
        ```cpp
        class MyClass {
        public:
            MyClass(int a) : x(a), y(100) {}

        private:
            const int x;
            int& y;
        };
        ```
    - Temel Sınıfların Başlatılması: Bir türemiş sınıf, temel sınıfın yapıcısını başlatma listesi kullanarak çağırabilir. Ya da dümdüz kendi classımızı da başlatırken kullanabiliriz.
        ```cpp
        class Base {
        public:
            Base(int a) {}
        };

        class Derived : public Base {
        public:
            Derived(int a, int b) : Base(a), y(b) {}
        private:
            int y;
        };
        ```

    - Performans: Başlatma listesi, veri üyelerinin doğrudan başlatılmasını sağlar ve gereksiz varsayılan başlatmaları ve sonradan atamaları önler.
        ```cpp
        class MyClass {
        public:
            MyClass(int a, int b) : x(a), y(b) {}
        private:
            int x;
            int y;
        };
        ```
- **Avantajlar**
    - Doğrudan Başlatma:
        - Veri üyeleri doğrudan başlatılır, bu da daha temiz ve etkili bir kod sağlar.
    - Performans:
        - Başlatma listesi, gereksiz kopyalamaları ve atamaları önleyerek performansı artırır.
    - Sabit ve Referans Üyeler:
        - const ve referans üyelerin doğru şekilde başlatılmasını sağlar.
## Delegating Construcors
- Delegating constructors, C++11 ile tanıtılan bir özelliktir ve bir sınıfın bir constructor'ının başka bir constructor'ı çağırmasına izin verir. Bu özellik, kod tekrarını azaltmak ve constructor mantığını merkezileştirmek için kullanılır. Temel olarak, bir constructor diğer bir constructor'ı çağırarak initialization işlemini devreder.
    ```cpp
    class MyClass {
    public:
        MyClass() : MyClass(0, 0) {
            // Burada ekstra bir işlem yapmanıza gerek kalmaz.
        }

        MyClass(int x) : MyClass(x, 0) {
            // Sadece bir parametre ile çağrıldığında ekstra işlemler yapılabilir.
        }

        MyClass(int x, int y) {
            // Ana constructor, gerçek initialization işlemleri burada yapılır.
            this->x = x;
            this->y = y;
        }

    private:
        int x, y;
    };
    ```
    - Parametresiz constructor MyClass(), MyClass(0, 0) constructor'ını çağırır.
    - Bir parametreli constructor MyClass(int x), MyClass(x, 0) constructor'ını çağırır.
    - İki parametreli constructor MyClass(int x, int y), gerçek initialization işlemlerini gerçekleştirir.
    - yani parametresiz construcotru çağırıken iki paremetre alan constructoru çağırıyor ve ona uygun paremetreleri veriyor.
    - çok işlevsel gelmedi bana çünkü parametresiz constructoru çağırıyoruz diyelim. Önce parametreli olanı çağırıyor sonra gidiyor parametresiz olanı çağırıyor. default parametre vermek gibi belki başka bir kullanım alanı olabilir.

## Member Data and their initilizations with classes
### Basit Veri Türleri (Basic Data Types)
- önerilen: initializaiton list kullan
    ```cpp
    class MyClass {
    public:
        MyClass(int a) : basicValue(a) {}
        void print() const { std::cout << "basicValue: " << basicValue << std::endl; }
    private:
        int basicValue;
    };

    int main() {
        MyClass obj(10);
        obj.print(); // Output: basicValue: 10
        return 0;
    }
    ```
- çalışan ama pek önerilmeyen
    ```cpp
    class MyClass {
    public:
        MyClass(int a) {
            basicValue = a; // Bu kullanım çalışır ancak yapıcı başlatma listesi kullanmak daha iyidir.
            this->basicValue // Bu kullanım da çalışır ancak yapıcı başlatma listesi kullanmak daha iyidir.
        }
    private:
        int basicValue;
    };

    int main() {
        MyClass obj(10);
        return 0;
    }
    ```
### const Değişkenler
- önerilen: initializaiton list kullan. const initialization u kesinlikle yapılmalıdır. normalde de öyle. const int a; diye bir değişken tanımlayamazsın bunu bir şeye eşitlemen lazım
    ```cpp
    class MyClass {
    public:
        MyClass(int a) : constValue(a) {}
        void print() const { std::cout << "constValue: " << constValue << std::endl; }
    private:
        const int constValue;
    };

    int main() {
        MyClass obj(10);
        obj.print(); // Output: constValue: 10
        return 0;
    }
    ```

- Nasıl Kullanılmamalı çalışmayan yöntem:
    ```cpp
    class MyClass {
    public:
        MyClass(int a) {
            constValue = a; // Hata: const üye yalnızca yapıcı başlatma listesi ile başlatılabilir.
        }
    private:
        const int constValue;
    };

    int main() {
        MyClass obj(10);
        return 0;
    }
    ```
### Referanslar (References)
- önerilen: initializaiton list kullan. ref initialization u kesinlikle yapılmalıdır. normalde de öyle. int& a; diye bir değişken tanımlayamazsın bunu bir şeye eşitlemen lazım
    ```cpp
    class MyClass {
    public:
        MyClass(int& b) : refValue(b) {}
        void print() const { std::cout << "refValue: " << refValue << std::endl; }
    private:
        int& refValue;
    };

    int main() {
        int value = 20;
        MyClass obj(value);
        obj.print(); // Output: refValue: 20
        return 0;
    }
    ```

- Nasıl Kullanılmamalı çalışmayan yöntem:
    ```cpp
    class MyClass {
    public:
        MyClass(int& b) {
            refValue = b; // Hata: Referans üye yalnızca yapıcı başlatma listesi ile başlatılabilir.
        }
    private:
        int& refValue;
    };

    int main() {
        int value = 20;
        MyClass obj(value);
        return 0;
    }
    ```

### const Referanslar
- önerilen hem cons hem reference zaten
    ```cpp
    class MyClass {
    public:
        MyClass(const int& b) : constRefValue(b) {}
        void print() const { std::cout << "constRefValue: " << constRefValue << std::endl; }
    private:
        const int& constRefValue;
    };

    int main() {
        int value = 20;
        MyClass obj(value);
        obj.print(); // Output: constRefValue: 20
        return 0;
    }
    ```
- çalışmayan
    ```cpp
    class MyClass {
    public:
        MyClass(const int& b) {
            constRefValue = b; // Hata: const referans üye yalnızca yapıcı başlatma listesi ile başlatılabilir.
        }
    private:
        const int& constRefValue;
    };

    int main() {
        int value = 20;
        MyClass obj(value);
        return 0;
    }
    ```
### İşaretçiler (Pointers)
- önerilen
    ```cpp
    class MyClass {
    public:
        MyClass(int* p) : ptrValue(p) {}
        void print() const { std::cout << "ptrValue: " << *ptrValue << std::endl; }
    private:
        int* ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        obj.print(); // Output: ptrValue: 20
        return 0;
    }
    ```
- önerilmeyen ama çalışır.
    ```cpp
    class MyClass {
    public:
        MyClass(int* p) {
            ptrValue = p; // Çalışabilir ancak yapıcı başlatma listesi kullanmak daha iyidir.
        }
    private:
        int* ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        return 0;
    }
    ```
### const İşaretçiler

#### İşaret Edilen Değer const Olduğunda:
- önerilen:
    ```cpp
    class MyClass {
    public:
        MyClass(const int* p) : ptrValue(p) {}
        void print() const { std::cout << "ptrValue: " << *ptrValue << std::endl; }
    private:
        const int* ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        obj.print(); // Output: ptrValue: 20
        return 0;
    }
    ```

- önerilmeyen ama çalışan:
    ```cpp
    class MyClass {
    public:
        MyClass(const int* p) {
            ptrValue = p; // Çalışabilir ancak yapıcı başlatma listesi kullanmak daha iyidir.
        }
    private:
        const int* ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        return 0;
    }
    ```

#### İşaretçi Kendisi const Olduğunda:
- önerilen
    ```cpp
    class MyClass {
    public:
        MyClass(int* p) : ptrValue(p) {}
        void print() const { std::cout << "ptrValue: " << *ptrValue << std::endl; }
    private:
        int* const ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        obj.print(); // Output: ptrValue: 20
        return 0;
    }
    ```

- çalışmayan yöntem
    ```cpp
    class MyClass {
    public:
        MyClass(int* p) {
            ptrValue = p; // Hata: const işaretçi yalnızca yapıcı başlatma listesi ile başlatılabilir.
        }
    private:
        int* const ptrValue;
    };

    int main() {
        int value = 20;
        MyClass obj(&value);
        return 0;
    }
    ```

### static Değişkenler
- önerilen
    ```cpp
    class MyClass {
    public:
        static int staticVar;
    };

    int MyClass::staticVar = 0; // Static değişkenin başlatılması cpp de veya ana yerde başlatabilirsin.

    int main() {
        MyClass::staticVar = 10; // Static değişkene sınıf adı üzerinden erişim
        return 0;
    }
    ```

- örnerilmeyen: 
    ```cpp
    class MyClass {
    public:
        static int staticVar;
    };

    // int MyClass::staticVar; // default olarak 0 atar ama direkt bizim set etmemiz daha mantıklı.
    ```

### extern Değişkenler
- çok iyi örnek yok burada nasıl olucağına bakmak için storage classes bölümünde incele
- önerilen
    ```cpp
    // file1.cpp
    int globalVar = 42;

    // file2.cpp
    extern int globalVar;
    int main() {
        std::cout << globalVar << std::endl; // Output: 42
        return 0;
    }
    ```

- çalışmayan
    ```cpp
    // file1.cpp
    extern int globalVar; // Hata: globalVar burada başlatılmamış

    // file2.cpp
    int globalVar = 42; // Bu bir başlatma, extern bildirimi değil
    extern int globalVar;
    int main() {
        std::cout << globalVar << std::endl; // Undefined behavior
        return 0;
    }
    ```
### Sabit Uzunluklu Diziler 
- önerilen : init list kullan
    ```cpp
    class MyClass {
    public:
        MyClass() : arr{1, 2, 3, 4, 5} {}
        void print() const {
            for (int i = 0; i < 5; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    private:
        int arr[5];
    };

    int main() {
        MyClass obj;
        obj.print(); // Output: 1 2 3 4 5
        return 0;
    }
    ```         
- çalışmayan
    ```cpp
    class MyClass {
    public:
        MyClass() {
            arr[5] = {1, 2, 3, 4, 5}; // Hata: Bu şekilde diziyi başlatamazsınız tek tek değerleri eşitlemen lazım en başta tanımlamıyorsan
        }
    private:
        int arr[5];
    };

    int main() {
        MyClass obj;
        return 0;
    }
    ```

### static const
- static const değişkenleri sınıflarda kullanmak, belirli sınıflar için sabit olan ve değişmeyen değerleri tanımlamak için yaygın bir tekniktir. static const değişkenler, sınıfın tüm nesneleri arasında paylaşılan ve sabit olan değerlerdir.
- static const değişkenler sınıfın dışında başlatılmalıdır, çünkü bu değişkenlerin bellekte yer alması için sınıf tanımı dışında bir bellek tahsisi gereklidir. sınıfın içinde de tanımlayabilirisn probelm olmuyor StaticandNonstatic bölümüne bak.
    ```cpp
    #include <iostream>

    class MyClass {
    public:
        static const int constantValue;

        MyClass() {
            std::cout << "MyClass created with constantValue: " << constantValue << std::endl;
        }
    };

    // Sınıfın dışında `static const` değişkenin tanımı ve başlatılması
    const int MyClass::constantValue = 10;

    int main() {
        MyClass obj1;
        MyClass obj2;

        std::cout << "Accessing constantValue: " << MyClass::constantValue << std::endl;

        return 0;
    }
    ```

- **özet**
    - Basit Veri Türleri: Doğrudan tanımlanabilir ve başlatılabilir, ancak uninitialized bırakılmamalıdır.
    - const Değişkenler: Yapıcı başlatma listesi ile başlatılmalı, doğrudan atama yapılmamalıdır.
    - Referanslar: Yapıcı başlatma listesi ile başlatılmalı, doğrudan atama yapılmamalıdır.
    - const Referanslar: Yapıcı başlatma listesi ile başlatılmalı, doğrudan atama yapılmamalıdır.
    - İşaretçiler: Doğrudan atama yapılabilir ancak yapıcı başlatma listesi kullanmak daha iyidir.
    - const İşaretçiler: Yapıcı başlatma listesi ile başlatılmalı, doğrudan atama yapılmamalıdır.
    - static Değişkenler: Sınıf dışı tanımlanmalı ve başlatılmalıdır.
    - extern Değişkenler: Başka bir dosyada tanımlanmalı ve başlatılmalıdır.
    - volatile Değişkenler: Doğrudan tanımlanabilir ancak işaretçiler uninitialized bırakılmamalıdır.
    - Sabit Uzunluklu Diziler: Yapıcı başlatma listesi ile başlatılmalıdır.
    - Dinamik Bellek Yönetimi: new ile tahsis edilmeli ve destructor'da delete ile serbest bırakılmalıdır.
    - Yapıcı Başlatma Listesi: const, referans veri üyeleri için kullanılır ve doğrudan atama yapılmamalıdır.