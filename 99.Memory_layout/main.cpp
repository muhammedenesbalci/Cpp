
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