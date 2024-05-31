# Operator Overloading
- Operator overloading, C++ dilinde mevcut olan operatörlerin (örneğin, +, -, *, ==, <<, vb.) kullanıcı tanımlı veri türleri (örneğin, sınıflar) için nasıl davranacağını belirlememize olanak tanıyan bir özelliktir. Bu sayede, sınıf nesneleri ile daha doğal ve anlaşılır bir şekilde çalışılabilir.
- **Operator Overloading'in Avantajları**
    - Kodun Okunabilirliği: Operatörler aşırı yüklendiğinde, kod daha okunabilir ve doğal hale gelir.
    - Kodun Yeniden Kullanılabilirliği: Aynı operatörü farklı veri türleri için kullanma yeteneği sağlar.
    -  Modülerlik ve Bakım Kolaylığı: Operatörlerin nasıl çalıştığını sınıfların içine tanımlamak, kodun modülerliğini ve bakımını kolaylaştırır.
- **Operator Overloading'in Kuralları**
    - Operatör fonksiyonları bir sınıfın üyesi olabilir veya global fonksiyonlar olabilir.
    - overloaded operatörlerin en az bir operandı kullanıcı tanımlı bir veri türü olmalıdır.
## Content
- [Class member operator overloading](#class-member-operator-overloading)
- [Global operator overloading](#global-operator-overloading)
- [Differences between class member and global overloading](#differences-between-class-member-and-global-overloading)
- [Overloadable Operators](#overloadable-operators)
- [Not overloadable operators](#not-overloadable-operators)
- [Most used overloadable operators](#most-used-overloadable-operators)
## Class member operator overloading
- Sınıf içi operatör overloading, operatör fonksiyonlarının sınıfın üye fonksiyonları olarak tanımlanmasıdır. Bu yöntemle operatör, sınıfın bir üyesi olan nesne üzerinde çalışır.
- rvalue genellikle bizim asıl objemiz oluyor lvalue ise fonksiyonun içine aldığımız obje oluyor.
- Avantajlar:
    - Doğrudan Erişim: Sınıfın özel ve korumalı üyelerine doğrudan erişebilir.
    - Daha Basit Syntax: Operatör, sınıfın üyesi olduğu için this işaretçisi ile erişim sağlar ve daha basit bir syntax sunar.
- Dezavantajlar:
    - Tek Taraflı Operasyon: Genellikle sadece bir operandı alır ve bu operand, fonksiyonun çağrıldığı nesne olur (this işaretçisi).
    - Sınıfa Bağımlılık: Operatör sadece sınıfın bir üyesi olduğu için diğer sınıflarla çalışmak zor olabilir.
- syntax
    ```cpp
    class ClassName {
    public:
        ReturnType operatorOp(const ClassName& other) const {
            // Fonksiyon gövdesi
        }
    };
    ```
## Global operator overloading
- Global operatör overloading, operatör fonksiyonlarının sınıfın dışında tanımlanmasıdır. Bu fonksiyonlar genellikle friend olarak ilan edilirler. Genellikle iki farklı classın objesini alırlar.
- burada header file lar ayrı source filelar ortak yazılır kodda örneği var.

- Avantajlar:
    - İki Taraflı Operasyon: İki nesne arasında operatör kullanımı sağlar.
    - Sınıflar Arası Operasyon: Farklı sınıflar arasında veya temel türler ile kullanıcı tanımlı türler arasında operatör kullanımını kolaylaştırır.
- Dezavantajlar:
    - friend Fonksiyon İhtiyacı: Özel ve korumalı üyelere erişmek için friend fonksiyonu olarak ilan edilmesi gerekir.
    - Daha Karmaşık Syntax: Sınıfın üyesi olmadığı için this işaretçisi kullanılmaz, bu da biraz daha karmaşık bir syntax gerektirir.
- syntax
    ```cpp
    class ClassName {
        friend ReturnType operatorOp(const ClassName& lhs, const ClassName& rhs);
    };

    ReturnType operatorOp(const ClassName& lhs, const ClassName& rhs) {
        // Fonksiyon gövdesi
    }
    ```
### Differences between class member and global overloading
- Erişim:
    - Sınıf içi operatör overloading doğrudan sınıf üyelerine erişebilir.
    - Global operatör overloading için friend fonksiyonu gerekebilir.

- Operasyon:
    - Sınıf içi operatör overloading genellikle tek taraflı operasyonlar için uygundur.
    - Global operatör overloading iki taraflı operasyonları daha rahat yönetir.

- Kullanım Durumları:
    - Sınıf içi operatör overloading, sınıfın iç işleyişiyle sıkı sıkıya bağlı olan operasyonlar için kullanılır.
    - Global operatör overloading, iki farklı sınıfın nesneleri arasında veya nesne ve temel türler arasında operasyonlar için idealdir.

- overload edilirken normal overload tek parametre alıyor genellikle.
    - mesela + tek parametre alıyoruz. Kendi classımızı obje olarak.
    - toplama işlemini yaparkende biri o anki nesne(this) diğeri parametre olarak aldığımız nesne olarak işlemlere devam ediyoruz.

- frined iki parametre birden alır
    - sınıfa ait fonksiyonlar olmadığı için this operatörü burada geçmiyor. O yüzden iki paremetre birden alması gerekiyor iki farklı classdan. veya aynı classdan. genellikle farklı classlar için kullanırız.

## Overloadable Operators
### Arithmetic Operators
- (class or global ) Bu operatörler, hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir.(yeni bir obje return ederiz)
    - `+` (Addition)
    - `-` (Subtraction)
    - `*` (Multiplication)
    - `/` (Division)
    - `%` (Modulus)

### Unary Operators
- (class or global) Bu operatörler, hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir. (iki farklı overloader i oluyor o anki obje ve o anki objeyi geçici değişkene atadığımız obje)
    - `+` (Unary plus)
    - `-` (Unary minus)
    - `++` (Increment)
    - `--` (Decrement)
    - `!` (Logical NOT)
    - `~` (Bitwise NOT)
    - `&` (Address-of)
    - `*` (Dereference)

### Assignment Operators
- (class)Bu operatörler, sınıf üyesi fonksiyonlar olarak overload edilmelidir.(o anki objeyi döndürüyor)(move assignemntin amacı mevcut belleği serbest bırakarak diğer objenin belleğini almak önemli bir yaklaşım (asıl objenin belleğini almak yani))
    - `=` (Assignment)
    - `+=` (Addition assignment)
    - `-=` (Subtraction assignment)
    - `*=` (Multiplication assignment)
    - `/=` (Division assignment)
    - `%=` (Modulus assignment)
    - `&=` (Bitwise AND assignment)
    - `|=` (Bitwise OR assignment)
    - `^=` (Bitwise XOR assignment)
    - `<<=` (Bitwise left shift assignment)
    - `>>=` (Bitwise right shift assignment)

### Comparison Operators
- (class or global) Bu operatörler, hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir. (bool ifade döndürür)
    - `==` (Equal to)
    - `!=` (Not equal to)
    - `<` (Less than)
    - `>` (Greater than)
    - `<=` (Less than or equal to)
    - `>=` (Greater than or equal to)

### Logical Operators
- (class or global) Bu operatörler, hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir.
    - `&&` (Logical AND)
    - `||` (Logical OR)

### Bitwise Operators
- (class or global) Bu operatörler, hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir.
    - `&` (Bitwise AND)
    - `|` (Bitwise OR)
    - `^` (Bitwise XOR)
    - `<<` (Bitwise left shift)
    - `>>` (Bitwise right shift)

### Other Operators
- `[]` (Array subscript): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.
- `()` (Function call): Sadece sınıf üyesi fonksiyon olarak overload edilebilir. (functor da deriz aynı zamanda)
- `->` (Member access): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.
- `->*` (Pointer to member access): Hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir.
- `,` (Comma): Hem sınıf üyesi fonksiyonlar olarak hem de global fonksiyonlar olarak overload edilebilir.
- `new` (Allocation): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.
- `new[]` (Array allocation): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.
- `delete` (Deallocation): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.
- `delete[]` (Array deallocation): Sadece sınıf üyesi fonksiyon olarak overload edilebilir.

### Special Case Operators
- `<<` (Stream insertion, typically used with `ostream`): Genellikle global fonksiyon olarak overload edilir.
- `>>` (Stream extraction, typically used with `istream`): Genellikle global fonksiyon olarak overload edilir. 

## Not overloadable operators
Bazı operatörler C++ dilinde overload edilemez. Bu operatörler şunlardır:
- `::` (Scope resolution)
- `.` (Member access)
- `.*` (Pointer to member access)
- `?:` (Ternary conditional)
- `sizeof` (Size of object)
- `typeid` (Type information)
- `alignof` (Alignment requirement)

### Most used overloadable operators
- Assignment Operator (=):
    - Sebep: Bir nesnenin başka bir nesneye atanmasını sağlar. Özellikle derin kopyalama(deep copy) gereken durumlarda kullanılır.
    - fonksiyona obje olarak verdiğimiz şey rvalue yani sağ ifadenin sağ tarafındaki değerdir.
    - yaptığımız örnekten copy assignmentin copy constructor gibi davranmasını sağladık.
    - move assignment operator da yazdık. Move olarak davranabilmesi için özellikle move diye belirtmen lazım. ifadeyi yazarken.
    - bunu overload edilmesi çok öenmli özellikle dynmaic memory kullanıyorsak.

- Addition Operator (+):
    - Sebep: İki nesneyi toplamak veya bir nesneye bir değeri eklemek için kullanılır. Matematiksel işlemler veya string birleştirme işlemleri için yaygındır.

- Subtraction Operator (-):
    - Sebep: İki nesne arasındaki farkı hesaplamak veya bir nesneden bir değeri çıkarmak için kullanılır. Matematiksel işlemler için yaygındır.

- Equality Operator (==):
    - Sebep: İki nesnenin eşit olup olmadığını kontrol etmek için kullanılır. Özellikle nesnelerin karşılaştırılması gerektiğinde önemlidir.

- Inequality Operator (!=):
    - Sebep: İki nesnenin eşit olup olmadığını kontrol etmek için kullanılır. == operatörünün tersi olarak çalışır.

- Stream Insertion Operator (<<):
    - Sebep: Bir nesneyi ostream (genellikle std::cout) ile ekrana yazdırmak için kullanılır. Özellikle kullanıcı tanımlı veri tiplerinin yazdırılması için önemlidir.

- Stream Extraction Operator (>>):
    - Sebep: Bir nesneyi istream (genellikle std::cin) ile okumak için kullanılır. Özellikle kullanıcı tanımlı veri tiplerinin okunması için önemlidir.

- Subscript Operator ([]):
    - Sebep: Dizi veya benzeri veri yapılarının elemanlarına erişmek için kullanılır. Örneğin, std::vector veya kullanıcı tanımlı dizi sınıflarında yaygındır.

- Function Call Operator (()) - (functor):
    - Sebep: Functor (işlev nesnesi) oluşturmak için kullanılır. Özellikle lambda ifadeleri ve function object (işlev nesnesi) kullanımında yaygındır.

- Pointer Dereference Operator (*):
    - Sebep: Bir pointer'ın işaret ettiği nesneye erişmek için kullanılır. Özellikle akıllı pointer (smart pointer) sınıflarında yaygındır.

- Arrow Operator (->):
    - Sebep: Bir pointer'ın işaret ettiği nesnenin üye fonksiyonlarına veya veri üyelerine erişmek için kullanılır. Özellikle smart pointer sınıflarında yaygındır.

- Increment and Decrement Operators (++ and --):
    - Sebep: Bir nesnenin değerini artırmak veya azaltmak için kullanılır. Genellikle sayısal değerler veya iteratörler üzerinde kullanılır.

- Comparison Operators (<, <=, >, >=):
    - Sebep: Nesneleri büyüklük veya küçüklük açısından karşılaştırmak için kullanılır. Özellikle sıralama algoritmalarında ve veri yapılarında önemlidir
