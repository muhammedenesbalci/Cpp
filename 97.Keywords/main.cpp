#include <iostream>
#include <cstddef>
#include <vector>

//alignas #######################################################################################################################################################################
void alignas_ex_1() {
    std::cout << "alignas_ex_1--------------------------" << std::endl;
    struct alignas(16) CustomData {
        int value1;
        float value2;
        char value3;
    };

    CustomData data;

    // Bellek adreslerini yazdırma
    data.value1 = 5;
    data.value2 = 23.3;
    data.value3 = 'a';

    std::cout << "Address of data: " << &data << std::endl;
    std::cout << "Address of value1: " << &(data.value1) << std::endl;
    std::cout << "Address of value2: " << &(data.value2) << std::endl;
    std::cout << "Address of value3: " << &(data.value3) << std::endl;

    // Bellek boyutunu kontrol etme
    std::cout << "Size of CustomData: " << sizeof(CustomData) << " bytes" << std::endl;
    std::cout << "Size of value1: " << sizeof(data.value1) << " bytes" << std::endl;
    std::cout << "Size of value2: " << sizeof(data.value2) << " bytes" << std::endl;
    std::cout << "Size of value3: " << sizeof(data.value3) << " bytes" << std::endl;
}

void alignas_ex_2() {
    std::cout << "alignas_ex_2--------------------------" << std::endl;

    struct CustomData {
        int value1;
        float value2;
        char value3;
    };

    CustomData data;

    // Bellek adreslerini yazdırma
    data.value1 = 5;
    data.value2 = 23.3;
    data.value3 = 'a';

    std::cout << "Address of data: " << &data << std::endl;
    std::cout << "Address of value1: " << &(data.value1) << std::endl;
    std::cout << "Address of value2: " << &(data.value2) << std::endl;
    std::cout << "Address of value3: " << &(data.value3) << std::endl;

    // Bellek boyutunu kontrol etme
    std::cout << "Size of CustomData: " << sizeof(CustomData) << " bytes" << std::endl;
    std::cout << "Size of value1: " << sizeof(data.value1) << " bytes" << std::endl;
    std::cout << "Size of value2: " << sizeof(data.value2) << " bytes" << std::endl;
    std::cout << "Size of value3: " << sizeof(data.value3) << " bytes" << std::endl;
}
//alignof ################################################################################
void alignof_example() {
    std::cout << "Alignment of int: " << alignof(int) << std::endl;
    std::cout << "Alignment of float: " << alignof(float) << std::endl;
    std::cout << "Alignment of double: " << alignof(double) << std::endl;
    std::cout << "Alignment of char: " << alignof(char) << std::endl;

    // Özel bir yapı için hafıza hizalamasını gösterme
    struct CustomData {
        int value1;
        float value2;
        char value3;
    };

    struct CustomData2 {
        int value1;
        double value2;
        char value3;
    };

    std::cout << "Alignment of CustomData: " << alignof(CustomData) << std::endl;
    std::cout << "Alignment of CustomData: " << alignof(CustomData2) << std::endl;
}

void and_eq_example() {
    int x = 12;  // 1100 in binary
    int y = 10;  // 1010 in binary

    // Use and_eq to perform bitwise AND on x with y and store the result in x
    x and_eq y;  // Same as x &= y;

    std::cout << "Sonuç: " << x << std::endl;  // Output will be 8, which is 1000 in binary
    std::cout << "Sonuç: " << y << std::endl; 
}

void asm_example() {
    int src = 1;
    int dest;

    // Inline assembly kullanımı
    asm ("mov %1, %0\n\t"
         "add $1, %0"
         : "=r" (dest)    // Çıktı: %0
         : "r" (src)      // Girdi: %1
         :               // Clobbered register yok
    );

    std::cout << "Sonuç: " << dest << std::endl;
}

void auto_example() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // auto ile döngü değişkeninin türü otomatik olarak çıkarılıyor
    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void bitand_ex() {
    int a = 12; // 1100 in binary
    int b = 10; // 1010 in binary
    int result = a bitand b; // Should be 1000 in binary which is 8 in decimal

    std::cout << "Result of " << a << " bitand " << b << " is " << result << std::endl;
}

void bitor_ex() {
    int a = 12; // 1100 in binary
    int b = 10; // 1010 in binary
    int result = a bitor b; // Should be 1110 in binary which is 14 in decimal

    std::cout << "Result of " << a << " bitor " << b << " is " << result << std::endl;
}

int main() {
    //alignas_ex_1();
    //alignas_ex_2();

    //alignof_example();
    
    //and_eq_example();
    
    //asm_example();
    
    //bitand_ex();
    //bitor_ex();
    return 0;
}