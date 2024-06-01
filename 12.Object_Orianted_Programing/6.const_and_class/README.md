# const and Classs
- Bir sınıfı const olarak tanımlamak, o sınıfın örneği üzerinde herhangi bir değişiklik yapılmasını engeller. Bu, sınıfın veri üyelerinin ve const olmayan üye fonksiyonlarının değiştirilmemesi anlamına gelir. const anahtar kelimesi, veri bütünlüğünü korumak ve hataları önlemek için kullanılır.

- const nesne
    - const fonksiyonları çağırabilir
    - const olmayanları çağıramaz.
    - const member çağırabilir değiştiremez değiştirmek isiyorsa mutable olarak tanımlamalıdır.
- **const Sınıf Örnekleri ve Davranışları**
    1. Veri Üyeleri Üzerinde Değişiklik Yapılamaz
        - Bir sınıfın const örneği üzerinde veri üyelerinde değişiklik yapılamaz.
    2. Sadece const Üye Fonksiyonlar Çağrılabilir
        - Bir const sınıf örneği yalnızca const olarak tanımlanmış üye fonksiyonları çağırabilir. const üye fonksiyonlar, veri üyelerini değiştirmeyen fonksiyonlardır.

- **Açıklama**
    1. Sınıf Tanımı:
        - Person sınıfı, name ve age veri üyelerine sahiptir.
        - getName ve getAge üye fonksiyonları const olarak tanımlanmıştır, bu nedenle bu fonksiyonlar const bir nesne üzerinde çağrılabilir.
        - setName ve setAge üye fonksiyonları const değildir, bu nedenle const bir nesne üzerinde çağrılamaz.

- **Const Sınıf Örneği**:
    - const Person p("John", 30); satırı ile oluşturulan p nesnesi const olarak tanımlanmıştır.
    - const üye fonksiyonlar (örn. getName ve getAge) p nesnesi üzerinde sorunsuzca çağrılabilir.
    - non-const üye fonksiyonlar (örn. setName ve setAge) p nesnesi üzerinde çağrıldığında derleme hatası verir.
    - p.name ve p.age gibi doğrudan veri üyelerine değişiklik yapılamaz.

- **Özel Durumlar**
    - Const Üye Fonksiyonlar:
        ```cpp
        int getAge() const {
            return age;
        }
        ```
        - const üye fonksiyonlar, sınıfın veri üyelerini değiştirmez ve const nesneler üzerinde çağrılabilir.

    - Mutable Veri Üyeleri:
        - mutable anahtar kelimesi, veri üyesinin const üye fonksiyonlar tarafından değiştirilebilmesini sağlar. Bu, normalde const üye fonksiyonların veri üyelerini değiştirememesi kuralının bir istisnasıdır.
            ```cpp
            class Example {
            public:
                void setData(int value) const {
                    data = value; // mutable olduğundan değiştirebilir
                }
            private:
                mutable int data;
            };
            ```
- **Özet**
    - Const Sınıf Örneği: Veri üyeleri doğrudan değiştirilemez ve yalnızca const üye fonksiyonlar çağrılabilir.
    - Const Üye Fonksiyonlar: Veri üyelerini değiştirmeyen ve const nesneler üzerinde çağrılabilen fonksiyonlardır.
    - Mutable Veri Üyeleri: const üye fonksiyonlar tarafından değiştirilebilen veri üyeleridir.

- **Overloading**
    - const ve non-const fonksiyon overlaoding ini function overload bölümünde bulabilirsin.