# Memory Layout
- Bir C++ programının bellek yerleşimi (memory layout), programın çalışması sırasında bellekte nasıl yapılandığını ve organize edildiğini gösterir. Genellikle, bir C++ programının belleği aşağıdaki ana bölümlere ayrılır: 
- process lerden bashederken initialized ve uninitialized aynı yerde olarak ele alınır yani data segmenti.

1. Text Segment (Kod Segmenti)
Bu bölüm, programın yürütülebilir kodunu içerir. Programın derlenen makine kodları burada saklanır ve yalnızca okunabilir olarak işaretlenir, yani çalıştırma sırasında değiştirilmesi mümkün değildir.

2. Data Segment (Veri Segmenti)
Bu bölüm, başlatılmış statik ve global değişkenleri içerir. Bu değişkenler programın başlangıcında belirli bir değere sahip olarak başlatılır ve programın yaşam süresi boyunca aynı değerde kalır.

3. BSS Segment
Bu bölüm, başlatılmamış statik ve global değişkenleri içerir. Program başlatıldığında bu değişkenler otomatik olarak sıfır değeri ile başlatılır.

4. Heap
Heap bölgesi, dinamik bellek tahsisi için kullanılır. malloc, calloc, realloc ve new gibi fonksiyonlar ve operatörler tarafından bellek tahsisi yapıldığında bu bölge kullanılır. Heap'teki bellek tahsisi ve serbest bırakma işlemleri programcı tarafından yönetilir.

5. Stack
Stack bölgesi, yerel değişkenler ve fonksiyon çağrıları için kullanılır. Her fonksiyon çağrıldığında, fonksiyonun yerel değişkenleri ve geri dönüş adresi stack üzerine yerleştirilir. Fonksiyon tamamlandığında, bu veriler stack'ten çıkarılır.

    ```cpp
    #include <iostream>
    #include <cstdlib>

    int globalVar = 10; // Veri Segmenti
    int uninitializedGlobalVar; // BSS Segmenti

    void function() {
        int localVar = 20; // Stack Segmenti
        std::cout << "Local Variable: " << localVar << std::endl;
    }

    int main() {
        static int staticVar = 30; // Veri Segmenti
        int* dynamicVar = (int*)std::malloc(sizeof(int)); // Heap Segmenti
        *dynamicVar = 40;

        std::cout << "Global Variable: " << globalVar << std::endl;
        std::cout << "Uninitialized Global Variable: " << uninitializedGlobalVar << std::endl;
        std::cout << "Static Variable: " << staticVar << std::endl;
        std::cout << "Dynamic Variable: " << *dynamicVar << std::endl;

        function();

        std::free(dynamicVar); // Heap'teki bellek serbest bırakılır

        return 0;
    }
    ```
- Global Değişkenler:
    - globalVar: Başlatılmış global değişken, veri segmentinde bulunur.
    - uninitializedGlobalVar: Başlatılmamış global değişken, BSS segmentinde bulunur.
- Static Değişken:
    - staticVar: Başlatılmış statik değişken, veri segmentinde bulunur.
- Yerel Değişken:
    - localVar: Fonksiyon içinde tanımlanmış yerel değişken, stack segmentinde bulunur.
- Dinamik Değişken:
    - dynamicVar: malloc ile tahsis edilen dinamik değişken, heap segmentinde bulunur.
    
```lua
+----------------------+
|      Text Segment    | (Program kodu)
+----------------------+
|      Data Segment    | (Başlatılmış statik ve global değişkenler)
+----------------------+
|       BSS Segment    | (Başlatılmamış statik ve global değişkenler)
+----------------------+
|         Heap         | (Dinamik bellek tahsisi, aşağı doğru büyür)
+----------------------+
|         Stack        | (Yerel değişkenler, yukarı doğru büyür)
+----------------------+
```
- Text Segment: Yürütülebilir kodları içerir.
- Data Segment: Başlatılmış statik ve global değişkenleri içerir.
- BSS Segment: Başlatılmamış statik ve global değişkenleri içerir.
Heap: Dinamik bellek tahsisi için kullanılır.
- Stack: Yerel değişkenler ve fonksiyon çağrıları için kullanılır.

### size komutu ile kod analizi
- text: Program kodunun boyutu.
- data: Başlatılmış statik ve global değişkenlerin boyutu.
- bss: Başlatılmamış statik ve global değişkenlerin boyutu.
- dec: Toplam boyut (decimal).
- hex: Toplam boyut (hexadecima)

- aşağıdaki linki kesinlikle incele
    - https://www.geeksforgeeks.org/memory-layout-of-c-program/