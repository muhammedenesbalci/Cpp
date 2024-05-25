# Structures
## Contents

- [Union](#union)
- [Enum](#enum)
- [Struct](#struct)
- [Differences C and Cpp Structure](#differences-c-and-cpp-structure)
- [typedef](#typedef)
- [Memory Allignment](#memory-allignment)

## Union
- C++'ta union, aynı bellek alanını paylaşan farklı veri türlerini depolamanın bir yoludur. Bir union içinde tanımlanan tüm üyeler, aynı başlangıç adresinden başlar ve bu da bellek tasarrufu sağlar. Bir unionun boyutu, içindeki en büyük üyenin boyutuna eşittir. Bu, aynı anda yalnızca bir üyenin değerini saklayabileceğiniz anlamına gelir; bir üyenin değerini değiştirdiğinizde diğer üyelerin değerleri de etkilenir.
- Her veri tipinden sadece bir eleman olabilir yani sadece bir int değişkeni olabilir. bütün elemanlar aynı memory adresinde depolanıyor.
- union, aynı bellek alanını paylaşan farklı veri türlerini saklamak için kullanılır.
- Bir union içinde tanımlanan tüm üyeler aynı bellek alanını paylaşır.
Bu nedenle, bir union'ın boyutu, içindeki en büyük üyenin boyutuna eşittir.
- union'lar genellikle bir veri parçasının birden fazla yorumunu saklamak için kullanılır, örneğin bir veri parçasının hem int hem de float olarak kullanılması.

## Enum
- enum, C++'ta ve birçok diğer programlama dilinde, sembolik isimler aracılığıyla tamsayı değerleri temsil etmek için kullanılan bir veri türüdür. Bu tür, kodun daha okunabilir ve yönetilebilir olmasını sağlar. enum sabitleri, bir dizi ilgili sabit değeri bir araya getirmek için kullanılır. 
- enumun içindeki değişkenleri yazdırdığımızda tam sayı değerleri görürüz 0 dan başlar

## Struct
- Code içeriği:
    - basics
    - arrays in struct
    - struct arrays
    - pointer to struct
    - nested struct
    - struct with functions
    - typedef 
    - memory allignment
- struct (yapı), farklı veri türlerinden oluşan bir grup veriyi tek bir birim olarak saklamanıza olanak tanıyan bir veri yapısıdır. Bir struct, birden fazla değişkeni bir araya getirerek, bir nesne gibi davranan ve bu nesneyle ilgili tüm verileri tek bir yerde toplamanızı sağlayan bir yapı sağlar.
- Structures iki tip member içerebilir
    - Data Member: normal veri tipleri. Structlar içinde farklı veri tipleri depolayabiliriz
    - Member Functions ( de bu yok). Structurenin içinde member fonksiyonlar tanımlayabiliriz
- cpp de başlangıç değerleri atayabiliriz. C de atayamayız
- tanımlarkende farklılık içeriyor. cpp için her iki tanımlama da uygundur.
    ```cpp
    struct Person {
        int age;
    }

    //cpp
    Person person1;

    //c
    struct Person person2;
    ```
- structun memberlerine ulaşma tanımlanış şekline göre değişebilir. Normal tanımlananlara "." ile ulaşabilirz. Pointer olarak tanımlananlara -> kullanabiliriz.

## Differences C and Cpp Structure


1. **Üye Fonksiyonlar**:
   - C Yapıları: Yalnızca veri üyeleri içerir, üye fonksiyonları içeremez.
   - C++ Yapıları: Hem üye fonksiyonları hem de veri üyeleri içerebilir.

2. **Statik Üyeler**:
   - C Yapıları: Statik üyeler içeremez.
   - C++ Yapıları: Statik üyeler içerebilir.

3. **Yapıcılar (Constructors)**:
   - C Yapıları: Yapıcı içeremez.
   - C++ Yapıları: Yapıcı tanımlamak mümkündür.

4. **Veri Üyelerinin Doğrudan Başlatılması**:
   - C Yapıları: Doğrudan başlatma mümkün değildir.
   - C++ Yapıları: Doğrudan başlatma mümkündür.

5. **`struct` Anahtar Kelimesi**:
   - C Yapıları: Yapı türü değişkenlerini bildirmek için `struct` anahtar kelimesi gereklidir.
   - C++ Yapıları: Yapı türü değişkenlerini bildirmek için `struct` anahtar kelimesi gerekli değildir.

6. **Erişim Belirleyicileri**:
   - C Yapıları: Erişim belirleyicileri yoktur.
   - C++ Yapıları: Erişim belirleyicilerini destekler (public, private, protected).

7. **Göstericiler ve Referanslar**:
   - C Yapıları: Yalnızca yapı göstericilerine izin verir.
   - C++ Yapıları: Hem yapı göstericilerini hem de referansları kullanabilir.

8. **Boş Yapının Boyutu**:
   - C Yapıları: Boş bir yapı için `sizeof` operatörü 0 döner.
   - C++ Yapıları: Boş bir yapı için `sizeof` operatörü 1 döner.

9. **Veri Saklama (Data Hiding)**:
    - private public vs
   - C Yapıları: Veri saklama mümkün değildir.
   - C++ Yapıları: Veri saklama mümkündür.

- Constructor creation in structure: Structures in C cannot have a constructor inside a structure but Structures in C++ can have Constructor creation.
    ```cpp
    // C program to demonstrate that
    // Constructor is not allowed
    
    #include <stdio.h>
    
    struct Student {
        int roll;
        Student(int x) { roll = x; }
    };
    
    // Driver Program
    int main()
    {
        struct Student s(2);
        printf("%d", s.x);
        return 0;
    }
    ```
- Direct Initialization: We cannot directly initialize structure data members in C but we can do it in C++. 
    ```cpp
    // C program to demonstrate that direct
    // member initialization is not possible in C
    
    #include <stdio.h>
    
    struct Record {
        int x = 7;
    };
    
    // Driver Program
    int main()
    {
        struct Record s;
        printf("%d", s.x);
        return 0;
    }
    ```
## typedef
- typedef anahtar kelimesi, C ve C++ programlama dillerinde mevcut bir veri türüne yeni bir isim (alias) vermek için kullanılır. Bu, kodun okunabilirliğini artırmak ve daha anlaşılır veri türleri tanımlamak için kullanışlıdır. typedef, özellikle karmaşık veri türlerini basitleştirmek için çok yararlıdır.
    ```cpp
    //typedef mevcut_tur yeni_isim;
    typedef unsigned int uint;
    typedef long int lint;

    uint age = 25;
    lint largeNumber = 1234567890L;

    struct Person {
        char name[50];
        int age;
    };

    typedef struct Person Personn;
    Personn person1;
    person1.age = 30;
    ```
    ```cpp
    // C++ Program to implement typedef 
    #include <bits/stdc++.h> 
    
    using namespace std; 
    
    int main() 
    { 
        // Now we can make more vectors by using vInt 
        typedef std::vector<int> vInt; 
    
        // vec1 is a vectorof type int 
        vInt v; 
    
        v.push_back(190); 
        v.push_back(180); 
        v.push_back(10); 
        v.push_back(10); 
        v.push_back(27); 
    
        for (auto X : v) { 
            cout << X << " "; 
        } 
    
        return 0; 
    }
    // 190 180 10 10 27 
    ```

## Memory Allignment
- Bellek hizalaması (memory alignment), bilgisayar belleğindeki veri yapılarının (örneğin, değişkenler ve yapılar) belirli bellek sınırlarıyla hizalanmasını ifade eder. Bu hizalama, bellek erişimini hızlandırmak ve performansı artırmak amacıyla kullanılır. Bellek hizalaması, verilerin bellek üzerinde belirli sınırlarla hizalanmasını gerektirir ve bu sınırlar genellikle verinin boyutuyla ilişkilidir.
1. Hizalama Sınırı (Alignment Boundary):
    - Verinin bellekte hangi adreslerde saklanabileceğini belirleyen bir sınırdır. Örneğin, 4 baytlık bir int değeri, genellikle 4 ile tam bölünebilen adreslerde saklanmalıdır.
2. Hizalama Gereksinimi (Alignment Requirement):
    - Belirli bir veri türü için gereken hizalama sınırıdır. Örneğin, int veri türü genellikle 4 bayt hizalaması gerektirir.
3. Dolgu Baytları (Padding Bytes):
    - Veri üyelerinin hizalama gereksinimlerini karşılamak için eklenen ekstra baytlardır. Bu baytlar, bellek israfına yol açabilir ancak performansı artırır.

```cpp
#include <iostream>
#include <cstddef> // offsetof için gerekli

using namespace std;

struct Example {
    char a;   // 1 bayt
    int b;    // 4 bayt
    char c;   // 1 bayt
};

int main() {
    cout << "Size of struct Example: " << sizeof(Example) << " bytes" << endl;
    cout << "Offset of a: " << offsetof(Example, a) << endl;
    cout << "Offset of b: " << offsetof(Example, b) << endl;
    cout << "Offset of c: " << offsetof(Example, c) << endl;

    return 0;
}

/*
Size of struct Example: 12 bytes
Offset of a: 0
Offset of b: 4
Offset of c: 8
*/
```
- Veri Üyeleri ve Hizalama:
    - char a: 1 bayt, 1 bayt hizalaması gerektirir.
    - int b: 4 bayt, 4 bayt hizalaması gerektirir.
    - char c: 1 bayt, 1 bayt hizalaması gerektirir.
- Dolgu Baytları:
    - a ve b arasında 3 bayt dolgu eklenir.
    - c'den sonra 3 bayt dolgu daha eklenir.
- char a: 0. baytta başlar ve 1 bayt kaplar.
- int b: 4 baytlık hizalama gerektirir, dolayısıyla 4. baytta başlar ve 4 bayt kaplar.
- char c: 8. baytta başlar ve 1 bayt kaplar, ancak yapı toplam boyutunun 4'ün katı olmasını sağlamak için 3 bayt dolgu eklenir.

- Bellek hizalaması ve dolgu baytlarını minimize etmek için, yapı (struct) üyelerini uygun bir sırayla düzenleyerek bellekte daha az yer kaplamasını sağlayabilirsiniz. Genel olarak, daha büyük veri türlerini önce ve daha küçük veri türlerini daha sonra yerleştirmek dolgu baytlarını azaltabilir.

    ```cpp
    struct Example {
        char a;   // 1 bayt
        int b;    // 4 bayt
        char c;   // 1 bayt
    };

    ```
    - Bu yapı, char a ve int b arasında 3 bayt, int b ve char c arasında da 3 bayt dolgu ekler. Toplamda 12 bayt olur.

    ```cpp
    struct Example {
        int b;    // 4 bayt
        char a;   // 1 bayt
        char c;   // 1 bayt
        // toplamda 6 bayt, hizalama gereksinimleri ile daha az dolgu
    };
    ```
    - int b: 4 bayt, hizalama gereksinimi 4 bayt.
    - char a: 1 bayt, hizalama gereksinimi 1 bayt.
    - char c: 1 bayt, hizalama gereksinimi 1 bayt.

    ```cpp
    #include <iostream>
    #include <cstddef> // offsetof için gerekli

    using namespace std;

    struct Example {
        int b;    // 4 bayt
        char a;   // 1 bayt
        char c;   // 1 bayt
    };

    int main() {
        cout << "Size of struct Example: " << sizeof(Example) << " bytes" << endl;
        cout << "Offset of b: " << offsetof(Example, b) << endl;
        cout << "Offset of a: " << offsetof(Example, a) << endl;
        cout << "Offset of c: " << offsetof(Example, c) << endl;

        return 0;
    }

    /*
    Size of struct Example: 8 bytes
    Offset of b: 0
    Offset of a: 4
    Offset of c: 5
    */
    ```
    - Bu yeni düzenleme, int türündeki veri üyesi en önde olacak şekilde yapılandırılmıştır ve ardından char türündeki veri üyeleri gelmektedir. Bu sayede dolgu baytları minimize edilmiştir.

- Özet
    - Daha büyük veri türlerini önce yerleştirmek ve daha küçük veri türlerini sonra yerleştirmek dolgu baytlarını azaltabilir.
    - Yapıyı yeniden düzenleyerek bellek kullanımını optimize edebilirsiniz.