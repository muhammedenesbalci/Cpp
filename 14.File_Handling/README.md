# File Handling
- File handling, dosya okuma ve yazma işlemlerinin programlama dilinde gerçekleştirilmesidir. 
- C++ dilinde, dosya işlemleri için fstream kütüphanesi kullanılır. Bu kütüphane, dosya işlemleri için üç temel sınıf sağlar:
    - ifstream (input file stream): Dosyadan veri okumak için kullanılır. 
    - ofstream (output file stream): Dosyaya veri yazmak için kullanılır.
    - fstream (file stream): Hem okuma hem de yazma işlemleri için kullanılır. 

## Dosya Modları
- Dosya açarken çeşitli modlar kullanabilirsiniz. Bu modlar std::ios namespace'i altındadır:

    - std::ios::in: Okuma modu.
    - std::ios::out: Yazma modu.
    - std::ios::app: Dosyanın sonuna yazma modu (append).
    - std::ios::ate: Dosya açıldıktan hemen sonra dosya sonuna gider.
    - std::ios::trunc: Dosyayı açarken içeriğini siler.
    - std::ios::binary: Dosyayı ikili (binary) modda açar.

- ifstream, ofstream, fstream default dosya modları
    - ifstream	ios::in
    - ofstream	ios::out
    - fstream	ios::in | ios::out

## Operators and Functions
- open()
    - Bir dosyayı belirtilen modlarda açar.
        ```cpp
        file.open("filename.txt", std::ios::in | std::ios::out);
        ```
- close()
    -  Açık olan dosyayı kapatır.
        ```cpp
        file.close();
        ```
- is_open()
    - Dosyanın açık olup olmadığını kontrol eder.
        ```cpp
        if (file.is_open()) {
            // Dosya açıksa yapılacak işlemler
        }
        ```
- read() and write()
    - Dosyadan binary veri okur.
    - Dosyaya binary veri yazar.
        ```cpp
        file.read(reinterpret_cast<char*>(&variable), sizeof(variable));
        file.write(reinterpret_cast<char*>(&variable), sizeof(variable));
        ```
- getline()
    - Dosyadan bir satır okur.
        ```cpp
        std::string line;
        std::getline(file, line);
        ```
- seekg()
    - Okuma konumunu ayarlar
        ```cpp
        file.seekg(0, std::ios::beg); // Dosyanın başına gider
        ```
- seekp()
    - Yazma konumunu ayarlar.
        ```cpp
        file.seekp(0, std::ios::beg); // Dosyanın başına gider
        ```
- tellg()
    - Geçerli okuma konumunu döner.
        ```cpp
        std::streampos pos = file.tellg();
        ```
- tellp()
    - Geçerli yazma konumunu döner.
        ```cpp
        std::streampos pos = file.tellp();
        ```
- << Operatörü (Insertion Operator)
    - Dosyaya veri yazmak için kullanılır.
        ```cpp
        std::fstream file("example.txt", std::ios::out | std::ios::app);
        if (file.is_open()) {
            file << "This is a line.\n";
        }
        ```
        ```cpp
        #include <iostream>
        #include <fstream>

        int main() {
            // Dosya akışı (fstream) oluştur ve dosyayı yazma ve ekleme modunda aç
            std::fstream file("example.txt", std::ios::out | std::ios::app);

            if (file.is_open()) {
                // Dosyaya veri yaz
                file << "Appending a new line to the file using << operator.\n";
                file.close();
            } else {
                std::cout << "Unable to open file for writing." << std::endl;
            }

            return 0;
        }
        ```
- '>>' Operatörü Extraction Operator
    - Dosyadan veri okumak için kullanılır
        ```cpp
        std::fstream file("example.txt", std::ios::in);
        if (file.is_open()) {
            std::string word;
            while (file >> word) {
                std::cout << word << " ";
            }
        }
        ```
        ```cpp
        #include <iostream>
        #include <fstream>
        #include <string>

        int main() {
            // Dosya akışı (fstream) oluştur ve dosyayı okuma modunda aç
            std::fstream file("example.txt", std::ios::in);

            if (file.is_open()) {
                std::string word;
                // Dosyadan kelime kelime oku
                while (file >> word) {
                    std::cout << word << " ";
                }
                std::cout << std::endl;
                file.close();
            } else {
                std::cout << "Unable to open file for reading." << std::endl;
            }

            return 0;
        }
        ```
## Dosya İşlemleri İçin Genel İpuçları
- Dosya Kapatma: İşlem bittikten sonra dosyayı kapatmayı unutmayın. close() fonksiyonu dosyayı kapatır ve kaynağı serbest bırakır.
- Dosya Kontrolü: Dosyanın açılıp açılmadığını kontrol etmek önemlidir. is_open() fonksiyonu dosyanın başarıyla açılıp açılmadığını kontrol eder.
- Hata Yönetimi: Dosya işlemleri sırasında hata yönetimi önemlidir. Hataları düzgün şekilde ele almak için uygun kontrol mekanizmaları kullanın.

