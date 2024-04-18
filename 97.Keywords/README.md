# Cpp Keywords
- C++ is a powerful language. In C++, we can write structured programs and object-oriented programs also. C++ is a superset of C and therefore most constructs of C are legal in C++ with their meaning unchanged. However, there are some exceptions and additions.

## Token
- When the compiler is processing the source code of a C++ program, each group of characters separated by white space is called a token. Tokens are the smallest individual units in a program. A C++ program is written using tokens. It has the following tokens
    - Keywords
    - Identifiers
    - Constants
    - Strings
    - Operators

## Identifiers
- Identifiers refer to the name of variables, functions, arrays, classes, etc. created by the programmer. They are the fundamental requirement of any language.
- Rules for naming identifiers:

    - Identifier names can not start with a digit or any special character.
    - A keyword cannot be used as an identifier name.
    - Only alphabetic characters, digits, and underscores are permitted.
    - The upper case and lower case letters are distinct. i.e., A and a are different in C++.
    - The valid identifiers are GFG, gfg, and geeks_for_geeks.
    
## Keywords
- Keywords(also known as reserved words)  have special meanings to the C++ compiler and are always written or typed in short(lower) cases. Keywords are words that the language uses for a special purpose, such as void, int, public, etc. It can’t be used for a variable name or function name or any other identifiers. The total count of reserved keywords is 95. Below is the table for some commonly used C++ keywords.

1. **alignas**: Değişken veya yapıların hafıza hizalamasını belirlemek için kullanılır.
    - **Notes**: 
        - alignas kullandığmızda hafızayı otomatik ayarlıyor kullanmadığımızda kendi ekleme yapıyor. ilki 16 oluyor diğeri 12 örnekler.

        - CustomData yapısının boyutunun beklenenden fazla çıkması, derleyicinin hafıza hizalaması ve dolgu (padding) alanları eklemesiyle ilgilidir. Bu durum, yapı içindeki veri tiplerinin hafıza hizalaması ve bellek boyutlarıyla ilgilidir.

        - Örnekte CustomData yapısının üyeleri şu şekildedir:
            ```
                value1 (int): 4 byte
                value2 (float): 4 byte
                value3 (char): 1 byte
            ```
        - Toplamda, üyelerin toplam boyutu 4 + 4 + 1 = 9 bytedır. Ancak sizeof(CustomData) ifadesi 12 byte olarak hesaplanıyor. Bu farkın nedeni, derleyicinin yapının hafıza hizalamasını sağlamak için ekstra dolgu alanları eklemesiyle ilgilidir.

        - Derleyiciler, veri yapılarını hafıza hizalamasına uygun hale getirmek için otomatik olarak dolgu alanları eklerler. 
        - Hafıza hizalaması, derleyicinin bellek erişimini optimize etmek için kullandığı bir tekniktir. Özellikle CPU'ların verimli çalışabilmesi için belirli hafıza hizalamalarına uygun veri yapıları önemlidir.

        - Derleyicinin hafıza hizalaması için eklediği dolgu alanları, yapı içindeki veri tiplerinin hafıza gereksinimleri ve hafıza hizalamasıyla ilgilidir. 
        - Örneğin, float tipi genellikle 4-byte hafıza hizalamasına sahiptir ve char tipi ise 1-byte hafıza hizalamasına sahiptir. Bu nedenle, float ve char tipi arasındaki dolgu alanı eklenmiş olabilir.

        - Hafıza hizalaması ve dolgu alanları derleyiciden derleyiciye farklılık gösterebilir. 
        Derleyici, platform ve derleme ayarlarına bağlı olarak farklı hafıza hizalaması stratejileri kullanabilir. Bu nedenle, sizeof operatörüyle elde edilen yapı boyutları beklenenden farklı olabilir.

        - Eğer alignas anahtar kelimesini kullanarak belirli bir hafıza hizalaması sağlamak istiyorsanız, yapının içindeki veri tiplerini ve sıralamasını dikkatlice kontrol etmeniz önemlidir. alignas kullanarak yapıyı belirli bir hafıza hizalamasına oturtmak, derleyicinin ekstra dolgu alanları eklemesini engelleyebilir ve beklenen yapı boyutunu sağlayabilir.

        - Sonuç olarak, yapı içindeki veri tiplerinin hafıza hizalaması ve derleyicinin eklediği dolgu alanları yapı boyutunu etkileyebilir.
        - Bu nedenle, yapıyı tasarlarken ve boyutunu kontrol ederken bu faktörleri göz önünde bulundurmanız önemlidir.

        - Dolgu (Padding) Alanları: Derleyiciler, yapı içindeki veri tiplerinin hafıza hizalamasını sağlamak için dolgu (padding) alanları ekleyebilir. 
        Özellikle, daha büyük hafıza hizalamasına sahip veri tipleriyle daha küçük hafıza hizalamasına sahip veri tipleri arasında boşluklar oluşturulabilir. 
        Bu dolgu alanları, yapıların bellekte daha düzenli ve verimli bir şekilde yerleştirilmesini sağlar.

        - Optimizasyon ve Performans: Hafıza hizalaması ve dolgu alanları, genellikle donanıma uygun veri yapıları oluşturmak için kullanılır. Özellikle bellek erişimini optimize etmek ve veri işleme performansını artırmak için önemlidir.

2. **alignof**: Bir türün hafıza hizalamasını (byte cinsinden) veren bir operatördür.
    - **Notes**: 
        - alignof C++'ta (C++11 standardından itibaren) tanıtılan bir operatördür ve bir veri tipinin veya bir nesnenin gerektirdiği hafıza hizalamasını (alignment) döndüren bir operatördür. Bu operatör, #include <cstddef> başlık dosyası içinde tanımlanmıştır ve alignof operatörüyle bir veri tipinin hafıza hizalaması compile-time (derleme zamanı) olarak elde edilebilir.

        - alignof operatörü, bir veri tipinin veya bir nesnenin bellekteki uygun hafıza hizalamasını belirtir. 

        - Hafıza hizalaması, bir veri tipinin bellekteki başlangıç adresinin hangi sınırlı tam sayı katlarına hizalandığına işaret eder. Özellikle, modern bilgisayar mimarilerinde veri tiplerinin belirli hafıza hizalamalarına uygun olması performansı artırabilir ve hatalı bellek erişimlerini önleyebilir.

        - alignof operatörü, tekil bir veri tipi için kullanıldığında o veri tipinin hafıza hizalamasını döndürür. Ayrıca, bir nesne veya bir yapı türü için kullanıldığında, bu nesnenin veya yapının gerektirdiği en büyük hafıza hizalamasını döndürür(struct örneğinde char ı int veya float ın hizalamasına göre döndürüyor).

        - **Hafıza hizalanması**(memory alignment), bilgisayar bilimlerinde ve bilgisayar mühendisliğinde kullanılan bir terimdir. Bu terim, veri yapılarının veya nesnelerin bellekteki yerleşimini düzenlemek için kullanılan bir kavramı ifade eder.

        - Hafıza hizalanması, bir veri tipinin bellekteki başlangıç adresinin belirli bir sınırlı tam sayı katlarına hizalanması işlemidir. Yani, bir veri tipinin bellekteki adresi, belirli bir hafıza hizalamasına (alignment) uygun olacak şekilde yerleştirilir. Bu hizalama işlemi, genellikle donanıma özgü performans gereksinimlerini karşılamak ve bellek erişimini optimize etmek amacıyla yapılır.

        - Bellek hizalanması, özellikle veri yapıları ve nesnelerin bellekteki yerleşimini düzenlerken önemlidir. Veri tipleri, belirli bir hafıza hizalamasına sahip olabilir. Örneğin, bir int genellikle 4 byte hafıza hizalamasına sahiptir, bu da int tipinin bellekteki adresinin 4'e tam bölünebilir olması gerektiği anlamına gelir. Benzer şekilde, double tipi genellikle 8 byte hafıza hizalamasına sahiptir.
        
        - Hafıza hizalanması, derleyiciler ve işletim sistemleri tarafından yönetilir ve donanım özelliklerine (örneğin, işlemci mimarisine) bağlı olarak değişebilir. Bellek hizalanması, bilgisayar sistemlerinin performansını ve verimliliğini artırmak için önemli bir optimizasyon tekniktir.

- and: İki veya daha fazla koşulun mantıksal "ve" operatörü.
- and_eq: Bit seviyesinde "ve" operatörü ve atama.
    - example explanation:
        - and_eq C++'da bit düzeyinde bir AND işlemi ve atama işlemini birleştiren bir işleçtir. Bu işleç, kısaca &= olarak da bilinir. İki işlemciyi birbiriyle AND operasyonuna tabi tutar ve sonucu ilk işlemciye atar. İşte basit bir and_eq. Bitwise olarak karşılaştırtıerkrn kullnadığımız & ve | operatorunun aynısı sadece burada atamayı da yapıyor.
        - x değişkeninin değeri 12 (1100 ikili olarak) ve y değişkeninin değeri 10 (1010 ikili olarak).
        - x and_eq y; ifadesi, x ve y'nin ikili temsillerindeki karşılık gelen bitler üzerinde AND operasyonu yapar.
        - İkisi de 1 olan bitler sonuçta da 1 olarak kalır, diğer bitler 0 olur. Bu durumda, 1100 AND 1010 = 1000 (decimal olarak 8).
        - Sonuç ekrana yazdırılır ve 8 olarak görüntülenir.
        - Bu şekilde and_eq işleci, bit düzeyinde işlemler için kullanışlı olabilir.

- asm: Makro düzeyinde iç içe geçmiş assembly kodu eklemek için kullanılır.
    - asm anahtar kelimesi, C veya C++ kodunun içine doğrudan assembly dilinde yazılmış kod parçalarını (genellikle "inline assembly" olarak adlandırılır) eklemek için kullanılır. Bu, programcılara işlemciye özel komutları doğrudan kullanma imkanı tanır ve böylece belirli işlemleri çok düşük seviyede kontrol etmeye olanak sağlar.
    - Inline assembly kullanımı, yüksek seviye dillerin sağlayamayacağı bir kontrol ve işlemci özgü optimizasyonları mümkün kılar. Ancak, bu kodlar doğrudan işlemciye özel olduğu için yazılan kodlar genellikle sadece o tür işlemcilerde çalışır ve taşınabilir değildir. Ayrıca, assembly dilinin karmaşıklığı ve düşük seviye doğası nedeniyle, hata yapma riski daha yüksektir ve kodun bakımı zorlaşabilir.
    - example expl: src değişkeni dest değişkenine kopyalanır ve ardından dest'e 1 eklenir. asm bloğunda iki satır assembly kodu vardır ve GCC özgü "Extended ASM" syntaxı kullanılmıştır. Bu örnek, assembly kodunun C++ içinde nasıl kullanılabileceğini gösterir. Ancak unutmayın ki, inline assembly'nin kullanımı derleyiciye bağlıdır ve bu örnekte GCC için yazılmıştır.

- auto: Otomatik tür belirleme için kullanılır (C++11'den itibaren).
    - C++11 ile tanıtılan auto anahtar kelimesi, değişkenlerin türlerinin derleyici tarafından otomatik olarak belirlenmesine olanak tanır. Bu özellik, kod yazımını daha temiz ve okunabilir hale getirir ve aynı zamanda programcının tür dönüşümü hatalarını azaltmasına yardımcı olur. auto kullanarak, bir değişkenin türü, o değişkene atanmış ifadenin türüne bağlı olarak otomatik olarak çıkarılır.

    - auto Anahtar Kelimesinin Avantajları
        - Tür Güvenliği: Tür çıkarımı sayesinde, yanlış tür kullanımından kaynaklanan hatalar azalır.
        - Kod Temizliği: Kod daha temiz ve okunabilir hale gelir, özellikle STL gibi kütüphanelerle çalışırken.
        - Bakım Kolaylığı: Kodun bakımı kolaylaşır çünkü tür değişiklikleri otomatik olarak yönetilir.
        - STL ile Uyumluluk: STL container'larla ve algoritmalarla çalışırken auto kullanmak, iteratör türlerini elle yazmaktan kaçınmayı sağlar.

    - Bu örnekte, numbers isimli bir std::vector<int> koleksiyonu oluşturulmuş ve bu koleksiyonun içindeki elemanlar bir döngü ile yazdırılmaktadır. for döngüsünde kullanılan auto anahtar kelimesi, num değişkeninin türünü std::vector<int>::value_type yani int olarak otomatik olarak belirler. Böylece, döngü her bir eleman üzerinde iterasyon yaparken tür konusunda bir hata oluşmaz ve kodun okunurluğu artar.

    - auto kullanımı, modern C++ programlamada yaygın bir uygulamadır ve özellikle karmaşık tür isimleri veya template kullanımı gerektiren durumlarda çok faydalıdır.
    - example explanation: 
        - numbers isimli bir std::vector<int> koleksiyonu oluşturulmuş ve bu koleksiyonun içindeki elemanlar bir döngü ile yazdırılmaktadır. for döngüsünde kullanılan auto anahtar kelimesi, num değişkeninin türünü std::vector<int>::value_type yani int olarak otomatik olarak belirler. Böylece, döngü her bir eleman üzerinde iterasyon yaparken tür konusunda bir hata oluşmaz ve kodun okunurluğu artar.

        - auto kullanımı, modern C++ programlamada yaygın bir uygulamadır ve özellikle karmaşık tür isimleri veya template kullanımı gerektiren durumlarda çok faydalıdır.

- bitand: Bit seviyesinde "ve" operatörü.
    - C++'da bitand ve bitor anahtar kelimeleri, sırasıyla bitwise AND (&) ve bitwise OR (|) operatörlerine alternatif isimlerdir. Bu anahtar kelimeler özellikle bazı sistemlerde veya durumlarda & ve | sembollerinin özel karakterler olarak kabul edilmesi durumunda kullanılır. Genellikle bu sembollerin kullanımını tercih etsek de, bitand ve bitor daha açıklayıcı olabilir.
    - Bitwise AND operatörü (&), karşılık gelen bitleri AND işlemine tabi tutar. Yani, her iki sayının da bitleri 1 ise sonuçta o bit 1 olur, aksi takdirde 0 olur.
    - example exp: Bu örnekte, 12 (1100) ve 10 (1010) sayılarının bitwise AND işlemi yapılıyor. Sonuç 8 (1000) olacaktır çünkü yalnızca ikinci bit her iki sayıda da 1'dir.

- bitor: Bit seviyesinde "veya" operatörü.
    - C++'da bitand ve bitor anahtar kelimeleri, sırasıyla bitwise AND (&) ve bitwise OR (|) operatörlerine alternatif isimlerdir. Bu anahtar kelimeler özellikle bazı sistemlerde veya durumlarda & ve | sembollerinin özel karakterler olarak kabul edilmesi durumunda kullanılır. Genellikle bu sembollerin kullanımını tercih etsek de, bitand ve bitor daha açıklayıcı olabilir.
    - Bitwise OR operatörü (|), karşılık gelen bitleri OR işlemine tabi tutar. Yani, bitlerden en az biri 1 ise sonuçtaki o bit 1 olur.
    - example exp: Bu örnekte, 12 (1100) ve 10 (1010) sayılarının bitwise OR işlemi yapılıyor. Sonuç 14 (1110) olacaktır çünkü en az bir bit sıfır hariç her pozisyonda 1'dir.

- bool: Mantıksal veri tipini temsil eder (true veya false).

- break: Döngü veya switch ifadesinden çıkmak için kullanılır.

- case: Switch ifadesinde belirli bir durumu temsil eder.

- catch: İstisnai durumları yakalamak için kullanılır (try-catch bloklarında).

- char: Karakter veri tipini temsil eder.
- char8_t: UTF-8 karakterlerini temsil etmek için kullanılır (C++20'den itibaren).
- char16_t: UTF-16 karakterlerini temsil etmek için kullanılır.
- char32_t: UTF-32 karakterlerini temsil etmek için kullanılır.
    - UTF-8, UTF-16 ve UTF-32, Unicode karakter kodlamalarını temsil etmek için kullanılan farklı metin kodlama formatlarıdır. Unicode, dünya genelinde kullanılan tüm karakterleri kapsayan bir karakter kodlama standardıdır. Unicode, her bir karaktere benzersiz bir sayısal değer (code point) atar ve bu değerler farklı kodlama formatlarıyla bilgisayar ortamında depolanabilir ve iletilir.
    - UTF-8: 
        - Karakter Kodlama Biçimi: UTF-8, Unicode karakterlerini en yaygın kullanılan değişken uzunlukta kodlama biçimidir.
        - Temel Özellikler:
        - Her karakteri 1 ila 4 byte arasında değişen uzunlukta temsil eder.
        - İngilizce ve diğer Batı dillerinde kullanılan ASCII karakterleri 1 byte ile temsil edilir.
        - Unicode karakterlerinin çoğu 2 veya 3 byte ile kodlanır.
        - UTF-8, ASCII uyumludur ve mevcut ASCII metinlerini doğrudan destekler.
    - UTF-16: 
        - Karakter Kodlama Biçimi: UTF-16, Unicode karakterlerini 16-bit veya 32-bit kodlama biçiminde temsil eder.
        - Temel Özellikler:
            - Her karakteri 2 veya 4 byte ile temsil eder.
            - Temel BMP (Basic Multilingual Plane) karakterleri (U+0000 ile U+FFFF arası) 2 byte ile kodlanır.
            - Diğer karakterler, 4 byte ile kodlanır ve bir çift 16-bit kod noktası (surrogate pair) kullanılır.
            - UTF-16, eski Unicode kodlamalarıyla uyumludur.
    - UTF-32:
        - Karakter Kodlama Biçimi: UTF-32, Unicode karakterlerini sabit 32-bit (4 byte) kodlama biçiminde temsil eder.
        - Temel Özellikler:
        - Her karakteri sabit olarak 4 byte ile temsil eder.
        - Her Unicode karakteri doğrudan tek bir 32-bit kod noktasıyla temsil edilir.
        - UTF-32, bellek kullanımı açısından diğerlerine göre daha fazla alan gerektirir ancak karakterlere sabit boyutla erişim sağlar.

    - Farklar ve Kullanım Alanları
        - UTF-8 vs. UTF-16: UTF-8, internet üzerinde çok yaygın olan ve esnek bir karakter kodlama biçimidir. UTF-16 ise genellikle Windows işletim sistemlerinde ve bazı programlama dillerinde kullanılır.
        - UTF-16 vs. UTF-32: UTF-16, Unicode karakterlerinin büyük çoğunluğunu iki byte ile temsil ederken, UTF-32 her karakter için sabit bir 4-byte uzunluk kullanır.
        - UTF-8 ve UTF-16 Karşılaştırması: UTF-8, daha düşük bellek kullanımı ve ASCII uyumluluğu ile tercih edilirken, UTF-16 daha hızlı karakter erişimine ve bellek maliyetlerinin bazı durumlarda daha düşük olmasına olanak tanır.

    - unicode: 
        - Unicode, dünya genelinde kullanılan tüm karakterleri kapsayan ve her bir karaktere benzersiz bir sayısal değer (code point) atayan bir karakter kodlama standardıdır. Unicode'un temel amacı, farklı dillerdeki ve yazı sistemlerindeki tüm karakterleri tek bir standart altında birleştirmek ve bilgisayar sistemlerinde tutarlı bir şekilde temsil etmektir.

        - Unicode'un temel özellikleri şunlardır:

            - Kapsamlı Karakter Seti: Unicode, dünya genelindeki tüm dillerin alfabelerini, sembollerini, rakamlarını, işaretlerini ve diğer yazı karakterlerini kapsar. Çin, Japon, Arap, Hint gibi farklı yazı sistemlerinden Latin alfabesine, matematiksel sembollerden emoji'ye kadar geniş bir karakter yelpazesini destekler.

            - Benzersiz Code Pointler: Unicode her bir karaktere benzersiz bir sayısal değer atar. Bu sayısal değerlere "code point" denir ve 0 ile 0x10FFFF (1,114,112 kadar) arasındadır. Her Unicode karakteri bu code pointlerden birine karşılık gelir.

            - Kodlama Biçimleri: Unicode karakterleri bilgisayar sistemlerinde depolamak ve iletmek için çeşitli kodlama biçimleri kullanılır. Bunlar arasında UTF-8, UTF-16 ve UTF-32 gibi yaygın olanlar bulunur. Her bir kodlama biçimi, Unicode code pointlerini farklı şekilde baytlara dönüştürerek temsil eder.

            - Unicode Consoritum: Unicode standardı, Unicode Consortium adı verilen uluslararası bir organizasyon tarafından yönetilir. Bu organizasyon, Unicode standardının geliştirilmesi, güncellenmesi ve yaygınlaştırılmasıyla ilgilenir.


- class: Sınıf tanımını belirtmek için kullanılır.

- **Coroutines**: 
    - Coroutines (işbirlikçi hesaplamalar), programlama dilindeki bir işlemi duraklatma, sonra devam ettirme ve bu süreçte kaynakları serbest bırakma yeteneği sağlayan bir programlama kavramıdır. Coroutines, asenkron ve kooperatif programlama için kullanılır ve özellikle uzun süren veya giriş/çıkış (I/O) işlemleri gerektiren durumlarda faydalıdır.
    - Coroutines'in temel amacı, bir işlemin yarıda kesilip daha sonra devam ettirilebilmesini sağlamaktır. Bu işlemler genellikle bir iş parçacığı (thread) içinde çalışır ve işlemci kaynaklarını daha etkin bir şekilde kullanmaya yardımcı olur. Coroutines, aynı zamanda asenkron programlama modellerini daha kolay ve doğal bir şekilde uygulamaya olanak tanır.
        - Coroutines'in ana özellikleri şunlardır
            1. Duraklatma ve Devam Etme (Yield ve Resume): Bir coroutine çalışırken, belirli bir noktada duraklatılabilir (yield) ve daha sonra aynı noktadan devam ettirilebilir (resume). Bu, coroutine'in çalışmasını yarıda kesip kaynakları serbest bırakmasına olanak tanır.
            2. Kooperatif Çalışma: Coroutines, işbirlikçi (cooperative) bir şekilde çalışır. Yani bir coroutine, başka bir coroutine'e kontrolü devretmek istediğinde veya bir coroutine, başka bir işlemi beklemesi gerektiğinde, bu işbirliği kooperatif olarak sağlanır. Bu, iş parçacıkları (threads) arasındaki sık geçişlerin (context switch) gerekmediği daha hafif bir paralel programlama modeli sunar.
            3. Asenkron Programlama: Coroutines, asenkron programlama modellerinde yaygın olarak kullanılır. Bir coroutine, uzun süren bir işlemi beklerken (örneğin ağ çağrıları veya disk I/O işlemleri), bu süreçte başka işleri yapabilir veya başka coroutine'lere kontrolü devredebilir.
            4. Asenkron Programlama: Coroutines, asenkron programlama modellerinde yaygın olarak kullanılır. Bir coroutine, uzun süren bir işlemi beklerken (örneğin ağ çağrıları veya disk I/O işlemleri), bu süreçte başka işleri yapabilir veya başka coroutine'lere kontrolü devredebilir.
        - Coroutines, C++20'de co_await, co_yield, co_return gibi anahtar kelimelerle desteklenen bir özelliktir. Benzer coroutine destekleri diğer modern programlama dillerinde de bulunmaktadır. Coroutines, kodun daha okunabilir, yönetilebilir ve performanslı hale gelmesine olanak sağlayan önemli bir programlama paradigmasıdır.

- **Asenkron and Multithreading**:
Asenkron Programlama:

Asenkron programlama, bir işlemin tamamlanmasını beklerken başka işlerin yapılmasına izin veren bir programlama modelidir. İşlemler sıralı olarak değil, başlatılır ve sonuçları beklenirken diğer işlemler devam ettirilebilir.
Asenkron programlama genellikle tek bir iş parçacığında gerçekleşebilir olmasına rağmen, asenkron işlemler başlatıldığında veya sonuçları beklenirken farklı iş parçacıklarında da çalışabilir. Özellikle I/O yoğun işlemler için farklı iş parçacıkları veya olay tabanlı (event-driven) yapılar kullanılabilir.
Multithread Programlama:

Multithread programlama, bir uygulamanın aynı anda birden fazla iş parçacığında çalışmasına izin veren bir programlama modelidir. Bu sayede farklı görevler paralel olarak yürütülebilir.
Multithread programlama, işlemleri farklı iş parçacıklarında (threads) paralel olarak yürütebilir. Her iş parçacığı, genellikle aynı anda farklı bir işi gerçekleştirir.
Asenkron programlama ve multithread programlama arasındaki ana farklar şunlardır:

Kontrol Akışı: Asenkron programlama modelinde, işlemler başlatılır ve sonuçları beklenirken diğer işlerin yapılmasına izin verilir. Multithread programlamada ise işler aynı anda farklı iş parçacıklarında yürütülür.

Senkronizasyon: Asenkron programlama, işlemleri senkronize etmek için callback'ler, promise/future gibi mekanizmalar kullanırken, multithread programlama ise farklı iş parçacıkları arasında senkronizasyon gerektirir (mutex, semaphore gibi araçlar kullanılır).

Performans ve Kaynak Kullanımı: Asenkron programlama genellikle daha hafif ve daha az işlemci kaynağı gerektirirken, multithread programlama daha fazla işlemci kaynağı kullanır ve iş parçacıkları arasında geçiş maliyeti vardır.

Sonuç olarak, asenkron programlama ve multithread programlama arasındaki farklar, programlama ihtiyaçlarına ve sistem gereksinimlerine bağlı olarak tercih edilir. Asenkron programlama genellikle I/O yoğun uygulamalar ve olay tabanlı sistemler için tercih edilirken, multithread programlama ise işlemci yoğun uygulamalar ve paralel işleme gerektiren senaryolar için kullanılır. Her iki programlama modeli de farklı senaryolarda etkili bir şekilde kullanılabilir.için kullanılırken, multithread programlama ise paralel işlemlerin eş zamanlı olarak gerçekleştirilmesi gereken durumlarda tercih edilir.
    
- co_await: Bir bekletme (await) ifadesinin başlangıcını belirtmek için kullanılır (C++20'den itibaren).
- co_return: Bir işlevden değer döndürmek için kullanılır (C++20'den itibaren).
- co_yield: Bir işlevden değer döndürmek üzere kullanılan bir ifadeyi belirtmek için kullanılır (C++20'den itibaren).
- compl: Bitleri tersine çevirme operatörü (~).
- concept: Şablon tür kavramını belirtmek için kullanılır (C++20'den itibaren).
- const: Bir değişkenin değerinin sabit olduğunu belirtmek için kullanılır.
- consteval: Bir ifadenin derleme zamanında değerlendirilmesini belirtmek için kullanılır (C++20'den itibaren).
- constexpr: Bir ifadenin derleme zamanında değerlendirilmesini veya bir fonksiyonun derleme  zamanında değer döndürmesini belirtmek için kullanılır.
- const_cast: Bir nesnenin const niteliğini kaldırmak için kullanılır.
- continue: Döngünün sonraki adımına geçmek için kullanılır.
- decltype: İfade türünü döndüren bir operatördür.
- default: Switch ifadesinde varsayılan durumu belirtmek için kullanılır veya bir sınıfın varsayılan üye işlevini tanımlamak için kullanılır.
- delete: Bir nesnenin bellekten silinmesini sağlayan bir ifade.
- do: Bir döngü başlatmak için kullanılır.
- double: Çift hassasiyetli kayan noktalı sayı veri tipini temsil eder.
- dynamic_cast: Çalışma zamanı tür dönüşümü yapmak için kullanılır.
- else: Bir if ifadesinin yanlış durumunu belirtmek için kullanılır.
- enum: Numaralandırma türünü tanımlamak için kullanılır.
- explicit: Dönüşümlerin otomatik olarak gerçekleşmemesi gerektiğini belirtmek için kullanılır.
- export: Bir modülün bir veya daha fazla bildirimini veya tanımını belirtmek için kullanılır (C++20'den itibaren).
- extern: Bir değişkenin veya fonksiyonun başka bir yerde tanımlanacağını belirtmek için kullanılır.
- false: Boolean false değerini temsil eder.
- float: Tek hassasiyetli kayan noktalı sayı veri tipini temsil eder.
- for: Bir döngü başlatmak için kullanılır.
- friend: Sınıfın özel üye işlevlerine diğer sınıflardan erişim sağlamak için kullanılır.
goto: Program akışını belirli bir etikete yönlendirmek için kullanılır (genellikle tavsiye edilmez).
- if: Bir koşul ifadesi başlatmak için kullanılır.
- inline: Küçük fonksiyonları derleme zamanında yerine geçecek şekilde tanımlamak için
kullanılır.
- int: Tamsayı veri tipini temsil eder.
- long: Uzun tamsayı veri tipini temsil eder.
- mutable: Bir sınıf veri üyesinin const niteliğini geçersiz kılar, böylece değiştirilebilir hale gelir.
- namespace: İsim alanını belirtmek için kullanılır.
- new: Bellekten dinamik olarak alan ayırmak için kullanılır.
- noexcept: Bir fonksiyonun veya ifadenin istisna fırlatmayacağını belirtmek için kullanılır.
- not: Mantıksal "değil" operatörü (!).
- not_eq: Bit seviyesinde "eşit değil" operatörü.
- nullptr: Null işaretçisini temsil eder.
- operator: İşlemci işlevini veya aşırı yüklenmiş operatörü tanımlamak için kullanılır.
- or: İki veya daha fazla koşulun mantıksal "veya" operatörü.
- or_eq: Bit seviyesinde "veya" operatörü ve atama.
- private: Sınıf üyelerinin erişimini belirlemek için kullanılır (sadece sınıf içinden erişilebilir).
- protected: Sınıf üyelerinin erişimini belirlemek için kullanılır (türetilmiş sınıflardan da erişilebilir).
- public: Sınıf üyelerinin erişimini belirlemek için kullanılır (herkes tarafından erişilebilir).
- register: Değişkenin CPU kayıtlarında saklanmasını istediğinizi belirtmek için kullanılır (modern derleyiciler genellikle bu anahtar kelimeyi yoksayarlar).
- reinterpret_cast: Tipler arası değişim yapmak için kullanılır.
- requires: Şablon gereksinimlerini belirtmek için kullanılır (C++20'den itibaren).
- return: Bir fonksiyondan değer döndürmek için kullanılır.
- short: Kısa tamsayı veri tipini temsil eder.
- signed: İşaretli tamsayı veri tipini belirtmek için kullanılır.
- sizeof: Bir türün veya bir nesnenin bellek boyutunu belirtmek için kullanılır.
- static: Bir değişkenin veya fonksiyonun ömrünü belirlemek için kullanılır.
- static_assert: Derleme zamanında bir koşulun sağlanıp sağlanmadığını kontrol etmek için kullanılır.
- static_cast: Tipler arası dönüşüm yapmak için kullanılır.
- struct: Bir yapı (structure) tanımını belirtmek için kullanılır.
- switch: Birden fazla koşul durumunu değerlendirmek için kullanılır.
- template: Şablon tabanlı programlama için kullanılır.
- this: Bir sınıfın işaretçisini (pointer) belirtir.
- thread_local: Konu bağımsız (thread-local) değişkenler için kullanılır (C++11'den itibaren).
- throw: Bir istisna fırlatmak için kullanılır.
- true: Boolean true değerini temsil eder.
- try: Bir istisna yakalama bloğunu başlatmak için kullanılır.
- typedef: Varolan bir türü yeni bir isimle tanımlamak için kullanılır.
- typeid: Bir türün tanımlayıcısını döndüren bir operatördür.
- typename: Şablon tür parametresini belirtmek için kullanılır.
- union: Birlik (union) veri türünü belirtmek için kullanılır.
- unsigned: İşaretsiz tamsayı veri tipini belirtmek için kullanılır.
- using: İsim uzaylarını ve isimleri içeri aktarmak için kullanılır.
- virtual: Sanal işlevleri tanımlamak veya geçersiz kılmak için kullanılır.
- void: Bir fonksiyonun geri dönüş türünü belirtmek için kullanılır veya işlevsiz (void) türü.
- volatile: Bir değişkenin değerinin program akışı dışında değişebileceğini belirtmek için kullanılır.
- wchar_t: Geniş karakter veri tipini temsil eder.
- while: Bir döngü başlatmak için kullanılır.
- xor: İki koşulun mantıksal "özel veya" (XOR) operatörü.
- xor_eq: Bit seviyesinde "özel veya" (XOR) operatörü ve atama.