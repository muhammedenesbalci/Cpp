#include <iostream>
#include <array> // 2 inci array yöntemi için
#include<tuple>
using namespace std;

//-------------------------------------------------------------------------
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

void use_max() {
    int a = 10, b = 20;

    // Calling above function to find max of 'a' and 'b'
    int m = max(a, b);

    cout << "m is " << m << endl;;
}

//-------------------------------------------------------------------------
int min(int, int);
void use_min() {
    int a = 10, b = 20;

    // Calling above function to find min of 'a' and 'b'
    int m = min(a, b);

    cout << "m is " << m << endl;;
}

//-------------------------------------------------------------------------
void increment(int x);
void use_increment() {
    int a = 5;
    increment(a);
    cout << "a: " << a << endl;
    // a will still be 5 here.
}

//-------------------------------------------------------------------------
void increment_2(int &x);
void use_increment_2() {
    int a = 5;
    increment_2(a);
    cout << "a: " << a << endl;
    // a will still be 5 here.
}

//-------------------------------------------------------------------------
void increment_3(int *x);
void use_increment_3() {
    int a = 5;
    increment_3(&a);
    cout << "a: " << a << endl;
    // a will be 6 here.
}

//-------------------------------------------------------------------------
void printValue(const int &x);
void use_const_pass_by_reference() {
    int a = 5;
    printValue(a);
    cout << "a: " << a << endl;
}

//-------------------------------------------------------------------------
void printArray(int[], int);
void use_array_1() {
    int myArray[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    printArray(myArray, arraySize);
}

//-------------------------------------------------------------------------
void printArray_2(int* arr, int size);
void use_array_2() {
    int myArray[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    printArray_2(myArray, arraySize);
}

//-------------------------------------------------------------------------
void printArray(std::array<int, 5>& arr);
void use_array_3() {
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};

    printArray(myArray);

}

//-------------------------------------------------------------------------
class Cal {
public:
    static int add(int a, int b) { return a + b; }
    static int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

void use_of_overloading_functions_1() {
    Cal C; // class object declaration.
    cout << C.add(10, 20) << endl;
    cout << C.add(12, 20, 23)<< endl;;
}

//-------------------------------------------------------------------------
int mul(int, int);
float mul(float, int);
void use_of_overloading_functions_2() {
    int r1 = mul(6, 7);
    float r2 = mul(0.2f, 3); // f veya double olarak belirtmek daha iyi olucaktır
    cout << "r1 is : " << r1 << endl;
    cout << "r2 is : " << r2 << endl;
}

//-------------------------------------------------------------------------
void compare(int a, int b, int* add_great, int* add_small) {
    if (a > b) {
 
        // a is stored in the address pointed
        // by the pointer variable *add_great
        *add_great = a;
        *add_small = b;
    }
    else {
        *add_great = b;
        *add_small = a;
    }
}

void use_of_multiple_retuen_1() {
    int great, small, x, y;
 
    x = 5;
    y = 8;
 
    // The last two arguments are passed
    // by giving addresses of memory locations
    compare(x, y, &great, &small);
    cout << "\nThe greater number is " << great << " and the smaller number is " << small << endl;;
}

//-------------------------------------------------------------------------
struct greaterSmaller {
    int greater, smaller;
};
 
typedef struct greaterSmaller Struct;
 
Struct findGreaterSmaller(int a, int b)
{
    Struct s;
    if (a > b) {
        s.greater = a;
        s.smaller = b;
    }
    else {
        s.greater = b;
        s.smaller = a;
    }
 
    return s;
}

void use_of_multiple_retuen_2() {
    int x, y;
    Struct result;
 
    x = 5;
    y = 10;
 
    result = findGreaterSmaller(x, y);
    printf("\nThe greater number is %d and the"
           "smaller number is %d\n",
           result.greater, result.smaller);
}

//-------------------------------------------------------------------------
// Store the greater element at 0th index
void findGreaterSmaller(int a, int b, int arr[])
{
 
    // Store the greater element at
    // 0th index of the array
    if (a > b) {
        arr[0] = a;
        arr[1] = b;
    }
    else {
        arr[0] = b;
        arr[1] = a;
    }
}

void use_of_multiple_retuen_3() {
    int x, y;
    int arr[2];
 
    x = 4;
    y = 3;
    
    findGreaterSmaller(x, y, arr);
 
    cout << "\nThe greater number is " << arr[0]  << " and the "
           "smaller number is " << arr[1] << endl;;
}
//-------------------------------------------------------------------------
tuple <int, int> findGreaterSmaller_1(int a, int b)
{
    if (a < b) {
    return make_tuple(a, b);
    }
    else {
    return make_tuple(b, a);
    }
}

void use_of_multiple_retuen_5() {
    int x = 5, y= 8;
    int max, min;
    tie(min, max) = findGreaterSmaller_1(x, y);
 
    printf("The greater number is %d and the "
        "smaller number is %d\n",
        max, min);
}


//-------------------------------------------------------------------------
void calculateSumAndProduct(int a, int b, int* sumResult, int* productResult) {
    *sumResult = a + b;       // Store sum in sumResult pointer
    *productResult = a * b;   // Store product in productResult pointer
}

void use_of_multiple_retuen_6() {
    int x = 5, y = 3;
    int sum, product;

    // Call the function and pass pointers to sum and product variables
    calculateSumAndProduct(x, y, &sum, &product);

    // Display the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;
}

//-------------------------------------------------------------------------
// Fonksiyon, dinamik olarak oluşturulan bir dizi (array) döndürür
int* createArray(int size) {
    // Bellekten 'size' uzunluğunda bir dizi için alan tahsis edilir
    int* array = new int[size]; //bellekten alan ayırmadan döndüremeyiz parametre olarak pointer alsaydık o zaman alan ayırmamıza gerek kalmazdı çünkü zaten alanı ayrılmış bir veri geliyor

    // Dizi elemanlarına başlangıç değerleri atanabilir (örneğin sıfırlarla)
    for (int i = 0; i < size; ++i) {
        array[i] = 0;
    }

    // Oluşturulan dizinin başlangıç adresi geri döndürülür
    return array;
}

// Dinamik olarak oluşturulan dizinin belleğini temizlemek için kullanılacak fonksiyon
void deleteArray(int* array) {
    // Oluşturulan dizinin belleği serbest bırakılır
    delete[] array;
}

void use_of_return_array() {
    const int size = 5;

    // createArray fonksiyonunu kullanarak dinamik olarak bir dizi oluşturulur
    int* myArray = createArray(size);

    // Oluşturulan dizinin elemanlarına erişim sağlanabilir
    std::cout << "Array Contents:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Oluşturulan dizinin belleği temizlenir (serbest bırakılır)
    deleteArray(myArray);
}

//-------------------------------------------------------------------------
int sum(int x, int y, int z = 0, int w = 0) //assigning default values to z,w as 0
{
    return (x + y + z + w);
}

void use_of_default_parameters() {
    // Statement 1
    cout << sum(10, 15) << endl;
   
    // Statement 2
    cout << sum(10, 15, 25) << endl;
   
    // Statement 3
    cout << sum(10, 15, 25, 30) << endl;
}

//-------------------------------------------------------------------------
class A {
    private:
        int var = 0;
    public:
        A(int x = 0) {
        var = x;
        }   
                                
        void setVar(int s){
            var = s; // OR => this->var = s;
            return;
        }
        int getVar(){
            return var; // OR => return this->var;
        }
};
void use_of_default_parameters_2() {
    A a;

    cout << "var = " << a.getVar() << endl;
 
    A a_1(1);
    cout << "var = " << a_1.getVar() << endl;

    A *a_2 = new A(1);
 
    a_2->setVar(2);
 
    cout << "var = " << a_2->getVar() << endl;
    
}

//-------------------------------------------------------------------------
// Inline olarak tanımlanan fonksiyon
inline int add(int a, int b) {
    return a + b;
}
void use_of_inline() {
    int x = 10, y = 20;
    int result = add(x, y); // Fonksiyon çağrısı

    std::cout << "Result: " << result << std::endl;
}

//-------------------------------------------------------------------------
void lambda_ex_1() {
    int x = 10;
    int y = 20;

    // Boş yakalama listesi
    auto lambda = []() {
        return 42; // Sadece yerel değişkenlere erişim yok
    };

    std::cout << "Result: " << lambda() << std::endl;
}

//-------------------------------------------------------------------------
void lambda_ex_2() {
    int x = 10;
    int y = 20;

    // Değişken referans yakalama
    auto lambda = [&]() {
        x *= 2; // x, referans yoluyla erişilir ve değiştirilebilir
        return x + y;
    };

    std::cout << "Result: " << lambda() << std::endl;
}
//-------------------------------------------------------------------------
void lambda_ex_3() {
    int x = 10;
    int y = 20;

    // Değişken kopyalama yakalama
    auto lambda = [=]() {
        return x + y; // x ve y, kopyalama yoluyla erişilir
    };

    std::cout << "Result: " << lambda() << std::endl;
}
//-------------------------------------------------------------------------
void lambda_ex_4() {
    int x = 10;
    int y = 20;

    // Belirli değişken yakalama
    auto lambda = [x, &y]() {
        y *= 2; // y, referans yoluyla erişilir ve değiştirilebilir
        return x + y;
    };

    std::cout << "Result: " << lambda() << std::endl;
}

class MyClass {
public:
    MyClass(int value) : x(value) {}

    int getValue() const {
        return x;
    }

    void testLambda() {
        // `this` kullanarak sınıfın üye fonksiyonlarına erişim
        auto lambda = [this]() {
            return getValue() * 2;
        };

        std::cout << "Result: " << lambda() << std::endl;
    }

private:
    int x;
};

void lambda_ex_5() {
    MyClass obj(10);
    obj.testLambda();
}

int main() {   
    cout << "Basic Function ----------------------------------------\n";
    use_max();

    cout << "Basic Function Prototype ----------------------------------------\n";
    use_min();

    cout << "Pass by Value ----------------------------------------\n";
    use_increment();

    cout << "Pass by Reference ----------------------------------------\n";
    use_increment_2();

    cout << "Pass by Pointer ----------------------------------------\n";
    use_increment_3();

    cout << "Pass by Const Reference ----------------------------------------\n";
    use_const_pass_by_reference();

    cout << "Print Array-1 ----------------------------------------\n";
    use_array_1();

    cout << "Print Array-2 ----------------------------------------\n";
    use_array_2();

    cout << "Print Array-3 ----------------------------------------\n";
    use_array_3();

    cout << "Overolading Functions 1 ----------------------------------------\n";
    use_of_overloading_functions_1();

    cout << "Overloading Functions 2 ----------------------------------------\n";
    use_of_overloading_functions_2();

    cout << "Multiple return Functions 1 ----------------------------------------\n";
    use_of_multiple_retuen_1();

    cout << "Multiple return Functions 2 ----------------------------------------\n";
    use_of_multiple_retuen_2();

    cout << "Multiple return Functions 3 ----------------------------------------\n";
    use_of_multiple_retuen_3();

    cout << "Multiple return Functions 5 ----------------------------------------\n";
    use_of_multiple_retuen_5();

    cout << "Multiple return Functions 6 ----------------------------------------\n";
    use_of_multiple_retuen_6();

    cout << "Returning array ----------------------------------------\n";
    use_of_return_array();

    cout << "Default Parameters 1 ----------------------------------------\n";
    use_of_default_parameters();

    cout << "Default Parameters 2 ----------------------------------------\n";
    use_of_default_parameters_2();

    cout << "inline ----------------------------------------\n";
    use_of_inline();

    cout << "lambda 1 ----------------------------------------\n";
    lambda_ex_1();

    cout << "lambda 2 ----------------------------------------\n";
    lambda_ex_2();

    cout << "lambda 3 ----------------------------------------\n";
    lambda_ex_3();

    cout << "lambda 4 ----------------------------------------\n";
    lambda_ex_4();

    cout << "lambda 5 ----------------------------------------\n";
    lambda_ex_5();
    return 0;
}

//-------------------------------------------------------------------------
int min(int x, int y){
    if (x < y)
        return x;
    else
        return y;
};

//-------------------------------------------------------------------------
void increment(int x) {
    x = x + 1;
    // This change will not affect the original argument.
}

//-------------------------------------------------------------------------
void increment_2(int &x) {
    x = x + 1;
    // This change will affect the original argument.
}

//-------------------------------------------------------------------------
void increment_3(int *x) {
if (x) {
    *x = *x + 1;
    }
}

//-------------------------------------------------------------------------
void printValue(const int &x) {
    std::cout << "Value: " << x << std::endl;
    // x cannot be modified here.
}

//-------------------------------------------------------------------------
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//-------------------------------------------------------------------------
void printArray_2(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
//-------------------------------------------------------------------------
void printArray(std::array<int, 5>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

//-------------------------------------------------------------------------
int mul(int a, int b) { return a * b; }
float mul(float x, int y) { return x * y; }