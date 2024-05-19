## Strings

**Content**

- String creation and using.
- string and cstring.

## Strings in C++
- C++ strings are sequences of characters stored in a char array. Strings are used to store words and text. They are also used to store data, such as numbers and other types of information. Strings in C++ can be defined either using the std::string class or the C-style character arrays.

1. C Style Strings
- These strings are stored as the plain old array of characters terminated by a null character ‘\0’. They are the type of strings that C++ inherited from C language.
    ```cpp
    //char str[] = "GeeksforGeeks";

    // C++ Program to demonstrate strings
    #include <iostream>
    using namespace std;
    
    int main()
    {
    
        char s[] = "Enes";
        cout << s << endl;
        return 0;
    }
    ```

2. std::string Class
    - These are the new types of strings that are introduced in C++ as std::string class defined inside <string> header file. This provides many advantages over conventional C-style strings such as dynamic size, member functions, etc.

        ```cpp
        //std::string str("GeeksforGeeks");

        // C++ program to create std::string objects
        #include <iostream>
        using namespace std;
        
        int main()
        {
        
            string str("Enes");
            cout << str;
            return 0;
        }
        ```

    - One more way we can make strings that have the same character repeating again and again.
        ```cpp
        std::string str(number,character);

        #include <iostream>
        using namespace std;
        
        int main()
        {
            string str(5, 'g');
            cout << str;
            return 0;
        }

        //ggggg
        ```
## Ways to Define a String in C++
- Strings can be defined in several ways in C++. Strings can be accessed from the standard library using the string class. Character arrays can also be used to define strings. String provides a rich set of features, such as searching and manipulating, which are commonly used methods. Despite being less advanced than the string class, this method is still widely used, as it is more efficient and easier to use. Ways to define a string in C++ are:
    - Using String keyword
    - Using C-style strings

## How to Take String Input in C++
- String input means accepting a string from a user. In C++. We have different types of taking input from the user which depend on the string. The most common way is to take input with cin keyword with the extraction operator (>>) in C++. Methods to take a string as input are
    - cin
    - getline
    - stringstream

1. Using Cin
    - The simplest way to take string input is to use the cin command along with the stream extraction operator (>>). 
    ```cpp
    cin>>s;
    ```

2. Using getline 
    - The getline() function in C++ is used to read a string from an input stream. It is declared in the <string> header file. direkt satırı almak için çok kullanışlı
    ```cpp
    getline(cin,s);
    ```
3. Using stringstream
    - The stringstream class in C++ is used to take multiple strings as input at once. #include <sstream> library. buda stringi parçalıyor gibi
    ```cpp
    stringstream stringstream_object(string_name);
    ```
## How to Pass Strings to Functions?
- In the same way that we pass an array to a function, strings in C++ can be passed to functions as character arrays
    - incele: String function, 2, 3

## Strings like arrays
    - stringler char arrayleridir döngülerle vs içinde gezebilirsn

## Pointers and Strings
    - Pointers in C++ are symbolic representations of addresses. They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures. By using pointers we can get the first character of the string, which is the starting address of the string. As shown below, the given string can be accessed and printed through the pointers.

## Difference between String and Character array
     - Stringler tanımlandıkran sonra değişebilir
     - char arrayleri de katakter karakter değiştirilebilir
     - char *str tanımlaması string literali hiç bir şekilde değiştirlemez çünkü direkt const oluyor
     - Strings define objects that can be represented as string streams. The null character terminates a character array of characters.
     - No Array decay occurs in strings as strings are represented as objects. The threat of array decay is present in the case of the character array 
     - A string class provides numerous functions for manipulating strings. Character arrays do not offer inbuilt functions to manipulate strings.
     - Memory is allocated dynamically.	The size of the character array has to be allocated statically. 

     -  A string is a class that defines objects that be represented as a stream of characters.
        - A character array is simply an array of characters that can be terminated by a null character.
    - In the case of strings, memory is allocated dynamically. More memory can be allocated at run time on demand. As no memory is preallocated, no memory is wasted.
        - The size of the character array has to be allocated statically, more memory cannot be allocated at run time if required. Unused allocated memory is also wasted
    - As strings are represented as objects, no array decay occurs.
        - There is a threat of array decay in the case of the character array. 
    - Strings are slower when compared to implementation than character array.
        - implementation of character array is faster than std:: string. 
    - String class defines a number of functionalities that allow manifold operations on strings.
        - Character arrays do not offer many inbuilt functions to manipulate strings.

## C++ String Functions
- length(): This function returns the length of the string.
- swap(): This function is used to swap the values of 2 strings.
- size(): Used to find the size of string
- resize(): This function is used to resize the length of the string up to the given number of characters.
- find(): Used to find the string which is passed in parameters
- push_back(): This function is used to push the passed character at the end of the string
- pop_back(): This function is used to pop the last character from the string
- clear(): This function is used to remove all the elements of the string.
- strncmp()	: This function compares at most the first num bytes of both passed strings.
- strncpy(): This function is similar to strcpy() function, except that at most n bytes of src are copied
- strrchr(): This function locates the last occurrence of a character in the string.
- strcat(): This function appends a copy of the source string to the end of the destination string
- find(): This function is used to search for a certain substring inside a string and returns the position of the first character of the substring. 
- replace(): This function is used to replace each element in the range [first, last) that is equal to old value with new value.
- substr(): This function is used to create a substring from a given string. 
- compare(): This function is used to compare two strings and returns the result in the form of an integer.
- erase(): This function is used to remove a certain part of a string.
- capacity(): This function returns the capacity which is allocated to the string by the compiler
- shrink_to_fit(): This function decreases the capacity and makes it equal to the minimum.

## C++ Strings iterator functions 
- begin(): This function returns an iterator pointing to the beginning of the string.
- end(): This function returns an iterator that points to the end of the string.
- rfind(): This function is used to find the string’s last occurrence.
- rbegin(): This function returns a reverse iterator pointing to the end of the string. 
- rend(): This function returns a reverse iterator pointing to the beginning of the string.
- cbegin(): This function returns a const_iterator pointing to the beginning of the string.
- cend(): This function returns a const_iterator pointing to the end of the string.
- crbegin(): This function returns a const_reverse_iterator pointing to the end of the string.
- crend(): This function returns a const_reverse_iterator pointing to the beginning of the string.

## Array of Strings
- In C++, a string is usually just an array of (or a reference/points to) characters that ends with the NULL character ‘\0‘. A string is a 1-dimensional array of characters and an array of strings is a 2-dimensional array of characters where each row contains some string.
    - Using Pointers
    - Using 2-D Array
    - Using the String Class
    - Using the Vector Class
    - Using the Array Class

1. Using Pointers
    - Pointers are the symbolic representation of an address. In simple words, a pointer is something that stores the address of a variable in it. In this method, an array of string literals is created by an array of pointers in which each pointer points to a particular string.
        - The number of strings is fixed, but needn’t be. The 4 may be omitted, and the compiler will compute the correct size. 
        - These strings are constants and their contents cannot be changed. Because string literals (literally, the quoted strings) exist in a read-only area of memory, we must specify “const” here to prevent unwanted accesses that may crash the program.

2. Using a 2D array
    - A 2-D array is the simplest form of a multidimensional array in which it stores the data in a tabular form. This method is useful when the length of all strings is known and a particular memory footprint is desired. Space for strings will be allocated in a single block
        - Both the number of strings and the size of the strings are fixed. The 4, again, may be left out, and the appropriate size will be computed by the compiler. The second dimension, however, must be given (in this case, 10), so that the compiler can choose an appropriate memory layout.
        - Each string can be modified but will take up the full space given by the second dimension. Each will be laid out next to each other in memory, and can’t change size.
        - Sometimes, control over the memory footprint is desirable, and this will allocate a region of memory with a fixed, regular layout.

3. Using the String class
    - The STL string or string class may be used to create an array of mutable strings. In this method, the size of the string is not fixed, and the strings can be changed which somehow makes it dynamic in nature nevertheless std::string can be used to create a string array using in-built functions. 
        - The array is of fixed size, but needn’t be. Again, the 4 here may be omitted, and the compiler will determine the appropriate size of the array. The strings are also mutable, allowing them to be changed.

4. Using the vector class
    - A vector is a dynamic array that doubles its size whenever a new character is added that exceeds its limit. The STL container vector can be used to dynamically allocate an array that can vary in size. This is only usable in C++, as C does not have classes. Note that the initializer-list syntax here requires a compiler that supports the 2011 C++ standard, and though it is quite likely your compiler does, it is something to be aware of.
        - Vectors are dynamic arrays and allow you to add and remove items at any time.
        - Any type or class may be used in vectors, but a given vector can only hold one type.

5. Using the Array Class
    - An array is a homogeneous mixture of data that is stored continuously in the memory space. The STL container array can be used to allocate a fixed-size array. It may be used very similarly to a vector, but the size is always fixed.

## String Concatenation
- The string is a type of data structure used for storing characters. Concatenating strings in C++ is one of the most discussed topics related to strings. There are multiple methods to concat strings using user-defined methods, and a couple of methods for the concatenation of strings using pre-defined methods. Let’s check on all of these methods.
    - Using append( ) Function.
    - Using ‘+’ Operator.
    - Using strcat( ) Function.
    - Using C++ for Loop.
    - Using Inheritance.
    - Using the Friend Function and strcat() Function.

1. Using append() Function
    - The append() function is a member function of the std::string class. Using this function, we can concatenate two std::string objects (C++ style strings) as shown in the below example.

2. Using ‘+’ Operator
    - This is the easiest method for the concatenation of two strings. The + operator adds strings and returns a concatenated string. This method only works for C++ style strings (std::string objects) and doesn’t work on C style strings (character array).

3. Using strcat() Function
    - The C++ strcat() function is a built-in function defined in <string.h> header file. This function concatenates the two strings init and add and the result is stored in the init string. This function only works for C-style strings (character arrays) and doesn’t work for C++-style strings (std::string objects).

4. Using for Loop
    - Using a loop is one of the most basic methods of string concatenation. Here, we are adding elements one by one while traversing the whole string and then another string.  The final result will be the concatenated string formed from both strings.
