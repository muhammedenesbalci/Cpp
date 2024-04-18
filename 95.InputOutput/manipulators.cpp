#include <iostream>
#include <string>

#include <istream>
#include <sstream>
#include <string>

#include <iomanip> // Manipülatörleri kullanmak için gerekli başlık dosyası
#include <ios> // Manipülatörleri kullanmak için gerekli başlık dosyası

using namespace std;

void ws_ex2() {
    istringstream str("           Programmer");
    string line;
    // Ignore all the whitespace in string
    // str before the first word.
    getline(str >> std::ws, line);
 
    // you can also write str>>ws
    // After printing the output it will automatically
    // write a new line in the output stream.
    cout << line << endl;
 
    // without flush, the output will be the same.
    cout << "only a test" << flush;
 
    // Use of ends Manipulator
    cout << "\na";
 
    // NULL character will be added in the Output
    cout << "b" << ends;
    cout << "c" << endl;

}

//Some important manipulators in <iomanip> are:#######################################
void setw_ex() {
    cout<< "setw_ex---------------------\n";
    int number = 123;
    std::string text = "Hello";

    // setw ile alan genişliğini ayarlayarak çıktı biçimini belirleme
    std::cout << std::setw(10) << text << std::setw(5) << number << std::endl;
}

void setfill_ex() {
    cout<< "setfill_ex---------------------\n";
    int number = 123;
    // setfill ile sayıyı karakterlerle doldurma
    std::cout << std::setfill('*') << std::setw(10) << number << std::endl;
}

void setprecision_ex() {
    cout<< "setprecision_ex---------------------\n";
    double pi = 3.14159265358979323846;

    // setprecision ile ondalık hassasiyeti ayarlama
    std::cout << std::setprecision(5) << "Pi: " << pi << std::endl;
}

void setbase_ex() {
    cout<< "setbase_ex---------------------\n";
    long int number = 25523123123123;

    // setbase ile sayısal tabanı ayarlama (8'lik taban)
    std::cout << "Number in octal: " << std::setbase(8) << number << std::endl;
    std::cout << "Number in hex: " << std::setbase(16) << number << std::endl;
    std::cout << "Number in binary: " << std::setbase(2) << number << std::endl;
    std::cout << "Number in 10: " << std::setbase(10) << number << std::endl;
}

void setiosflags_resetiosflags_ex() {
    cout<< "setiosflags_resetiosflags_ex---------------------\n";
    long int number = 25523123123123;

    // setiosflags ile format bayrağı ayarı (hexadecimal olarak gösterim)
    std::cout << "Number in hexadecimal: " << std::setiosflags(std::ios::hex) << number << std::endl;

    // resetiosflags ile format bayrağı sıfırlama
    std::cout << "Number in decimal: " << std::resetiosflags(std::ios::hex) << number << std::endl;
}

//Some important manipulators in <ios> are:#######################################
void showpos_noshowpos_ex() {
    int number = 42;

    // showpos manipülatörü kullanarak pozitif sayıları artı işareti ile gösterme
    std::cout << "Number with positive sign (showpos): " << std::showpos << number << std::endl;

    // noshowpos manipülatörü kullanarak pozitif sayıları artı işareti olmadan gösterme
    std::cout << "Number without positive sign (noshowpos): " << std::noshowpos << number << std::endl;

}
void showbase() {
    int number = 255;

    // showbase manipülatörü kullanarak sayının tabanını belirten ön ek ekleyerek gösterme
    std::cout << "Number in hexadecimal with base prefix (showbase): " << std::showbase << std::hex << number << std::endl;
}

void uppercase_nouppercase_ex() {
    int number = 255;

    // uppercase manipülatörü kullanarak hexadecimal sayıları büyük harfle gösterme
    std::cout << "Number in hexadecimal (uppercase): " << std::uppercase << std::hex << number << std::endl;

    // nouppercase manipülatörü kullanarak hexadecimal sayıları küçük harfle gösterme
    std::cout << "Number in hexadecimal (lowercase): " << std::nouppercase << std::hex << number << std::endl;

}

void fixed_scientific_ex() {
    double pi = 3.14159;

    // fixed manipülatörü kullanarak ondalık gösterim
    std::cout << "Pi (fixed): " << std::fixed << pi << std::endl;

    // scientific manipülatörü kullanarak bilimsel gösterim
    std::cout << "Pi (scientific): " << std::scientific << pi << std::endl;
} 

void hex_dec_oct() {
    int number = 255;

    // hex manipülatörü kullanarak hexadecimal gösterim
    std::cout << "Number in hexadecimal: " << std::hex << number << std::endl;

    // dec manipülatörü kullanarak ondalık gösterim
    std::cout << "Number in decimal: " << std::dec << number << std::endl;

    // oct manipülatörü kullanarak sekizlik (octal) gösterim
    std::cout << "Number in octal: " << std::oct << number << std::endl;
}
void left_right_ex() {
    std::string text = "Hello";

    // left manipülatörü kullanarak metni sola hizala
    std::cout << std::left << std::setw(20) << "Text (left): " << text << std::endl;

    // right manipülatörü kullanarak metni sağa hizala
    std::cout << std::right << std::setw(20) << "Text (right): " << text << std::endl;
}
int main() {
    cout << "ws examples---------------------------\n";
    ws_ex2();

    cout << "<iomanip> examples---------------------------\n";
    setw_ex();
    setfill_ex();
    setprecision_ex();
    setbase_ex();
    setiosflags_resetiosflags_ex();

    cout << "<ios> examples---------------------------\n";
    showpos_noshowpos_ex();
    showbase();
    uppercase_nouppercase_ex();
    fixed_scientific_ex();
    hex_dec_oct();
    left_right_ex();
    return 0;
}