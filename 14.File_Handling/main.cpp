#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// General Examples ####################################################
// Writing File -------------------------------------------------------
void writing_file_ex() {
    // Dosya çıkış akışı (ofstream) oluştur
    std::ofstream outFile("./example.txt");

    // Dosya açıldı mı kontrol et
    if (outFile.is_open()) {
        // Dosyaya veri yaz
        outFile << "This is a line.\n";
        outFile << "This is another line.\n";

        // Dosyayı kapat
        outFile.close();
        std::cout << "Data written to file successfully." << std::endl;
    } else {
        std::cout << "Unable to open file for writing." << std::endl;
    }
}

// reading File -------------------------------------------------------
void reading_file_ex() {
     // Dosya giriş akışı (ifstream) oluştur
    std::ifstream inFile("example.txt");

    // Dosya açıldı mı kontrol et
    if (inFile.is_open()) {
        std::string line;
        // Dosyadan satır satır oku
        while (getline(inFile, line)) {
            std::cout << line << std::endl;
        }

        // Dosyayı kapat
        inFile.close();
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
    }
}

// reading and writing File -------------------------------------------------------
void reading_writing_file_ex() {
    // Dosya akışı (fstream) oluştur
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app);

    // Dosya açıldı mı kontrol et
    if (file.is_open()) {
        // Dosyaya veri yaz
        file << "Appending a new line to the file.\n";

        // Okuma konumunu başa taşı
        file.seekg(0, std::ios::beg);

        // Dosyadan veri oku
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }

        // Dosyayı kapat
        file.close();
    } else {
        std::cout << "Unable to open file for reading and writing." << std::endl;
    }
}

// File Modes Examples ####################################################
// std::ios::in ve std::ios::out (Hem Okuma Hem Yazma) -----------------------------------------------------
void fstream_read_write_ex() {
    std::fstream file("./example_2.txt", std::ios::in | std::ios::out);

    if (file.is_open()) {
        // Dosyaya yazma
        file << "This is a line.\n";
        file << "This is another line.\n";

        // Okuma konumunu başa taşı
        file.seekg(0, std::ios::beg);

        // Dosyadan okuma
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

// std::ios::app (Ekleme Modu) -----------------------------------------------------
void fstream_app_ex() {
    std::fstream file("./example_2.txt", std::ios::out | std::ios::app);

    if (file.is_open()) {
        file << "Appending a new line to the file.\n";
        file.close();
    } else {
        std::cout << "Unable to open file for appending." << std::endl;
    }
}

// std::ios::ate (Başlangıçta Dosya Sonuna Gitme)
void fstream_ate_ex() {
     std::fstream file("./example_2.txt", std::ios::in | std::ios::out | std::ios::ate);

    if (file.is_open()) {
        // Dosyaya yazma
        file << "Writing at the end of the file using ate mode.\n";

        // Okuma konumunu başa taşı
        file.seekg(0, std::ios::beg);

        // Dosyadan okuma
        std::string line;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    } else {
        std::cout << "Unable to open file using ate mode." << std::endl;
    }

}

// std::ios::trunc (İçeriği Silerek Yazma)
void fstream_trunc_ex() {
    std::fstream file("./example_2.txt", std::ios::out | std::ios::trunc);

    if (file.is_open()) {
        file << "This is a new content after truncating the file.\n";
        file.close();
    } else {
        std::cout << "Unable to open file with trunc mode." << std::endl;
    }
}

// std::ios::binary (İkili Mod)
void fstream_binary_ex() {
    std::fstream file("example.dat", std::ios::in | std::ios::out | std::ios::binary);

    if (file.is_open()) {
        // Yazma işlemi
        int number = 12345;
        file.write(reinterpret_cast<char*>(&number), sizeof(number));

        // Okuma konumunu başa taşı
        file.seekg(0, std::ios::beg);

        // Okuma işlemi
        int readNumber;
        file.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));
        std::cout << "Read number: " << readNumber << std::endl;

        file.close();
    } else {
        std::cout << "Unable to open file in binary mode." << std::endl;
    }
}
int main() {
    cout << "General Examples ####################################################\n";
    cout << "Writing File -------------------------------------------------------\n";
    writing_file_ex();

    cout << "\nReading File -------------------------------------------------------\n";
    reading_file_ex();

    cout << "\nReading and Writing File -------------------------------------------------------\n";
    reading_writing_file_ex();

    cout << "\n\nFile Modes Examples ####################################################\n";
    cout << "\nfstream: Reading and Writing File -------------------------------------------------------\n";
    fstream_read_write_ex();
    
    cout << "\nfstream: app File -------------------------------------------------------\n";
    fstream_app_ex();

    cout << "\nfstream: ate File -------------------------------------------------------\n";
    fstream_ate_ex();
    return 0;
}