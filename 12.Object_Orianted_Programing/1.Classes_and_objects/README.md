# Classes and Objects
## Content
1. First part
    - [Class](#class)
    - [Defining Class and Declaring Objects](#defining-class-and-declaring-objects)
    - [Accesing Data Members and Functions](#accesing-data-members-and-member-functions)
    - [Constructors](#constructors)
    - [Destructors](#destructors)

2. Second Part
    - [Access Specifiers](#access-specifiers)

3. Third Part
    - [Friend Class and Friend Function](#friend-class-and-friend-function)
# First Part
## Class
- Class, Object-Oriented Programming'in (OOP) temel yapı taşlarından biridir. Class, veri ve bu veriler üzerinde işlem yapan fonksiyonları bir araya getirerek bir tür şablon oluşturur. Bu şablon, nesnelerin (objects) özelliklerini ve davranışlarını tanımlar.

### Temel Özellikleri:
- **Data Members (Veri Üyeleri)**: Class içinde tanımlanan değişkenlerdir. Bu değişkenler, class'ın özelliklerini veya durumunu saklar. Örneğin, bir "Car" class'ında "color", "model" gibi veri üyeleri olabilir.
- **Member Functions (Üye Fonksiyonlar)**: Class içinde tanımlanan fonksiyonlardır. Bu fonksiyonlar, class'ın veri üyeleri üzerinde işlem yapar ve class'ın davranışlarını tanımlar. Örneğin, bir "Car" class'ında "startEngine()", "stopEngine()", "accelerate()" gibi üye fonksiyonlar olabilir.
- **Access Specifiers (Erişim Belirleyicileri)**: Class içindeki veri üyelerinin ve üye fonksiyonların erişim seviyesini belirler. C++'da üç temel erişim belirleyicisi vardır:
    - public: Bu belirleyici ile tanımlanan üyeler, class dışından erişilebilir.
    - private: Bu belirleyici ile tanımlanan üyeler, sadece class içinden erişilebilir.
    - protected: Bu belirleyici ile tanımlanan üyeler, class içinden ve türetilmiş sınıflardan erişilebilir.

## Defining Class and Declaring Objects
### Defining Class
- Öncelikle, basit bir Person sınıfı tanımlayalım. Bu sınıf sadece bir kişinin adını ve yaşını saklayacak.
- Bu kodda, Person sınıfı iki veri üyesine (name ve age) ve bir üye fonksiyona (display) sahiptir. display fonksiyonu, Person nesnesinin adını ve yaşını ekrana yazdırır.
- (ana kodda Person classı)

### Declaring Objects
- Şimdi, Person sınıfından bir nesne oluşturacağız ve bu nesnenin veri üyelerini atayacağız.
- Bu kodda, Person sınıfından person1 adlı bir nesne oluşturduk ve name ve age üyelerine değerler atadık. Daha sonra display fonksiyonunu kullanarak bu bilgileri ekrana yazdırdık.
- bir class tanımlanıdğında o class için memory allocate edilmez. O classdan bir obje oluşturudğumuzda obje için alan allocate edilir.
- (basic_class_usage())

## Accesing Data Members and Member Functions
- Public data member ve member function lara class dışından oluşturulan obje ile ulaşılabilir. data member veya function member lara ulaşmak için "." operatörünü kullanmalıyız.
- (basic_class_usage())

### Member Functions
- iki farklı şekilde fonksiyonları tanımlayabiliriz.
    - class tanımının olduğu yerde
    - class ın dışında (özellikle header ve cpp dosyaları kullanırken bunu çok yapıyoruz)
        - classın dışında fonksiyonun definitionunu yazmak için scope resolution:: operator kullanıyoruz. classın içinde fonksiyon declaration u yapmış olmamız gerekiyor.
- (basic_class_usage() person class)

- C++'da, sınıf tanımı içinde tanımlanan tüm üye fonksiyonlar varsayılan olarak inline'dır. Bununla birlikte, herhangi bir sınıf dışı fonksiyonu da inline anahtar kelimesini kullanarak inline yapabilirsiniz. Inline fonksiyonlar, derleme sırasında her yere kopyalanan gerçek fonksiyonlardır, bu nedenle fonksiyon çağrılarının ek yükü azaltılır. Sınıfa ait sınıfın dışında definitionu yapılan fonksiyonlar inline değildir.

- **Inline Fonksiyonlar ve Kullanımı**
    - inline'ın derleyiciye verilen bir talimat olmadığını, sadece bir istek olduğunu ve derleyicinin bu isteği, koşullara bağlı olarak yerine getirip getirmeyeceğini unutmamak gerekir.
    - Inline fonksiyonlar, küçük ve sıkça çağrılan fonksiyonların verimliliğini artırmak için kullanılır. Derleyici, inline fonksiyonları çağrıldıkları yerdeki kodun içine kopyalar. Bu, fonksiyon çağrısı başına gelen ek yükü ortadan kaldırır. 
        ```cpp
        #include <iostream>

        class Math {
        public:
            int add(int a, int b) {
                return a + b;
            }

            int multiply(int a, int b) {
                return a * b;
            }
        };

        int main() {
            Math math;
            std::cout << "Sum: " << math.add(5, 3) << std::endl;
            std::cout << "Product: " << math.multiply(5, 3) << std::endl;
            return 0;
        }
        ```
    - Bu örnekte, add ve multiply fonksiyonları Math sınıfı içinde tanımlanmıştır. Bu nedenle, bu fonksiyonlar varsayılan olarak inline'dır.

        ```cpp
        #include <iostream>

        inline int add(int a, int b) {
            return a + b;
        }

        inline int multiply(int a, int b) {
            return a * b;
        }

        int main() {
            std::cout << "Sum: " << add(5, 3) << std::endl;
            std::cout << "Product: " << multiply(5, 3) << std::endl;
            return 0;
        }
        ```
    - Bu örnekte, add ve multiply fonksiyonları sınıf dışında tanımlanmıştır ve inline anahtar kelimesi kullanılarak inline yapılmıştır. Derleyici, bu fonksiyonları çağrıldıkları yere kopyalayarak fonksiyon çağrısı ek yükünü ortadan kaldırır. inline fonksiyonlar, fonksiyon çağrısı sırasında oluşan ek yükü ortadan kaldırır, çünkü fonksiyon gövdesi çağrıldıkları yere kopyalanır.

## Constructors
- Constructor, bir sınıfın (class) örneği (object) oluşturulduğunda otomatik olarak çağrılan özel bir fonksiyondur(ilk çağrılan fonksiyon). Constructor'lar, nesnenin veri üyelerini başlatmak (initialize etmek) için kullanılır. Constructor, sınıfın adıyla aynı ada sahiptir ve dönüş tipi (return type) yoktur.
- Sınıfın Adıyla Aynı İsimde Olur: Constructor'ın adı, sınıfın adıyla aynı olmalıdır.
- Dönüş Tipi Olmaz: Constructor'ların dönüş tipi yoktur, hatta void bile olmaz.
- Otomatik Olarak Çağrılır: Bir nesne oluşturulduğunda constructor otomatik olarak çağrılır(ilk çağrılan fonksiyon).
- Overload Edilebilir: Bir sınıfta birden fazla constructor olabilir (overloading).

- **Constructor Türleri**
    - Varsayılan Constructor (Default Constructor): Parametre almaz. Eğer hiçbir constructor tanımlanmazsa, derleyici tarafından otomatik olarak sağlanır.(basic_example_usage)
    - Parametreli Constructor (Parameterized Constructor): Bir veya daha fazla parametre alır ve nesne oluşturulurken bu parametreleri kullanarak veri üyelerini başlatır.
    - Kopya Constructor (Copy Constructor): Bir nesneyi aynı sınıftan başka bir nesne ile başlatmak için kullanılır. Parametre olarak aynı sınıftan bir referans alır.

- **Constructor'ların Avantajları**
    - Başlatma: Constructor'lar, nesnelerin veri üyelerini başlatmak için kullanılır.
    - Otomatik Çağrılma: Nesne oluşturulduğunda constructor otomatik olarak çağrılır, bu nedenle ek bir çağrı yapmaya gerek yoktur.
    - Overloading: Bir sınıfta birden fazla constructor tanımlayarak nesneleri farklı şekillerde başlatmak mümkündür.

- default consturctor(parametresiz) içeren veya içermeyen classlarda obje oluşturuken dikkat etmemiz gerekn bir şey var.
    ```cpp
    Person person; // doğru
    Person person(); // yanlış
    ```
    - yukarıdaki iki tanımlama farklı şeyler
    - Person person;: Bu ifade, Person sınıfından bir nesne oluşturur. Bu, bir nesne tanımıdır ve derleyiciye person adında bir Person nesnesi oluşturmasını söyler. Bu nesne, varsayılan constructor (eğer tanımlanmışsa) kullanılarak başlatılır.
    - Person person(); Bu ifade ise, bir fonksiyon bildirimi (declaration) yapar. Bu, person adında ve Person türünde bir nesne döndüren parametresiz bir fonksiyonun bildirimidir. Yani, bu ifade aslında bir nesne oluşturmaz, sadece bir fonksiyonun varlığını bildirir. Yani Person türünde bir dönüş değeri olan fonksiyonun declarationunu yapmışsın gibi davranır.
    - parametre alan constructorları tanımlarken parantez kullanabiliriz ama parametre almayan constructor ları kullanırken buna dikkat etmelisin. 
    - Yani parmetre yoksa parantez kullanma varsa kullan.

## Destructor
- Destructor, bir sınıfın (class) örneği (object) yaşam döngüsünün sonunda otomatik olarak çağrılan özel bir fonksiyondur(son çağrılan fonksiyon). Destructor'lar, nesne bellekten silinmeden önce herhangi bir temizleme işlemi yapmak için kullanılır. Bu, özellikle dinamik bellek tahsisi (dynamic memory allocation) yapıldığında önemlidir.
- Sınıfın Adıyla Aynı İsimde Olur: Destructor'ın adı, sınıfın adıyla aynı olmalı, ancak önünde bir tilde (~) işareti bulunmalıdır.
- Dönüş Tipi Olmaz: Destructor'ların dönüş tipi yoktur, hatta void bile olmaz.
- Parametre Almaz: Destructor'lar parametre almazlar ve overload edilemezler (bir sınıfta sadece bir destructor olabilir).
- Otomatik Olarak Çağrılır: Bir nesne, kapsam dışına çıktığında veya delete operatörü kullanıldığında destructor otomatik olarak çağrılır.

- **Destructor'ların Avantajları**
    - Bellek Yönetimi: Destructor'lar, dinamik olarak tahsis edilen belleği serbest bırakmak için kullanılır. Bu, bellek sızıntılarını (memory leaks) önlemeye yardımcı olur.
    - Kaynak Yönetimi: Dosya tanıtıcıları, soketler gibi diğer kaynakları serbest bırakmak için de destructor'lar kullanılır.
    - Otomatik Temizlik: Destructor'lar, nesne yaşam döngüsünün sonunda otomatik olarak çağrıldığı için manuel temizleme işlemlerini azaltır.

# Second Part
## Access Specifiers
- Access Specifiers, C++'da sınıfların (classes) ve yapıların (structs) üyelerine (data members ve member functions) erişim seviyelerini belirlemek için kullanılır. Bu, veri gizliliğini (data encapsulation) ve veri korumasını (data protection) sağlar. C++'da üç ana erişim belirleyicisi (access Specifiers) vardır: public, private, ve protected.
- **Access Modifiers Türleri**
    - public
        - Erişim: public üyeler, sınıfın dışındaki herhangi bir kod tarafından erişilebilir.
        - Kullanım: Sınıfın dışındaki kodun erişmesi gereken veri üyeleri ve fonksiyonlar için kullanılır.

    - private
        - Erişim: private üyeler, sadece tanımlandıkları sınıfın üyeleri (data members ve member functions) tarafından erişilebilir. Sınıfın dışındaki kod veya diğer sınıflar tarafından erişilemez.
        - Kullanım: Veri üyelerinin ve fonksiyonların sadece sınıfın içinden erişilebilir olmasını sağlamak için kullanılır. Bu, veri gizliliğini sağlar.
        - dışarıdan erişilebilir olmasını sağlamak için public getter ve setter fonksiyonları yazarız. ya da friend function lar kullanabiliriz.

    - protected
        - Erişim: protected üyeler, tanımlandıkları sınıfın ve bu sınıftan türetilmiş sınıfların (derived classes) üyeleri tarafından erişilebilir. Sınıfın dışındaki kod tarafından doğrudan erişilemez.
        - Kullanım: Türetilmiş sınıfların erişmesi gereken, ancak sınıfın dışındaki kod tarafından erişilmemesi gereken veri üyeleri ve fonksiyonlar için kullanılır.
- **Özet**
    - public: Sınıfın dışındaki kod tarafından erişilebilir.
    - private: Sadece tanımlandıkları sınıfın üyeleri tarafından erişilebilir.
    - protected: Tanımlandıkları sınıfın ve türetilmiş sınıfların üyeleri tarafından erişilebilir.
- Eğer herhangi bir acces modifiers tanımlamazsak defaultu private dır. 

# Third Part
## Friend Class and Friend Function
### Friend Class
- C++'da friend class, başka bir sınıfa (class) tüm özel (private) ve korumalı (protected) üyelerine erişim izni veren bir sınıftır. Bu, normalde erişilemeyen üyeleri bir başka sınıfın erişmesine izin verir. friend class kavramı, sınıflar arasında özel bir ilişki tanımlamak ve belirli sınıfların verilerine ve işlevlerine daha geniş bir erişim sağlamak için kullanılır. 
- bunları objelerle yapıyoruz unutma direkt değişkenin ismini kullanmıyoruz. genellikle parametre olarak o sınıfın objesini alıyoruz ve onun private veya protected değişkenlerine o şekilde ulaşıyoruz.
- Yani mesela private değişkenlere hiçbir şekilde erişemeyiz ama friend class tanımlarsak erişebilriz başka classtan. 
- Aynı şekilde portected içinde geçerli. Inheritence kullanmadığımız sürece hiç bir şekilde bu verilere ulaşamayız ama friend class lar sayesinde ulaşabiliyoruz.
- friend classı public, protected, private altında nerde tanımladığın önemli değil her türlü o classın özel verilerine erişebişir. Çünkü friendler classa ait bir member değildir o yüzden access modifiers den etklienmez.
- friend classın body sini yazareken scope resolution kullanmıyoruz(genllikle). bir istisna var kodda yer alıyor o da.
    - A ve B classlarını ele alalım. B nin bir member fonksiyonu A nın objeisni alıyor diyelim. Ben bu fonksiyona tam erişim vermek istiyorum varsayalım. A ya gidip b nin bu fonksioynunu friend olarak tanımlarım. bu sadece bir classa friend olarak görmek isityorsak ve kod düzenliliği isitorsak güzel olabilir. bnun yerine direkt B classına friend desek daha mantıklı bence.
- aynı şekilde fonksiyonu çağırırken de kullanmıyoruz. 
- obje de kullanmıyoruz çağırıken(. ile çağırmaktan bashediyorum). sadece paremetre olarak obje alıyor.
- **Örnek açıklamları**:
    - İleriye Doğru Bildirim (Forward Declaration): class ClassB; ifadesi, ClassB'nin varlığını ClassA'ya bildirmek için kullanılır. Bu, ClassB'yi ClassA'dan önce tanımlamak zorunda kalmamak için yapılır. Yapmasak da çalışıyor ama yapmak daha mantıklı.
    - Friend Class Bildirimi: friend class ClassB; ifadesi, ClassB'nin ClassA'nın tüm özel (private) ve korumalı (protected) üyelerine erişmesine izin verir.

- **Avantajlar**
    - Veri Gizliliğini Sağlarken Esneklik: friend class, verilerin gizliliğini korurken belirli sınıflar arasında esneklik sağlar.
    - Daha İyi Performans: Fonksiyonların sınıf üyelerine doğrudan erişim sağlaması, fonksiyon çağrılarının ek yükünü azaltabilir.
    - Sınıflar Arası Sıkı İlişki: İki sınıf arasında sıkı bir iş birliği gerektiğinde kullanışlıdır.
- **Dezavantajlar**
    - Güvenlik Riski: friend class, veri gizliliğini ihlal edebilir ve sınıflar arasındaki ayrımı bulanıklaştırabilir.
    - Bakım Zorluğu: Çok sayıda friend class kullanımı, kodun anlaşılmasını ve bakımını zorlaştırabilir.
    - Kapsüllemeyi Azaltma: friend class, kapsülleme ilkesini zayıflatabilir ve kodun daha az modüler olmasına neden olabilir.

- **Özet**
    - friend Class: Bir sınıfın özel (private) ve korumalı (protected) üyelerine erişim izni verir.
    - Kullanımı: Sınıflar arasında özel ilişkiler tanımlamak ve belirli sınıfların verilerine ve işlevlerine daha geniş erişim sağlamak için kullanılır.
    - Avantajlar ve Dezavantajlar: friend class, esneklik ve performans artışı sağlayabilir ancak veri gizliliğini ve kapsüllemeyi zayıflatabilir.

### Friend Function
- friend fonksiyonlar tanımlayarak class ın private değişkenlerine erişim sağlayabilirsin.
- C++'da, friend function, bir sınıfın (class) private (özel) ve protected (korumalı) üyelerine erişim izni verilen bir fonksiyondur. Bu fonksiyon, sınıfın bir üyesi (member function) değildir, ancak sınıfın private ve protected üyelerine erişebilir. friend function, bir sınıfın iç mantığına dışarıdan erişim sağlamak için kullanılır ve genellikle sınıfın işlevselliğini genişletmek veya test etmek amacıyla kullanılır.
- üç farklı friend fonksiyon tanımlama vardır.
    - global olarak
        - Member olmadığı için Class scope u kullanmayız Definitionunu yazarken.
    - başka bir classın member fonksiyonu olarak
        - burada scope kullanıyoruz çünkü farklı bir tanımlama biçimi var. Çünkü buradana gösterilen friend fonksiyonu başka bir classın normal fonksiyonu. Biz bu fonksiyona friend yetkisi veriyoruz ana classdan. Bu yüzden scope var ama ana classın scopu yok dikkat ettiysen normal olarak tanımlandığı classın scopu kullanılmış. Başka class ın member function u başka classın özelliklerine erişmek isterken.(örneğe bak)
    - friend bir fonksiyonu birden fazla class kullanabilir.(Operator overloading de kullanılıyor)

- **Friend Fonksiyonların Avantajları**
    - Bir sınıfı miras almadan üyelerine erişim sağlar: Bir friend fonksiyon, sınıfı miras almadan o sınıfın üyelerine erişebilir.
    - İki sınıf arasında köprü görevi görür: Friend fonksiyon, iki sınıfın private verilerine erişerek aralarında köprü görevi görür.
    - Operatörlerin esnekliğini artırır: Operatör aşırı yüklemelerini (overloaded operators) daha esnek hale getirmek için kullanılabilir.
    - Sınıfın herhangi bir kısmında bildirilebilir: Public, private veya protected bölümde bildirilebilir. Bu fonksiyona erişimimiz kısıtlanmaz çünkü class ın member functionu değil ve obje üzerinden ulaşmıyoruz zaten. Class scop u ile ulaşıyoruz genellikle.

- **Friend Fonksiyonların Dezavantajları**
    - Veri gizliliğini ihlal eder: Friend fonksiyonlar, bir sınıfın private üyelerine sınıf dışından erişebilir, bu da veri gizliliği (data hiding) ilkesini ihlal eder.
    - Çalışma zamanı çok biçimlilik yapamaz: Friend fonksiyonlar, üyeleri arasında çalışma zamanı çok biçimlilik (run-time polymorphism) gerçekleştiremez.

- **Friend Fonksiyonlar ve Sınıflar Hakkında Önemli Noktalar**
    - Sınırlı amaçlar için kullanılmalıdır: Friend fonksiyonlar sadece sınırlı amaçlar için kullanılmalıdır. Çok sayıda fonksiyon veya dış sınıf, bir sınıfın protected veya private verilerine erişim izni alırsa, ayrı sınıfların kapsülleme değerini azaltır.
    - friendship karşılıklı değildir: Eğer A sınıfı B'nin dostu ise, B otomatik olarak A'nın dostu olmaz.
    - friendship miras alınmaz. yani base a class ından b classını türettik diyelim. a classının da c diye friendi olsun diyelim. c b nin firendi değildir ve b nin özel memberlarına erişemez.