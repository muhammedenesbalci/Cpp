## Friend

**Content**
- Friend creation and using.

**Informations**

- **friend** keyword is used to declare a non-member function or an entire external class as a friend of a class. When a function or class is declared as a friend, it is granted special access privileges to the private and protected members of the class.

  Here are some key points about the `friend` keyword:

  Access to private and protected members: A friend function or class can access the private and protected members of the class that declared it as a friend. This means that the friend entity can directly access and manipulate the private and protected members, bypassing the usual access restrictions.

  Declaration inside the class: The `friend` declaration typically appears inside the class definition, preceded by the `friend` keyword and followed by the declaration of the friend function or class.

  Bidirectional friendship: Friendship is not automatically reciprocal. Just because Class A declares Class B as a friend, it doesn't mean that Class B is automatically a friend of Class A. Friendship needs to be explicitly declared in both directions, if necessary.

  Granular control: The `friend` keyword allows you to selectively grant access to specific functions or classes, providing a way to control which external entities have access to the private and protected members of a class.

  Here's an example to illustrate the usage of the `friend` keyword:

      class MyClass {
      private:
          int privateData;
          
      public:
          MyClass(int data) : privateData(data) {}
          
          friend void friendFunction(MyClass& obj);
      };
      
      void friendFunction(MyClass& obj) {
          // Friend function has access to private members of MyClass
          obj.privateData = 42;
      }
      
      int main() {
          MyClass obj(10);
          friendFunction(obj);
          // Access private member through the friend function
          std::cout << obj.privateData << std::endl; // Output: 42
          return 0;
      }

  In this example, the `friendFunction` is declared as a friend of the `MyClass` class using the `friend` keyword. As a result, the `friendFunction` has access to the private member `privateData` of the `MyClass` object and can modify its value.

  The `friend` keyword can also be used to declare an entire external class as a friend, granting it access to the private and protected members of the declaring class. This can be useful when you want to establish a close relationship between two classes, allowing them to access each other's internals.

  It's important to note that using the `friend` keyword should be done judiciously, as it can potentially undermine encapsulation and break the principle of information hiding. It should be used when there is a genuine need for accessing private or protected members from external functions or classes.