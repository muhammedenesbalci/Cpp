// file2.cpp
#include <iostream>
#include "common_variable.h"

void function_in_file2() {
    std::cout << "common_variable değeri (file2): " << common_variable << std::endl;
    std::cout << "common_variable addres (file2): " << &common_variable << std::endl;
}