## Struct

**Content**

- Struct creation and using.
- Object Oriented Programing (OOP)

**Informations**

- ***struct*** is a user-defined data type that allows you to group together related variables of different types into a single unit. It is similar to a class in C++, but with default public access for its members. `struct` declaration consists of the keyword `struct` followed by the name of the structure and a block of members enclosed in curly braces. Each member can have its own data type, and they can be accessed using the dot `(.)` operator.

  	#include <iostream>

  	struct Person {
  	    std::string name;
  	    int age;
  	    float height;
  	};

  	int main() {
  	    Person person1;
  	    person1.name = "John";
  	    person1.age = 25;
  	    person1.height = 175.5;

  	    std::cout << "Name: " << person1.name << std::endl;
  	    std::cout << "Age: " << person1.age << std::endl;
  	    std::cout << "Height: " << person1.height << std::endl;

  	    return 0;
  	}

- in the above example, we define a `struct` named `Person` that
  contains three members: `name` (of type `std::string`), `age` (of
  type `int`), and `height` (of type `float`).

  In the `main` function, we declare an instance of the `Person` struct
  named `person1`. We can access the members of the `person1` object
  using the dot (`.`) operator and assign values to them. Finally, we
  print the values of the members using `std::cout`.

  The output of the program will be:

  	Name: John
  	Age: 25
  	Height: 175.5

  Structures can be useful for organizing related data into a single unit, making the code more modular and easier to manage. They can be used to represent entities, such as a person, a point in space, or any other logical grouping of variables.

  Note that in C++, the `struct` keyword can also be used with the same syntax as a class, allowing the declaration of member functions and access modifiers. In this case, the only difference between a `struct` and a `class` is the default access level (public for `struct` and private for `class`).