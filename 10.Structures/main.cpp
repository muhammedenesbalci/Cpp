#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Union --------------------------------------------------------------------
union Data {
    int intValue;
    float floatValue;
    char charArray[4];
};

union Data2 {
    int intValue;
    float floatValue;
};

void union_example() {
    Data data;

    cout << "+++++++++++++++++++++++++\n";
    cout << "setted int value" << endl;
    data.intValue = 42;
    cout << "intValue: " << data.intValue << endl;
    cout << "floatValue: " << data.floatValue << endl;
    cout << "charArray: " << data.charArray << endl;
    cout << "size of union: " << sizeof(data) <<endl;
    cout << "addres of data union: " << &data << endl;
    cout << "addres of int: " << &data.intValue << endl;
    cout << "addres of float: " << &data.floatValue << endl;
    cout << "addres of inchart: " << &data.charArray << endl;

    cout << "+++++++++++++++++++++++++\n";
    cout << "setted float value" << endl;
    data.floatValue = 3.14f;
    cout << "intValue: " << data.intValue << endl;
    cout << "floatValue: " << data.floatValue << endl;
    cout << "charArray: " << data.charArray << endl;
    cout << "size of union: " << sizeof(data) <<endl;
    cout << "addres of data union: " << &data << endl;
    cout << "addres of int: " << &data.intValue << endl;
    cout << "addres of float: " << &data.floatValue << endl;
    cout << "addres of inchart: " << &data.charArray << endl;

    cout << "+++++++++++++++++++++++++\n";
    cout << "setted char value" << endl;
    data.charArray[0] = 'a';
    data.charArray[1] = 'b';
    data.charArray[2] = 'c';
    data.charArray[3] = '\0';
    cout << "intValue: " << data.intValue << endl;
    cout << "floatValue: " << data.floatValue << endl;
    cout << "charArray: " << data.charArray << endl;
    cout << "size of union: " << sizeof(data) <<endl;
    cout << "addres of data union: " << &data << endl;
    cout << "addres of int: " << &data.intValue << endl;
    cout << "addres of float: " << &data.floatValue << endl;
    cout << "addres of inchart: " << &data.charArray << endl;

    Data2 data2;
    cout << "Data-2 ++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "setted int value" << endl;
    data2.intValue = 42;
    cout << "intValue: " << data2.intValue << endl;
    cout << "floatValue: " << data2.floatValue << endl;
    cout << "size of union: " << sizeof(data2) <<endl;
    cout << "addres of data union: " << &data2 << endl;
    cout << "addres of int: " << &data2.intValue << endl;
    cout << "addres of float: " << &data2.floatValue << endl;

    cout << "+++++++++++++++++++++++++\n";
    cout << "setted float value" << endl;
    data2.floatValue = 3.14;
    cout << "intValue: " << data2.intValue << endl;
    cout << "floatValue: " << data2.floatValue << endl;
    cout << "size of union: " << sizeof(data2) <<endl;
    cout << "addres of data union: " << &data2 << endl;
    cout << "addres of int: " << &data2.intValue << endl;
    cout << "addres of float: " << &data2.floatValue << endl;
}

// Enum ----------------------------------------------------------------------------------
// Trafik ışığı durumlarını temsil eden enum
enum TrafficLight {
    Red,
    Yellow,
    Green
};

// Trafik ışığı durumuna göre mesaj yazdıran fonksiyon
void printTrafficLightState(TrafficLight light) {
    switch (light) {
        case Red:
            cout << "Stop! The light is red " << Red <<endl;
            break;
        case Yellow:
            cout << "Caution! The light is yellow "<< Yellow << endl;
            break;
        case Green:
            cout << "Go! The light is green "<< Green << endl;
            break;
        default:
            cout << "Unknown traffic light state!"<< endl;
    }
}

void enum_example() {
    TrafficLight currentLight = Red;
    printTrafficLightState(currentLight);

    currentLight = Yellow;
    printTrafficLightState(currentLight);

    currentLight = Green;
    printTrafficLightState(currentLight);
}

// Struct ----------------------------------------------------------------------------------
struct Person {
    int age = 18; // deafult value
    int gender;
    string name;
};

struct Family {
    string names[4];
};

struct Points {
    int x;
    int y;
};

struct Square {
    Points left;
    Points right;
};

void area_Square(Square s){
    int area = (s.right.x) * (s.left.x);
 
    cout << area << endl;
}

struct Person_with_fun {
    int age = 18; 
    int gender;
    string name;

    void setAge(int newAge) {
       age = newAge;
    }

    void setGender(int newGender) {
        gender = newGender;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << (gender == 0 ? "Male" : "Female") << endl;
    }
};

void struct_example() {
    cout << "size of sturct person: " << sizeof(Person) << endl;

    cout << "basics #####################################\n";
    //initilizations,
    cout << "Person 1 *********************************\n";
    Person person1 = {25, 0, "Enes"};
    cout << "person.age: " << person1.age << endl;
    cout << "person.gender: " << person1.gender << endl;
    cout << "person.name: " << person1.name << endl;
    cout << "size: " << sizeof(person1) << endl;

    cout << "Person 2 *********************************\n";
    Person person2 = {.age=49, .gender=0, .name = "Isa"};
    cout << "person.age: " << person2.age << endl;
    cout << "person.gender: " << person2.gender << endl;
    cout << "person.name: " << person2.name << endl;
    cout << "size: " << sizeof(person2) << endl;

    cout << "Person 3 *********************************\n";
    Person person3;
    person3.age = 12;
    person3.gender = 0;
    person3.name = "Kuzey";
    cout << "person.age: " << person3.age << endl;
    cout << "person.gender: " << person3.gender << endl;
    cout << "person.name: " << person3.name << endl;
    cout << "size: " << sizeof(person3) << endl;

    cout << "Person 4 *********************************\n";
    Person person4 = {.gender=0, .name="Efe"};
    cout << "person.age: " << person4.age << endl;
    cout << "person.gender: " << person4.gender << endl;
    cout << "person.name: " << person4.name << endl;
    cout << "size: " << sizeof(person4) << endl;

    cout << "Person 5 *********************************\n";
    Person person5;
    cout << "person.age: " << person5.age << endl;
    cout << "person.gender: " << person5.gender << endl;
    cout << "person.name: " << person5.name << endl;
    cout << "size: " << sizeof(person5) << endl;

    cout << "arrays in struct #####################################\n";
    cout << "fam 1 *********************************\n";
    Family fam1 = {.names = {"isa", "selma", "enes", "efe"}};

    cout << "name 1: " << fam1.names[0] << endl;
    cout << "name 2: " << fam1.names[1] << endl;
    cout << "name 3: " << fam1.names[2] << endl;
    cout << "name 4: " << fam1.names[3] << endl;

    cout << "fam 2 *********************************\n";
    Family fam2;
    fam2.names[0] = "isa";
    fam2.names[1] = "selma";
    fam2.names[2] = "enes";
    fam2.names[3] = "efe";

    cout << "name 1: " << fam2.names[0] << endl;
    cout << "name 2: " << fam2.names[1] << endl;
    cout << "name 1: " << fam2.names[2] << endl;
    cout << "name 4: " << fam2.names[3] << endl;

    cout << "struct arrays #####################################\n";
    Person person_array[4] = {person1, person2, person3, person4};
    
    for (int i = 0; i < 4; i++) {
        cout << "****\n";
        cout << "person "<< i <<": "<<person_array[i].age << endl;
        cout << "person "<< i <<": "<<person_array[i].gender << endl;
        cout << "person "<< i <<": "<<person_array[i].name << endl;
    }

    cout << "pointer to struct #####################################\n";
    Person person_ptr_orj = {45, 1, "selma"};
    Person *person_ptr = &person_ptr_orj;

    cout << "reach with . **************" << endl;
    cout << "(*person_ptr).age: " << (*person_ptr).age << endl;
    cout << "(*person_ptr).gender: " << (*person_ptr).gender << endl;
    cout << "(*person_ptr).name: " << (*person_ptr).name << endl;

    cout << "reach with -> ************" << endl;
    cout << "person_ptr->age: " << person_ptr->age << endl;
    cout << "person_ptr->gender: " << person_ptr->gender << endl;
    cout << "person_ptr->name: " << person_ptr->name << endl;

    cout << "nested struct #####################################\n";
    Square square = { { 4, 4 }, { 4, 4 } };
    area_Square(square);

    cout << "struct with functions #####################################\n";
    Person_with_fun person_with_fun1;
    person_with_fun1.setAge(25);
    person_with_fun1.setGender(0);
    person_with_fun1.setName("Enes");
    person_with_fun1.printDetails();

    cout << "Memory Allignment #####################################\n";
    cout << "ex1 **************\n";
    struct Example {
        char a;   // 1 bayt
        int b;    // 4 bayt
        char c;   // 1 bayt
    };

    cout << "Size of struct Example: " << sizeof(Example) << " bytes" << endl;
    cout << "Offset of a: " << offsetof(Example, a) << endl;
    cout << "Offset of b: " << offsetof(Example, b) << endl;
    cout << "Offset of c: " << offsetof(Example, c) << endl;

    cout << "ex2 **************\n";
    struct Example2 {
        int b;    // 4 bayt
        char a;   // 1 bayt
        char c;   // 1 bayt
    };

    cout << "Size of struct Example: " << sizeof(Example2) << " bytes" << endl;
    cout << "Offset of b: " << offsetof(Example2, b) << endl;
    cout << "Offset of a: " << offsetof(Example2, a) << endl;
    cout << "Offset of c: " << offsetof(Example2, c) << endl;
}

//typedef ---------------------------------------------------------------------
void typedef_example() {

    // Now we can make more vectors by using vInt 
    typedef std::vector<int> vInt; 

    // vec1 is a vectorof type int 
    vInt v; 

    v.push_back(190); 
    v.push_back(180); 
    v.push_back(10); 
    v.push_back(10); 
    v.push_back(27); 

    for (auto X : v) { 
        cout << X << " "; 
    } 
    cout << endl;
}

int main() {
    cout << "\nunion example -------------------------------------------\n";
    union_example();

    cout << "\nenum example -------------------------------------------\n";
    enum_example();

    cout << "\nstruct example -------------------------------------------\n";
    struct_example();

    cout << "\ntypedef example -------------------------------------------\n";
    typedef_example();
}