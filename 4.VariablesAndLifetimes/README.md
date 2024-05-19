## Variables and Lifetimes

## Content
- Variables and lifetimes.

## Informations
- In general, the scope is defined as the extent up to which something can be worked with. In programming also the scope of a variable is defined as the extent of the program code within which the variable can be accessed or declared or worked with. There are mainly two types of variable scopes: 

    - Local Variables
    - Global Variables

- Local Variables
    - Variables defined within a function or block are said to be local to those functions.  

    - Anything between ‘{‘ and ‘}’ is said to inside a block.
    - Local variables do not exist outside the block in which they are declared, i.e. they can not be accessed or used outside that block.
    - Declaring local variables: Local variables are declared inside a block.

- Global Variables
    - they are available through out the life time of a program.
    - They are declared at the top of the program outside all of the functions or blocks.
    - Declaring global variables: Global variables are usually declared outside of all of the functions and blocks, at the top of the program. They can be accessed from any portion of the program.

    ## Types of Variables
- look.png open it !!!

- There are three types of variables based on the scope of variables in C++
	- Local Variables
	- Instance Variables
	- Static Variables
	- Global Variables

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