# Function Overloading
- Function overloading, C++'ta aynı isimde fakat farklı parametre listelerine sahip birden fazla fonksiyon tanımlama yeteneğidir. Bu özellik, fonksiyonların farklı durumlarda çalışmasını sağlamak için kullanılır. 
- normal fonksiyonlarda
- constrcutorlarda 
- static fonksiyonlar
- const veya const olmayacak şekilde overload edilen fonksiyonlar
- Aynı fonksiyon isimlerine sahip farklı scop daki fonksiyonlar.
- syntax
    ```cpp
    add(int a, int b)
    add(double a, double b)
    ```
- farklı namespace aynı fonksiyon overload example
    ```cpp
    #include <iostream>
    using namespace std;
    
    i// New X.h:
    namespace X {
    f(int);
    }
    
    // New Y.h:
    namespace Y {
    f(char);
    }
    
    // New program.c:
    #include "X.h"
    #include "Y.h"
    
    using namespace X;
    using namespace Y;
    
    int main(){
    f('a');   // calls f() from Y.h
    }
    ```
## Not overloadable functions
- bunu ayırt etmenin en iyi yolu şu. Fonksiyonda bir şeyi değiştiriyorsun. çağırıkende bir şeyleri değiştirmen gerekir mu veya değiştirirsen bu farkı fonksiyon ayırt edebilir mi.bir şeyler değiştirmiyorsan ve ayırt edemiyorsa overload edilemez.

- Destructor: Bir sınıfın destructor'ı overload edilemez. Her sınıf yalnızca bir destructor'a sahip olabilir. Parametre vs almıyor zaten.
- Variadic Functions: Değişken sayıda parametre alan fonksiyonlar (variadic functions) overload edilemez.
- Main Function: main fonksiyonu overload edilemez.
- tamamen aynı ama dönüş değerleri farklı olan fonksiyonlar
- ex
    ```cpp
    #include<iostream>
    int foo() { 
    return 10; 
    }
    
    char foo() { 
    return 'a'; 
    }
    
    int main()
    {
    char x = foo();
    getchar();
    return 0;
    }
    ```

- static ve member fonksiyon aynı ada ve parametre listesine sahip olan fonksiyonlar. yani fonksiyonlar arasındaki tek fark static olması olunca bunlar overload edilemez mantıken.
    ```cpp
    #include<iostream>
    class Test {
    static void fun(int i) {}
    void fun(int i) {}   
    };
    
    int main()
    {
    Test t;
    getchar();
    return 0;
    }
    ```

- isimleri aynı ve paremetre olara pointer veya array kabul eden fonksiyonlar. İkiside aynı şey o yüzden overload edilemez.
    ```cpp
    int fun(int *ptr);
    int fun(int ptr[]); // redeclaration of fun(int *ptr)
    ```

- aynı isimde, aynı paremetreli alan. ama başında acces modifier olan fonksiyonlar ovverload edilemez. const volalite gibi. örnek paremetreyi const olarak tanımlamak o paremetrenin normlade de const olduğu anlmına gelmiyor. sadece o fonksiyona girerken değerinin değişemeyeceği anlamına geliyor.
    ```cpp
    #include<iostream>
    #include<stdio.h>
    
    using namespace std;
    
    int f ( int x) {
        return x+10;
    }
    
    int f ( const int x) {
        return x+10;
    }
    
    int main() {     
    int a;
    f(a);
    return 0;
    }
    ```

- tamamen aynı iki fonksiyon ama sadece birinde default paremetreler varsa bu da overload edilmiş olmaz hata verir.
    ```cpp
    #include<iostream>
    #include<stdio.h>
    
    using namespace std;
    
    int f ( int x, int y) {
        return x+10;
    }
    
    int f ( int x, int y = 10) {
        return x+y;
    }
    
    int main() {     
    getchar();
    return 0;
    }
    ```
### variadic Functions
- Variadic functions, değişken sayıda argüman alabilen fonksiyonlardır. C ve C++ dillerinde, variadic functions kullanarak fonksiyonlara farklı sayıda ve türde argümanlar geçirebilirsiniz. En bilinen örneklerinden biri, printf fonksiyonudur.

- **<cstdarg>**: başlık dosyası, C++'ta değişken sayıda argüman alan (variadic) fonksiyonlar yazabilmek için gerekli olan makroları ve türleri tanımlar. C'deki stdarg.h başlık dosyasının C++ karşılığıdır. Bu başlık dosyasını kullanarak va_list, va_start, va_arg, ve va_end gibi makroları ve türleri kullanabilirsiniz.
    - va_list: Variadic argümanları tutan türdür.
    - va_start: Variadic argüman listesinin başlatılması için kullanılır. İlk parametre olarak va_list türünde bir değişken alır ve ikinci parametre olarak sabit bir argüman (variadic fonksiyonun son sabit parametresi) alır.
    - va_arg: Belirtilen türde bir sonraki argümanın alınması için kullanılır. İlk parametre olarak va_list türünde bir değişken alır ve ikinci parametre olarak istenen argüman türünü alır.
    - va_end: Variadic argüman listesinin sonlandırılması için kullanılır. Tek parametre olarak va_list türünde bir değişken alır.
- ex explanations:
    1. fonksiyona ilk gönderidğimiz paremetre burada kaç tane değer göndereceğimiz. bunu sonrasındakiler paremetre oluyor.
    2. fonksiyona ilk gönderidğimiz paremetre sonraki göndereceğimiz argümanların type ını belirten bir string. ilk paremetreden sonrakiler argümant oluyor.

## const keyword
- const fonksiyonlar overload edilebilir. Bir üye fonksiyonun const olarak tanımlanması, bu fonksiyonun sınıfın const nesneleri tarafından çağrıldığında, sınıfın verilerini değiştiremeyeceği anlamına gelir. const üye fonksiyonlar, const olmayan üye fonksiyonlardan farklı olarak kabul edilir ve bu nedenle overload edilebilirler.
- const obje sadece const fonksiyonu çağırabilir. const olmayanları çağıramaz.
- objenin const olmaması durumunda hem const hemde const olmayan fonksiyonları çağırabilir.
    - burada şöyle bir şey gelebilir aklına. const olmayan obje her iksiinide çağırabiliyorsa ve bir fonksiyon const veya non const olarak overload edildiyse hangisini çağırır. burada derleyici bunu ayarlıyor ve const olmayan fonksiyonu çağırıyor yani karışıklık olmuyor.
- example exp.
    - obj.show() çağrısı, const olmayan üye fonksiyonu çağırır, çünkü obj normal bir nesnedir.
    - constObj.show() çağrısı, const üye fonksiyonu çağırır, çünkü constObj const olarak tanımlanmış bir nesnedir.

    - Ek olarak, const olmayan bir nesneyle bile const üye fonksiyon açıkça çağrılabilir:
        - const MyClass* pObj = &obj; ile obj'i const işaretçi ile işaretlediğimizde, pObj->show() const üye fonksiyonu çağırır.(burada tuttuğu değeri const olarak işaretliyoruz o yüzden yine const u çağırıyor)

## Function ambiguity
- fonksiyon belirsizliği, bir fonksiyon çağrısının hangi fonksiyonun çağrılacağını belirleyememesi durumudur. Bu genellikle overload edilen fonksiyonlar arasında seçim yapmanın mümkün olmadığı durumlarda ortaya çıkar. Derleyici, birden fazla uygun fonksiyon bulduğunda ve hangisinin çağrılması gerektiğini kesin olarak belirleyemediğinde bir hata üretir.
- Function ambiguity, derleyicinin bir fonksiyon çağrısının hangi overload edilmiş fonksiyona karşılık geldiğini belirleyemediği durumlarda ortaya çıkar. Bu tür belirsizliklerden kaçınmak için, fonksiyonların parametre türlerini ve sayısını dikkatli bir şekilde belirlemek, açık tür dönüşümleri kullanmak veya daha spesifik fonksiyonlar tanımlamak önemlidir.

    - overloading yaparken dikkat etmen gereken şeylerden biri float değerler. aşağıdaki program hata vericektir. çünkü içine verilen paremetreler geçici değerler bunları özellikle float diye tanımlamamışız. complier bu değrleri default olarak float değil double olarak alır.
        ```cpp
        #include<iostream>
        using namespace std;
        void test(float s,float t)
        {
            cout << "Function with float called ";
        }
        void test(int s, int t)
        {
            cout << "Function with int called ";
        }
        int main() {
            test(3.5, 5.6); // hata
            return 0;
        }
        ```

        - çözmek için.
            - paremtreleri verirken yanlarına f koyabilirz.  gibi
            - static_cast kullanabiliriz 
            - fonksiyonun double alacak şekilde de overload edebiliriz.
                ```cpp
                test(3.5f, 5.6f);
                test(static_cast<float>(3.5), static_cast<float>(5.6));

                void test(double s,double t)
                {
                    cout << "Function with float called ";
                }
                ```