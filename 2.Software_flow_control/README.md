## Software Flow Control

**Content**
- if.
- else if.
- else.
- switch-case.
- While loop.
- For loop

## Jump statements
- Jump statements are used to manipulate the flow of the program if some conditions are met. It is used to terminate or continue the loop inside a program or to stop the execution of a function.
    - break
    - continue
    - goto
    - return


## continue
- The C++ continue statement is used to execute other parts of the loop while skipping some parts declared inside the condition, rather than terminating the loop, it continues to execute the next iteration of the same loop. It is used with a decision-making statement which must be present inside the loop.

- This statement can be used inside for loop or while or do-while loop.

    ```cpp
    // C++ program to demonstrate the
    // continue statement
    #include <iostream>
    using namespace std;
    
    // Driver code
    int main()
    {
        for (int i = 1; i < 10; i++) {
    
            if (i == 5)
                continue;
            cout << i << " ";
        }
        return 0;
    }
    //1 2 3 4 6 7 8 9 
    ```
## break
- The C++ break statement is used to terminate the whole loop if the condition is met. Unlike the continue statement after the condition is met, it breaks the loop and the remaining part of the loop is not executed.
    ```cpp
    // C++ program to demonstrate the
    // break statement
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        for (int i = 1; i < 10; i++) {
    
            // Breaking Condition
            if (i == 5)
                break;
            cout << i << " ";
        }
        return 0;
    }
    //1 2 3 4 
    ```

## return
- The return statement takes control out of the function itself. It is stronger than a break. It is used to terminate the entire function after the execution of the function or after some condition. like a break for a loop
    ```cpp
    // C++ program to demonstrate the
    // return statement
    #include <iostream>
    using namespace std;
    
    // Driver code
    int main()
    {
        cout << "Begin ";
    
        for (int i = 0; i < 10; i++) {
    
            // Termination condition
            if (i == 5)
                return 0;
            cout << i << " ";
        }
        cout << "end";
    
        return 0;
    }
    // Begin 0 1 2 3 4 
    ```

    - The above program starts execution by printing “Begin” and then the for loop starts to print the value of, it will print the value of i from 0 to 4 but as soon as i becomes equal to 5 it will terminate the whole function i.e., it will never go to print the “end” statement of the program.
    - Note: The return in void() functions can be used without any return type.

    ```cpp
    // C++ program to demonstrate the return
    // statement in void return type function
    #include <iostream>
    using namespace std;
    
    // Function to find the greater element
    // among x and y
    void findGreater(int x, int y)
    {
        if (x > y) {
            cout << x << " "
                << "is greater"
                << "\n";
            return;
        }
        else {
            cout << y << " "
                << "is greater"
                << "\n";
            return;
        }
    }
    
    // Driver Code
    int main()
    {
        // Function Call
        findGreater(10, 20);
    
        return 0;
    }
    //20 is greater
    ```
## Goto
- The C++ goto statement is used to jump directly to that part of the program to which it is being called.  Every goto statement is associated with the label which takes them to part of the program for which they are called. The label statements can be written anywhere in the program it is not necessary to use them before or after the goto statement.
- Note: The goto statement makes it difficult to understand the flow of the program therefore it is avoided to use it in a program.
    ```cpp
    // C++ program to demonstrate the
    // goto statement
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        int n = 4;
    
        if (n % 2 == 0)
            goto label1;
        else
            goto label2;
    
    label1:
        cout << "Even" << endl;
        return 0;
    
    label2:
        cout << "Odd" << endl;
    }
    //Even
    ``` 
    - The above program is used to check whether the number is even or odd if the number pressed by the user says it is 4 so the condition is met by the if statement and control go to label1 and label1 prints that the number is even. Here it is not necessary to write a label statement after the goto statement we can write it before goto statement also it will work fine.

## Loops
- while loop: First checks the condition, then executes the body.
- for loop: firstly initializes, then, condition check, execute body, update.
    - The For loop can be used to iterating through the elements in the STL container(e.g., Vector, etc). here we have to use iterator.
    - auto keyword with arrays and vectors
    - range based loops: Range-based for loop in C++ has been added since C++ 11. It executes a for loop over a range. Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a container.
        ```cpp
        for ( range_declaration : range_expression ) 
        loop_statement
        ```
        Parameters :
        range_declaration : 
        a declaration of a named variable, whose type is the 
        type of the element of the sequence represented by 
        range_expression, or a reference to that type.
        Often uses the auto specifier for automatic type 
        deduction.
        range_expression : 
        any expression that represents a suitable sequence 
        or a braced-init-list.
        loop_statement : 
        any statement, typically a compound statement, which
        is the body of the loop.
        
        ```cpp
        #include <iostream>
        #include <vector>

        int main() {
            std::vector<int> numbers = {1, 2, 3, 4, 5};

            // Range-based for loop ile vektördeki tüm elemanları yazdır
            for (int num : numbers) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            return 0;
        }
        ```
    - C++ 17 or higher: Range-based loops can also be used with maps like this: 
        ```cpp
        for (auto& [key, value]: myMap) {
            cout << key << " has value " << value << std::endl;
        }
        ```
        - Here [key, value] works like elements of pair which can be directly accessed without specifying first or second keyword. 
        
    - for_each loop: C++ for_each loop accepts a function that executes over each of the container elements. This loop is defined in the header file <algorithm> and hence has to be included for the successful operation of this loop.
        ```cpp
        //for_each ( InputIterator start_iter, InputIterator last_iter, Function fnc);
        ```
        - start_iter: Iterator to the beginning position from where function operations have to be executed.
        - last_iter: Iterator to the ending position till where function has to be executed.
        - fnc: The 3rd argument is a function or a function object which would be executed for each element.

            ```cpp
            // C++ Program to show use of for_each loop 
    
            #include <bits/stdc++.h> 
            using namespace std; 
            
            // function to print values passed as parameter in loop 
            void printValues(int i) { cout << i << " " << endl; } 
            
            int main() 
            { 
                // initializing vector 
                vector<int> v = { 1, 2, 3, 4, 5 }; 
            
                // iterating using for_each loop 
                for_each(v.begin(), v.end(), printValues); 
            
                return 0; 
            }
            //1 
            //2 
            //3 
            //4 
            //5 
            ```
            - The above program uses for_each loop to iterate through each element of the vector (v here), it calls the printValues function to print each element. Output is displayed in the next line for each iteration.
- do-while loop: firstly, execute the body then condition check


