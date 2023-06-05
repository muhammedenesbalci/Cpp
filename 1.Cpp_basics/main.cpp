#include <iostream>
#include <string>

using namespace std;

int main() {

    //Basic print
    cout << "Basic print--------------------------------------------------------------------------------------" << endl;
    std::cout << "Hello"; // if we do not write using namespace std we have to use 'std::';
    cout << "Hello\n";

    //'endl' makes it go to the bottom line like '\n'
    cout << "endl---------------------------------------------------------------------------------------------" << endl;
    cout << "1 line" << endl;
    cout << "2 line" << endl;

    //variables
    cout << "Variables----------------------------------------------------------------------------------------" << endl;

    int a = 3;
    int b;
    b = -5;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    //Variable Types
    cout << "Variable types-----------------------------------------------------------------------------------" << endl;
    short s = -78;
    cout << "--short size: " << sizeof(short) << " byte" << endl;
    cout << "s size: " << sizeof(s) << " byte" << endl;
    cout << "s value: " << s << endl;

    int i = 354656;
    cout << "--int size: " << sizeof(int) << " byte" << endl;
    cout << "i size: " << sizeof(i) << " byte" << endl;
    cout << "i value: " << i << endl;

    unsigned int ui = 354656; // unsigned : only non-negative values 0, 1, 2... It can be use others short, long, double etc.
    cout << "--unsigned int size: " << sizeof(int) << " byte" << endl;
    cout << "ui size: " << sizeof(ui) << " byte" << endl;
    cout << "ui value: " << ui << endl;

    long l = 86;
    cout << "--long size: " << sizeof(long) << " byte" << endl;
    cout << "l size: " << sizeof(l) << " byte" << endl;
    cout << "l value: " << l << endl;

    float f = 78.8; // decimal
    cout << "--float size: " << sizeof(float) << " byte" << endl;
    cout << "f size: " << sizeof(f) << " byte" << endl;
    cout << "f value: " << f << endl;

    double d = -78.8; // decimal
    cout << "--double size: " << sizeof(double) << " byte" << endl;
    cout << "d size: " << sizeof(d) << " byte" << endl;
    cout << "d value: " << d << endl;

    char c = 'c'; //char
    cout << "--char size: " << sizeof(char) << " byte" << endl;
    cout << "c size: " << sizeof(c) << " byte" << endl;
    cout << "c value: " << c << endl;

    //Variables-2
    cout << "Variables-2 -------------------------------------------------------------------------------------" << endl;
    int x = 1, y = 2, z = 3;
    cout << "x:" << x << " y:" << y << " z:" << z << endl;

    x = y = z = 5;
    cout << "x:" << x << " y:" << y << " z:" << z << endl;

    int t(48);
    cout << "t: " << t << endl;

    //Boolean
    cout << "Boolean -----------------------------------------------------------------------------------------" << endl;
    bool boolV1 = true;
    bool boolV2 = false;

    cout << "v1: " << boolV1 << endl;
    cout << "v2: " << boolV2 << endl;

    //Get input from keyboard
    cout << "Get input from keyboard--------------------------------------------------------------------------" << endl;

    int count = 0;
    cout << "Enter a number: ";
    cin >> count;
    cout << "count: " << count << endl;

    //Strings
    cout << "Strings------------------------------------------------------------------------------------------" << endl;
    string str = "Hello";
    cout << str << endl;

    // Escape sequences
    cout << "Escape sequences---------------------------------------------------------------------------------" << endl;

    cout << "Hello\nEnes" << endl;
    cout << "Hello\tEnes" << endl;
    cout << "Hello\aEnes" << endl; // you can hear something

    cout << "8\\" << endl;
    cout << "8\"" << endl;
    cout << "8\'" << endl;

    // Raw strings
    cout << "Raw strings -------------------------------------------------------------------------------------" << endl;
    cout << "normal: " << "\\n, \\t, \\a" << endl;
    cout << "raw strings: " << R"(\n, \t, \a)" << endl;

    // 'const' variables
    const int constX = 4;
    //constX = 7 can not change because it is a constant variable
    cout << constX << endl;

    //Arithmetic operations
    cout << "Arithmetic operations----------------------------------------------------------------------------" << endl;

    int x1 = 8;
    int y1 = 3;
    int z1;

    z1 = x1 + y1;
    cout << "x1 + y1 = " << z1 << endl;

    z1 = x1 - y1;
    cout << "x1 - y1 = " << z1 << endl;

    z1 = x1 / y1;
    cout << "x1 / y1 = " << z1 << endl;

    z1 = x1 * y1;
    cout << "x1 * y1 = " << z1 << endl;

    z1 = x1 % y1;
    cout << "x1 % y1 = " << z1 << endl;

    int x2 = 8;
    double y2 = 3;
    double z2 = x2 / y2;

    cout << "x2 % y2 = " << z2 << endl;

    //Conversion of variables static_cast
    cout << "Conversion of variables--------------------------------------------------------------------------" << endl;

    double x3 = 3.14;
    cout << "x3: " << x3 << endl;

    int y3 = static_cast<int>(x3);
    cout << "y3: " << y3 << endl;

    float z3 = static_cast<float>(y3);
    cout << "z3: " << z3 << endl;

    // Increasing and decreasing values (++ --)
    cout << "Increasing and decreasing values (++ --)---------------------------------------------------------" << endl;
    int a1 = 0;

    a1 = a1 + 1;
    cout << "a1 = a1 + 1: " << a1 << endl;

    a1++;
    cout << "a1++: " << a1 << endl;

    a1 = a1 + 5;
    cout << "a1 = a1 + 5: " << a1 << endl;

    a1 += 5;
    cout << "a1 += 5: " << a1 << endl;

    a1 = a1 - 1;
    cout << "a1 = a1 - 1: " << a1 << endl;

    a1--;
    cout << "a1--: " << a1 << endl;

    a1 = a1 - 5;
    cout << "a1 = a1 - 5: " << a1 << endl;

    a1 -= 5;
    cout << "a1 -= 5: " << a1 << endl;


    // Right and left increment difference
    int b1 = 0;
    int c1;

    cout << "Right and left increment difference (++a, a++)---------------------------------------------------" << endl;

    c1 = b1++; //It first assigns the value b to c and then increments the value of b.
    cout << "c1: " << c1 << " b1: " << b1 << endl;

    c1 = ++b1;//It first increments the value of b and then assigns the value b to c and.
    cout << "c1: " << c1 << " b1: " << b1 << endl;

    return 0;
}