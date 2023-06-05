
## C++ Basics

**Content**

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

**Informations**

- ***#include*** directive is used to include external files or libraries in your program. It is a preprocessor directive that tells the compiler to insert the contents of another file into the current file at the point where the *#include* directive is used. This allows you to access definitions, declarations, and functionalities from the included files.
- ***iostream*** header is part of the C++ Standard Library and provides input and output functionality.  
  It defines several stream objects, such as cin (for input from the standard input) and cout (for output to the standard output). The iostream header is commonly used for console input and output operations.
- ***namespace*** is a feature that allows you to group related declarations together and prevent naming conflicts. It provides a way to organize code and avoid naming collisions between different components of a program. To define a namespace in C++, you use the ***namespace*** keyword followed by the desired namespace name. Here's an example:

  	// Declaration of a namespace called "myNamespace" namespace  
  	myNamespace {  
  	// Declarations of classes, functions, variables, etc.  
  	// ... }  

  Within the namespace block, you can define classes, functions, variables, and other entities, just like you would outside of a namespace. However, these declarations will be scoped within the namespace, meaning they are only accessible using the namespace name as a prefix.

  To use the entities defined in a namespace, you can either qualify the names explicitly or introduce the entire namespace into your code with the ***using*** directive. Here are examples of both approaches:

  	// Qualifying the names explicitly  
  	myNamespace::MyClass obj;  
  	myNamespace::myFunction();  
  	  
  	// Introducing the entire namespace  
  	using namespace myNamespace;  
  	  
  	// Now you can access the entities directly  
  	MyClass obj;  
  	myFunction()  

  It's important to note that using the ***using*** directive to introduce a namespace can lead to naming conflicts if there are multiple namespaces with the same name or if there are naming clashes with other entities in your code. Therefore, it's generally recommended to use namespace qualifications to maintain clarity and avoid potential issues.

  Remember, namespaces are a way to organize and modularize your code, making it easier to manage and collaborate on large projects.