## Code With Multiple Files

**Content**

- Multiple files creation and using when coding.

**Informations**

- In C++, .cpp and .h (or .hpp) files are commonly used to separate the implementation and declaration of classes and functions. These file extensions are widely adopted conventions, but they are not mandatory.


- .cpp (C++ source file):

  	 - A .cpp file contains the implementation details of classes and functions.
  	    
  	 - It typically includes the definitions (implementations) of member functions and other non-member functions.
   
  	 - The .cpp file is compiled along with other source files to generate object files, which are then linked together to create the final executable program.

- h (or .hpp) (header file):
    -   A .h file contains the declarations (or prototypes) of classes, functions, constants, and other entities.
    -   It provides the interface or contract of the code, specifying the public members and how they can be used.
    -   The .h file is typically included in other source files using the `#include` preprocessor directive, allowing the declaration to be visible to those files.
    -   The purpose of the header file is to allow separate compilation, where the compiler only needs to see the declarations without the implementation details, reducing compilation time for larger projects.

  Here's a simplified example to demonstrate the usage of .cpp and .h files:

      #ifndef MYCLASS_H
      #define MYCLASS_H
      
      class MyClass {
      private:
          int privateData;
          
      public:
          MyClass(int data);
          void doSomething();
      };
      
      #endif

  `MyClass.cpp` (source file):

      #include "MyClass.h"
      #include <iostream>
      
      MyClass::MyClass(int data) : privateData(data) {}
      
      void MyClass::doSomething() {
          std::cout << "Doing something with privateData: " << privateData << std::endl;
      }

  In this example, `MyClass.h` contains the class declaration (including the constructor and member function declaration), surrounded by include guards (`#ifndef`, `#define`, `#endif`) to prevent multiple inclusion.

  `MyClass.cpp` includes the corresponding header file using `#include "MyClass.h"` and provides the implementation details of the constructor and `doSomething()` member function.

  By separating the implementation into .cpp files and declarations into .h files, the code is organized, modular, and easier to maintain. It also allows for better encapsulation and information hiding, as the implementation details are kept private in the .cpp files while the public interface is exposed in the .h files.

- `#ifndef`, `#define`, and `#endif` are preprocessor directives used in header files to prevent multiple inclusions and ensure that the contents of the header file are included only once during compilation. This is achieved through the use of include guards.

- `#ifndef` (if not defined):

    -   `#ifndef` checks if a preprocessor symbol is not defined.
    -   If the specified symbol is not defined, the code between `#ifndef` and `#endif` will be included during compilation.
    -   If the symbol is defined, the code between `#ifndef` and `#endif` will be skipped.

- `#define`:

    -   `#define` is used to define a preprocessor symbol or macro.
    -   When used in conjunction with `#ifndef`, it defines the symbol if it was not previously defined.
    -   The value specified in `#define` is not important in this context; it is typically set to a non-empty value for clarity.

- `#endif`:

    -   `#endif` marks the end of a conditional block started by `#ifndef`.
    -   It is used to close the conditional statement and resume normal compilation.

  By using these directives in a header file, you can ensure that the contents of the header are included only once, regardless of how many times the header file is included in different source files.

  Here's an example to illustrate the usage of include guards:

      #ifndef MYHEADER_H
      #define MYHEADER_H
      
      // Content of the header file
      
      #endif

  In this example, `MYHEADER_H` is an arbitrary name chosen for the include guard symbol. When the header file is included for the first time, `MYHEADER_H` is not defined, so the code between `#ifndef` and `#endif` is included. On subsequent inclusions, `MYHEADER_H` is already defined, so the code is skipped.

  Including the header file multiple times without include guards could result in multiple definitions and compiler errors due to redefinition of symbols, including duplicate function declarations or class definitions. The use of include guards ensures that these issues are avoided.

  It's important to choose unique and descriptive names for the include guard symbols to avoid potential conflicts with other header files. Common naming conventions include using the file name in uppercase, followed by an underscore or double underscore.