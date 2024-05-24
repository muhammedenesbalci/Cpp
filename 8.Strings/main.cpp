#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>

#include <sstream> //multiple input string

using namespace std;

//------------------------------------------------------------------------------------------------------------------
void old_lessons() {
    cout << "General string ----------------------------------------------------------------------------------" << endl;
    /*
     In a C-style string, '\0' denotes the null terminator; it's used to mark the end of the string
    */

    char characterArray[] = "Hello C++";
    cout << characterArray << endl;

    char characterArray2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << characterArray2 << endl;

    string myString = "string variable";
    cout << myString << endl;

    cout << "input string ------------------------------------------------------------------------------------" << endl;
    char name[30];
    cout << "Enter a neme: ";

    // if you type more than one word, it takes just first word.
    // cin >> name;
    // cout << "name: " << name << endl;

    // it gets 30 character
    cin.getline(name, 30);
    cout << "name: " << name << endl;

    cout << "Length, combining, copying-----------------------------------------------------------------------" << endl;

    char myString2[] = "HELLO ";
    char myString3[] = "C++";

    cout << myString2 << endl;

    cout << "length: " << strlen(myString2) << endl;

    strcat(myString2, myString3);
    cout << "myString2: " << myString2 << " myString3: " << myString3 << endl;

    strcpy(myString2, myString3);
    cout << "myString2: " << myString2 << " myString3: " << myString3 << endl;
}

//------------------------------------------------------------------------------------------------------------------
void cpp_string_func(string s) {
    cout << "Passed String is: " << s << endl;
}

//------------------------------------------------------------------------------------------------------------------
string cpp_string_func_2(string s) {
    return s;
}

//------------------------------------------------------------------------------------------------------------------
string cpp_string_func_3() {
    string str = "local string\n";
    return str;
}

//------------------------------------------------------------------------------------------------------------------
void string_iterator_ex_fun() {
    // declaring an iterator
    string::iterator itr;
 
    // declaring a reverse iterator
    string::reverse_iterator rit;
 
    string s = "GeeksforGeeks";
 
    itr = s.begin();
   
    cout << "Pointing to the start of the string: " << *itr<< endl;
 
    itr = s.end() - 1;
 
    cout << "Pointing to the end of the string: " << *itr << endl;
 
    rit = s.rbegin();
    cout << "Pointing to the last character of the string: " << *rit << endl;
 
    rit = s.rend() - 1;
    cout << "Pointing to the first character of the string: " << *rit << endl;
}

//------------------------------------------------------------------------------------------------------------------
void string_capacity_ex_fun() {
    
    string s = "GeeksforGeeks";
   
      // length function is used to print the length of the string
    cout << "The length of the string is " << s.length() << endl;
       
      // capacity function is used to print the capacity of the string
    cout << "The capacity of string is " << s.capacity()<< endl;

    cout << "The size of string is " << sizeof(s)<< endl;
     
    // the string.resize() function is used to resize the string to 10 characters
      s.resize(10);
   
    cout << "The string after using resize function is " << s << endl;
       
      s.resize(20);
     
    cout << "The capacity of string before using shrink_to_fit function is "<< s.capacity() << endl;
     
      // shrink to fit function is used to reduce the capacity of the container
    s.shrink_to_fit();
 
    cout << "The capacity of string after using shrink_to_fit function is "<< s.capacity() << endl;
}

//------------------------------------------------------------------------------------------------------------------
void array_of_strings_using_pointers() {
    const char* colour[4] = { "Blue", "Red", "Orange", "Yellow" }; // const yazmasaydık da otomatik olarak const oluyor
 
  // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    cout << "-------------------------\n";

    for (int i = 0; i < 4; i++)
        std::cout << *(colour + i) << "\n";
}

void array_of_strings_using_pointers_2() {
    string colour[4] = { "Blue", "Red", "Orange", "Yellow" }; 
 
  // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    cout << "-------------------------\n";

    for (int i = 0; i < 4; i++)
        std::cout << *(colour + i) << "\n";
}

//------------------------------------------------------------------------------------------------------------------
void array_of_strings_using_2d_arrays() {
    // Initialize 2D array
    char colour[4][10] = { "Blue", "Red", "Orange", "Yellow" };

    // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    cout << "-------------------------\n";

    for (int i = 0; i < 4; i++)
        std::cout << *(colour + i) << "\n";
}

//------------------------------------------------------------------------------------------------------------------
void array_of_strings_using_vector() {
    // Declaring Vector of String type
    // Values can be added here using 
    // initializer-list
    // syntax
    std::vector<std::string> colour{"Blue", "Red",
                                    "Orange"};

    // Strings can be added at any time 
    // with push_back
    colour.push_back("Yellow");

    // Print Strings stored in Vector
    for (int i = 0; i < colour.size(); i++)
        std::cout << colour[i] << "\n";
}

//------------------------------------------------------------------------------------------------------------------
void array_of_strings_using_string_class() {
    // Initialize String Array
    std::string colour[4] = { "Blue", "Red", "Orange", "Yellow" };

    // Print Strings
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";

    cout << "-------------------------\n";

    for (int i = 0; i < 4; i++)
        std::cout << *(colour + i) << "\n";
}

//------------------------------------------------------------------------------------------------------------------
void array_of_strings_using_array_class() {
    // Initialize array
    std::array<std::string, 4> colour{"Blue", "Red", "Orange", "Yellow"};

    // Printing Strings stored in array
    for (int i = 0; i < 4; i++)
        std::cout << colour[i] << "\n";
 
}

//------------------------------------------------------------------------------------------------------------------
void string_concatenation_append(){
    string init("this is init");
    string add(" added now");
 
    // Appending the string.
    init.append(add);
 
    cout << init << endl;    
}

//------------------------------------------------------------------------------------------------------------------
void string_concatenation_plus(){
    string init("this is init");
    string add(" added now");
 
    // Appending the string.
    init = init + add;
 
    cout << init << endl;
}

//------------------------------------------------------------------------------------------------------------------
void string_concatenation_strcat(){
    char init[] = "this is init";
    char add[] = " added now";
 
    // Concatenating the string.
    strcat(init, add);
 
    cout << init << endl;
}

//------------------------------------------------------------------------------------------------------------------
void string_concatenation_for_loop(){
    string init("this is init");
    string add(" added now");
 
    string output;
 
    // Adding element inside output
    // from  init
    for (int i = 0; init[i] != '\0'; i++) 
    {
        output += init[i];
    }
 
    // Adding element inside output
    // fromt add
    for (int i = 0; add[i] != '\0'; i++) 
    {
        output += add[i];
    }
 
    cout << output << endl;
}

//------------------------------------------------------------------------------------------------------------------
void cpp_strings_basics() {
    cout << "\nbasics------------------------------------------\n";
    string str("enes 1");
    cout << str << endl;

    cout << "\nbasics------------------------------------------\n";
    string str2 = "enes 2";
    cout << str2<< endl;

    cout << "\nbasics------------------------------------------\n";
    string str3(5, 'e');
    cout << str3<< endl;;

    cout << "\nbasics------------------------------------------\n";
    string str10 = "Muhammed Enes BALCI";
    cout << str10 << endl;

    str10 = "Furkan Efe BALCI";
    cout << str10 << endl;

    cout << "\ncin input ------------------------------------------\n";
    string str4;
       
    cout<<"Enter String"<<endl;
    cin>>str4;
    cout<<"String is: "<<str4<<endl;
    cin.ignore(); // cin den sonra ignore kullanmayı unutma yoksa çok sıkıntı yapıyor

    cout << "\ngetline input ------------------------------------------\n";
    string str5;

    cout << "Enter String" << endl;
    getline(cin, str5);
    cout << "String is: " << str5 << endl;

    cout << "\nstringstream input ------------------------------------------\n";
    string str6 = " Enes to the Moon ";
    stringstream obj(str6);
    // string to store words individually
    string temp;
    // >> operator will read from the stringstream object
    while (obj >> temp) {
        cout << temp << endl;
    }

    cout << "\nString function ------------------------------------------\n";
    cpp_string_func("enes");

    cout << "\nString function 2 ------------------------------------------\n";
    string my_str = cpp_string_func_2("enes");
    cout << "my_str: " << my_str << endl;

    cout << "\nString function 3 ------------------------------------------\n";
    string my_str_2 =  cpp_string_func_3();
    cout << "my_str_2: " << my_str_2 << endl;

    cout << "\nString like arrays ------------------------------------------\n";
    string str_array = "Muhammed Enes BALCI";

    for (auto str : str_array) {
        cout << str << " ";
    }
    cout << endl;

    cout << "\nString like arrays 2 ------------------------------------------\n";
    string str_array2 = "Muhammed Enes BALCI";
    
    for (int i = 0; i < str_array2.length(); i++) {
        cout << "str_array2" << "[" << i << "]" << " = " << str_array2[i] << endl;
    }

    cout << "\nString like addres 3------------------------------------------\n";
    string str_array3 = "Muhammed Enes BALCI";
    
    for (int i = 0; i < str_array3.length(); i++) {
        cout << "&str_array3" << "[" << i << "]" << " = " << &str_array3[i] << endl;
    }
    cout << endl;

    cout << "\nString like addres 4 ------------------------------------------\n";
    string str_array4 = "Muhammed Enes BALCI";
    
    char *ptr_s = &str_array4[0]; // starting addres of a string
    while (*ptr_s != '\0') {
        cout << *ptr_s << "  " << ptr_s <<endl;
        ptr_s++;
    }
    cout << endl;

    cout << "\nstring_iterator_ex_fun  ------------------------------------------\n";
    string_iterator_ex_fun();

    cout << "\nstring_capacity_ex_fun  ------------------------------------------\n";
    string_capacity_ex_fun();

    cout << "\nsize a string  ------------------------------------------\n";
    string kzy = "Said Kuzey";
    cout << "lenght string: " << kzy.length() << endl;
    cout << "size string: " << sizeof(kzy) << endl;

    char c_array_str[] = "Said Kuzey";
    cout << "size c_array_str: " << sizeof(c_array_str) << endl;

    cout << "\narray of strings(Using Pointers)------------------------------------------\n";
    array_of_strings_using_pointers();

    cout << "\nrray of strings(Using Pointers)_2------------------------------------------\n";
    array_of_strings_using_pointers_2();

    cout << "\narray_of_strings_using_2d_array------------------------------------------\n";
    array_of_strings_using_2d_arrays();

    cout << "\narray_of_strings_using_string_class------------------------------------------\n";
    array_of_strings_using_string_class();

    cout << "\narray_of_strings_using_vector------------------------------------------\n";
    array_of_strings_using_vector();

    cout << "\narray_of_strings_using_array_class------------------------------------------\n";
    array_of_strings_using_array_class();

    cout << "\nstring_concatenation_append------------------------------------------\n";
    string_concatenation_append();

    cout << "\nstring_concatenation_plus------------------------------------------\n";
    string_concatenation_plus();

    cout << "\nstring_concatenation_strcat------------------------------------------\n";
    string_concatenation_strcat();

    cout << "\nstring_concatenation_for_loop------------------------------------------\n";
    string_concatenation_for_loop();
}

void c_style_strings_basics() {
    cout << "\nbasics------------------------------------------\n";
    char s[] = "GeeksforGeeks";
    s[0] = 'e';
    cout << s << endl;
    

    cout << "\nbasics------------------------------------------\n";
    char s1[] = { 'g', 'f', 'g', '\0' }; //nul terminator
    char s2[4] = { 'g', 'f', 'g', '\0' }; //nul terminator
    char s3[4] = "gfg";
    char s4[] = "gfg";
 
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
}
int main() {
    cout << "\nCpp style strings-------------------------\n";
    cpp_strings_basics();

    cout << "\nC style strings-------------------------\n";
    //c_style_strings_basics();

    return 0;
}