# Functions

**Content**
- [Function](#function)
- [Why Do We Need Functions?](#why-do-we-need-functions)
- [Function Declaration](#function-declaration)
- [Types of Functions](#types-of-functions)
- [Parameter Passing to Functions](#parameter-passing-to-functions)
- [Points to Remember About Functions](#points-to-remember-about-functions)
- [Recursion](#recursion)
- [Main Function ](#main-function)
- [Passing Array to Function](#passing-array-to-function)
- [Overloading Function](#overloading-function)
- [Function Overloading and Ambiguity](#function-overloading-and-ambiguity)
- [Friend Function](#friend-function)
- [return statement](#return-statement)
- [Default Arguments](#default-arguments)
- [Inline Functions](#inline-functions)
- [lambda expression](#lambda-expression)

## Function
- A function is a set of statements that takes input, does some specific computation, and produces output. The idea is to put some commonly or repeatedly done tasks together to make a function so that instead of writing the same code again and again for different inputs, we can call this function. In simple terms, a function is a block of code that runs only when it is called.

    ```cpp
    // C++ Program to demonstrate working of a function
    #include <iostream>
    using namespace std;
    
    // Following function that takes two parameters 'x' and 'y'
    // as input and returns max of two input numbers
    int max(int x, int y)
    {
        if (x > y)
            return x;
        else
            return y;
    }
    
    // main function that doesn't receive any parameter and
    // returns integer
    int main()
    {
        int a = 10, b = 20;
    
        // Calling above function to find max of 'a' and 'b'
        int m = max(a, b);
    
        cout << "m is " << m;
        return 0;
    }
    ```
## Why Do We Need Functions? 
- Functions help us in reducing code redundancy. If functionality is performed at multiple places in software, then rather than writing the same code, again and again, we create a function and call it everywhere. This also helps in maintenance as we have to make changes in only one place if we make changes to the functionality in future.
- Functions make code modular. Consider a big file having many lines of code. It becomes really simple to read and use the code,  if the code is divided into functions.
- Functions provide abstraction. For example, we can use library functions without worrying about their internal work.

## Function Declaration
- function prototype ile aynı şey
- A function declaration tells the compiler about the number of parameters, data types of parameters, and returns type of function. Writing parameter names in the function declaration is optional but it is necessary to put them in the definition. Below is an example of function declarations. (parameter names are not present in the below declarations) 
    ```cpp
    // C++ Program to show function that takes
    // two integers as parameters and returns
    // an integer
    int max(int, int);
    
    // A function that takes an int
    // pointer and an int variable
    // as parameters and returns
    // a pointer of type int
    int* swap(int*, int);
    
    // A function that takes
    // a char as parameter and
    // returns a reference variable
    char* call(char b);
    
    // A function that takes a
    // char and an int as parameters
    // and returns an integer
    int fun(char, int);
    ```
## Types of Functions
- **User Defined Function**: are user/customer-defined blocks of code specially customized to reduce the complexity of big programs. They are also commonly known as “tailor-made functions” which are built only to satisfy the condition in which the user is facing issues meanwhile reducing the complexity of the whole program.

- **Library Function**: Library functions are also called “built-in Functions“. These functions are part of a compiler package that is already defined and consists of a special function with special and different meanings. Built-in Function gives us an edge as we can directly use them without defining them whereas in the user-defined function we have to declare and define a function before using them. For Example: sqrt(), setw(), strcat(), etc.

## Parameter Passing to Functions
- The parameters passed to the function are called actual parameters. For example, in the program below, 5 and 10 are actual parameters. 
- The parameters received by the function are called formal parameters. For example, in the above program x and y are formal parameters. 

### There are three most popular ways to pass parameters
1. **Pass by Value**: This is the simplest and often default way of passing parameters. When a parameter is passed by value, the function receives a copy of the argument, and any modifications to the parameter inside the function do not affect the original argument.
    ```cpp
    void increment(int x) {
        x = x + 1;
        // This change will not affect the original argument.
    }

    int main() {
        int a = 5;
        increment(a);
        // a will still be 5 here.
    }
    ```
2. **Pass by Reference**: When a parameter is passed by reference, the function receives a reference (alias) to the argument. Any changes to the parameter affect the original argument. This method is used when you want the function to modify the original data or when you want to avoid copying large data structures.
- bir değişkenin referansını parametre olarak alırsa, bu değişkenin orijinaline erişim sağlar. Referans ile parametre geçme, aslında değişkenin bellek adresini fonksiyona ileterek çalışır. Bu nedenle fonksiyon içinde referans parametre ile yapılan değişiklikler, orijinal değişkene yansır.
- Fonksiyon çağrısı yapılırken, değişkenin adı veya ifadesi ile birlikte fonksiyon adı kullanılır. Bu, değişkenin referansının fonksiyona iletilmesini sağlar.
    ```cpp
    void increment(int &x) {
        x = x + 1;
        // This change will affect the original argument.
    }

    int main() {
        int a = 5;
        increment(a);
        // a will be 6 here.
    }
    ```
3. **Pass by Pointer**: Passing by pointer is similar to passing by reference in that changes to the pointed-to data within the function affect the original data. This method is used for legacy reasons, to handle arrays (since arrays decay to pointers when passed to functions), or when nullability needs to be represented 
- pointers can be null, references cannot.
    ```cpp
    void increment(int *x) {
    if (x) {
        *x = *x + 1;
        }
    }

    int main() {
        int a = 5;
        increment(&a);
        // a will be 6 here.
    }
    ```
### Difference pass by Reference and Pass by Pointer
- Benzerlikler
    - Ortak Amaç: Hem "pass by reference" hem de "pass by pointer", bir fonksiyona değişkenin orijinalini ileterek, değişkenin değerini fonksiyon içinde değiştirmeyi sağlar.
    - Veri Paylaşımı: Her iki yaklaşım da fonksiyonlar arasında veri paylaşımını ve etkileşimi sağlar.
    - Her ikisi de bir fonksiyona değişkenin adresini ileterek, fonksiyonun orijinal değişken üzerinde değişiklik yapmasını sağlar. Ancak aralarında bazı önemli farklar bulunmaktadır.
- Farklar
    - Semantik Farklılıklar:
        - Pass by Reference: Referans ile parametre geçme, dilin sağladığı özel bir dil özelliğidir. Referanslar, bir değişkenin başka bir adı olarak görülür ve işlev çağrısında değişkenin kendisi ile çalışılır.
        - Pass by Pointer: İşaretçiler (pointers), değişkenin bellek adresini tutar ve bu adres üzerinden değişkenin değerine erişilir.
- Dil Özellikleri:
    - Pass by Reference: C++ dilinde özgün bir özelliktir. Referanslar, işaretçilerin daha okunaklı ve güvenli bir alternatifidir.
    - Pass by Pointer: C ve C++ dillerinde kullanılabilir. İşaretçiler daha genel amaçlıdır ve daha düşük seviyeli bellek manipülasyonlarına izin verir.
- Null İşaretçi (Null Pointer) Kullanımı:
    - Pass by Reference: Referanslar, null değerini alamazlar. Dolayısıyla, işlevlere geçirilen referans parametreler her zaman geçerli bir değişkeni temsil eder.
    - Pass by Pointer: İşaretçiler null değerini alabilirler. Bu nedenle, işlevlere geçirilen işaretçi parametreleri, işlevin geçerli bir değişkeni temsil edip etmediğini kontrol etmelidir.
- C++ Tercihi: C++ dilinde, genellikle "pass by reference" kullanımı tavsiye edilir. Referanslar, işaretçilere kıyasla daha güvenli ve okunabilir bir kod sağlar.

- C Dilinde: C dilinde ise, işaretçiler daha yaygın olarak kullanılır. Ancak C dilinde de referans benzeri işlevsellikler sağlayacak teknikler bulunmaktadır.
        

4. **Pass by Const Reference**: When you want to avoid making a copy of the parameter and do not intend to modify it, you can pass it by const reference. This ensures efficiency and also guarantees that the function will not alter the argument.
    ```cpp
    void printValue(const int &x) {
        std::cout << "Value: " << x << std::endl;
        // x cannot be modified here.
    }

    int main() {
        int a = 5;
        printValue(a);
        // a is safely passed without being modified.
    }
    ```
5. **Pass by Const Pointer**: 
- **Pointerin işaret ettiği değerin** değişmesini engellemek için const anahtar kelimesi pointer tipinin önüne yazılır:
    ```cpp
    void function(const int *ptr) {
        // ptr'nin işaret ettiği değeri değiştirmeye çalışmak derleme hatası verir
        // *ptr = 10; // Bu satır hata verir

        // Ancak ptr'nin kendisini değiştirebilirsiniz
        int anotherValue = 20;
        ptr = &anotherValue; // Bu geçerli bir işlemdir
    }

    int main() {
        int value = 5;
        function(&value);
        return 0;
    }
    ```
    Bu örnekte const int *ptr, pointerin işaret ettiği değerin (*ptr) değiştirilemeyeceği anlamına gelir. Ancak, pointerin kendisi (ptr) değiştirilebilir.
- **Pointerin Kendisi Değişmesin**
    ```cpp
    void function(int *const ptr) {
        // ptr'nin işaret ettiği değeri değiştirebilirsiniz
        *ptr = 10; // Bu geçerli bir işlemdir

        // Ancak ptr'nin kendisini değiştirmeye çalışmak derleme hatası verir
        // int anotherValue = 20;
        // ptr = &anotherValue; // Bu satır hata verir
    }

    int main() {
        int value = 5;
        function(&value);
        return 0;
    }
    ```
    Bu örnekte int *const ptr, pointerin kendisinin (ptr) değiştirilemeyeceği anlamına gelir. Ancak, pointerin işaret ettiği değer (*ptr) değiştirilebilir.
- **Hem Pointerin Kendisi Hem de İşaret Ettiği Değer Değişmesin**
    ```cpp
    void function(const int *const ptr) {
        // ptr'nin işaret ettiği değeri değiştirmeye çalışmak derleme hatası verir
        // *ptr = 10; // Bu satır hata verir

        // ptr'nin kendisini değiştirmeye çalışmak da derleme hatası verir
        // int anotherValue = 20;
        // ptr = &anotherValue; // Bu satır da hata verir
    }

    int main() {
        int value = 5;
        function(&value);
        return 0;
    }
    ```
    Bu durumda, const int *const ptr ifadesi, pointerin kendisinin de işaret ettiği değerin de değiştirilemeyeceği anlamına gelir.

- Özet
    - const int *ptr: Pointerin işaret ettiği değer değiştirilemez, pointerin kendisi değiştirilebilir.
    - int *const ptr: Pointerin kendisi değiştirilemez, pointerin işaret ettiği değer değiştirilebilir.
    - const int *const ptr: Hem pointerin kendisi hem de işaret ettiği değer değiştirilemez.
6. **Passing by R-value Reference (C++11 onwards)**: Used primarily in moving semantics and perfect forwarding scenarios. This method allows a function to take ownership of a temporary object without copying it.
    ```cpp
    void process(std::string &&str) {
        std::cout << str << std::endl;
        // str can be modified or moved without affecting the original, since it owns the temporary.
    }

    int main() {
        process(std::string("Hello"));
        // Temporary string "Hello" is moved into process.
    }
    ```

- Summary, Each of these methods has its use cases:

    - Pass by value: Use when the function does not need to modify the input and the value is small.
    - Pass by reference: Use when the function needs to modify the input or avoid costly copies of large objects.
    - Pass by pointer: Use when nullability is a factor, or for legacy code interfacing.
    - Pass by const reference: Use when passing large objects that should not be modified.
    - Pass by r-value reference: Use in advanced scenarios involving move semantics or perfect forwarding.
    - Choosing the correct method for passing parameters can greatly affect the performance, safety, and clarity of your code.

## Points to Remember About Functions
- Most C++ program has a function called main() that is called by the operating system when a user runs the program. 
- Every function has a return type. If a function doesn’t return any value, then void is used as a return type. Moreover, if the return type of the function is void, we still can use the return statement in the body of the function definition by not specifying any constant, variable, etc. with it, by only mentioning the ‘return;’ statement which would symbolize the termination of the function as shown below: 
    ```cpp
    void function name(int a)
    {
        ....... // Function Body
            return; // Function execution would get terminated
    }
    ```
- To declare a function that can only be called without any parameter, we should use “void fun(void)“. As a side note, in C++, an empty list means a function can only be called without any parameter. In C++, both void fun() and void fun(void) are same.

## Main Function 
- Without parameters:
    ```cpp
    int main() { ... return 0; }
    ```
- With parameters:
    ```cpp
    int main(int argc, char* const argv[]) { ... return 0; }
    ```
    - The reason for having the parameter option for the main function is to allow input from the command line. When you use the main function with parameters, it saves every group of characters (separated by a space) after the program name as elements in an array named argv. 
    - Since the main function has the return type of int, the programmer must always have a return statement in the code. The number that is returned is used to inform the calling program what the result of the program’s execution was. Returning 0 signals that there were no problems.
### Arguments
- We can give arguments to our program. Main function takes two argument. 
    ```cpp
    int main(int argc, char *argv[])
    {    
        return 0;
    }
    ```
- The first argument is count of given arguments on cli.
- The second argument is real arguments. the first one is program's name other ones other arguments.
- we can run this program like below.
    ```
    gcc -c main.c
    gcc -o main main.o
    ./main(argument one) 6(argument two)
    ```

## Recursion
- When function is called within the same function, it is known as recursion in C++. The function which calls the same function, is known as recursive function.
A function that calls itself, and doesn’t perform any task after function call, is known as tail recursion. In tail recursion, we generally call the same function with return statement.
```cpp
recursionfunction()
{
    recursionfunction(); // calling self function
}
```

## Passing Array to Function
- In C++, to reuse the array logic, we can create a function. To pass an array to a function in C++,  we need to provide only the array name.
    ```cpp
    //function_name(array_name[]); //passing array to function
    #include <iostream>
    using namespace std;
    void printMin(int arr[5]);
    int main()
    {
        int ar[5] = { 30, 10, 20, 40, 50 };
        printMin(ar); // passing array to function
    }
    void printMin(int arr[5])
    {
        int min = arr[0];
        for (int i = 0; i < 5; i++) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        cout << "Minimum element is: " << min << "\n";
    }
    
    // Minimum element is: 10
    ```

## Overloading Function
- If we create two or more members having the same name but different in number or type of parameters, it is known as C++ overloading. In C++, we can overload.
    - methods,
    - constructors
    - indexed properties
- Types of overloading in C++ are:
    - Function overloading
    - Operator overloading
### C++ Function Overloading
- Function Overloading is defined as the process of having two or more functions with the same name, but different parameters. In function overloading, the function is redefined by using either different types or number of arguments. It is only through these differences a compiler can differentiate between the functions.
- The advantage of Function overloading is that it increases the readability of the program because you don’t need to use different names for the same action.
    ```cpp
    // program of function overloading when number of arguments
    // vary
    #include <iostream>
    using namespace std;
    class Cal {
    public:
        static int add(int a, int b) { return a + b; }
        static int add(int a, int b, int c)
        {
            return a + b + c;
        }
    };
    int main(void)
    {
        Cal C; // class object declaration.
        cout << C.add(10, 20) << endl;
        cout << C.add(12, 20, 23);
        return 0;
    }
    ```
    ```cpp
    // Program of function overloading with different types of
    // arguments.
    #include <iostream>
    using namespace std;
    int mul(int, int);
    float mul(float, int);
    
    int mul(int a, int b) { return a * b; }
    float mul(double x, int y) { return x * y; }
    int main()
    {
        int r1 = mul(6, 7);
        float r2 = mul(0.2, 3);
        cout << "r1 is : " << r1 << endl;
        cout << "r2 is : " << r2 << endl;
        return 0;
    }
    ```

## Function Overloading and Ambiguity
- When the compiler is unable to decide which function is to be invoked among the overloaded function, this situation is known as function overloading ambiguity. When the compiler shows the ambiguity error, the compiler does not run the program.
- Causes of Ambiguity:
    - Type Conversion.
    - Function with default arguments.
    - Function with pass-by-reference.

    ```cpp
    #include <iostream>
    using namespace std;
    void fun(int);
    void fun(float);
    void fun(int i) { cout << "Value of i is : " << i << endl; }
    void fun(float j) {
        cout << "Value of j is : " << j << endl;
    }
    int main() {
        fun(12);
        fun(1.2);
        return 0;
    }
    ```
    - The above example shows an error “call of overloaded ‘fun(double)’ is ambiguous“. The fun(10) will call the first function. The fun(1.2) calls the second function according to our prediction. But, this does not refer to any function as in C++, all the floating point constants are treated as double not as a float. If we replace float to double, the program works. Therefore, this is a type conversion from float to double.
    ```cpp
    #include <iostream>
    using namespace std;

    void fun(int i) {
        cout << "Value of i is : " << i << endl;
    }

    void fun(float j) {
        cout << "Value of j is : " << j << endl;
    }

    void fun(double k) {
        cout << "Value of k is : " << k << endl;
    }

    int main() {
        fun(12);    // int türünde argüman
        fun(1.2f);  // float türünde argüman
        fun(1.2);   // double türünde argüman
        return 0;
    }
    ```
    ```cpp
    #include <iostream>
    using namespace std;
    void fun(int);
    void fun(int, int);
    void fun(int i) { cout << "Value of i is : " << i << endl; }
    void fun(int a, int b = 9)
    {
        cout << "Value of a is : " << a << endl;
        cout << "Value of b is : " << b << endl;
    }
    int main()
    {
        fun(12);
    
        return 0;
    }
    ```
    - The above example shows an error “call of overloaded ‘fun(int)’ is ambiguous“. The fun(int a, int b=9) can be called in two ways: first is by calling the function with one argument, i.e., fun(12) and another way is calling the function with two arguments, i.e., fun(4,5). The fun(int i) function is invoked with one argument. Therefore, the compiler could not be able to select among fun(int i) and fun(int a,int b=9).

- Function with Pass By Reference

    ```cpp
    #include <iostream>
    using namespace std;
    void fun(int);
    void fun(int&);
    int main()
    {
        int a = 10;
        fun(a); // error, which fun()?
        return 0;
    }
    void fun(int x) { cout << "Value of x is : " << x << endl; }
    void fun(int& b)
    {
        cout << "Value of b is : " << b << endl;
    }
    ```
- The above example shows an error “call of overloaded ‘fun(int&)’ is ambiguous“. The first function takes one integer argument and the second function takes a reference parameter as an argument. In this case, the compiler does not know which function is needed by the user as there is no syntactical difference between the fun(int) and fun(int &).

## Friend Function
- friend ile ilgili olan dosyaları incele
- A friend function is a special function in C++ which in spite of not being a member function of a class has the privilege to access private and protected data of a class.
- A friend function is a non-member function or an ordinary function of a class, which is declared by using the keyword “friend” inside the class. By declaring a function as a friend, all the access permissions are given to the function.
- The keyword “friend” is placed only in the function declaration but not in the function definition.
- When the friend function is called neither the name of the object nor the dot operator is used. However, it may accept the object as an argument whose value it wants to access.
- A friend function can be declared in any section of the class i.e. public, private, or protected.

    ```cpp
    /*
    class <class_name> {    
            friend  <return_type>  <function_name>(argument/s);
    };
    */

    #include <iostream>
    using namespace std;
    class Largest {
        int a, b, m;
    
    public:
        void set_data();
        friend void find_max(Largest);
    };
    
    void Largest::set_data()
    {
        cout << "Enter the first number : ";
        cin >> a;
        cout << "\nEnter the second number : ";
        cin >> b;
    }
    
    void find_max(Largest t)
    {
        if (t.a > t.b)
            t.m = t.a;
        else
            t.m = t.b;
    
        cout << "\nLargest number is " << t.m;
    }
    
    int main()
    {
        Largest l;
        l.set_data();
        find_max(l);
        return 0;
    }
    //Enter the first number : 789
    //Enter the second number : 982
    //Largest number is 982
    ```
### Türkçe
- C++ programlama dilinde friend anahtar kelimesi, bir fonksiyonun veya sınıfın, başka bir sınıfın private veya protected üyelerine erişim izni kazanmasını sağlar. friend fonksiyonları sınıfın üye fonksiyonları değildir; bunun yerine sınıf dışında tanımlanan normal fonksiyonlardır. Bu fonksiyonlar, ilgili sınıfın private veya protected üyelerine doğrudan erişebilir.
    - friend fonksiyonu, sınıfın private ve protected üyelerine erişim izni kazanır.
    - friend fonksiyonu, sınıfın üye fonksiyonu değildir; yani sınıfın içinde tanımlanmaz.
    - friend fonksiyonları, sınıfın private veya protected üyelerine erişmek için friend olarak tanımlanmış bir sınıfın bir üyesi olarak davranır.
    - ilişkili Sınıflar Arasında Veri Paylaşımı:
        - İki sınıf arasında doğrudan veri paylaşımı veya işbirliği gerekiyorsa, bu durumda sınıfın private üyelerine erişim sağlamak için friend fonksiyonları kullanılabilir.
        - Örneğin, bir sınıfın içindeki verileri başka bir sınıfın içinde kullanmanız gerekiyorsa ve bu verilere sınıfın dışından erişmek istiyorsanız, friend fonksiyonları kullanılabilir.
    - Operatör Overloading:
        - Operatör aşırı yükleme (operator overloading) durumlarında, sınıfın private veya protected üyelerine erişim sağlamak için friend fonksiyonları kullanılabilir.
        - Örneğin, << veya >> gibi operatörlerin sınıf üyelerine erişmesi gerekiyorsa, bu operatörlerin friend fonksiyonlar olarak tanımlanması yaygın bir uygulamadır.
    - Yardımcı Fonksiyonlar:
        - Sınıfın iç işleyişi için özel durumlar veya yardımcı işlevler oluşturmanız gerekiyorsa, bu fonksiyonları friend olarak tanımlayabilirsiniz.
        - Örneğin, sınıfın private verilerini başka bir sınıfta işlemek için friend fonksiyonlar oluşturabilirsiniz.
    - private veya protected üyelerine erişim sağlayabilir ve bu üyeleri değiştirebilir
    - dikkat
        - friend fonksiyonları, sınıfın kapsülleme prensibini zayıflatabilir ve sınıfın iç yapısını dışarıya açabilir.
        - friend fonksiyonlarını gereksiz yere kullanmak yerine, sınıfın kapsülleme prensibini koruyacak ve sınıf dışından erişimi en aza indirecek tasarımı tercih etmek daha iyidir.
        - friend fonksiyonları, dikkatli ve ihtiyaç doğrultusunda kullanılmalıdır. Sınıfın private veya protected üyelerine doğrudan erişimin gerekliliği durumunda 
    - ENormalde, herhangi bir fonksiyon veya sınıfın dışındaki kod, bir nesnenin private veya protected üyelerine doğrudan erişemez. Ancak, friend fonksiyonlar tanımlandığında, bu fonksiyonlar sınıfın private ve protected üyelerine erişebilir ve onları değiştirebilir.
    - **Note!!!!!** friend fonksiyonu class dosyasında veya main de yazılabilir. definitiondan bashediyorum fonksiyon bodysi hem class dosayının olduğu yerde hemde main dosyada yazılabilir
    - ekstra dosyalar olduğu için bu şekilde derlemelisin
        ```cpp
        g++ -c MyClass.cpp -o MyClass.o
        g++ -c main.cpp -o main.o
        g++ MyClass.o main.o -o program
        ```

## return statement
- The return statement returns the flow of the execution to the function from where it is called. This statement does not mandatorily need any conditional statements. As soon as the statement is executed, the flow of the program stops immediately and returns the control from where it was called. The return statement may or may not return anything for a void function, but for a non-void function, a return value must be returned. 
1. Methods not returning a value
    - In C++ one cannot skip the return statement when the methods are of the return type. The return statement can be skipped only for void types.
    - Not using a return statement in void return type function When a function does not return anything, the void return type is used. So if there is a void return type in the function definition, then there will be no return statement inside that function
    ```cpp
    // C++ code to show not using return 
    // statement in void return type function 
    #include <iostream> 
    using namespace std; 
    
    // void method 
    void Print() 
    { 
        cout << "Welcome to GeeksforGeeks"; 
    } 
    
    // Driver method 
    int main() 
    { 
    
        // Calling print 
        Print(); 
    
        return 0; 
    } 
    //Welcome to GeeksforGeeks
    ```
    - Using the return statement in void return type function Now the question arises, what if there is a return statement inside a void return type function? Since we know that, if there is a void return type in the function definition, then there will be no return statement inside that function. But if there is a return statement inside it, then also there will be no problem
    - This syntax is used in function just as a jump statement in order to break the flow of the function and jump out of it. One can think of it as an alternative to “break statement” to use in functions.

        ```cpp
        // C++ code to show using return 
        // statement in void return type function 
        #include <iostream> 
        using namespace std; 
        
        // void method 
        void Print() 
        { 
            cout << "Welcome to GeekforGeeks"; 
        
            // void method using the return statement 
            return; 
        } 
        
        // Driver method 
        int main() 
        { 
        
            // Calling print 
            Print(); 
            return 0; 
        } 
        ```
2. Multiple Values
    - New programmers are usually in the search of ways to return multiple values from a function. Unfortunately, C and C++ do not allow this directly. But fortunately, with a little bit of clever programming, we can easily achieve this. Below are the methods to return multiple values from a function in C:
        - By using pointers.
        - By using structures.
        - By using Arrays.
        - By using Class.
        - By using Tuples
        - By using Vectors
        - By using static (static and not static bölümünde bunun örneğini görebilirsin)
    1. Returning multiple values Using pointers: Pass the argument with their address and make changes in their value using pointer. So that the values get changed into the original argument.
    2. Returning multiple values using structures : As the structure is a user-defined datatype. The idea is to define a structure with two integer variables and store the greater and smaller values into those variable, then use the values of that structure. int ve string gibi farklı veri tipleri de döndürebilirsin.
    3. Returning multiple values using an array (Works only when returned items are of same types): When an array is passed as an argument then its base address is passed to the function so whatever changes made to the copy of the array, it is changed in the original array. Below is the program to return multiple values using array i.e. store greater value at arr[0] and smaller at arr[1]. 
    4. Returning multiple values using Class and Object : The idea is similar to structures. We create a class with two integer variables and store the greater and smaller values into those variable, then use the values of that structure. 
        ```cpp
        #include <stdio.h>
        
        class GreaterSmaller {
        public:
            int greater, smaller;
        };
        
        GreaterSmaller findGreaterSmaller(int a, int b)
        {
            GreaterSmaller s;
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
        
        // Driver code
        int main()
        {
            int x, y;
            GreaterSmaller result;
        
            printf("Enter two numbers: \n");
            scanf("%d%d", &x, &y);
        
            // The last two arguments are passed
            // by giving addresses of memory locations
            result = findGreaterSmaller(x, y);
            printf("\nThe greater number is %d and the"
                "smaller number is %d",
                result.greater, result.smaller);
        
            return 0;
        }
        ```

    5. Returning multiple values using STL tuple : The idea is similar to structures. We create a tuple with two integer variables and return the tuple, and then inside main function we use tie function to assign values to min and max that is returned by the function. 

3. return array
    -  dynamic array: bir fonksiyon bir dizi (array) döndürebilir. Ancak C++'ta fonksiyonlar doğrudan bir dizi döndüremezler. Bunun yerine, bir fonksiyon bir dizi döndürmek istiyorsa, genellikle dinamik bellek tahsisi yapılır ve bu bellek bloğunun adresi bir pointer aracılığıyla döndürülür. Bu pointer, işaret ettiği bellek bloğunu temsil eden diziye erişim sağlar.

## Default Arguments
1. A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the calling function doesn’t provide a value for the argument. In case any value is passed, the default value is overridden. 
- exp1: 
    - The following is a simple C++ example to demonstrate the use of default arguments. Here, we don’t have to write 3 sum functions; only one function works by using the default values for 3rd and 4th arguments. 
    - In statement 1, only two values are passed, hence the variables z and w take the default values of 0. In statement 2, three values are passed, so the value of z is overridden with 25. In statement 3, four values are passed, so the values of z and w are overridden with 25 and 30 respectively.
2. If function overloading is done containing the default arguments, then we need to make sure it is not ambiguous to the compiler, otherwise it will throw an error. The following is the modified version of the above program:
    ```cpp
    // CPP Program to demonstrate Function overloading in
    // Default Arguments
    #include <iostream>
    using namespace std;
    
    // A function with default arguments, it can be called with
    // 2 arguments or 3 arguments or 4 arguments.
    int sum(int x, int y, int z = 0, int w = 0)
    {
        return (x + y + z + w);
    }
    int sum(int x, int y, float z = 0, float w = 0)
    {
        return (x + y + z + w);
    }
    // Driver Code
    int main()
    {
        cout << sum(10, 15) << endl;
        cout << sum(10, 15, 25) << endl;
        cout << sum(10, 15, 25, 30) << endl;
        return 0;
    }
    /*
    prog.cpp: In function 'int main()':
    prog.cpp:17:20: error: call of overloaded 
    'sum(int, int)' is ambiguous
    cout << sum(10, 15) << endl; 
                        ^
    prog.cpp:6:5: note: candidate: 
    int sum(int, int, int, int)
    int sum(int x, int y, int z=0, int w=0) 
        ^
    prog.cpp:10:5: note: candidate: 
    int sum(int, int, float, float)
    int sum(int x, int y, float z=0, float w=0) 
        ^
    */
    ```

3. A constructor can contain default parameters as well. A default constructor can either have no parameters or parameters with default arguments.
    - exp:
        - Here, we see a default constructor with no arguments and a default constructor with one default argument. The default constructor with argument has a default parameter x, which has been assigned a value of 0. 

### Key Points
- Default arguments are different from constant arguments as constant arguments can’t be changed whereas default arguments can be overwritten if required.
- Default arguments are overwritten when the calling function provides values for them. For example, calling the function sum(10, 15, 25, 30) overwrites the values of z and w to 25 and 30 respectively.
- When a function is called, the arguments are copied from the calling function to the called function in the order left to right. Therefore, sum(10, 15, 25) will assign 10, 15, and 25 to x, y, and z respectively, which means that only the default value of w is used.
- Once a default value is used for an argument in the function definition, all subsequent arguments to it must have a default value as well. It can also be stated that the default arguments are assigned from right to left. For example, the following function definition is invalid as the subsequent argument of the default variable z is not default.
    ```cpp
    // Invalid because z has default value, but w after it doesn't have a default value
    int sum(int x, int y, int z = 0, int w).
    ```

## Inline Functions
- C++ provides inline functions to reduce the function call overhead. An inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of the inline function call. This substitution is performed by the C++ compiler at compile time. An inline function may increase efficiency if it is small.
- C++ dilinde inline fonksiyonlar, derleyiciye fonksiyonun metnini fonksiyon çağrısı yerine doğrudan yerleştirmesi için bir öneri olarak sunan bir özelliktir. Bu, kodun performansını artırabilir ve fonksiyon çağrılarının maliyetini azaltabilir.
- inline fonksiyonlar genellikle kısa ve basit olan fonksiyonlar için kullanılır. Fonksiyonun tanımı genellikle başlık dosyalarında (header files) yer alır, bu nedenle her dosyada tekrar tanımlamaya gerek kalmaz. header de tanımlanır source de tanımlanmaz. her şeyi, header da olur
- exp: 
    - Bu örnekte add fonksiyonu inline olarak tanımlanmıştır. Derleyici, bu fonksiyonu çağrıldığında, kodun doğrudan a + b ifadesiyle değiştirilmesini tercih edebilir. Ancak derleyici bu tercihe uymak zorunda değildir; inline sadece bir öneridir.
- Küçük fonksiyonlar için işlemci belleğinde daha az maliyetli olabilir.
- Fonksiyon çağrısı yerine doğrudan kodun yerleştirilmesi, performansı artırabilir
- Header dosyalarında tanımlanan inline fonksiyonlar, çoklu dosyalar tarafından kullanıldığında, çoklu tanımlama hatasına neden olmaz.
- Ancak inline fonksiyonlar her zaman performans artışı sağlamaz. Derleyicinin bu öneriyi ne kadar uygulayacağı, kodun karmaşıklığına, fonksiyonun boyutuna ve derleyici optimizasyonlarına bağlıdır. Genellikle, fonksiyonun çok sık çağrıldığı ve kısa olduğu durumlarda inline kullanımı daha etkili olabilir.

### Extra about inline
- Normal (Non-Inline) Fonksiyonlar
    - Tekil Tanım: Normal fonksiyonlar, genellikle başlık dosyalarında (header files) prototip olarak tanımlanır ve gerçek tanımları ayrı bir kaynak dosyasında (source file) bulunur. Bu durumda, fonksiyon çağrıldığında derleyici, fonksiyonun gerçek kodunu çağrı yerine ekler.
    - Birlikte Derleme (Linkage): Normal fonksiyonlar, her dosyada farklı kod içerse bile birlikte derleme (linkage) kurallarına uygun olarak birleştirilir.
    - Derleme Zamanı Bağlantısı: Normal fonksiyonlar, derleme zamanında çağrı yerine işlemci koduna dönüştürülür. Fonksiyon çağrısı, çağrıldığı yerden fonksiyonun bulunduğu kaynak dosyasına yönlendirilir.
- inline Fonksiyonlar
    - Çoklu Tanımlama Sorunu: inline fonksiyonlar, başlık dosyasında (header file) tanımlanır ve genellikle aynı dosyada prototip ve gerçek tanımı içerir. Derleyiciye, bu fonksiyonun çağrıldığında direkt olarak yerine geçmesi önerilir.
    - Her Bir Çağrı İçin Kopya Oluşturulabilir: inline fonksiyonlar, her çağrıda direkt kod parçasını kullanarak fonksiyon çağrısını optimize eder. Bu nedenle, fonksiyonun çağrıldığı her yerde bir kopyası oluşturulabilir.
    - Derleme Zamanı Bağlantısı: inline fonksiyonlar, derleme sırasında çağrıldıkları yerde kodlarına dönüştürülür. Yani inline fonksiyon çağrılarının birlikte derlenme (link) kuralları kapsamında olması gerekmez.
- Farklar
    - inline fonksiyonlar, derleyiciye fonksiyonun doğrudan yerine geçmesini önerir ve böylece fonksiyon çağrısı maliyetini azaltır.
    - inline fonksiyonlar, kısa ve sıkça çağrılan fonksiyonlar için kullanışlıdır.
    - inline fonksiyonlar, başlık dosyasında tanımlanırken normal fonksiyonlar ayrı bir kaynak dosyasında tanımlanır.
    - inline fonksiyonların birlikte derleme kuralları farklıdır; her fonksiyon çağrısı için ayrı bir kopya oluşturulabilir.

- Sonuç olarak, inline fonksiyonlar derleyici tarafından optimize edilerek fonksiyon çağrı maliyetini azaltırken, normal fonksiyonlar ayrı tanım ve prototip olarak tanımlanır ve derleme zamanında işlemci koduna dönüştürülerek çağrılır. inline kullanımı, performans ve bellek kullanımı açısından öncelikli olarak düşünülen durumlarda tercih edilir.

## lambda expression
- C++ 11 introduced lambda expressions to allow inline functions which can be used for short snippets of code that are not going to be reused and therefore do not require a name. In their simplest form a lambda expression can be defined as follows: 

- Generally, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify it explicitly. Also the -> return-type part can be ignored.  However, in some complex cases e.g. conditional statements, the compiler can’t determine the return type and explicit specification is required. 

- lambda fonksiyonları C++'ta oldukça kullanışlı ve güçlü bir özelliktir. Lambda fonksiyonları, anonim (isimsiz) isimde olabilir aslında fonksiyonlar oluşturmanıza ve bu fonksiyonları yerinde (inline) olarak kullanmanıza olanak tanır. İşte bir lambda 

- genellikle kullanılcağı scope da yazılır onun haricinde çok işlevsel değil

    ```cpp
    #include <iostream>

    int main() {
        // Lambda fonksiyonunu kullanarak iki sayıyı toplama
        auto add = [](int a, int b) {
            return a + b;
        };

        // Lambda fonksiyonunu çağırma
        int result = add(10, 20);

        std::cout << "Result: " << result << std::endl;

        return 0;
    }
    ```
    - Yukarıdaki örnekte, add adında bir lambda fonksiyonu tanımlanmıştır. Lambda fonksiyonu [ ] arasındaki parametre listesi ile başlar ve { } arasında fonksiyonun gövdesini içerir. Parametre listesi ve gövde arasında => (ok) işareti bulunur. Bu örnekte, add lambda fonksiyonu int türünde a ve b parametrelerini alır ve bu parametrelerin toplamını döndürür.
    - Lambda fonksiyonlarının auto anahtar kelimesiyle tanımlandığına dikkat edin. Bu, C++'ın lambda ifadelerini temsil etmek için kullanılan işlevsel bir özelliktir. Derleyici, lambda fonksiyonunun türünü otomatik olarak çıkartır.
    - Lambda fonksiyonları ayrıca diğer fonksiyonlara parametre olarak veya algoritma fonksiyonları (örneğin std::for_each, std::sort gibi) içinde de kullanılabilir. Ayrıca lambda fonksiyonları, fonksiyon nesneleri (function objects) olarak da kullanılabilir, yani bir değişkene atanabilir veya başka fonksiyonların parametresi olarak kullanılabilir.
    - Lambda fonksiyonları, özellikle basit ve tek seferlik kullanımlar için idealdir. Fonksiyonel programlama yaklaşımını destekleyerek C++ kodunu daha kısa ve anlaşılır hale getirebilirler.

    - Lambda ifadesindeki [ ] kısmı, lambda fonksiyonunun yakalama listesini belirtmek için kullanılır. Yakalama listesi, lambda fonksiyonunun dışındaki değişkenlere erişimini kontrol etmek için kullanılır. Bu bölümde kullanabileceğiniz bazı öğeler şunlardır: 
    - değişkenlerinde türlerini otomatik atar. kendi türü hep auto olmalıdır
        1. Boş Yakalama Listesi ([]):
            - Lambda fonksiyonu dışındaki hiçbir değişkene erişemez. Sadece fonksiyon parametreleri ve kendisine özgü değişkenler kullanılabilir.
        2. Değişken Referans Yakalama ([&]):
            - Tüm değişkenlere referans aracılığıyla erişim sağlar. Değişkenlerin değerleri lambda fonksiyonunda değiştirilebilir.
        3. Değişken Kopyalama Yakalama ([=]):
            - Tüm değişkenlere kopyalama aracılığıyla erişim sağlar. Değişkenlerin değerleri lambda fonksiyonunda değiştirilebilir, ancak orijinal değişkenler değişmez.
        4. Belirli Değişken Yakalama ([x, &y] veya [=, &z]):
            - Belirli değişkenlere referans veya kopyalama aracılığıyla erişim sağlar. Örnek olarak [x, &y] ifadesi, x değişkenine kopyalama yoluyla ve y değişkenine referans yoluyla erişim sağlar.
        5. this Yakalama ([this]):
            - Sınıf üyesi bir lambda fonksiyonunda sınıfın diğer veri elemanlarına erişim sağlamak için kullanılır.