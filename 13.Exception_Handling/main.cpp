#include <iostream>
#include <exception>

using namespace std;

// Genel Hata Yakalama #######################################################
//std::exception -------------------------------------------------------------
void std_exception_ex() {
    try {
        throw std::exception();
    } catch (const std::exception& e) {
        std::cerr << "std::exception: Genel bir hata meydana geldi: " << e.what() << std::endl;
    }
}

// Logical Errors ##############################################################
void check_logic(bool condition) {
    if (!condition) {
        throw std::logic_error("Mantiksal hata: Koşul yanliş.");
    }
}

void std_logical_error_ex() {
    try {
        check_logic(false);
    } catch (const std::logic_error& e) {
        std::cerr << "std::logic_error: " << e.what() << std::endl;
    }
}

// invalid_argument ----------------------------------------------------------
void set_age(int age) {
    if (age < 0) {
        throw std::invalid_argument("Geçersiz argüman: Yaş negatif olamaz.");
    }
}

void invalid_argument_ex() {
    try {
        set_age(-5);
    } catch (const std::invalid_argument& e) {
        std::cerr << "std::invalid_argument: " << e.what() << std::endl;
    }
}
// std::domain_error ---------------------------------------------------------
#include <cmath>
double calculate_log(double x) {
    if (x <= 0) {
        throw std::domain_error("Domain hatası: Logaritma negatif veya sıfır olamaz.");
    }
    return std::log(x);
}

void domain_error_ex() {
     try {
        std::cout << calculate_log(-1) << std::endl;
    } catch (const std::domain_error& e) {
        std::cerr << "std::domain_error: " << e.what() << std::endl;
    }
}

// Lenght error -------------------------------------------------------------
void lenght_error_ex() {
    try {
        std::string str;
        str.reserve(str.max_size() + 1); // Geçersiz uzunluk
    } catch (const std::length_error& e) {
        std::cerr << "std::length_error: " << e.what() << std::endl;
    }
}

// Out of range error -----------------------------------------------------
#include <vector>
void out_of_range_ex() {
    try {
        std::vector<int> vec = {1, 2, 3};
        std::cout << vec.at(10) << std::endl; // Geçersiz indeks erişimi
    } catch (const std::out_of_range& e) {
        std::cerr << "std::out_of_range: " << e.what() << std::endl;
    }
}

// Runtime Error ###########################################################
void runtime_error_ex() {
    try {
        throw std::runtime_error("Çalişma zamani hatasi meydana geldi.");
    } catch (const std::runtime_error& e) {
        std::cerr << "std::runtime_error: " << e.what() << std::endl;
    }
}

// range_error ------------------------------------------------------------
double calculate_division(double a, double b) {
    if (b == 0) {
        throw std::range_error("Bölen sifir olamaz.");
    }
    return a / b;
}

void range_error_ex() {
    try {
        std::cout << calculate_division(10, 0) << std::endl;
    } catch (const std::range_error& e) {
        std::cerr << "std::range_error: " << e.what() << std::endl;
    }
}

// overflow_error --------------------------------------------------
#include <limits>
void overflow_error_ex() {
    try {
        int max = std::numeric_limits<int>::max();
        if (max == max + 1) {
            throw std::overflow_error("Aritmetik taşma meydana geldi.");
        }
    } catch (const std::overflow_error& e) {
        std::cerr << "std::overflow_error: " << e.what() << std::endl;
    }
}

// underflow_error---------------------------------------------------
void underflow_error_ex() {
    try {
        int min = std::numeric_limits<int>::min();
        if (min - 1 > min) {
            throw std::underflow_error("Aritmetik alt taşma meydana geldi.");
        }
    } catch (const std::underflow_error& e) {
        std::cerr << "std::underflow_error: " << e.what() << std::endl;
    }
}
// Memory Management Errors #########################################
// bad_alloc error---------------------------------------------------
void bad_alloc_error_ex() {
    try {
        int* p = new int[100000000000]; // Bellek tahsisi hatası
        delete[] p;
    } catch (const std::bad_alloc& e) {
        std::cerr << "std::bad_alloc: " << e.what() << std::endl;
    }
}

// bad_array_new_length --------------------------------------------
void bad_array_lenght_error_ex() {
    try {
        int* p = new int[0]; // Geçersiz dizi uzunluğu
        delete[] p;
    } catch (const std::bad_array_new_length& e) {
        std::cerr << "std::bad_array_new_length: " << e.what() << std::endl;
    }
}

// bad cast error -------------------------------------------------
class Base {
    virtual void foo() {}
};

class Derived : public Base {};

void bad_cast_error_ex() {
    try {
        Base base;
        Derived& derived = dynamic_cast<Derived&>(base); // Geçersiz tür dönüşümü
    } catch (const std::bad_cast& e) {
        std::cerr << "std::bad_cast: " << e.what() << std::endl;
    }
}

// bad type_id eror -------------------------------------------------
void bad_type_id_error_ex() {
    try {
        Base* base = nullptr;
        const std::type_info& ti = typeid(*base); // Geçersiz tür bilgisi
    } catch (const std::bad_typeid& e) {
        std::cerr << "std::bad_typeid: " << e.what() << std::endl;
    }
}

// bad_exception error ----------------------------------------------
void my_unexpected() {
    throw std::bad_exception();
}

void bad_exception_error_ex() {
    try {
        Base* base = nullptr;
        const std::type_info& ti = typeid(*base); // Geçersiz tür bilgisi
    } catch (const std::bad_typeid& e) {
        std::cerr << "std::bad_typeid: " << e.what() << std::endl;
    }
}

// Input/output error ################################################
#include <fstream>
void input_output_error_ex() {
    try {
        std::ifstream file("nonexistent_file.txt");
        if (!file) {
            throw std::ios_base::failure("Dosya açilamadi.");
        }
    } catch (const std::ios_base::failure& e) {
        std::cerr << "std::ios_base::failure: " << e.what() << std::endl;
    }
}

// C++ 11 sonrası ####################################################
// system_error ------------------------------------------------------
void system_error_ex() {
    try {
        throw std::system_error(std::make_error_code(std::errc::operation_not_permitted));
    } catch (const std::system_error& e) {
        std::cerr << "std::system_error: " << e.what() << std::endl;
    }
}
// regex_error ------------------------------------------------------
#include <regex>
void regex_error_ex() {
    try {
        std::regex re("[a-z"); // Geçersiz regex
    } catch (const std::regex_error& e) {
        std::cerr << "std::regex_error: " << e.what() << std::endl;
    }
}

// future_error ---------------------------------------------------
#include <future>
void future_error_ex() {
    try {
        std::future<int> fut;
        int value = fut.get(); // Geçersiz future erişimi
    } catch (const std::future_error& e) {
        std::cerr << "std::future_error: " << e.what() << std::endl;
    }
}
//bad_function_call -----------------------------------------------
#include <functional>
void bad_function_call_error_ex() {
    try {
        std::function<void()> func;
        func(); // Geçersiz function çağrısı
    } catch (const std::bad_function_call& e) {
        std::cerr << "std::bad_function_call: " << e.what() << std::endl;
    }
}

// bad_weak_ptr error ---------------------------------------------
void bad_weak_ptr_ex() {
     try {
        std::weak_ptr<int> wp;
        std::shared_ptr<int> sp = wp.lock(); // Geçersiz weak_ptr erişimi
        if (!sp) {
            throw std::bad_weak_ptr();
        }
    } catch (const std::bad_weak_ptr& e) {
        std::cerr << "std::bad_weak_ptr: " << e.what() << std::endl;
    }
}

// bad_variant_access --------------------------------------------
#include <variant>
void bad_variant_access_error_ex() {
    try {
        std::variant<int, std::string> var = 42;
        std::string str = std::get<std::string>(var); // Geçersiz variant erişimi
    } catch (const std::bad_variant_access& e) {
        std::cerr << "std::bad_variant_access: " << e.what() << std::endl;
    }
}
// bad_optional_access ----------------------------------------
#include <optional>
void bad_optional_access_error_ex() {
    try {
        std::optional<int> opt;
        int value = opt.value(); // Geçersiz optional erişimi
    } catch (const std::bad_optional_access& e) {
        std::cerr << "std::bad_optional_access: " << e.what() << std::endl;
    }
}

// General Exception behavior #########################################################
// catch_all block -----------------------------------------------------------------
void catch_all_block() {
    // try block
    try {
 
        // throw
        throw 10;
    }
 
    // catch all
    catch (...) {
        cout << "Default Exception\n";
    }
}
// nested try catch -------------------------------------------------------------------
void nested_try_catch() {
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially ";
            throw;
        }
    }
    catch (...) {
        cout << "Handle remaining ";
    }
}

// Custom Exception Classes #########################################################
// Kendi özel exception sınıfımız
class MyCustomException : public std::exception {
private:
    std::string message;

public:
    // Yapıcı (constructor) ile hata mesajını alıyoruz
    MyCustomException(const std::string& msg) : message(msg) {}

    // Hata mesajını döndüren fonksiyon
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Hata fırlatacak bir fonksiyon
void riskyOperation(bool condition) {
    if (!condition) {
        throw MyCustomException("Özel hata: Riskli operasyon başarisiz oldu.");
    }
}

void custom_exception_class_ex() {
    try {
        // Hata fırlatacak durumu test ediyoruz
        riskyOperation(false);
    } catch (const MyCustomException& e) {
        // Hata mesajını yakalayıp yazdırıyoruz
        std::cerr << "Yakalanan hata: " << e.what() << std::endl;
    }
}

// Stack Unwinding #####################################################################
#include <iostream>
#include <stdexcept>

class Resource {
public:
    Resource(const std::string& name) : name(name) {
        std::cout << "Kaynak oluşturuldu: " << name << std::endl;
    }
    ~Resource() {
        std::cout << "Kaynak yok edildi: " << name << std::endl;
    }
private:
    std::string name;
};

void functionC() {
    Resource resC("C");
    throw std::runtime_error("functionC'de hata!");
}

void functionB() {
    Resource resB("B");
    functionC();
}

void functionA() {
    Resource resA("A");
    try {
        functionB();
    } catch (const std::runtime_error& e) {
        std::cerr << "Yakalanan hata: " << e.what() << std::endl;
    }
}

void stack_unwinding_ex() {
    functionA();
}

int main() {
    cout << "Genel Hata Yakalama #######################################################" << endl;
    cout << "std::exception -------------------------------------------------------------\n";
    std_exception_ex();

    cout << "\n\nLogical Errors ##############################################################\n";
    std_logical_error_ex();

    cout << "\ninvalid_argument ----------------------------------------------------------\n";
    invalid_argument_ex();

    cout << "\nstd::domain_error ----------------------------------------------------------\n";
    domain_error_ex();

    cout << "\nLenght error ----------------------------------------------------------\n";
    lenght_error_ex();

    cout << "\nOut of range error ----------------------------------------------------------\n";
    out_of_range_ex();
    
    cout << "\n\nRuntime Error ###########################################################\n";
    runtime_error_ex();
    
    cout << "\nrange_error ----------------------------------------------------------\n";
    range_error_ex();

    cout << "\noverflow_error ----------------------------------------------------------\n";
    overflow_error_ex();

    cout << "\nunderflow_error ----------------------------------------------------------\n";
    underflow_error_ex();

    cout << "\n\nMemory Management Errors #################################################\n";
    cout << "\nbad_alloc error ----------------------------------------------------------\n";
    bad_alloc_error_ex();

    cout << "\nbad_array_new_length ----------------------------------------------------------\n";
    bad_array_lenght_error_ex();

    cout << "\nbad cast error ----------------------------------------------------------\n";
    bad_cast_error_ex();
    
    cout << "\nbad_type_id_error ----------------------------------------------------------\n";
    bad_type_id_error_ex();
    
    cout << "\nbad_exception ----------------------------------------------------------\n";
    bad_exception_error_ex();

    cout << "\n\nInput/Output error ######################################################\n";
    input_output_error_ex();

    cout << "\n\nC++ 11 sonrasi ^^^^######################################################\n";

    cout << "\nsystem_error ----------------------------------------------------------\n";
    system_error_ex();

    cout << "\nregex_error_ex ----------------------------------------------------------\n";
    regex_error_ex();

    cout << "\nfuture_error_ex ----------------------------------------------------------\n";
    future_error_ex();

    cout << "\nbad_function_call_error_ex ----------------------------------------------------------\n";
    bad_function_call_error_ex();

    cout << "\nbad_weak_ptr error ----------------------------------------------------------\n";
    bad_weak_ptr_ex();

    cout << "\nbad_variant_access_error_ex ----------------------------------------------------------\n";
    bad_variant_access_error_ex();

    cout << "\nbad_optional_access_error_ex ----------------------------------------------------------\n";
    bad_optional_access_error_ex();

    cout << "\n\nGeneral Exception behavior ######################################################\n";
    cout << "\ncatch_all block ----------------------------------------------------------\n";
    catch_all_block();

    cout << "\nnested try catch ----------------------------------------------------------\n";
    nested_try_catch();

    cout << "\n\nCustom exception class ######################################################\n";
    custom_exception_class_ex();

    cout << "\n\nStack Unwinding example ######################################################\n";
    stack_unwinding_ex();
}