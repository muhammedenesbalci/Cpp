# Input and Output
- Input Stream: If the direction of flow of bytes is from the device(for example, Keyboard) to the main memory then this process is called input.
- Output Stream: If the direction of flow of bytes is opposite, i.e. from main memory to device( display screen ) then this process is called output.
- Header files available in C++ for Input/Output operations are
    - iostream: iostream stands for standard input-output stream. This header file contains definitions of objects like cin, cout, cerr, etc.
    - iomanip: iomanip stands for input-output manipulators. The methods declared in these files are used for manipulating streams. This file contains definitions of setw, setprecision, etc.
    - fstream: This header file mainly describes the file stream. This header file is used to handle the data being read from a file as input or data being written into the file as output.
    - bits/stdc++: This header file includes every standard library. In programming contests, using this file is a good idea, when you want to reduce the time wasted in doing chores; especially when your rank is time sensitive.
    - In C++ after the header files, we often use ‘using namespace std;‘. The reason behind it is that all of the standard library definitions are inside the namespace std. As the library functions are not defined at global scope, so in order to use them we use namespace std. So, that we don’t need to write STD:: at every line (eg. STD::cout etc.).
    - The two instances cout in C++ and cin in C++ of iostream class are used very often for printing outputs and taking inputs respectively. These two are the most basic methods of taking input and printing output in C++. To use cin and cout in C++ one must include the header file iostream in the program.
   
   - **Standard output stream (cout)**: Usually the standard output device is the display screen. The C++ cout statement is the instance of the ostream class. It is used to produce output on the standard output device which is usually the display screen. The data needed to be displayed on the screen is inserted in the standard output stream (cout) using the insertion operator(<<).

        ```cpp
        #include <iostream>
        
        using namespace std;
        
        int main()
        {
            char sample[] = "GeeksforGeeks";
        
            cout << sample << " - A computer science portal for geeks";
        
            return 0;
        }
        //GeeksforGeeks - A computer science portal for geeks
        ```
    - In the above program, the insertion operator(<<) inserts the value of the string variable sample followed by the string “A computer science portal for geeks” in the standard output stream cout which is then displayed on the screen.

    - **standard input stream (cin)**: Usually the input device in a computer is the keyboard. C++ cin statement is the instance of the class istream and is used to read input from the standard input device which is usually a keyboard. 
        - The extraction operator(>>) is used along with the object cin for reading inputs. The extraction operator extracts the data from the object cin which is entered using the keyboard.

            ```cpp
            #include <iostream>
            using namespace std;
            
            int main()
            {
                int age;
            
                cout << "Enter your age:";
                cin >> age;
                cout << "\nYour age is: " << age;
            
                return 0;
            }
            // in: 18
            // Enter your age:
            //Your age is: 18
            ```

            - The above program asks the user to input the age. The object cin is connected to the input device. The age entered by the user is extracted from cin using the extraction operator(>>) and the extracted data is then stored in the variable age present on the right side of the extraction operator.
    
    - **Un-buffered standard error stream (cerr)**: The C++ cerr is the standard error stream that is used to output the errors. This is also an instance of the iostream class. As cerr in C++ is un-buffered so it is used when one needs to display the error message immediately. It does not have any buffer to store the error message and display it later.
        - The main difference between cerr and cout comes when you would like to redirect output using “cout” that gets redirected to file if you use “cerr” the error doesn’t get stored in file.(This is what un-buffered means ..It cant store the message)
            ```cpp
            #include <iostream>
    
            using namespace std;
            
            int main()
            {
                cerr << "An error occurred";
                return 0;
            }
            //An error occurred
            ```
    - **buffered standard error stream (clog)**: This is also an instance of ostream class and used to display errors but unlike cerr the error is first inserted into a buffer and is stored in the buffer until it is not fully filled. or the buffer is not explicitly flushed (using flush()). The error message will be displayed on the screen too.
        ```cpp
        #include <iostream>
    
        using namespace std;
        
        int main()
        {
            clog << "An error occurred";
        
            return 0;
        }
        //An error occurred
        ```
## cin
- The cin object in C++ is an object of class iostream. It is used to accept the input from the standard input device i.e. keyboard. It is associated with the standard C input stream stdin. The extraction operator(>>) is used along with the object cin for reading inputs. The extraction operator extracts the data from the object cin which is entered using the keyboard.
    ```cpp
    // C++ program to demonstrate the 
    // cin object 
    #include <iostream> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
        string s; 
    
        // Take input using cin 
        cin >> s; 
    
        // Print output 
        cout << s; 
    
        return 0; 
    }
    //in: enes
    //out: enes
    ```
- Multiple inputs using the extraction operators(>>) with cin. Below is the C++ program to take multiple user inputs.
    ```cpp
    // C++ program to illustrate the take 
    // multiple input 
    #include <iostream> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
        string name; 
        int age; 
    
        // Take multiple input using cin 
        cin >> name >> age; 
    
        // Print output 
        cout << "Name : " << name << endl; 
        cout << "Age : " << age << endl; 
    
        return 0; 
    }
    //in enes
    // enter keyboard
    //in 25

    //out name enes, age 25
    ```

- The cin can also be used with some member functions which are as follows: 
    ```cpp
    cin.getline(char *buffer, int N):
    ```
    - It reads a stream of characters of length N into the string buffer, It stops when it has read (N – 1) characters or it finds the end of the file or newline character(\n). Below is the C++ program to implement cin.getline():
        ```cpp
        // C++ program to illustrate the use 
        // of cin.getline 
        #include <iostream> 
        using namespace std; 
        
        // Driver Code 
        int main() 
        { 
            char name[5]; 
        
            // Reads stream of 3 
            // characters 
            cin.getline(name, 3); 
        
            // Print output 
            cout << name << endl; 
        
            return 0; 
        }
        //in Enes
        //out: En
        ```
- It reads an input character and stores it in a variable.  Below is the C++ program to implement cin.get():
    ```cpp
    cin.get(char& var):
    ```
    ```cpp
    // C++ program to illustrate the use 
    // of cin.get() 
    #include <iostream> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
        char ch; 
        cin.get(ch, 25); 
    
        // Print ch 
        cout << ch; 
    }
    //in Enes
    //out Enes
    ```

- Reads a stream of characters of length N. Below is the C++ program to implement cin.read():
    ```cpp
    cin.read(char *buffer, int N):

    // C++ program to illustrate the use 
    // of cin.read() 
    #include <iostream> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
        char gfg[20]; 
    
        // Reads stream of characters 
        cin.read(gfg, 10); 
    
        // Print output 
        cout << gfg << endl; 
    
        return 0; 
    }
    //in Welcome to efe
    // our Welcome to
    ```

- It ignores or clears one or more characters from the input buffer. Below is the C++ program to implement cin.ignore():
    ```cpp
    cin.ignore():
    // C++ program to illustrate the use 
    // of cin.ignore() 
    #include <iostream> 
    
    // used to get stream size 
    #include <ios> 
    
    // used to get numeric limits 
    #include <limits> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
        int x; 
        char str[80]; 
        cout << "Enter a number andstring:\n"; 
        cin >> x; 
    
        // clear buffer before taking 
        // new line 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
        // Input a string 
        cin.getline(str, 80); 
        cout << "You have entered:\n"; 
        cout << x << endl; 
        cout << str << endl; 
    
        return 0; 
    }
    // in 8
    // welcome to gfg

    // Enter .....
    //you have ....
    //8
    // Welcome to gfg
    ```
    - Explanation: In the above program if cin.ignore() has not been used then after entering the number when the user presses the enter to input the string, the output will be only the number entered. The program will not take the string input. To avoid this problem cin.ignore() is used, this will ignore the newline character.

## cout
- The cout object in C++ is an object of class iostream. It is defined in iostream header file. It is used to display the output to the standard output device i.e. monitor. It is associated with the standard C output stream stdout. The data needed to be displayed on the screen is inserted in the standard output stream (cout) using the insertion operator(<<).
    ```cpp
    // C++ program to illustrate the use
    // of cout object
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        // Print standard output
        // on the screen
        cout << "Welcome to GFG";
    
        return 0;
    }
    //Welcome to GFG
    ```

- More than one variable can be printed using the insertion operator(<<) with cout.
    ```cpp
    // C++ program to illustrate printing
    // of more than one statement in a
    // single cout statement
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        string name = "Akshay";
        int age = 18;
    
        // Print multiple variable on
        // screen using cout
        cout << "Name : " << name << endl
            << "Age : " << age << endl;
    
        return 0;
    }
    //Name : Akshay
    //Age : 18
    ```
- cout.write(char *str, int n): Print the first N character reading from str.
    ```cpp
    // C++ program to illustrate the use
    // of cout.write() and cout.put()
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        char gfg[] = "Welcome at GFG";
        char ch = 'e';
    
        // Print first 6 characters
        cout.write(gfg, 6);
    
        // Print the character ch
        cout.put(ch);
        return 0;
    }
    //Welcome
    ```
- cout.put(char &ch): Print the character stored in character ch.
    ```cpp
    // C++ program to illustrate the use
    // of cout.write() and cout.put()
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        char gfg[] = "Welcome at GFG";
        char ch = 'e';
    
        // Print first 6 characters
        cout.write(gfg, 6);
    
        // Print the character ch
        cout.put(ch);
        return 0;
    }
    //Welcome
    ```
- cout.precision(int n): Sets the decimal precision to N, when using float values.
    ```cpp
    // C++ program toillustrate the use
    // of cout.precision()
    #include <iostream>
    using namespace std;
    
    // Driver Code
    int main()
    {
        double pi = 3.14159783;
    
        // Set precision to 5
        cout.precision(5);
    
        // Print pi
        cout << pi << endl;
    
        // Set precision to 7
        cout.precision(7);
    
        // Print pi
        cout << pi << endl;
    
        return 0;
    }
    //3.1416
    //3.141598
    ```

## cerr – Standard Error Stream Object 
- Standard output stream(cout): cout is the instance of the ostream class. cout is used to produce output on the standard output device which is usually the display screen. The data needed to be displayed on the screen is inserted in the standard output stream(cout) using the insertion operator(<<).
- Standard error stream (cerr): cerr is the standard error stream which is used to output the errors. It is an instance of the ostream class. As cerr stream is un-buffered so it is used when we need to display the error message immediately and does not store the error message to display later. The object of class ostream that represents the standard error stream oriented to narrow characters(of type char). It corresponds to the C stream stderr.
- The “c” in cerr refers to “character” and ‘err’ means “error”, Hence cerr means “character error”. It is always a good practice to use cerr to display errors.
    ```cpp
    // C++ program to illustrate std::cerr 
    
    #include <iostream> 
    using namespace std; 
    
    // Driver Code 
    int main() 
    { 
    
        // This will print "Welcome to GfG" 
        // in the error window 
        cerr << "Welcome to GfG! :: cerr"; 
    
        // This will print "Welcome to GfG" 
        // in the output window 
        cout << "Welcome to GfG! :: cout"; 
        return 0; 
    } 
    // Welcome to GfG! :: cerr
    ```
    - In the above program the Output of Line 11 will display an error window as:

## Manipulators
- Manipulators are helping functions that can modify the input/output stream. It does not mean that we change the value of a variable, it only modifies the I/O stream using insertion (<<) and extraction (>>) operators. 
    - Manipulators are special functions that can be included in the I/O statement to alter the format parameters of a stream. 
    - Manipulators are operators that are used to format the data display.
    - To access manipulators, the file iomanip.h should be included in the program.
- For example, if we want to print the hexadecimal value of 100 then we can print it as:
    ```cpp
    cout<<setbase(16)<<100
    ```
- Types of Manipulators There are various types of manipulators:
- Manipulators without arguments: The most important manipulators defined by the IOStream library are provided below.
    - endl: It is defined in ostream. It is used to enter a new line and after entering a new line it flushes (i.e. it forces all the output written on the screen or in the file) the output stream.
    - ws: It is defined in istream and is used to ignore the whitespaces in the string sequence.
        - ws" C++ dilinde, giriş akışı (istream) nesneleri üzerinde boşluk karakterlerini atlamak için kullanılan bir manipülatördür. Manipülatör, <iomanip> başlık dosyasında tanımlanmıştır ve std::ws şeklinde kullanılır.

        - std::ws manipülatörü, giriş akışından bir sonraki olmayan boşluk karakterine (boşluk, tab veya satır sonu karakteri) kadar olan tüm boşluk karakterlerini atlar. Bu, özellikle giriş işlemleri sırasında kullanıcı tarafından fazladan boşluk veya satır sonları girilmişse girişin beklenmedik şekilde etkilenmesini önlemek için faydalıdır.
            ```cpp
            #include <iostream>
            #include <string>

            int main() {
                std::string firstName, lastName;

                std::cout << "Enter your first name and last name: ";
                std::cin >> std::ws; // İlk önce boşlukları atla
                std::getline(std::cin, firstName); // İlk adı oku
                std::getline(std::cin, lastName); // Soyadı oku

                std::cout << "Hello, " << firstName << " " << lastName << "!" << std::endl;

                return 0;
            }
            ```
            - Yukarıdaki örnekte, std::ws manipülatörü std::cin üzerinde kullanılarak önce girişten boşluk karakterleri atlanır. Böylece, kullanıcı tarafından girilen isim ve soyisim verileri doğru şekilde okunur ve beklenmedik boşluk karakterlerinden arındırılmış olur.
    - ends: It is also defined in ostream and it inserts a null character into the output stream. It typically works with std::ostrstream, when the associated output buffer needs to be null-terminated to be processed as a C string.

    - flush: It is also defined in ostream and it flushes the output stream, i.e. it forces all the output written on the screen or in the file. Without flush, the output would be the same, but may not appear in real-time. 

### Examples
```cpp
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
 
using namespace std;
 
int main()
{
    istringstream str("           Programmer");
    string line;
    // Ignore all the whitespace in string
    // str before the first word.
    getline(str >> std::ws, line);
 
    // you can also write str>>ws
    // After printing the output it will automatically
    // write a new line in the output stream.
    cout << line << endl;
 
    // without flush, the output will be the same.
    cout << "only a test" << flush;
 
    // Use of ends Manipulator
    cout << "\na";
 
    // NULL character will be added in the Output
    cout << "b" << ends;
    cout << "c" << endl;
 
    return 0;
}
Programmer
only a test
abc
```

## Manipulators with Arguments
- Some of the manipulators are used with the argument like setw (20), setfill (‘*’), and many more. These all are defined in the header file. If we want to use these manipulators then we must include this header file in our program. For Example, you can use following manipulators to set minimum width and fill the empty space with any character you want: std::cout << std::setw (6) << std::setfill (’*’);

- Some important manipulators in <iomanip> are:
    - setw (val): It is used to set the field width in output operations.
        -  Bu örnekte, setw(10) ile text değişkeninin çıktıda 10 karakterlik bir alan kaplayacağı belirtilir. setw(5) ile ise number değişkeninin çıktıda 5 karakterlik bir alan kaplayacağı belirtilir. Bu şekilde çıktı alanları belirli genişlikte düzenlenir.

    - setfill (c): It is used to fill the character ‘c’ on output stream.
        - ex_exp: Bu örnekte, setfill('*') ile setw(10) tarafından belirtilen alanın boş kalan kısmı * karakteri ile doldurulur.
    - setprecision (val): It sets val as the new value for the precision of floating-point values.
        - ex_exp: Bu örnekte, setprecision(5) ile pi değişkeninin ondalık hassasiyeti 5 olarak ayarlanır.

    - setbase(val): It is used to set the numeric base value for numeric values.
        - ex_exp: Bu örnekte, setbase(8) ile number değişkeni 8'lik (oktal) sayısal tabanda gösterilir.

    - setiosflags(flag): It is used to set the format flags specified by parameter mask.
    - resetiosflags(m): It is used to reset the format flags specified by parameter mask.
        - ex_exp: Bu örnekte, setiosflags(std::ios::hex) ile number değişkeni onaltılık (hexadecimal) olarak gösterilir. resetiosflags(std::ios::hex) ile ise önceki format bayrağı sıfırlanarak tekrar ondalık (decimal) olarak gösterim yapılır.
        
- Some important manipulators in <ios> are:
    - showpos: It forces to show a positive sign on positive numbers.
    - noshowpos: It forces not to write a positive sign on positive numbers.
    - showbase: It indicates the numeric base of numeric values.
    - uppercase: It forces uppercase letters for numeric values.
    - nouppercase: It forces lowercase letters for numeric values.
    - fixed: It uses decimal notation for floating-point values.
    - scientific: It uses scientific floating-point notation.
    - hex: Read and write hexadecimal values for integers and it works same as the setbase(16).
    - dec: Read and write decimal values for integers i.e. setbase(10).
    - oct: Read and write octal values for integers i.e. setbase(10).
    - left: It adjusts output to the left.
    - right: It adjusts output to the right.