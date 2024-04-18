# Static Keyword

The static keyword has different meanings when used with different types. We can use static keywords with:

- Static Variables: Variables in a function, Variables in a class
- Static Members of Class: Class objects and Functions in a class Let us now look at each one of these uses of static in detail.
## Static Variables
- Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of the variable in the previous call gets carried through the next function call. This is useful for implementing coroutines in C/C++ or any other application where the previous state of function needs to be stored. 

- You can see in the above program that the variable count is declared static. So, its value is carried through the function calls. The variable count is not getting initialized every time the function is called.

## Static variables in a class
- As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of the same static variables for different objects. Also because of this reason static variables can not be initialized using constructors. 
- ex1 exp: You can see in the above program that we have tried to create multiple copies of the static variable i for multiple objects. But this didn’t happen. So, a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class as shown below: 
- clasın içindeki static veriyi tanımlamak isterken fonksyionun içinde değil tamamane dışarda tanımlamalıyız

## Static Members of Class
- Just like variables, objects also when declared as static have a scope till the lifetime of the program. Consider the below program where the object is non-static. 
- ex1 exp: In the above program, the object is declared inside the if block as non-static. So, the scope of a variable is inside the if block only. So when the object is created the constructor is invoked and soon as the control of if block gets over the destructor is invoked as the scope of the object is inside the if block only where it is declared. 
- exp2 expl: You can clearly see the change in output. Now the destructor is invoked after the end of the main. This happened because the scope of static objects is throughout the lifetime of the program.

## Static Functions in a class
- Just like the static data members or static variables inside the class, static member functions also do not depend on the object of the class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator. Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class. 