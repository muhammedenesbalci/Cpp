# Static Keyword

The static keyword has different meanings when used with different types. We can use static keywords with:

- Static Variables: Variables in a function, Variables in a class
- Static Members of Class: Class objects and Functions in a class Let us now look at each one of these uses of static in detail.
- (Önemli)statik değişkenlere bir alan ayrılır o alan ve o alanı işaret eden pointer aynıdır hep bu yüzden değerlerini taşıyorlar. 

## Content
- [Static Variables in a Function](#static-variables-in-a-function)
- [Static variables in a class](#static-variables-in-a-class)
- [Static objects of Class](#static-objects-of-class)
- [Static Functions in a class](#static-functions-in-a-class)
- [extra](#extra)
## Static Variables in a Function
- Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of the variable in the previous call gets carried through the next function call. This is useful for implementing coroutines in C/C++ or any other application where the previous state of function needs to be stored. 
- You can see in the above program that the variable count is declared static. So, its value is carried through the function calls. The variable count is not getting initialized every time the function is called.
- fonksiyonun içinde oluşturulan bu static count o fonksiyona özel olur başka yerlerden çağıramayız.
- return static
    - fonksiyonun içinde çağrılan static değişkeni de aslında bir şekilde dışa aktarabiliriz. Bunu fonksiyonların içinde kullanılan local değişkenleri dışarı aktarmak istediğinde kullanabilirsin. arraylar vs. ama tabi bu değeri değiştiriken sıkıntılar yaşlyabilirsin. Çünkü hem dışarıdan hemde içeriden değiştiriliebilir olabilir. adresini veya referansını dışarıya veriyoruz çünkü ve onun üzerinde ulaşıyoruz. aynısını referanslar ile de yapabiliriz.

- fonksiyonun içindeki static değişkene, fonksiyona paremetre  olarak aldığımız değişkeni atayamayız. başlangıç değeri olarak.

## Static variables in a class
- As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of the same static variables for different objects. Also because of this reason static variables can not be initialized using constructors. 
- ex1 exp: You can see in the above program that we have tried to create multiple copies of the static variable i for multiple objects. But this didn’t happen. So, a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class as shown below: 
- clasın içindeki(header dosyasında) static veriye derğer atamak isterken constructorun içinde değil tamamane dışarda tanımlamalıyız. farklı dosyada veya cpp dosyasında yapılabilir. header dosyasında değil.
- static veriyi kullanabilmek için tanımlama yapmak yeterli değil kesinlikle initilization yapmalısın boş veya dolu. Yoksa kullanamazsın. boş yaparsan 0 dır başlangıç değeri.initializationdan kasıt scope operatoru ile tanımlanarak değer atanması veya atanmaması. Kullanmadan önce kesinlike scop operatörü ile değer atamalısın.
- classın içinde declaration yaparken direkt değer atamak istiyorsan const kullanmalısın
- değer atama yapılırken bir fonksiyon içinde olmamalısın global şekilde tanımlama yapmalıyız.
- static veriye illa obje üzerinden ulaşmak zorunda değilsin classın scopunu kullanarak da ulaşabilrsin. class scopunu veya bir obje kullanmzsan ulaşamazsın.
- static const değerlere direkt olduğu yerde değer atayabiliriz. static int a = 5; gibi classınn içinde. tabi dışarıda da atayabiliriz. classın içinde sadece bildiri yaparız


## Static objects of class
- Just like variables, objects also when declared as static have a scope till the lifetime of the program. Consider the below program where the object is non-static. 
- ex1 exp: In the above program, the object is declared inside the if block as non-static. So, the scope of a variable is inside the if block only. So when the object is created the constructor is invoked and soon as the control of if block gets over the destructor is invoked as the scope of the object is inside the if block only where it is declared. 
- exp2 expl: You can clearly see the change in output. Now the destructor is invoked after the end of the main. This happened because the scope of static objects is throughout the lifetime of the program.
- class objesini static olarak oluşturudğumuzda program bitene kadar devam eder. 
    - İlk örnekte static tanımlamıyoruz ve if den çıkarken önce obje yok ediliyor sonra end of main yazıyor.
    - ikinci örnekte static tanımlıyorz ve if den çıktıktan sonra end of main yazıyor daha sonra program bitince obje yok ediliyor

## Static Functions in a class
- Just like the static data members or static variables inside the class, static member functions also do not depend on the object of the class. We are allowed to invoke a static member function using the object and the ‘.’ operator but it is recommended to invoke the static members using the class name and the scope resolution operator. 
- Static member functions are allowed to access only the static data members or other static member functions, they can not access the non-static data members or member functions of the class. 
- static fonksiyonlardan static değişkenlere direkt ulaşlabilirz ama statik olmyayan değişkenlerde direkt ulaşamıyız bir objeye ihtiyacımız olucaktır
- Statik fonksiyonlar, belirli bir işleve sahip olan ve nesne durumuna bağlı olmayan işlevleri gruplamak için kullanışlıdır. Bu, kodun organizasyonunu ve anlaşılabilirliğini artırır. Fonksiyonlar, sınıfın bir parçası olarak mantıksal bir grup oluşturur, ancak nesne durumu ile etkileşime girmedikleri için statik olarak tanımlanırlar.
    ```cpp
    class Cal {
    public:
        static int add(int a, int b) { 
            return a + b; 
        }

        static int add(int a, int b, int c){
            return a + b + c;
        }
    };

    void use_of_overloading_functions_1() {
        Cal C; // class object declaration.
        cout << C.add(10, 20) << endl;
        cout << C.add(12, 20, 23)<< endl;;
    }
    ```
## extra
- static değişkenlere veya fonksiyonlaraa class scopu kullanarak direkt ulaşabiliriz veya bir obje de oluşturabilirz. class içinde veya dışında
- static olmayan değişkenlere veya fonksiyonlara direkt ulaşamayız, bir obje oluşturmalıyız ve onun vasıtasıyla ulaşmalıyız. classın dışındayken
- staticler kullanıldığı scope ve oonun alt scoplarından ulaşılabilir. Mesela global tanımlarsan o file daki bütün her yerden ulaşılabilir. ama fonksiyonun içinde tanımlarsan sadece o fonksiyondan ulaşılabilir.
- static değişkenler sadece statik değişkenlere direkt ulaşabilir onun dışındakilere obje yardımıyla ulaşabilir.