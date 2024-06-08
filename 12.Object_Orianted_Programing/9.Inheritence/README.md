# Inheritence
- Inheritance (kalıtım), nesne yönelimli programlamada (OOP) temel bir kavramdır ve bir sınıfın (child class veya derived class) başka bir sınıftan (parent class veya base class veya super class) özellik ve davranışları (veri üyeleri ve metotlar) devralmasını sağlar. Bu, kodun yeniden kullanılabilirliğini artırır ve daha organize ve yönetilebilir bir kod yapısı oluşturur.
- syntax:
    ```cpp
    class  <derived_class_name> : <access-specifier> <base_class_name> {
            //body
    }
    ```
- class: keyword to create a new class
- derived_class_name: name of the new class, which will inherit the base class
- access-specifier: either of private, public or protected. If neither is specified, PRIVATE is taken as default
- base-class-name: name of the base class
- Note: A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.
- ana classın memberlarına ulaşabiliriz. türetilmiş class aracılığıyla.
- ana classın fonksiyonlarına ulaşabilirz. türetilmiş class aracılığıyla.

## Content
- [Access Specifier with Inheritence](#access-specifier-with-inheritence)
- [Types Of Inheritance](#types-of-inheritance)
- [Constructor and Destructor](#constructor-and-destructor)
- [Inheritence Friendship](#inheritence-friendship)
- [Operator Overloading](#operator-overloading)
- [Overloading and Inheritance](#overloading-and-inheritance)
- [Copy and move constrcutor](#copy-and-move-constrcutor)
- [Pointers](#pointers)

## Access Specifier with Inheritence
- C++'ta bir sınıfın başka bir sınıftan nasıl miras alacağını belirlemek için public, protected ve private erişim belirleyicileri kullanılır. Bu erişim belirleyicileri, türetilmiş sınıftaki (derived class) temel sınıfın (base class) üyelerine nasıl erişileceğini kontrol eder. Bu tür miras alma türlerine erişim belirleyicisiyle kalıtım denir.
- base classın değişkenlerinin derived classda nasıl bir hal alacağını belirtmek için kullanıyoruz.
- base classın üyelerinin derived classda nasıl bir acces modifierse sahip olacağını belirtiyoruz aslında.

- **Public Inheritance (Genel Kalıtım)**:
    - Türetilmiş sınıfta temel sınıfın public üyeleri public olarak kalır, protected üyeleri protected olarak kalır, ancak private üyeler türetilmiş sınıfta erişilemez. Klasik inheritence yani.
    - Base Classın access modifiersini olduğu gibi alırız. 
    - Base class ın public üyelerine derived classdan da public olarak yer alır.
    - Base class ın protected üyelerine derived classdan da protected olarak yer alır. Yani protected üyeler derived class da da protected olarak saklanır.
    - Base class ın private üyelerine derived classdan dan erişemeyiz.

- **Protected Inheritance (Korumalı Kalıtım)**:
    - Türetilmiş sınıfta temel sınıfın public ve protected üyeleri protected olarak kalır, ancak private üyeler türetilmiş sınıfta erişilemez.
    - Base Classın, public ve protected üyeleri, derived classda protected acces modifierse sahip olur.
    - Base classın private memberlarına erişemeyiz.

- **Private Inheritance (Özel Kalıtım)**:
    - Türetilmiş sınıfta temel sınıfın public ve protected üyeleri private olur, ancak private üyeler türetilmiş sınıfta erişilemez.
    - Base Classın public ve protected üyeleri derived classda private gibi davranır.
    - Base Classın private değişkenlerine yine ulaşamyız.
    
- **Erişim Belirleyicilerinin Etkileri**
    - Public Inheritance: Base sınıfının public ve protected üyelerine, Derived sınıfı ve Derived sınıfının dışındaki kod (uygun erişim belirleyicileriyle) erişebilir.
    - Protected Inheritance: Base sınıfının public ve protected üyelerine, yalnızca Derived sınıfı ve Derived sınıfından türetilmiş sınıflar erişebilir, ancak dışarıdan erişilemez.
    - Private Inheritance: Base sınıfının public ve protected üyelerine, yalnızca Derived sınıfı erişebilir, ancak dışarıdan ve Derived sınıfından türetilmiş sınıflardan erişilemez.

## Types Of Inheritance
- Nesne yönelimli programlamada (OOP) kalıtım (inheritance) türleri, sınıfların nasıl birbirlerinden miras alacağını belirler. Bu türler, kodun yeniden kullanılabilirliğini ve genişletilebilirliğini artırmak için farklı şekillerde uygulanabilir. İşte başlıca kalıtım türleri
1. **Single Inheritance (Tekli Kalıtım)**
    - Bir sınıfın yalnızca bir başka sınıftan miras almasıdır. Bu, en temel ve yaygın kalıtım şeklidir.
        ```cpp
        class subclass_name : access_mode base_class
        {
        // body of subclass
        };
        OR
        class A
        { 
        ... .. ... 
        };
        class B: public A
        {
        ... .. ...
        };
        ```
2. **Multiple Inheritance (Çoklu Kalıtım)**
    - Bir sınıfın birden fazla sınıftan miras almasıdır. Bu, bir sınıfın birçok farklı sınıfın özelliklerini ve davranışlarını devralmasını sağlar.
    ```cpp
    class subclass_name : access_mode base_class1, access_mode base_class2, ....
    {
    // body of subclass
    };
    class B
    { 
    ... .. ... 
    };
    class C
    {
    ... .. ...
    };
    class A: public B, public C
    {
    ... ... ...
    };
    ```

3. **Multilevel Inheritance (Çok Katmanlı Kalıtım)**
    - Bir sınıfın başka bir sınıftan miras alması ve bu sınıfın da başka bir sınıftan miras almasıdır. Bu, bir hiyerarşi oluşturur.
    ```cpp
    class C
    { 
    ... .. ... 
    };
    class B:public C
    {
    ... .. ...
    };
    class A: public B
    {
    ... ... ...
    };
     ```

4. **Hierarchical Inheritance (Hiyerarşik Kalıtım)**
    - Birden fazla sınıfın aynı temel sınıftan miras almasıdır. Bu, bir temel sınıfın birçok alt sınıfı olması durumunda kullanılır.
    ```cpp
    class A  {  
        // body of the class A.  
    }    
    class B : public A {  
        // body of class B.  
    }  
    class C : public A {  
        // body of class C.  
    }   
    class D : public A  {  
        // body of class D.  
    } 
    ```
5. **Hybrid Inheritance (Melez Kalıtım)**
    - Farklı kalıtım türlerinin bir kombinasyonudur. Bu tür kalıtım, daha karmaşık hiyerarşiler oluşturmak için kullanılır. Ancak, bu tür kalıtımda "diamond problem" adı verilen bir sorun ortaya çıkabilir ve bu sorunun çözümü için sanal kalıtım (virtual inheritance) kullanılabilir. mesela hierarchical ile multiple inheritence kombinasyonu.
    - Burada virtual inheritence kullanırsan en derived classdan, en base classın constructorunu çağırmayı unutma.

## Diamond Problem ve Virtual Inheritance
- Diamond Problem (Elmas Problemi), çoklu kalıtım kullanılan nesne yönelimli programlama dillerinde ortaya çıkabilen bir sorundur. Bu sorun, bir sınıfın iki farklı temel sınıftan aynı sınıfı miras alması durumunda ortaya çıkar. Bu durumda, türetilmiş sınıfta aynı temel sınıfın iki kopyası bulunur ve bu da belirsizliklere ve potansiyel hatalara yol açar.
    ```cpp
    class A {
    public:
        void display() {
            cout << "Class A" << endl;
        }
    };

    class B : public A {
        // Class B inherits from Class A
    };

    class C : public A {
        // Class C inherits from Class A
    };

    class D : public B, public C {
        // Class D inherits from both Class B and Class C
    };
    ```
    - yukarıdaki örnekte, D sınıfı hem B sınıfından hem de C sınıfından miras alır ve bu sınıflar da A sınıfından miras alır. Bu durumda, D sınıfı içinde iki farklı A sınıfı kopyası bulunur ve D sınıfından A sınıfının bir üyesine erişmeye çalıştığınızda, derleyici hangi A sınıfının kullanılması gerektiğini belirleyemez.

- **Diamond Problem'in Çözümü: Virtual Inheritance (Sanal Kalıtım)**
Sanal kalıtım, diamond problem'i çözmek için kullanılan bir tekniktir. Sanal kalıtım, temel sınıfın yalnızca bir kopyasının türetilmiş sınıflar tarafından miras alınmasını sağlar. Bu, diamond problem'de ortaya çıkan belirsizlikleri ortadan kaldırır.
    ```cpp
    class A {
    public:
        void display() {
            cout << "Class A" << endl;
        }
    };

    class B : virtual public A {
        // Class B inherits from Class A virtually
    };

    class C : virtual public A {
        // Class C inherits from Class A virtually
    };

    class D : public B, public C {
        // Class D inherits from both Class B and Class C
    };
    ```

- Bu örnekte, B ve C sınıfları A sınıfından sanal olarak miras alır. Bu, D sınıfı oluşturulduğunda, yalnızca bir A sınıfı örneği olmasını sağlar. Böylece, diamond problem çözülmüş olur ve D sınıfı A sınıfının üyelerine erişirken belirsizlik yaşamaz.
- sanal Kalıtımın Etkileri
    - Tek Bir Temel Sınıf Kopyası: Sanal kalıtım sayesinde, türetilmiş sınıflar yalnızca bir temel sınıf kopyasına sahip olur, bu da bellek tasarrufu sağlar ve belirsizlikleri önler.
    - Daha Karmaşık Yapılar: Sanal kalıtım, çoklu kalıtım yapılarının daha karmaşık hale gelmesine neden olabilir ve yönetimi zorlaştırabilir. Ancak, doğru kullanıldığında, güçlü bir araçtır.
    - Erişim Belirleyicileriyle Uyumluluk: Sanal kalıtım, public, protected, ve private kalıtımla birlikte kullanılabilir ve erişim denetimleri üzerinde etkili olabilir.
- Özet
    - Diamond Problem, bir sınıfın aynı temel sınıfı birden fazla yol üzerinden miras alması durumunda ortaya çıkar.
    - Virtual Inheritance (Sanal Kalıtım), bu sorunu çözmek için temel sınıfın yalnızca bir kopyasının türetilmiş sınıflar tarafından miras alınmasını sağlar.
    - Sanal kalıtım, C++'ta virtual anahtar kelimesi kullanılarak gerçekleştirilir.
    - (öenmli!!) A classını B ve C classları çağırmaz. Sadece D çağırır virtual tanımladığımız için
- virtual inheritence kullanırsan en derived classdan, en base classın constructorunu çağırmayı unutma!!! aslında bir nevi hepsi base classından inheritence yapıyor gibi oluyor

## Constructor and Destructor
- Constrcutorlar inheritence sırasına göre çağrılır. 
- destructor inheritence sırasının tersi yönünde çağrılır.
- C++'da constructor'lar inheritance edilmez, yani derived sınıf, base sınıfının constructor'larını miras almaz. Ancak, derived sınıfın constructor'ları, base sınıfının constructor'larını çağırmak zorundadır. Bu, constructor initializer list kullanılarak yapılır.
    - C++'da "constructor inherit edilmez" demek, derived sınıfın, base sınıfın constructor'larını otomatik olarak miras almadığı anlamına gelir. Yani, derived sınıf, base sınıfın constructor'larını doğrudan kullanamaz. Bunun yerine, derived sınıf, base sınıf constructor'ını çağırmak için kendi constructor'ını tanımlamalı ve base sınıf constructor'ını initializer list kullanarak çağırmalıdır. Değerleri initialize etmek için diyor.
    - Aslında, derived sınıfın bir constructor'ı tanımlandığında, base sınıf constructor'ı otomatik olarak çağrılır. Bu çağrı, derived sınıf constructor'ının initializer list kısmında açıkça belirtilmezse, base sınıfın default constructor'ı çağrılır. Eğer base sınıfın parametreli constructor'ları varsa, derived sınıfın constructor'ının initializer list'inde explicit (açıkça) çağrılması gerekir. aynısı copy ve move constrcutor içinde geçerli
    - using keywordu ile inheritence alabilirsin.
- C++'da destructor'lar inheritance edilen sınıflarda özel bir davranış sergiler. 
    - Non-Virtual Destructor:
        - Derived sınıftan bir nesne yok edilirken, önce derived sınıfın destructor'ı, ardından base sınıfın destructor'ı çağrılır. (pointer kısmında ayrıntısı var)
    - Virtual Destructor:
        - Base sınıfın destructor'ı virtual olarak tanımlandığında, derived sınıf nesnesi base sınıf pointer'ı ile yok edildiğinde bile doğru destructor çağrılır. (pointer kısmında ayrıntısı var)
- constrcutor virtual olamaz.
- destrcutor virtual olabilir.

- **Constrcutor initilization**
    - Inheritance yaparken data member'ları doğru bir şekilde initialize etmek, programın doğru çalışması ve istenmeyen yan etkilerin önlenmesi açısından önemlidir. Data member'ları initialize etmenin en yaygın ve doğru yolu, constructor initializer list kullanmaktır. 
    - constrctor initilization list kullanırken base classın uygun constrcutorunu çağırıyoruz aslında.
    - paremetresiz çağırmak istiyorsan : Base() şeklinde çağır, nomral obje oluşturmayla karıştırma.

### Multileveli, Hybrid Inheritance ve Virtual Inheritance
- Multilevel Inheritance
    - Multilevel inheritance'da, her sınıf bir üst sınıfının constructor'ını çağırır ve base sınıf constructor'ı en derived sınıfa kadar zincirleme olarak çağrılır. En derived sınıfta base sınıf constructor'ını tekrar çağırmaya gerek yoktur çünkü her aşamada constructor'lar birbirini otomatik olarak çağırır.
- Hybrid Inheritance ve Virtual Inheritance
    - Hybrid inheritance'da, virtual inheritance kullanıldığında, base sınıf constructor'ı yalnızca en derived sınıfta çağrılır. Bunun nedeni, virtual inheritance kullanıldığında, base sınıfın tek bir kopyası oluşturulur ve bu kopya en derived sınıf tarafından initialize edilir.(en derived sınıfını kullanılırken)
- Multilevel Inheritance: Constructor zincirleme olarak çağrılır ve base sınıf constructor'ı her aşamada çağrılır.
- Hybrid Inheritance ve Virtual Inheritance: Base sınıf constructor'ı yalnızca en derived sınıfta çağrılır ve diğer intermediate sınıflar bunu tekrar çağırmaz. Bu, base sınıfın tek bir kopyasının oluşturulmasını sağlar ve diamond problem'i önler.(en derived sınıfını kullanılırken)
- virtual inheritence kullanırsan en derived classdan, en base classın constructorunu çağırmayı unutma!!! aslında bir nevi hepsi base classından inheritence yapıyor gibi oluyor.(Hybrid için  )

## Inheritence Friendship
- friend lik durumu inherit edilmez.
    ```cpp
    #include <iostream> 
    using namespace std; 
    
    // Parent Class 
    class A { 
    protected: 
        int x; 
    
    public: 
        A() { x = 0; } 
        friend void show(); 
    }; 
    
    // Child Class 
    class B : public A { 
    private: 
        int y; 
    
    public: 
        B() { y = 0; } 
    }; 
    
    void show() 
    { 
        B b; 
        cout << "The default value of A::x = " << b.x; 
    
        // Can't access private member declared in class 'B' 
        cout << "The default value of B::y = " << b.y; 
    } 
    
    int main() 
    { 
        show(); 
        getchar(); 
        return 0; 
    }
    ```

    ```bash
    prog.cpp: In function ‘void show()’:
    prog.cpp:19:9: error: ‘int B::y’ is private
        int y;
            ^
    prog.cpp:31:49: error: within this context
        cout << "The default value of B::y = " << b.y;  
    ```

## Overloading and Inheritance
- Overloading doesn’t work for derived class in the C++ programming language. There is no overload resolution between Base and Derived. The compiler looks into the scope of Derived, finds the single function “double f(double)” and calls it. It never disturbs the (enclosing) scope of Base. In C++, there is no overloading across scopes and derived class scopes are not an exception to this general rule.
- biz overriding yapmış olduk. farklı classlar arasında overload yapamazsın.
- yani üst classda tanımladığın fonksiyonu alt classda overload edemezsin.
    ```cpp

    #include <iostream>
    using namespace std;
    class Base
    {
    public:
        int f(int i)
        {
            cout << "f(int): ";
            return i+3;
        }
    };
    class Derived : public Base
    {
    public:
        double f(double d)
        {
            cout << "f(double): ";
            return d+3.3;
        }
    };
    int main()
    {
        Derived* dp = new Derived;
        cout << dp->f(3) << '\n';
        cout << dp->f(3.3) << '\n';
        delete dp;
        return 0;
    }
    ```

    ```bash
    //real output
    f(double): 6.3
    f(double): 6.6 
    ```

     ```bash
    //expected output
    f(int): 6
    f(double): 6.6  
    ```

## Operator Overloading 
-  operator overloading işlevleri inheritance yoluyla miras alınır. Bu, derived sınıfların base sınıf operator overloading işlevlerini otomatik olarak miras alacağı anlamına gelir. Ancak, derived sınıflar bu işlevleri override edebilir veya yeniden tanımlayabilir. Farklı senaryolarda nasıl davranıldığını anlamak için bazı temel kavramları ve örnekleri inceleyelim.
- Temel Kavramlar
    - Operator Overloading Miras Alınır: Eğer base sınıfta bir operator overload edilirse, derived sınıf bu operatorü otomatik olarak miras alır.
    - Override ve Yeniden Tanımlama: Derived sınıf, base sınıfta tanımlanan operator overload işlevlerini kendi ihtiyaçlarına göre override edebilir.
    - Derived Sınıf Nesneleri: Derived sınıf nesneleri, base sınıf operator overload işlevlerini kullanabilir.

- Özet
    - Base Sınıfta Tanımlanan Operator Overloading: Derived sınıflar bu operator overload işlevlerini miras alır.
    - Derived Sınıfta Operator Overloading Override Edilmesi: Derived sınıf, base sınıfın operator overload işlevini override edebilir ve kendi işlevselliğini ekleyebilir.

1. Base Sınıfta Operator Overloading
    - Base sınıfta bir operator overloading yapıyoruz. alt sınınf bunu miraz alır ama sadece base classı return edebilir. yani overloadingin sonucunu atayacağın obje Base classından olmalı.(ex-1).
        - ve bu tarz overloading de şunuda göz önünde bulundur. derived classdaki data memberler ı üzerinde hiç bir işlem yapmamış oluyorsun. sadece base classın elemanları üzerinde gerçekleşiyor.
    - eğer Base türünde değilde derived türünde döndürmesini istiyorsan. derived classın içinde tür dönüşümü yapabilicek bir constrcutor yazman lazım(ex-2)

2. Derived Sınıfta Operator Overloading Override Edilmesi
- Derived sınıf, base sınıfın operator overload işlevini override edebilir ve kendi işlevselliğini ekleyebilir.

- (Önemli): Overload ederken şunu göz ününde bulundur. lvalue hangi classa ait rvalue hangi classa ait. bunu göz önünde bulunuraraktan. eşitliği yazarken hangisnin hangi tarafata bulunması gerektiini yazabilirsin. ya da hangi classa gidip overload etmen gerektiini de yazabilirsin.(kodda örnepi incele ne demek istediğimi anlaycaksın)
- bide unutma aynı operatorun birden fazla overloading verisoynunuu yazabilirsin subclasslarda.
- bir tane override base classınki ile aynı, bir tane de derived için yazarsan yeterli olucaktır.

## Copy and move constrcutor
- Copy Constructor
    - Copy constructor, bir nesnenin başka bir nesneden kopyalanması sırasında çağrılır. Inheritance ile birlikte kullanıldığında, base sınıfın copy constructor'ı derived sınıfın copy constructor'ından önce çağrılır.

- Move Constructor
    - Move constructor, bir nesnenin başka bir nesneden kaynaklarını taşıması (move semantics) sırasında çağrılır. Bu, geçici nesnelerle veya kaynakların sahipliğini devretmek istediğiniz durumlarla ilgilidir. Move constructor, shallow copy yerine kaynakların sahipliğini alır.

- Genel Davranışlar
    - Copy Constructor:
        - Bir derived nesne kopyalanırken, önce base sınıfın copy constructor'ı, ardından derived sınıfın copy constructor'ı çağrılır.
        - Derin kopyalama gerekiyorsa, custom copy constructor tanımlanmalıdır.
    - Move Constructor:
        - Bir derived nesne taşınırken, önce base sınıfın move constructor'ı, ardından derived sınıfın move constructor'ı çağrılır.
        - Kaynakların sahipliği devredilir ve taşınan nesneler "boşaltılır" (örneğin, pointerlar null yapılır).

- Inheritance durumlarında, copy ve move constructor'lar önemli bir rol oynar. Derived sınıfların constructor'ları, base sınıf constructor'larını çağırmak zorundadır. Bu, nesnelerin doğru şekilde kopyalanmasını ve taşınmasını sağlar. Eğer custom copy veya move constructor'lar tanımlanmışsa, bu constructor'lar base sınıf constructor'larını explicit olarak çağırmalıdır. Bu, kaynak yönetimi ve doğru constructor sırasının korunması için gereklidir.

- burada derived classda copy ve move yazarekn dikkat etmen gereken bir syntax var. Base classın da copysini veya move nu initialization list de çağırıyoruz. kodda syntax ı incele. 
- böyle yaparak şunu yapmış oluyoruz mem allocatin ve deallocation işlemlerinin hepsi base de dönüyor. biz derivedin copy constructorunda geln objeyi base classa da gönderiyoruz zaten.

- base classda yaptığın dynamic mem oluşturma ve silme işlemlerini derivedde de yapmana gerek yok. mantıken düşün.

- base classda copy ve move constrcutor yazdıysan ve derived classda yazmadıysan. Base classın copy ve move u çağrılır ve aynı şekilde çalışır. Ama önerilen seninde derivedde bunu yazman ve ordan base classın copy ve move constrctorunu yazman.(bu inheritence sayılmıyormuş complier in otomatik mekanizmasıymış)

## Pointers
- Dynmaic memory allocate ederken, inheritence uygulanmıuş classlar üzerinde çalışırken. oluşturulucak objenin türü ve new de alan ayrılıcak olan objenin türü aynı olduğu sürece bir sıkıntı çıkmıyor aslında ptr kullanımında.
    - constrcutorlar ve destructorlar olması gereken sırayla çağrılıyor.
- eğer sen objenin türünü base class,  new yaparkende derived classı kullanarak alan ayırmaya çalışırsan işte burada sıkıntılar başlıyor. Destrcutor çağrılırken sadece Base classın destructoru çağrılıyor mesela. Constructorlar yine aynı şekilde çağrılıyor.(son örneğe bakabilirsin).
- bunu önlemek için virtual destructorlar kullanılıyor. Polymorphism bölümünde işleyeceğiz.
- (önemli !!) Dynmaic olarak allocate etmediğin zaman normal ptr kullanımları referanslar ile birlikte. Beklenen sonuçları veriyor. yani constrcutor ve destrcutoru beklenen sırada çağırıyor dikkat et.