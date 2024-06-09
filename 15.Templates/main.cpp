#include <iostream>
#include <string>
 
using namespace std;

// General Template examples ####################################################
// Function template example -----------------------------------------------------
template <typename T_F>

T_F add(T_F a, T_F b) {
    return a + b;
}

void funciton_template_example() {
    int intV = add(3, 4);
    double doubleV = add(3.5, 4.5);
    float floatV = add(3.5f, 4.5f);
    //add(3, 5.3f); Hata verir
    cout << "intV: " << intV << " type: " << typeid(intV).name() << endl;
    cout << "doubleV: " << doubleV << " type: " << typeid(doubleV).name() << endl;
    cout << "floatV: " << floatV << " type: " << typeid(floatV).name() << endl;

    int intV_ = add<int>(3, 4);
    double doubleV_ = add<double>(3.5, 4.5);
    float floatV_ = add<float>(3.5f, 4.5f);

    cout << "intV_: " << intV_ << " type: " << typeid(intV_).name() << endl;
    cout << "doubleV_: " << doubleV_ << " type: " << typeid(doubleV_).name() << endl;
    cout << "floatV_: " << floatV_ << " type: " << typeid(floatV_).name() << endl;
}

// Class template example -----------------------------------------------------
template <typename T_C>

class Template_Class{
private:
    T_C data;
public:
    Template_Class(T_C dataV) : data(dataV) {
    }

    void display() {
        cout << "data: " << data << " | type " << typeid(data).name() << endl;
    }
};

void class_template_example() {
    cout << "cpp 11 ile 17 arasi----------------\n";
    Template_Class<int> template_Class_1(5);
    template_Class_1.display();

    Template_Class<double> template_Class_2(5.5);
    template_Class_2.display();

    Template_Class<float> template_Class_3(5.7f);
    template_Class_3.display();

    Template_Class<std::string> template_Class_4("enes");
    template_Class_4.display();

    cout << "cpp 17 ve yukarisi arasi----------------\n";
    Template_Class template_Class_5(5);
    template_Class_5.display();

    Template_Class template_Class_6(5.5);
    template_Class_6.display();

    Template_Class template_Class_7(5.7f);
    template_Class_7.display();

    Template_Class template_Class_8("enes");
    template_Class_8.display();

}

// Full Template Specialization ####################################################
// Function template example -----------------------------------------------------
template <typename T_F_FULL>
void print(T_F_FULL data) {
    cout << "Full Template Specialization (Funciton) " << data << endl;
}

template <>
void print(int value) {
    cout << "Specialized template for int: " << value << endl;
}

template <>
void print(double value) {
    cout << "Specialized template for double: " << value << endl;
}

template <>
void print(std::string str) {
    cout << "Specialized template for string: " << str << endl;
}

void full_template_spec_function_ex() {
    print(42);       
    print(3.14);    
    print(string("Enes"));  
    print(3.2f);
}
// Class template example -----------------------------------------------------
template <typename T_C_F>
class ClassTemplateFull {
public:
    T_C_F data;

    ClassTemplateFull(T_C_F value) : data(value){
        cout << "Generic template constrctor: " << value << " type: "<<typeid(value).name() <<endl;
    }

    void display() const {
        cout << "Generic template display: " << data << " type: "<<typeid(data).name() <<endl;
    }
};

template <>
class ClassTemplateFull<int> {
    
public:
    int data;

    ClassTemplateFull(int value) : data(value){
        cout << "Specialized template constrctor: " << value << " type: "<<typeid(value).name() <<endl;
    }

    void display() const {
        cout << "Specialized template display: " << data << " type: "<<typeid(data).name() <<endl;
    }
};

template <>
class ClassTemplateFull<double> {
public:
    double data;

    ClassTemplateFull(double value) : data(value){
        cout << "Specialized template constrctor: " << value << " type: "<<typeid(value).name() <<endl;
    }

    void display() const {
        cout << "Specialized template display: " << data << " type: "<<typeid(data).name() <<endl;
    }
};

template<>
class ClassTemplateFull<std::string> {
public:
    string data;

    ClassTemplateFull(string value) : data(value){
        cout << "Specialized template constrctor: " << value << " type: "<<typeid(value).name() <<endl;
    }

    void display() const {
        cout << "Specialized template display: " << data << " type: "<<typeid(data).name() <<endl;
    }
};
void full_template_spec_class_ex() {
    ClassTemplateFull<int> intObj(5);
    intObj.display(); 

    ClassTemplateFull<double> doubleObj(2.33);
    doubleObj.display(); 

    ClassTemplateFull<std::string> stringobj(std::string("enes"));
    stringobj.display(); 

    ClassTemplateFull<float> floatObj(3.3333f);
    floatObj.display();
}
// Partial Template Specialization ####################################################
template <typename T_C_P_a, typename T_C_P_b>

class  ClassTemplatePartial {
public:
    T_C_P_a data_a;
    T_C_P_b data_b;

    ClassTemplatePartial(T_C_P_a value_a, T_C_P_b value_b) : data_a(value_a), data_b(value_b){
        cout << "Partial template constrctor value_a: " << value_a << " type: "<<typeid(value_a).name() <<endl;
        cout << "Partial template constrctor value_b: " << value_b << " type: "<<typeid(value_b).name() <<endl;
    }

    void display() const {
        cout << "Partial template display value_a: " << data_a << " type: "<<typeid(data_a).name() <<endl;
        cout << "Partial template display value_b: " << data_b << " type: "<<typeid(data_b).name() <<endl;
    }
};

// T_C_P_b pointer türü için kısmi özel durum
template <typename  T_C_P_a>
class ClassTemplatePartial<T_C_P_a, T_C_P_a*> {
public:
    T_C_P_a data_a;
    T_C_P_a* data_a_ptr;
    ClassTemplatePartial(T_C_P_a value_a, T_C_P_a* value_a_ptr) : data_a(value_a), data_a_ptr(value_a_ptr){
        cout << "Partial template constrctor value_a: " << value_a << " type: "<<typeid(value_a).name() <<endl;
        cout << "Partial template constrctor value_a_ptr: " << value_a_ptr << " type: "<<typeid(value_a_ptr).name() <<endl;
    }

    void display() const {
        cout << "Partial template display value_a: " << data_a << " type: "<<typeid(data_a).name() <<endl;
        cout << "Partial template display value_a_ptr: " << data_a_ptr << " type: "<<typeid(data_a_ptr).name() <<endl;
    }
};

void partial_template_spec_class_example() {
    ClassTemplatePartial<int, double> obj1(5, 10.4);
    obj1.display(); 

    int a = 5;
    int* a_ptr = &a;

    ClassTemplatePartial<int, int*> obj2(a, a_ptr);
    obj2.display(); 
}
// Static variable with template funcitons ################################################
template <typename T>
void printAndCount(T value) {
    static int count = 0; // Her şablon örneği için ayrı statik veri
    ++count;
    std::cout << "type: " << typeid(value).name() << " Value: " << value << ", Count: " << count << std::endl;
}

void static_Variable_fun_ex() {
    printAndCount(42);         
    printAndCount(3.14);        
    printAndCount("Hello");      
    
    printAndCount(45);           
    printAndCount(3.16);         
    printAndCount("enes");     
}

int main() {
    cout << "General Template examples ###########################################\n";
    cout << "Function template example ----------------------------------------\n";
    funciton_template_example();

    cout << "\nClass template example ----------------------------------------\n";
    class_template_example();

    cout << "\n\nFull Template Specializations #########################################\n";
    cout << "Function template example ----------------------------------------\n";
    full_template_spec_function_ex();

    cout << "\nClass template example ----------------------------------------\n";
    full_template_spec_class_ex();

    cout << "\n\nPartial Template Specializations #########################################\n";
    partial_template_spec_class_example();

    cout << "\n\nStatic variable with template funcitons ##################################\n";
    static_Variable_fun_ex();
    return 0;
}
