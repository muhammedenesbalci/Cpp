# Extra Knowledge
## Content
- [Header and Source Files](#header-and-source-files)
- [File Organization](#file-organization)
- [Complie Project](#complie-project)
- [build](#build)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)

## Header and Source Files
### Header Dosyaları (Header Files)
- Header dosyaları .h veya .hpp uzantısı ile biter ve genellikle sınıf, yapı, fonksiyon prototipleri ve makroların deklarasyonlarını içerir. Header dosyalarının temel amacı, kodun tekrar kullanılabilirliğini ve düzenini sağlamaktır. Bir header dosyası, birden fazla cpp dosyası tarafından dahil edilebilir, böylece kodda ortak kullanılan yapılar ve fonksiyonlar merkezi bir yerde tanımlanmış olur.
- ex: 
    ```cpp
    #ifndef EXAMPLE_H // EXAMPLE_H makrosu tanımlı değilse
    #define EXAMPLE_H // EXAMPLE_H makrosunu tanımla

    class Example {
    public:
        Example();  // Constructor
        void display();  // Member function
    private:
        int value;  // Member variable
    };

    #endif // EXAMPLE_H
    ```
- Header dosyalarındaki #ifndef, #define ve #endif direktifleri, "include guard" olarak adlandırılan bir mekanizmanın parçasıdır. Bu mekanizma, bir header dosyasının aynı çevirme birimi içinde birden fazla kez dahil edilmesini önler. Bu, özellikle büyük projelerde karşılaşılabilecek "multiple definition" (çoklu tanım) hatalarını engeller ve derleme sürecinde oluşabilecek diğer sorunları önler.
- **Include Guard Nasıl Çalışır**
    - #ifndef (if not defined): Bu direktif, belirli bir makronun tanımlı olup olmadığını kontrol eder. Eğer makro tanımlı değilse, sonraki kodlar işlenir.
    - #define: Bu direktif, belirli bir makroyu tanımlar.
    - #endif: Bu direktif, #ifndef ile başlayan koşullu derleme bloğunu sonlandırır.

- **Include Guard Neden Kullanılır?**
- Tekrarlı Dahil Etmeyi Önler: Aynı header dosyasının birden fazla kez dahil edilmesini engeller. Bu, özellikle header dosyaları arasında çapraz bağımlılıklar olduğunda veya bir header dosyasının farklı header dosyaları tarafından tekrar tekrar dahil edildiği büyük projelerde yaygındır.
- Derleme Hatalarını Engeller: Bir header dosyasının birden fazla kez dahil edilmesi, derleyicinin aynı sınıf, yapı veya fonksiyonun birden fazla tanımını görmesine neden olabilir, bu da derleme hatalarına yol açar.
- Derleme Süresini Azaltır: Include guard'lar, derleyicinin aynı header dosyasını tekrar tekrar işlemek zorunda kalmasını engelleyerek derleme süresini kısaltır.
- yani farklı farklı eyrlerde bu ehader dosyasını implemente ederken sıknıtı yaşamanı engelliyor.

### Kaynak Dosyaları (Source Files)
- Kaynak dosyaları .cpp uzantısı ile biter ve genellikle header dosyalarında deklarasyonu yapılan sınıf ve fonksiyonların tanımlarını içerir. Kaynak dosyaları, derleyici tarafından işlenir ve nesne dosyalarına (object files) dönüştürülür. Bu nesne dosyaları daha sonra bağlantı aşamasında birleştirilerek çalıştırılabilir bir program oluşturulur.
- ex:
    ```cpp
    #include "example.h"
    #include <iostream>

    Example::Example() : value(0) {}

    void Example::display() {
        std::cout << "Value: " << value << std::endl;
    }
    ```

## File Organization
- Bir C++ projesinde dosya düzeni, kodun okunabilirliğini, bakımı ve derlenmesini kolaylaştırmak için iyi organize edilmelidir. Bu düzen, projenin büyüklüğüne, karmaşıklığına ve kullanılan geliştirme ortamına bağlı olarak değişebilir. Ancak, genel olarak kabul edilen bazı iyi uygulamalar ve önerilen dosya ve klasör yapısı şunlardır

```css
/my_project
├── build/
├── doc/
├── include/
│   └── my_project/
│       └── example.h
├── src/
│   ├── main.cpp
│   └── example.cpp
├── lib/
├── tests/
│   └── example_test.cpp
├── CMakeLists.txt
└── README.md
```
- build/: Derleme çıktı dosyalarının (nesne dosyaları, yürütülebilir dosyalar) saklandığı klasördür. Bu klasör, genellikle derleme sistemi (örneğin, CMake veya Makefile) tarafından kullanılır ve kaynak kod dosyalarıyla karışıklığı önler.

- doc/: Projeyle ilgili belgelerin (dökümantasyon, kullanım kılavuzları, teknik dökümanlar) saklandığı klasördür.

- include/: Header dosyalarının saklandığı klasördür. Proje isimli bir alt klasör kullanmak, farklı projelerde aynı isimli header dosyalarının çakışmasını önler ve kodun düzenini artırır.

- src/: Kaynak dosyalarının (cpp dosyaları) saklandığı klasördür. Bu klasörde, projenin ana işlevlerini içeren dosyalar bulunur.

- lib/: Harici kütüphanelerin veya proje için geliştirilen bağımlı kütüphanelerin saklandığı klasördür. Bu klasörde statik (.a) veya dinamik (.so, .dll) kütüphane dosyaları bulunabilir.

- tests/: Birim testlerin ve diğer test kodlarının saklandığı klasördür. Bu klasörde, projedeki kodun doğruluğunu ve güvenilirliğini test etmek için kullanılan dosyalar bulunur.

- CMakeLists.txt: CMake ile derleme sistemini yöneten dosya. Projenin derlenmesi için gerekli yapılandırma ve bağımlılık bilgilerini içerir.

- README.md: Proje hakkında genel bilgilerin (kurulum talimatları, kullanım örnekleri, lisans bilgisi) yer aldığı dosya. Genellikle Markdown formatında yazılır.

## Complie Project
```css
/my_project
├── include/
│   ├── example1.h
│   ├── example2.h
│   └── example3.h
├── src/
│   ├── example1.cpp
│   ├── example2.cpp
│   ├── example3.cpp
│   └── main.cpp
└── README.md

```
### Command line 
1. Hepsini ayrı ayrı object dosyaysını oluşturup sonra birleştir. 
    ```bash
    g++ -Iinclude -c src/example1.cpp -o src/example1.o
    g++ -Iinclude -c src/example2.cpp -o src/example2.o
    g++ -Iinclude -c src/example3.cpp -o src/example3.o
    g++ -Iinclude -c src/main.cpp -o src/main.o
    g++ src/example1.o src/example2.o src/example3.o src/main.o -o my_prog
    ```
2. tek komutta hepsini birleştir. 
    ```bash
    g++ -Iinclude src/*.cpp -o my_prog
    ```

### cmake
    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(my_project)

    # C++ standardını belirtin
    set(CMAKE_CXX_STANDARD 11)

    # include dizinini ekleyin
    include_directories(include)

    # src dizinindeki tüm cpp dosyalarını kaynak dosyaları olarak belirleyin
    file(GLOB SOURCES "src/*.cpp")

    # my_prog adlı yürütülebilir dosyayı oluşturun
    add_executable(my_prog ${SOURCES})
    ```

    ```bash
    mkdir build
    cd build

    CMake yapılandırma dosyasını (CMakeLists.txt) #okuyarak derleme sistemini oluşturun: makefile oluşur

    make #Projeyi derlemek ve yürütülebilir dosyayı oluşturmak için make komutunu çalıştırın:
    ```
## build
- CMake kullanarak mkdir build ve cd build komutlarını otomatik olarak çalıştırmak için doğrudan bir CMake komutu bulunmamaktadır, ancak CMake yapılandırma ve derleme sürecini bir betik (script) ile otomatikleştirebilirsiniz. Bu betik, gerekli dizinleri oluşturur ve derleme sürecini başlatır.
- Örneğin, bir build.sh adlı bash betiği oluşturabilirsiniz:
- build.sh:
    ```bash
    #!/bin/bash

    # Build dizinini oluştur ve içine geç
    mkdir -p build
    cd build

    # CMake ile derleme sistemini oluştur
    cmake ..

    # Projeyi derle
    make
    ```
- usage
    ```bash
    bash build.sh
    ```
- **shell script or bash script(Bash betiği)**, bir dizi komutun bir dosyaya yazıldığı ve bu dosyanın çalıştırılmasıyla tüm komutların sırasıyla yürütüldüğü bir betik (script) dosyasıdır. Genellikle Unix tabanlı işletim sistemlerinde (Linux, macOS) kullanılır ve .sh uzantısıyla kaydedilir. Bash betikleri, bir terminalde manuel olarak girilecek bir dizi komutun otomatik olarak çalıştırılmasını sağlar.
- buil.sh kök disinde, scripts veya tools adlı klasörde olabilir.
```bash
1------------
/my_project
├── include/
├── src/
├── build/
├── scripts/
│   └── build.sh
├── CMakeLists.txt
├── README.md

2------------
/my_project
├── include/
├── src/
├── build/
├── tools/
│   └── build.sh
├── CMakeLists.txt
├── README.md

3------------
/my_project
├── include/
│   ├── example1.h
│   ├── example2.h
│   └── example3.h
├── src/
│   ├── example1.cpp
│   ├── example2.cpp
│   ├── example3.cpp
│   └── main.cpp
├── build/
├── CMakeLists.txt
├── README.md
└── build.sh

```