## Classes
**Content**

- Class creation and using.
- Object-Oriented Programing (OOP).

**Informations**

- ***Class*** is a blueprint or a user-defined data type that defines a set of properties (data members) and behaviors (member functions) that objects of that class will have. It serves as a template or a blueprint for creating objects.

      class Rectangle {
          // Data members
          int length;
          int width;
          
      public:
          // Member functions
          void setDimensions(int len, int wid) {
              length = len;
              width = wid;
          }
          
          int calculateArea() {
              return length * width;
          }
      };

  In this example, we define a class named "Rectangle" with two data members: `length` and `width`, which represent the dimensions of a rectangle. We also have two member functions: `setDimensions()` to set the dimensions of the rectangle, and `calculateArea()` to calculate the area of the rectangle.

  Once a class is defined, you can create objects (instances) of that class:

      Rectangle r1;  // Creating an object of the Rectangle class

  You can then access the data members and member functions of an object using the dot operator (`.`):

      r1.setDimensions(5, 3);   // Setting the dimensions of r1
      int area = r1.calculateArea();  // Calculating the area of r1

  Classes provide a way to encapsulate related data and behavior into a single unit, allowing for better organization, code reusability, and abstraction in your C++ programs.


- ***OOP*** stands for Object-Oriented Programming, and C++ is a programming language that supports object-oriented programming paradigms. OOP is a programming paradigm that focuses on organizing code around objects, which are instances of classes.
- ***Classes***: A class is a blueprint or template that defines the structure and behavior of objects. It encapsulates data (member variables) and functions (member functions) related to that class. Objects are instances of a class.
- ***Objects***: Objects are instances of classes. They represent individual entities that have their own unique state and behavior. Objects are created based on the class definition, and they can interact with each other through messages (method calls).
- ***Encapsulation***: Encapsulation is the process of bundling data and functions together within a class, and controlling  
  access to the internal data. It allows for data hiding and information hiding, by declaring private or protected member variables and providing public member functions as an interface to access and modify the data.
- ***Inheritance***: Inheritance is a mechanism that allows a class (called the derived class or subclass) to inherit   properties and behavior from another class (called the base class or superclass). It promotes code reuse and enables the creation of specialized classes based on more general ones.
- ***Polymorphism***: Polymorphism allows objects of different classes to be treated as objects of a common base class. It  
  enables the use of a single interface to represent multiple types, and it provides flexibility and extensibility  
  to the code.
- ***Abstraction***: Abstraction involves focusing on the essential features of an object and hiding unnecessary details. It allows for creating abstract classes and interfaces that define the common characteristics and behaviors of related objects, without specifying the specific implementation details.
- These OOP concepts provide a way to write modular, reusable, and maintainable code by organizing data and behavior into objects, promoting code reusability, and enhancing code organization and structure.