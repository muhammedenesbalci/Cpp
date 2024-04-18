## Parameters and Function Overloading

**Content**
- Call by value parameters.
- Call by reference parameters.
- Call by value and reference parameters.
- Overloading Functions.
- Default parameter function.
- Constant parameter function.

**Informations**

- ***Call by value*** means that when a function is called, the values of the arguments are copied into the function's parameters. The function works with these copies, and any modifications made to the parameter variables inside the function do not affect the original arguments.
- ***Call by reference*** is a method of passing arguments to a function where a reference to the original variables is passed instead of making copies. This allows the function to modify the original variables directly.
- ***Function overloading*** in C++ is a feature that allows you to define multiple functions with the same name but different parameters or argument lists. These functions can perform similar operations but on different data types or with different numbers of parameters. The key idea behind function overloading is that the compiler can determine which function to call based on the number, types, and order of the arguments provided during the function call. The functions must have the same name but differ in their parameter lists.
