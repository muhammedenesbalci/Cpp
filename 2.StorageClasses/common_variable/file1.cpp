// file1.cpp
#include <iostream>
#include "common_variable.h"

void function_in_file1() {
    std::cout << "common_variable değeri (file1): " << common_variable << std::endl;
    std::cout << "common_variable addres (file1): " << &common_variable << std::endl;
    std::cout << "common_variable changed (file1): " << std::endl;
    common_variable = 100; // common_variable'ın değerini 100 olarak değiştir
}