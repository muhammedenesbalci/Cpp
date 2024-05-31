#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;

    mutable int data;

    Person(const std::string& name, int age) : name(name), age(age) {}

    // Const member function to get the person's name
    std::string getName() const {
        return name;
    }

    // Const member function to get the person's age
    int getAge() const {
        return age;
    }

    // Non-const member function to set the person's name
    void setName(const std::string& name) {
        this->name = name;
    }

    // Non-const member function to set the person's age
    void setAge(int age) {
        this->age = age;
    }
};

int main() {
    const Person p("John", 30);

    // Const üye fonksiyonlar çağrılabilir
    std::cout << "Name: " << p.getName() << std::endl; // Output: John
    std::cout << "Age: " << p.getAge() << std::endl;   // Output: 30
    std:: cout << "Name: "<< p.name << std::endl; // normal değişkenlere de erişebilir.
    std:: cout << "Age: " << p.age << std::endl; // normal değişkenlere de erişebilir.

    // Non-const üye fonksiyonlar çağrılamaz
    // p.setName("Jane"); // Hata: const nesne üzerinde non-const üye fonksiyonu çağrılamaz
    // p.setAge(35);      // Hata: const nesne üzerinde non-const üye fonksiyonu çağrılamaz

    // Doğrudan veri üyelerine erişim ve değişiklik yapılamaz
    // p.name = "Jane"; // Hata: const nesne üzerinde veri üyeleri değiştirilemez
    // p.age = 35;      // Hata: const nesne üzerinde veri üyeleri değiştirilemez
    p.data = 35; // mutable olarak ayarladığımız için değiştirebilirz
    
    return 0;
}
