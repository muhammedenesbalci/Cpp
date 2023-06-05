## Encapsulation

**Content**

- Encapsulation creation and using.

**Informations**

- ***Encapsulation*** is a fundamental concept in object-oriented programming (OOP) that combines data and methods (functions) into a single unit called a class. It allows for the bundling of data and behavior together, and it provides control over how the data is accessed and manipulated.

  In C++, encapsulation is achieved through the use of access specifiers (`public`, `private`, and `protected`) in class definitions. These access specifiers determine the visibility and accessibility of class members (data members and member functions) from outside the class.

  Here's an overview of the three access specifiers:

  ***Public***: Public members are accessible from outside the class. They can be accessed by objects of the class and other functions or classes that have access to the object.

  ***Private***: Private members are not accessible from outside the class. They can only be accessed by member functions of the same class. By default, class members are private if no access specifier is specified.

  ***Protected***: Protected members are similar to private members, but they are also accessible to derived classes (classes that inherit from the base class)

- To use encapsulation in C++, you typically follow these steps:

  Define a class: Start by defining a class that encapsulates the desired data and behavior. Declare the data members and member functions within the class.

      class MyClass {
      private:
          int privateData;
          
      public:
          void publicMethod();
      };

  Set access specifiers: Specify the desired access specifiers (`public`, `private`, or `protected`) for each member of the class. Determine which members should be accessible from outside the class and which should be hidden.

  Accessing data and methods: Use objects of the class to access the public members. Public member functions can be called on objects to perform operations, while private members are accessed and modified through the public member functions.

      MyClass obj;
      obj.publicMethod();  // Accessing a public member function

  Encapsulation allows you to control the visibility of your class members and provide public interfaces to interact with the object while keeping the internal implementation details hidden. It promotes code modularity, data integrity, and code reusability, and helps in achieving better software design and maintenance.

- ***this->*** is a pointer that refers to the current object instance within a member function or member variable of a class. It is an implicit pointer available in non-static member functions of a class.

  The `this` pointer is automatically created when a member function is called on an object, and it points to the memory address of that object. Using `this->` allows you to access the members (variables or functions) of the current object explicitly.

  Here's an example to illustrate the usage of `this->`:

      class MyClass {
      private:
          int data;
          
      public:
          void setData(int data) {
              this->data = data;
          }
          
          int getData() {
              return this->data;
          }
      };

  In this example, the `setData()` member function takes an input `data` and assigns it to the member variable `data` of the current object using `this->data`. By using `this->`, we explicitly specify that we want to assign the input `data` to the member variable `data` of the current object.

  Similarly, in the `getData()` member function, `this->data` is used to access and return the value of the member variable `data` of the current object.

  Using `this->` can be especially useful when there is a naming conflict between a local variable and a member variable of a class. It allows you to differentiate and explicitly refer to the member variable using the `this` pointer.

  Note that in most cases, using `this->` is optional, as you can directly access the members of the current object without explicitly using `this->`. However, it can be helpful for code readability and disambiguation in certain scenarios.