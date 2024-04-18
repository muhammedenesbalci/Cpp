# C++ Basics

## Content

- Basic print.
- 'endl'.
- Variables.
- Variable types.
- Boolean.
- Input.
- Strings.
- Escape sequences.
- Raw Strings.
- 'const' variables.
- Arithmetic Operations.
- Conversion of variables 'static_cast'.
- Increasing and decreasing values.
- Right and left increment difference.
- Compile a cpp file

## Informations

- ***#include*** directive is used to include external files or libraries in your program. It is a preprocessor directive that tells the compiler to insert the contents of another file into the current file at the point where the *#include* directive is used. This allows you to access definitions, declarations, and functionalities from the included files.
- ***iostream*** header is part of the C++ Standard Library and provides input and output functionality. It defines several stream objects, such as cin (for input from the standard input) and cout (for output to the standard output). The iostream header is commonly used for console input and output operations.
	- This is a preprocessor directive. The #include directive tells the compiler to include the content of a file in the source code.
	- For example, #include<iostream> tells the compiler to include the standard iostream file which contains declarations of all the standard input/output library functions. (https://www.geeksforgeeks.org/cc-preprocessors/)
- ***namespace*** is a feature that allows you to group related declarations together and prevent naming conflicts. It provides a way to organize code and avoid naming collisions between different components of a program. To define a namespace in C++, you use the ***namespace*** keyword followed by the desired namespace name. Here's an example:
	```cpp
		// Declaration of a namespace called "myNamespace" namespace  
		myNamespace {  
		// Declarations of classes, functions, variables, etc.  
		// ... 
		}  
	```

  Within the namespace block, you can define classes, functions, variables, and other entities, just like you would outside of a namespace. However, these declarations will be scoped within the namespace, meaning they are only accessible using the namespace name as a prefix.

  To use the entities defined in a namespace, you can either qualify the names explicitly or introduce the entire namespace into your code with the ***using*** directive. Here are examples of both approaches:
	```cpp
		// Qualifying the names explicitly  
		myNamespace::MyClass obj;  
		myNamespace::myFunction();  
		
		// Introducing the entire namespace  
		using namespace myNamespace;  
		
		// Now you can access the entities directly  
		MyClass obj;  
		myFunction()  
	```

  It's important to note that using the ***using*** directive to introduce a namespace can lead to naming conflicts if there are multiple namespaces with the same name or if there are naming clashes with other entities in your code. Therefore, it's generally recommended to use namespace qualifications to maintain clarity and avoid potential issues.

  Remember, namespaces are a way to organize and modularize your code, making it easier to manage and collaborate on large projects.

## Difference Between Variable Declaration and Definition
- The variable declaration refers to the part where a variable is first declared or introduced before its first use. A variable definition is a part where the variable is assigned a memory location and a value. Most of the time, variable declaration and definition are done together.
See the following C++ program for better clarification: 
	```cpp
	/ C++ program to show difference between
	// definition and declaration of a 
	// variable
	#include <iostream>
	using namespace std;
	
	int main()
	{
		// this is declaration of variable a
		int a;
	
		// this is initialisation of a
		a = 10;
	
		// this is definition = declaration + initialisation
		int b = 20;
	
		// declaration and definition
		// of variable 'a123'
		char a123 = 'a';
	
		// This is also both declaration and definition
		// as 'c' is allocated memory and
		// assigned some garbage value.
		float c;
	
		// multiple declarations and definitions
		int _c, _d45, e;
	
		// Let us print a variable
		cout << a123 << endl;
	
		return 0;
	}
	```
## Types of Variables
- look.png open it !!!

- There are three types of variables based on the scope of variables in C++
	- Local Variables
	- Instance Variables
	- Static Variables

1. Local Variables: A variable defined within a block or method or constructor is called a local variable. 
	- These variables are created when entered into the block or the function is called and destroyed after exiting from the block or when the call returns from the function.
	- The scope of these variables exists only within the block in which the variable is declared. i.e. we can access this variable only within that block.
	- Initialization of Local Variable is Mandatory.

2. Instance Variables: Instance variables are non-static variables and are declared in a class outside any method, constructor, or block. 
	- As instance variables are declared in a class, these variables are created when an object of the class is created and destroyed when the object is destroyed.
	- Unlike local variables, we may use access specifiers for instance variables. If we do not specify any access specifier then the default access specifier will be used.
	- Initialization of Instance Variable is not Mandatory.
	- Instance Variable can be accessed only by creating objects.

3. Static Variables: Static variables are also known as Class variables. 
	- These variables are declared similarly as instance variables, the difference is that static variables are declared using the static keyword within a class outside any method constructor or block.
	- Unlike instance variables, we can only have one copy of a static variable per class irrespective of how many objects we create.
	- Static variables are created at the start of program execution and destroyed automatically when execution ends.
	- Initialization of Static Variable is not Mandatory. Its default value is 0
	- If we access the static variable like the Instance variable (through an object), the compiler will show the warning message and it won’t halt the program. The compiler will replace the object name with the class name automatically.
	- If we access the static variable without the class name, the Compiler will automatically append the class name.

- **Instance Variable Vs Static Variable
Each object will have its own copy of the instance variable**
	- Each object will have its own copy of the instance variable whereas We can only have one copy of a static variable per class irrespective of how many objects we create.
	- Changes made in an instance variable using one object will not be reflected in other objects as each object has its own copy of the instance variable. In the case of static, changes will be reflected in other objects as static variables are common to all objects of a class.
	- We can access instance variables through object references and Static Variables can be accessed directly using the class name.
- The syntax for static and instance variables:
	```cpp
	class Example
	{
		static int a; // static variable
		int b;        // instance variable
	}
	```

## Type Modifiers
- Modifiers are used in C++ to change or give extra meaning to already existing data types. It’s added to primitive data types as a prefix to change their meaning. A modifier is used to change the meaning of a basic type so that it better matches the requirements of different circumstances.
	- signed
	- unsigned
	- short
	- long

- signed Modifier
	- Signed variables can store positive, negative integers, and zero.
		```cpp
		signed int a = 45;
		signed int b = -67;
		signed int c = 0;
		```
	- Note: The int datatype is signed by default. So, int can be directly be used instead of signed int.

- unsigned Modifier
	- Unsigned variables can store only non-negative integer values.
		```cpp
		unsigned int a = 9;
		unsigned int b = 0;
		```
- Difference Between Signed and Unsigned Modifiers
	- The signed value of the signed variable is stored in the allocated memory. However, the signed value is not stored by the unsigned variables.
	- The sign takes 1 bit extra. So, if the unsigned value is being used then one-bit extra space is used to save the value of a variable.
	- The range of values for unsigned types starts from 0. For example, for unsigned int, the value range is from 0 to 4,294,967,295. However, for signed int, the value range is from -2,147,483,648 to 2,147,483,647.
	- Note: signed and unsigned modifiers can only be used with int and char datatypes.

- short Modifier
	- The short keyword modifies the minimum values that a data type can hold. It is used for small integers that lie in the range of −32,767 to +32,767
		```cpp
		short int x = 4590;
		```
	- Note: The short int can be written as short also. They are equivalent.

- long Modifier
	- the long keyword modifies the maximum values that a data type can hold. It is used for large integers that are in the range of -2147483647 to 2147483647.
		```cpp
		long int y = 26936;
		``` 
	- Note: The long int can be written as long also. They are equivalent.

### Important Points about Data Type Modifiers
- The modifiers for a data type can be combined.
	- For example, signed/unsigned can be used with long/short modifiers. Below is the C++ program to demonstrate the above concept.
		```cpp
		/ C++ program to demonstrate 
		// that modifiers can be combined
		// together
		#include <iostream>
		using namespace std;
		
		// Driver Code
		int main()
		{
			cout << "Size of signed long int : " << 
					sizeof(signed long int) << 
					" bytes" << endl;
			cout << "Size of unsigned short int : " << 
					sizeof(unsigned short int) << 
					" bytes" << endl;
			return 0;
		}
		```
		```bash
		Size of signed long int : 8 bytes
		Size of unsigned short int : 2 bytes
		```
- The long modifier can be used as twice as long long.
	- It is used for even larger numbers than long. However, long long-type modifiers can only be used with int. Below is the C++ program to demonstrate the above concept.
		```cpp
		/ C++ program to demonstrate 
		// the long long modifier
		#include <iostream>
		using namespace std;
		
		// Driver Code
		int main()
		{
			cout << "Size of long long int : " << 
					sizeof(long long int) << 
					" bytes" << endl;
			return 0;
		}
		```
		```bash
		Size of long long int : 8 bytes
		```
## Type Qualifiers
- Type qualifiers are used to provide more information about a value while also guaranteeing that the data is used correctly.
	1. **const**: Objects of type const cannot be altered during execution. Const objects cannot be modified by your program while it is running.
	2. **volatile**: The modifier volatile tells the compiler that a variable’s value can be changed in ways that are not explicitly defined by the program. The compiler is informed by the modifier volatile that a variable’s value might change in ways that aren’t clearly stated in the program.
		- volatile anahtar kelimesi, C ve C++ programlama dillerinde kullanılan bir nitelik (qualifier) veya belirleyicidir. Bu nitelik, bir değişkenin değerinin programın normal akışı dışında, öngörülemeyen şekillerde değişebileceğini ve bu değişikliklerin derleyici tarafından optimize edilmesini engellediğini belirtir. Yani, volatile kullanılan bir değişkenin değeri, programın beklenen akışı dışında, örneğin donanım veya dış etkenlerden kaynaklı olarak değişebilir.
		- değişkenin Optimizasyonu Engelleme: volatile kullanılan bir değişkenin değeri, derleyici tarafından optimize edilerek bellek veya register içinde tutulabilir. Bu nedenle, bu tür değişkenlerin değerlerine her zaman doğrudan erişmek ve okumak gereklidir.
		- Dışsal Değişikliklere Karşı Hassaslık: volatile değişkenler, programın normal akışı dışında (örneğin donanım veya dışarıdan gelen sinyaller nedeniyle) değişebilecek veriler için kullanılır. Bu değişkenler, derleyicinin bu değişiklikleri göz ardı etmesini engeller.
			```cpp
			#include <iostream>

			int main() {
				volatile int sensorValue = 0;  // Volatile olarak tanımlanan bir değişken

				while (true) {
					// Değişkenin değerini okuma
					std::cout << "Sensor value: " << sensorValue << std::endl;

					// Değişkenin değerini güncelleme (örneğin, dışarıdan gelen bir sinyal)
					sensorValue = readSensor();  // Sensörden yeni veri okunduğunu varsayalım

					// Kısa bir bekleme süresi
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}

				return 0;
			}
			```
		- Yukarıdaki örnekte, sensorValue isimli değişken volatile olarak tanımlanmıştır. Bu değişkenin değeri, programın normal akışı dışında (örneğin, readSensor() fonksiyonu aracılığıyla) değişebilir. Bu durumda, sensorValue değişkeninin her döngüde doğrudan okunması ve güncellenmesi önemlidir.
		- volatile anahtar kelimesi genellikle donanım ile etkileşim gerektiren veya kesme hizmeti (interrupt service) sağlayan programlar, zamanlayıcılar (timers), port işlemleri gibi durumlarda kullanılır. Ancak, modern C++'ta volatile kullanımı yerine std::atomic veya özel senkronizasyon teknikleri (mutex, semaphore gibi) tercih edilmektedir. volatile değişkenlerin yanlış kullanımı, programın doğruluğunu ve taşınabilirliğini etkileyebileceğinden dikkatli bir şekilde kullanılmalıdır.
	3. **restrict**: A pointer qualified by restricting is initially the only means by which the object it points to can be accessed. The object restricts links that can only initially be accessed via a pointer qualified by it. Restrict is a new type of qualifier that is only added in C99.
		- restrict, C ve C++ programlama dillerinde kullanılan bir nitelik (qualifier) veya belirleyicidir. Bu nitelik, bir işaretçinin (pointer) işaret ettiği bellek alanının başka bir işaretçi veya referans tarafından değiştirilmeyeceğini garanti eder. Bu belirleyici, derleyiciye işaretçinin optimize edilmesinde ve bellek erişiminde daha agresif davranmasına izin verir.
		- Bellek Erişimi Optimizasyonu: restrict belirleyicisi, işaretçinin işaret ettiği bellek bloğunun başka işaretçiler veya referanslar tarafından değiştirilmeyeceğini garanti eder. Bu sayede derleyici, işaretçinin eriştiği bellek bloğunu daha etkin bir şekilde optimize edebilir.
		- Bellek Erişimi Güvenliği: restrict kullanımı, programcının derleyiciye veri bağımsızlığı (data aliasing) hakkında bilgi verir. Bu belirleyiciyi kullanan bir işaretçi, aynı bellek bloğunu işaret eden başka işaretçilerle çakışma yaşamaz.
			```cpp
				#include <stdio.h>

				void add_arrays(int* restrict result, const int* restrict arr1, const int* restrict arr2, int size) {
					for (int i = 0; i < size; ++i) {
						result[i] = arr1[i] + arr2[i];
					}
				}

				int main() {
					int arr1[] = {1, 2, 3, 4, 5};
					int arr2[] = {5, 4, 3, 2, 1};
					int result[5];

					add_arrays(result, arr1, arr2, 5);

					printf("Result array: ");
					for (int i = 0; i < 5; ++i) {
						printf("%d ", result[i]);
					}
					printf("\n");

					return 0;
				}
			```
		- Yukarıdaki örnekte, add_arrays fonksiyonunda restrict belirleyicisi kullanılmıştır. Bu belirleyici ile result, arr1 ve arr2 işaretçilerinin aynı bellek bloğunu işaret etmediği garanti edilir. Bu sayede derleyici, bu işaretçilerin bağımsız olarak optimize edilmesini sağlar.
		- restrict belirleyicisi özellikle bellek yoğun uygulamalarda (örneğin, işlemciye yakın programlama, veri işleme gibi) performansı artırmak için kullanılır. Ancak, restrict belirleyicisinin yanlış kullanımı programın doğruluğunu etkileyebilir ve tanımsız davranışlara (undefined behavior) yol açabilir. Bu nedenle, restrict belirleyicisini kullanırken dikkatli olunmalı ve programın gereksinimlerine uygun olarak doğru şekilde kullanılmalıdır.
## Type Conversion
- A type cast is basically a conversion from one type to another. There are two types of type conversion:
	1. Implicit Type Conversion Also known as ‘automatic type conversion’
		- Done by the compiler on its own, without any external trigger from the user.
		- Generally takes place when in an expression more than one data type is present. In such condition type conversion (type promotion) takes place to avoid lose of data.
		- All the data types of the variables are upgraded to the data type of the variable with largest data type.
			```cpp
			bool -> char -> short int -> int -> 

			unsigned int -> long -> unsigned -> 

			long long -> float -> double -> long double

			```
		- It is possible for implicit conversions to lose information, signs can be lost (when signed is implicitly converted to unsigned), and overflow can occur (when long long is implicitly converted to float).
		- Example of Type Implicit Conversion:
			```cpp
			// An example of implicit conversion 
			
			#include <iostream> 
			using namespace std; 
			
			int main() 
			{ 
				int x = 10; // integer x 
				char y = 'a'; // character c 
			
				// y implicitly converted to int. ASCII 
				// value of 'a' is 97 
				x = x + y; 
			
				// x is implicitly converted to float 
				float z = x + 1.0; 
			
				cout << "x = " << x << endl 
					<< "y = " << y << endl 
					<< "z = " << z << endl; 
			
				return 0; 
			} 
			```
			```bash
			x = 107
			y = a
			z = 108
			```
	2. Explicit Type Conversion: This process is also called type casting and it is user-defined. Here the user can typecast the result to make it of a particular data type.
	In C++, it can be done by two ways:
		- Converting by assignment: 
			- This is done by explicitly defining the required type in front of the expression in parenthesis. This can be also considered as forceful casting.

				```cpp
				(type) expression
				```
			- where type indicates the data type to which the final result is converted.
				```cpp
				// C++ program to demonstrate 
				// explicit type casting 
				
				#include <iostream> 
				using namespace std; 
				
				int main() 
				{ 
					double x = 1.2; 
				
					// Explicit conversion from double to int 
					int sum = (int)x + 1; 
				
					cout << "Sum = " << sum; 
				
					return 0; 
				} 
				```
				```bash
				Sum = 2
				```
		- Conversion using Cast operator: A Cast operator is an unary operator which forces one data type to be converted into another data type.
			- Static Cast
				```cpp
				#include <iostream> 
				using namespace std; 
				int main() 
				{ 
					float f = 3.5; 
				
					// using cast operator 
					int b = static_cast<int>(f); 
				
					cout << b; 
				} 
				```
				```
				3
				```
			- Dynamic Cast
				- dynamic_cast operatörü, genellikle runtime'da (çalışma zamanında) tür güvenliği sağlamak için kullanılır. Bu operatör, genellikle bir nesnenin dinamik türünü (runtime'daki gerçek türünü) kontrol etmek ve uygun bir alt türe dönüşüm yapmak için kullanılır.
					```cpp
					class Base {
					public:
						virtual ~Base() {}
					};

					class Derived : public Base {
					public:
						void derivedMethod() {}
					};

					int main() {
						Base* basePtr = new Derived();

						// Base* tipindeki işaretçiyi Derived* tipine dönüştürme
						Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

						if (derivedPtr) {
							// Dönüşüm başarılı ise, Derived sınıfına özgü işlemleri yapabiliriz
							derivedPtr->derivedMethod();
						}

						delete basePtr;
						return 0;
					}

					```
				- Yukarıdaki örnekte, dynamic_cast operatörü kullanılarak Base* tipindeki işaretçi Derived* tipine güvenli bir şekilde dönüştürülüyor. Bu operatör, dönüşümün güvenli olduğunu kontrol eder. Eğer dönüşüm başarısızsa (örneğin, basePtr aslında Derived türünden bir nesneyi işaret etmiyorsa), dynamic_cast null işaretçisi döndürür.
			- Const Cast
				- const_cast operatörü, bir değişkenin const niteliğini kaldırmak veya const bir değişkeni geçici olarak const olmayan bir değişkene dönüştürmek için kullanılır.
					```cpp
					void printValue(const int& value) {
						int& mutableValue = const_cast<int&>(value);
						mutableValue = 100; // const niteliği kaldırıldı, value artık değiştirilebilir
						std::cout << "Modified value: " << value << std::endl;
					}

					int main() {
						int num = 42;
						const int& constRef = num;

						printValue(constRef);

						return 0;
					}
					```
				- Yukarıdaki örnekte, const_cast operatörü kullanılarak const int& tipindeki bir referans geçici olarak int& tipine dönüştürülüyor. Bu sayede printValue fonksiyonu içinde value referansı üzerinden const niteliği kaldırılıyor ve num değişkeni fonksiyon içinde değiştirilebiliyor.
			- Reinterpret Cast
				- reinterpret_cast operatörü, türler arasında düşük seviyeli bir dönüşüm yapmak için kullanılır. Bu operatör, bir türün başka bir türe dönüştürülmesini sağlar ve genellikle iki tür arasında anlam taşımayan dönüşümler için kullanılır. Bu operatörün kullanımı genellikle riskli olduğundan ve platforma bağımlı olduğundan dikkatli kullanılmalıdır.
					```cpp
					int main() {
					int intValue = 100;

					// int* tipindeki bir işaretçiyi char* tipine reinterpret_cast kullanarak dönüştürme
					char* charPtr = reinterpret_cast<char*>(&intValue);

					for (size_t i = 0; i < sizeof(int); ++i) {
						std::cout << "Byte " << i << ": " << static_cast<int>(charPtr[i]) << std::endl;
					}

					return 0;
					}
					```

				- Yukarıdaki örnekte, reinterpret_cast operatörü kullanılarak int* tipindeki bir işaretçi char* tipine dönüştürülüyor. Bu dönüşüm, intValue değişkeninin bellek yapısını char tipinde bir dizi olarak gösterir. Ancak, reinterpret_cast operatörü platforma özgü olduğu için dikkatli kullanılmalıdır ve genellikle yüksek seviyeli C++ kodlama standartlarına aykırıdır.

			- Bu cast operatörleri, C++ dilinde tür dönüşümlerini yönetmek için güçlü araçlardır. Ancak, güvenlik ve taşınabilirlik açısından dikkatli kullanılmalı ve alternatif yaklaşımlar (örneğin, polymorphism kullanımı dynamic_cast yerine) tercih edilmelidir.
	Advantages of Type Conversion:
		- This is done to take advantage of certain features of type hierarchies or type representations.
		- It helps to compute expressions containing variables of different data types.

## Casting Operators
- Casting operators are used for type casting in C++. They are used to convert one data type to another. C++ supports four types of casts:
	- static_cast
	- dynamic_cast
	- const_cast
	- reinterpret_cast
1. static_cast
	- The static_cast operator is the most commonly used casting operator in C++. It performs compile-time type conversion and is mainly used for explicit conversions that are considered safe by the compiler. 
		```cpp
		static_cast <new_type> (expression);
		```
	- The static_cast can be used to convert between related types, such as numeric types or pointers in the same inheritance hierarchy.

		```cpp
		// C++ program to illustrate the static_cast
		#include <iostream>
		#include <typeinfo>
		using namespace std;

		int main()
		{

			int num = 10;

			// converting int to double
			double numDouble = static_cast<double>(num);

			// printing data type
			cout << typeid(num).name() << endl;

			// typecasting
			cout << typeid(static_cast<double>(num)).name() << endl;

			// printing double type t
			cout << typeid(numDouble).name() << endl;

			return 0;
		}
		```
		```
		i
		d
		d
		```
	- In this example, we have included the “typeinfo” library so that we can use typeid() function to check the data type. We have defined an integer variable ‘num’ and converted it into a double using static_cast. After that, we print the data types of variables and pass static_cast<double>(num) in typeid() function to check its data type. we can see the output “i, d, d” is printed where ‘i’ denotes integer and ‘d’ denotes double.

2. dynamic_cast
	- The dynamic_cast operator is mainly used to perform downcasting (converting a pointer/reference of a base class to a derived class). It ensures type safety by performing a runtime check to verify the validity of the conversion.
		```cpp
		dynamic_cast <new_type> (expression);
		```
	- If the conversion is not possible, dynamic_cast returns a null pointer (for pointer conversions) or throws a bad_cast exception (for reference conversions).
		```cpp
		// C++ program to illustrate the dynamic_cast
		#include <iostream>
		using namespace std;

		// Base Class
		class Animal {
		public:
			virtual void speak() const
			{
				cout << "Animal speaks." << endl;
			}
		};

		// Derived Class
		class Dog : public Animal {
		public:
			void speak() const override
			{
				cout << "Dog barks." << endl;
			}
		};

		// Derived Class
		class Cat : public Animal {
		public:
			void speak() const override
			{
				cout << "Cat meows." << endl;
			}
		};

		int main()
		{
			// base class pointer to derived class object
			Animal* animalPtr = new Dog();

			// downcasting
			Dog* dogPtr = dynamic_cast<Dog*>(animalPtr);

			// checking if the typecasting is successfull
			if (dogPtr) {
				dogPtr->speak();
			}
			else {
				cout << "Failed to cast to Dog." << endl;
			}

			// typecasting to other dervied class
			Cat* catPtr = dynamic_cast<Cat*>(animalPtr);
			if (catPtr) {
				catPtr->speak();
			}
			else {
				cout << "Failed to cast to Cat." << endl;
			}

			delete animalPtr;
			return 0;
		}
		```	
		```
		Dog barks.
		Failed to cast to Cat.
		```
	- Explanation: The first line of output is printed because the ‘animalPtr’ of the ‘Animal’ type is successfully cast to the ‘Dog’ type and speak() function of the Dog class is invoked but the casting of the ‘Animal’ type to ‘Cat’ type is failed because ‘animalPtr’ points to a ‘Dog’ object thus, the dynamic cast fails because the typecasting is not safe.
3. const_cast
	- The const_cast operator is used to modify the const or volatile qualifier of a variable. It allows programmers to temporarily remove the constancy of an object and make modifications. Caution must be exercised when using const_cast, as modifying a const object can lead to undefined behavior.
		```cpp
		const_cast <new_type> (expression);
		```
		````cpp
		// C++ program to illustrate the const_cast
		#include <iostream>
		using namespace std;

		int main()
		{

			const int number = 5;
			// Pointer to a const int
			const int* ptr = &number;

			// int* nonConstPtr = ptr; if we use this
			// instead of without using const_cast
			// we will get error of invalid conversion
			int* nonConstPtr = const_cast<int*>(ptr);
			*nonConstPtr = 10;

			cout << "Modified number: " << *nonConstPtr;

			return 0;
		}
		```
		```
		Modified number: 10
		```
	- In the above example, we have modified the value of the const type pointer by changing its qualifier from const to non-const and then printing the modified value.(geçici olarak)
- reinterpret_cast
	- The reinterpret_cast operator is used to convert the pointer to any other type of pointer. It does not perform any check whether the pointer converted is of the same type or not.
		```cpp
		reinterpret_cast <new_type> (expression);
		```
		```cpp
		// C++ program to illustrate the reinterpret_cast
		#include <iostream>
		using namespace std;

		int main()
		{
			int number = 10;
			// Store the address of number in numberPointer
			int* numberPointer = &number;

			// Reinterpreting the pointer as a char pointer
			char* charPointer
				= reinterpret_cast<char*>(numberPointer);

			// Printing the memory addresses and values
			cout << "Integer Address: " << numberPointer << endl;
			cout << "Char Address: "
				<< reinterpret_cast<void*>(charPointer) << endl;

			return 0;
		}
		```
		```
		Integer Address: 0x7fff64789f1c
		Char Address: 0x7fff64789f1c
		```
	- In the above example, we have defined an int variable ‘number’ and then store the address of ‘number’ in ‘numberPointer’ of the int type after that we have converted the ‘numberPointer’ of the int type into char pointer and then store it into ‘charPointer’ variable. To verify that we have printed the address of both numberPointer and charPointer. To print the address stored in ‘charPointer’ reinterpret_cast<void*> is used to bypass the type-checking mechanism of C++ and allow the pointer to be printed as a generic memory address without any type-specific interpretation.
	- Note: const_cast and reinterpret_cast are generally not reccommended as they vulnerable to different kinds of errors.

## Operators 
- Arithmetic Operators
	- These operators are used to perform arithmetic or mathematical operations on the operands. For example, ‘+’ is used for addition, ‘-‘ is used for subtraction ‘*’ is used for multiplication, etc. 
		- Unary Operators: These operators operate or work with a single operand. For example: Increment(++) and Decrement(–) Operators.
			- Note: ++a and a++, both are increment operators, however, both are slightly different. In ++a, the value of the variable is incremented first and then It is used in the program. In a++, the value of the variable is assigned first and then It is incremented. Similarly happens for the decrement operator.

		- Binary Operators: These operators operate or work with two operands. For example: Addition(+), Subtraction(-), etc.

- Relational Operators
	- These operators are used for the comparison of the values of two operands. For example, ‘>’ checks if one operand is greater than the other operand or not, etc. The result returns a Boolean value, i.e., true or false.

- Logical Operators
	- These operators are used to combine two or more conditions or constraints or to complement the evaluation of the original condition in consideration. The result returns a Boolean value, i.e., true or false.(&& || !)

- Bitwise Operators
	- These operators are used to perform bit-level operations on the operands. The operators are first converted to bit-level and then the calculation is performed on the operands. Mathematical operations such as addition, subtraction, multiplication, etc. can be performed at the bit level for faster processing. 
	- &: Copies a bit to the evaluated result if it exists in both operands
		```cpp
		int a = 2, b = 3;

		(a & b); //returns 2
		```
	- |: Copies a bit to the evaluated result if it exists in any of the operand
		```cpp
		int a = 2, b = 3;

		(a | b); //returns 3
		```
	- ^: Copies the bit to the evaluated result if it is present in either of the operands but not both
		```cpp
		int a = 2, b = 3;

		(a ^ b); //returns 1
		```
	- <<: Shifts the value to left by the number of bits specified by the right operand.
		```cpp
		int a = 2, b = 3;

		(a << 1); //returns 4
		```
	- **>>**: Shifts the value to right by the number of bits specified by the right operand.
		```cpp
		int a = 2, b = 3;

		(a >> 1); //returns 1
		```
	- ~: Changes binary digits 1 to 0 and 0 to 1	
		```cpp
		int b = 3;

		(~b); //returns -4
		```
	- Note: Only char and int data types  can be used with Bitwise Operators.

- Assignment Operators
	- These operators are used to assign value to a variable. The left side operand of the assignment operator is a variable and the right side operand of the assignment operator is a value. The value on the right side must be of the same data type as the variable on the left side otherwise the compiler will raise an error. 
		- =: Assigns the value on the right to the variable on the left 
			```cpp
			int a = 2; 

			// a = 2
			```
		- +=: First adds the current value of the variable on left to the value on the right and then assigns the result to the variable on the left 
			```cpp
			int a = 2, b = 4;

			a+=b; // a = 6
			```
		- -=: First subtracts the value on the right from the current value of the variable on left and then assign the result to the variable on the left
			```cpp
			int a = 2, b = 4;

			a-=b; // a = -2
			```
		- *=: First multiplies the current value of the variable on left to the value on the right and then assign the result to the variable on the left
			```cpp
			int a = 2, b = 4;

			a*=b; // a = 8
			```
		- /=: First divides the current value of the variable on left by the value on the right and then assign the result to the variable on the left.
			```cpp
			int a = 4, b = 2;

			a /=b; // a = 2
			```
- Ternary or Conditional Operators
	- This operator returns the value based on the condition. 
		```cpp
		Expression1? Expression2: Expression3
		```
	- The ternary operator ? determines the answer on the basis of the evaluation of Expression1. If it is true, then Expression2 gets evaluated and is used as the answer for the expression. If Expression1 is false, then Expression3 gets evaluated and is used as the answer for the expression. This operator takes three operands, therefore it is known as a Ternary Operator. 
		```cpp
		// CPP Program to demonstrate the Conditional Operators
		#include <iostream>
		using namespace std;
		
		int main()
		{
			int a = 3, b = 4;
		
			// Conditional Operator
			int result = (a < b) ? b : a;
			cout << "The greatest number is " << result << endl;
		
			return 0;
		}
		//The greatest number is 4
		```
- **Extra**: 
	- There are some other common operators available in C++ besides the operators discussed above. Following is a list of these operators discussed in detail:
		- **sizeof Operator**: This unary operator is used to compute the size of its operand or variable.
			```cpp
			sizeof(char); // returns 1
			```
		- **Comma Operator(,)**: This binary operator (represented by the token) is used to evaluate its first operand and discards the result, it then evaluates the second operand and returns this value (and type). It is used to combine various expressions together.
			```cpp
			int a = 6;
			int b = (a+1, a-2, a+5); // b = 11
			```
		- **-> Operator**: This operator is used to access the variables of classes or structures.
			```cpp
			cout<<emp->first_name;
			```
		- **Cast Operator**: This unary operator is used to convert one data type into another.
			```cpp
			float a = 11.567;
			int c = (int) a; // returns 11
			```
		- **Dot Operator(.)**: This operator is used to access members of structure variables or class objects in C++.
			```cpp
			cout<<emp.first_name;
			```
		- **& Operator**: This is a pointer operator and is used to represent the memory address of an operand.
		- ** * Operator**: This  is an Indirection Operator(dereference).
			```cpp
			// CPP Program to demonstrate the & and * Operators
			#include <iostream>
			using namespace std;
			
			int main()
			{
				int a = 6;
				int* b;
				int c;
				//  & Operator
				b = &a;
			
				// * Operator
				c = *b;
				cout << " a = " << a << endl;
				cout << " b = " << b << endl;
				cout << " c = " << c << endl;
			
				return 0;
			}
			//a = 6
 			//b = 0x7ffe8e8681bc
 			//c = 6
			```
		- **<< Operator**: It is called the insertion operator. It is used with cout to print the output.
		- **>> Operator**: It is called the extraction operator. It is used with cin to get the input.
## Compile a CPP file
-
	```bash
	g++ example.cpp -o example
	./example
	```
-
  ```bash
  g++ -c example.cpp -o example.o
  g++ example.o -o example
  ./example
  ```
- ekstra dosyalar olduğu için bu şekilde derlemelisin class ımız var bir tane
	```bash
	g++ -c MyClass.cpp -o MyClass.o
	g++ -c main.cpp -o main.o
	g++ MyClass.o main.o -o program
	```
## Extra Reading

  - https://www.geeksforgeeks.org/writing-first-c-program-hello-world-example/?ref=lbp
  - Difference Cpp and C: https://www.geeksforgeeks.org/difference-between-c-and-c/?ref=lbp
  - https://www.geeksforgeeks.org/variables-in-c/?ref=lbp