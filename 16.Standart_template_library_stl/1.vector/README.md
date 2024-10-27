
# Vector
- vector, C++ Standard Template Library (STL) içerisinde bulunan bir konteyner (container) sınıfıdır. Dinamik dizi olarak da adlandırılabilir ve elemanlarının dinamik olarak yönetilmesini sağlar. Yani, vektörün boyutu, program çalışırken ihtiyaçlara göre otomatik olarak ayarlanabilir. vector sınıfının bazı temel özellikleri ve kullanım alanları şunlardır:
- Temel Özellikler
    - Dinamik Boyut: vector, eleman ekleme ve çıkarma işlemleri ile boyutunu dinamik olarak değiştirir. Yeni eleman eklendiğinde kapasitesi yeterli değilse, iç kapasitesi otomatik olarak artırılır.
    - Sıralı Erişim: Vektördeki elemanlara indeksleme ile hızlıca erişilebilir. Bu, tıpkı normal dizilerde olduğu gibi vector[index] ile gerçekleştirilir.
    - Bellek Yönetimi: vector, bellek yönetimini otomatik olarak gerçekleştirir. new ve delete operatörleriyle manuel bellek yönetimi gerektirmez.
    - STL Algoritmaları ile Uyumlu: vector, STL algoritmaları ile uyumlu olarak çalışır ve begin(), end(), rbegin(), rend() gibi iterator fonksiyonları destekler.

- Nerelerde Kullanılır?
    - Dinamik Veri Saklama: Boyutu önceden bilinmeyen veya çalışma zamanında değişen veri koleksiyonlarının saklanması gereken durumlarda kullanılır. Örneğin, kullanıcıdan alınan girdiler veya dosyalardan okunan veriler.
    - Dizi İşlemleri: Normal dizilerin yetmediği veya daha esnek bir yapı gerektiren durumlarda, vector kullanılarak eleman ekleme, çıkarma ve erişim işlemleri kolayca yapılabilir.
    - STL Algoritmaları ile Birlikte Kullanım: STL algoritmalarıyla (sort, find, accumulate, vb.) sıkça kullanılır. vector ve STL algoritmaları birlikte, verimli ve esnek veri işleme sağlar.
    - Sıralı Veri Erişimi Gerektiren Durumlar: Verilere sıralı erişim ve işlem yapılması gereken durumlarda (örneğin, bir veri setinin sıralanması) idealdir.

- Ne Zaman Kullanılır?
    - Bellek Yönetimi Gerektiren Durumlar: Manuel bellek yönetiminin zor veya riskli olduğu durumlarda vector kullanarak bu işlemler otomatikleştirilebilir.
    - Esneklik Gerektiğinde: Veri yapısının esnek ve kolayca değiştirilebilir olması gerektiğinde, vector uygun bir çözümdür.
    - Sıklıkla Eleman Eklenip Çıkarılıyorsa: Verilere sık sık eleman ekleme ve çıkarma işlemleri yapılıyorsa, vector bu işlemleri verimli bir şekilde gerçekleştirebilir.

## Content
- [How to work](#how-to-work)
- [Vector Functions](#vector-functions)
- [Algorithms](#algorithms)
- [Most used Algorithms](#most-used-algorithms)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)
- [](#)



## How to work
- C++'ta std::vector, dinamik boyutlandırılabilir bir dizi sağlayan bir veri yapısıdır. Arka planda, std::vector ham bir dizi (raw array) kullanarak elemanları saklar ve bu diziyi gerektiğinde yeniden boyutlandırır. Bu mekanizma, vektörün ihtiyaç duyulduğunda dinamik olarak büyüyebilmesini ve elemanlara rastgele erişim sağlayabilmesini mümkün kılar.
- **Dinamik Bellek Yönetimi**:
    - std::vector arka planda ham bir dizi kullanır. Bu dizi dinamik olarak tahsis edilir ve yönetilir. Elemanlar eklendikçe ve dizinin kapasitesi doldukça, std::vector yeni ve daha büyük bir ham dizi tahsis eder, mevcut elemanları yeni diziye kopyalar ve eski diziyi serbest bırakır. Bu süreç amortize edilmiş sabit zamanlıdır, çünkü kapasite genellikle iki katına çıkarılır.
- **Kapasite ve Boyut**:
    - std::vector'ün size ve capacity kavramları, dinamik boyutlandırma mekanizmasını anlamak için kritiktir.
    - Size: Vektörde şu anda bulunan eleman sayısıdır.
    - Capacity: Vektörün mevcut dizi tahsisi ile tutabileceği maksimum eleman sayısıdır.
- **Kopyalama ve Taşıma:**
    - std::vector, elemanları kopyalama ve taşıma işlemleri için özel constructor'lar ve atama operatörleri kullanır. Bu, vektörün içerdiği elemanları etkin bir şekilde yönetmesini sağlar.
- vector:
    ```cpp
    template <typename T>
    class Vector {
    private:
        T* data;         // Elemanları saklayan dinamik dizi
        size_t size;     // Mevcut eleman sayısı
        size_t capacity; // Tahsis edilen kapasite

    public:
        // Constructor
        Vector() : data(nullptr), size(0), capacity(0) {}

        // Destructor
        ~Vector() {
            delete[] data;
        }

        // push_back fonksiyonu
        void push_back(const T& value) {
            if (size == capacity) {
                resize();
            }
            data[size++] = value;
        }

        // resize fonksiyonu
        void resize() {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        // size fonksiyonu
        size_t getSize() const {
            return size;
        }

        // operator[]
        T& operator[](size_t index) {
            return data[index];
        }
    };
    ```

## Vector Functions
### **Add and delete element**
- push_back(const T& value): Vektörün sonuna bir eleman ekler.

- push_back(T&& value): Vektörün sonuna taşınabilir bir eleman ekler. (std::move kullanarak eleman ekleme. 
    - kopyalamk yerine taşıyoruz özellikle class yapılarını kullanırken çok yararlı)
    - özellikle move diye belirmtezsen ikisini birden kullanır.
    - mesela düşün elemanı vektöre ekledin normal elemana artık ihityacın yok onu move ile taşıyabilirsin.

- pop_back(): Vektörün sonundaki elemanı siler.

- insert(iterator pos, const T& value): Belirtilen konuma bir eleman ekler.
    - direkt index veremiyoruz onun yerine vec.begin() gibi fonksiyonlar kullanıyoruz.
    - vektörün boyunu aşıp aşmadığına da dikkat etmen lazım. hata verir ya da saçma davranışlar sergiler. maximum size dan fazla girmemen lazımm sonuna eklemek istiyorsan.
    - vec.begin() 0 gibi düşünebililrsin. 0. index yani. sonra yanına 1 ekliyoruz 1. index olmuş oluyor.
    - size ile kontrol edebilirsin
    - birde eleman değiştirme değil ekleme yapıyoruz ona dikkat et.
    - vec.begin kullanırekn giridğimiz index dahil oluyor. vec.end kullanırken girdiğimiz index dahil olmuyor ondan bir küçüğünü dahil ediyor. yani end() sonu değil sondan bi sonrasını temsil ediyor aslında. birde şöyle düşün -1 deyince son elemanı almış oluyoruz vec.end() de. vec.begin de yapsak 1. indexi alırdık ama end() kullandığımız zaman sonra 0. idnexi alıyoruz.

- insert(iterator pos, T&& value): Belirtilen konuma taşınabilir bir eleman ekler.

- insert(iterator pos, size_type count, const T& value): Belirtilen konuma belirli sayıda eleman ekler.
    - belli bir konuma birden fazla sayıda aynı elemanları ekler.

- insert(iterator pos, InputIt first, InputIt last): Belirtilen konuma başka bir vectorden elemanlar ekler.
    - direkt initilizar list ile de ekleyebiliriz.

- erase(iterator pos): Belirtilen konumdaki elemanı siler.

- erase(iterator first, iterator last): Belirtilen aralıktaki elemanları siler.

- clear(): Vektördeki tüm elemanları siler.

- emplace(iterator pos, Args&&... args): Belirtilen konuma bir eleman yerleştirir.

- emplace_back(Args&&... args): Vektörün sonuna bir eleman yerleştirir.


### **Elemanlara Erişim**
- operator[]: Belirtilen indeksteki elemanı döner. (Sınır kontrolü yapmaz)
    - fazla eleman girersek yine ulaşabiliyoruz ama mantıklı sonuçlar dönmüyor mantıken.
    - değer de değiştirebiliyoruz bu operatörle.

- at(size_type pos): Belirtilen indeksteki elemanı döner. (Sınır kontrolü yapar ve eğer indeks geçersizse istisna fırlatır)
    - indexten fazla elemana ulaşmaya çalışınca out of range erroru fırlatıyor.

- front(): Vektörün ilk elemanını döner.
    - elemanı da değiştirebiliyoruz aynı zamanda.

- back(): Vektörün son elemanını döner.
    - elemanı da değiştirebiliyoruz aynı zamanda.

- data(): Vektörün iç verilerine doğrudan erişim sağlar ve bir işaretçi döner.
    - arraylerde kullandığımız pointer aritemtiğini sağlıyor bize.

### **Iteratörler**
- iteraötürler ptr lar gibi çalışıyor ama tam olarak ptr aritmetiği geçerli değil gibi.(yorum satırına aldım bak çalışmayana)

- it i direkt yazdıramıyoruz unutma, büyük ihitmalle ptr(*) ı overload etmiştir.

- ptr aritmetiği kullanarak nasıl yazabileceğimizin örneğini kodda yaptım.

- iteratörler kullanarak eleman ekleme veya çıkartma yapabiliyoruz zaten.

- normal_iterator, reverse_iterator, const_iterator . gibi iterator çeşitleri var.

    - begin(): Vektörün başını işaret eden bir iterator döner.
        - O'ıncı indexi işaret eden iteratör döner.
    - end(): Vektörün sonunu işaret eden bir iterator döner.
        - son elemanı değil sondan bir sonraki elemanı işaret eder. yani son elemana ulaşmak isitoyrsan  end -1 demelisin.
    - rbegin(): Vektörün ters başını işaret eden bir reverse_iterator döner.
    - rend(): Vektörün ters sonunu işaret eden bir reverse_iterator döner.
    - cbegin(): Vektörün başını işaret eden bir const_iterator döner.
    - cend(): Vektörün sonunu işaret eden bir const_iterator döner.
    - crbegin(): Vektörün ters başını işaret eden bir const_reverse_iterator döner.
    - crend(): Vektörün ters sonunu işaret eden bir const_reverse_iterator döner.

### **Atama ve Karşılaştırma**
- operator=(const vector& other): Bir vektörü başka bir vektöre kopyalar.
- operator=(vector&& other): Bir vektörü başka bir vektöre taşır.
- operator=(initializer_list<T> ilist): Bir vektöre initializer_list atar.
- assign(size_type count, const T& value): Vektöre belirli sayıda eleman atar.
- assign(InputIt first, InputIt last): Vektöre başka bir aralıktan elemanlar atar.
- assign(initializer_list<T> ilist): Vektöre initializer_list'den elemanlar atar.

### **Diğer Yardımcı Fonksiyonlar**
- swap(vector& other): İki vektörün içeriklerini takas eder.
- get_allocator(): Vektörün belleği yönetmek için kullandığı allocator'u döner.

### **Kapasite Yönetimi**
- orjinal değerleri görebilmek için fonksiyona sokarken referansla sok ki kopyalama yapmasın. kopyalama yapınca orjinal vektörrün değerlerini göremiyoruz. 
- size(): Vektördeki eleman sayısını döner.
- max_size(): Vektörün teorik olarak tutabileceği maksimum eleman sayısını döner.
- resize(size_type count): Vektörün boyutunu belirli bir değere ayarlar. Eğer boyut küçültülürse, fazla elemanlar silinir; boyut büyütülürse, yeni elemanlar varsayılan değeri alır.
- capacity(): Vektörün şu anda ayırdığı bellek miktarını döner.
- empty(): Vektörün boş olup olmadığını kontrol eder. (Eğer vektör boşsa true döner.)
- reserve(size_type new_cap): Vektörün kapasitesini belirli bir değere yükseltir.
- shrink_to_fit(): Vektörün kapasitesini, boyutunu içerecek şekilde azaltır.

## Algorithms
- `<algorithm>` kütüphanesini eklemeyi ubnutma.
- algortimaları combine layarak istediğin sonuçları elde edebilirsn.
- her trülü veri tipiyle çalışır.

### **Search Algorithms**
- std::find: Belirtilen değeri kapsayıcıda arar.
- std::find_if: Belirtilen koşulu sağlayan ilk elemanı arar.
    - boolean ifadeler kullanıyoruz. fonksiyonları kullanıyoruz. koşul fonksiyonları kullanıyoruz daha doğrusu.
- std::find_if_not: Belirtilen koşulu sağlamayan ilk elemanı arar.
- std::binary_search: Sıralı bir kapsayıcıda ikili arama yapar.
    - bulunan elemanın indexini döndürmez
- **std::count**: Belirtilen değerin kaç kez geçtiğini sayar.
- **std::count_if**: Belirtilen koşulu sağlayan elemanların sayısını döner.
    - tek paremetreli functor veya fonksiyon yazabilirsin.(boolean)
- std::search: Bir containerin alt dizisini arar.
- std::search_n: Belirtilen sayıda tekrarlanan değeri arar. (ardışık olmalı aslında search ın aynısı buradaa sadece aynı elemanlar olsun demişler.)

### **Sorting Algorithms**
- std::sort: Elemanları artan düzende sıralar.
    - büyükten küçüğe sıralamak için functorlar kullanıyoruz.(Fonksiyonel obje kısmında işleyeceğiz)
    - iki paremetreli fonkisyon veya functor yazabilirsin.

- std::stable_sort: Elemanları artan düzende sıralar ve eşit elemanların göreli sırasını korur. 
    - sıralama için özel fonksiyon yaazdık yine.

- std::partial_sort: containerin bir kısmını sıralar.
    - aslında şöyle çalışıyor. mesela ilk 3 eleman dedik diyeim. dizideki en küçük 3 elemanı alıp oraya yerleştiriyor. yani hali hazırda bulunun vector daki iilk 3 elemanı değil. diğer elemanlar random şekilde dağılmış olabilir.

- std::nth_element: n'inci elemanın sıralı konumuna getirilmesi ve geri kalanların sırasız olması.
    - yani 3. sırada hangi eleman olması gerekiyorsa o elemaı oraya koyuyuor.
- **std::is_sorted**: Kapsayıcının sıralı olup olmadığını kontrol eder.
- std::is_sorted_until: Kapsayıcı sıralı olmadığı ilk elemanı bulur.

### **copy and convert Algorithms**
- std::copy: Bir containerde ki elemanları başka bir containere kopyalar.
    - kopyalancak containerin boyutu eşit veya bütük olmalı yoksa hata verir.
    - otomaitk boyut arttırmıyor.
- **std::copy_if**: Belirtilen koşulu sağlayan elemanları başka bir aralığa kopyalar.
    - tek paremetreli
- std::copy_n: Belirtilen sayıda elemanı kopyalar.
- std::move: Bir container elemanları başka bir aralığa taşır.
- std::transform: Bir container elemanları dönüştürür ve sonucu başka bir aralığa yazar.
    - aynı aralığa da yazabilir. verdiğin paremetrelerle alakalı
    - if koşullu fonksionda ayzabilirsin sadece 2 ye bölünenleri al gibisinden.
- std::replace: Bir container de belirtilen değerleri yenileriyle değiştirir.
- std::replace_if: Belirtilen koşulu sağlayan değerleri yenileriyle değiştirir.

### **Reordering Algorithms**
- sorting de elemanlar sıralı olmalı burada öyle bir şey yok burada vectorun şeklini değiştiriyoruz.
- **std::reverse**: Bir containerdeki elemanların sırasını tersine çevirir.
- std::rotate: Bir containerdeki elemanları döndürür.
    - sola doğru shift ediyor
- std::shuffle: Bir containerdeki elemanları rastgele karıştırır.
- std::unique: Ardı ardına tekrarlanan elemanları kaldırır.
    - (ardışık olmalı elemanlar). sorting kullan o yüzden.
- std::next_permutation: Bir dizinin bir sonraki permütasyonunu oluşturur.
- std::prev_permutation: Bir dizinin bir önceki permütasyonunu oluşturur.

### **Divide and Conquer Algorithms**
- **std::partition**: Belirtilen koşulu sağlayan ve sağlamayan elemanları ayırır.
    - koşulu sağlayıp sapğlamayanları arrayin içinde ikiye ayırıyor başka arraya atmıyor.
- std::stable_partition: Belirtilen koşulu sağlayan ve sağlamayan elemanları göreli sıralarını koruyarak ayırır.
    - ayırıdktan sonra sırasını koruyor
- **std::merge**: İki sıralı aralığı birleştirir.
- std::inplace_merge: İki bitişik sıralı aralığı birleştirir.
    - çok gerekli değil.

### **Heap Algorithms**
- std::push_heap, std::pop_heap, std::make_heap ve std::sort_heap işlevleri ile yığın (heap) işlemlerini gerçekleştirebiliriz. Her biri için std::vector kullanarak örnekler verelim.
    ```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {10, 20, 30, 5, 15};

        // Yığın oluştur
        std::make_heap(vec.begin(), vec.end());

        // Yeni eleman ekle ve yığını koru
        vec.push_back(25);
        std::push_heap(vec.begin(), vec.end());

        // Sonucu yazdır
        std::cout << "Push Heap sonucu: ";
        for(int x : vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    ```
- std::push_heap: Bir elemanı yığına ekler.
    ```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {10, 20, 30, 5, 15};

        // Yığın oluştur
        std::make_heap(vec.begin(), vec.end());

        // Kök elemanı kaldır ve yığını koru
        std::pop_heap(vec.begin(), vec.end());
        int maxElement = vec.back();
        vec.pop_back();

        // Sonucu yazdır
        std::cout << "Pop Heap sonucu: ";
        for(int x : vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        std::cout << "Kök eleman: " << maxElement << std::endl;

        return 0;
    }
    ```
- std::pop_heap: Yığındaki kök elemanı kaldırır.
    ```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {10, 20, 30, 5, 15};

        // Yığın oluştur
        std::make_heap(vec.begin(), vec.end());

        // Kök elemanı kaldır ve yığını koru
        std::pop_heap(vec.begin(), vec.end());
        int maxElement = vec.back();
        vec.pop_back();

        // Sonucu yazdır
        std::cout << "Pop Heap sonucu: ";
        for(int x : vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        std::cout << "Kök eleman: " << maxElement << std::endl;

        return 0;
    }
    ```
- std::make_heap: Bir aralıktan yığın oluşturur.
    ```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {10, 20, 30, 5, 15};

        // Yığın oluştur
        std::make_heap(vec.begin(), vec.end());

        // Sonucu yazdır
        std::cout << "Make Heap sonucu: ";
        for(int x : vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    ```
- std::sort_heap: Yığını sıralar.
    ```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main() {
        std::vector<int> vec = {10, 20, 30, 5, 15};

        // Yığın oluştur
        std::make_heap(vec.begin(), vec.end());

        // Yığını sırala
        std::sort_heap(vec.begin(), vec.end());

        // Sonucu yazdır
        std::cout << "Sort Heap sonucu: ";
        for(int x : vec) {
            std::cout << x << " ";
        }
        std::cout << std::endl;

        return 0;
    }
    ```
### **Hesaplama Algoritmaları**
- bu kısım örnekleri yapmadım.
- std::accumulate: Bir aralıktaki elemanların toplamını hesaplar.
- std::inner_product: İki aralıktaki elemanların iç çarpımını hesaplar.
- std::adjacent_difference: Bir aralıktaki ardışık elemanların farkını hesaplar.
- std::partial_sum: Bir aralıktaki elemanların kümülatif toplamını hesaplar.

### for_each
- std::for_each: Bir aralıktaki her eleman için belirtilen fonksiyonu uygular
    ```cpp
    #include <iostream>
    #include <vector>
    #include <algorithm> // std::for_each için gerekli

    void print_element(int element) {
        std::cout << element << " ";
    }

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5};

        // std::for_each kullanarak elemanları yazdırma
        std::cout << "Vector elements: ";
        std::for_each(vec.begin(), vec.end(), print_element);
        std::cout << std::endl;

        return 0;
    }
    ```

## Functors
- STL'de birçok algoritma ve veri yapısı functorları kullanır. 
- ama algortimaların içine verirken geçici nesne olarak veriyoruz direkt functoru çağırmıyoruz. Compare() gibi.
- yani biz objeyi içine veriyoruz. bu class () operatörünü overload etmiş olması gerekiyor kullanabilmesi için. Yani içine direkt functoru vermiyoruz.
- sort a functor yazarken iki paremetreli yazıyoruz, o otomatik içinde o paremetreli karşılaştırıyor.
- functor yazarken kullacağın algoritmanın nasıl çalışacağını düşün ve ona göre bir functor yaz.
- functor kullanılan yerlerin çoğunda fonksiyonları da kullanabiliriz aslında. olay durum saklayıp saklamamasıyla alakalı iksiini karşılaştırn örnek aiağıda. yani functor daha genel kapsamlı yazılabiliyor. fucntion yazılamıyor.
    ```cpp
    // Functor ----------------------------------------
    #include <iostream>
    #include <vector>
    #include <algorithm>

    class GreaterThan {
    public:
        GreaterThan(int value) : value(value) {}
        bool operator()(int x) const {
            return x > value;
        }
    private:
        int value;  // Bu, functorun durumunu temsil eder.
    };

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6};
        int count = std::count_if(vec.begin(), vec.end(), GreaterThan(3));
        std::cout << "Count of elements greater than 3: " << count << std::endl;
        return 0;
    }

    // function-------------------------------------
    #include <iostream>
    #include <vector>
    #include <algorithm>

    bool isGreaterThanThree(int x) {
        return x > 3;
    }

    int main() {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6};
        int count = std::count_if(vec.begin(), vec.end(), isGreaterThanThree);
        std::cout << "Count of elements greater than 3: " << count << std::endl;
        return 0;
    }

    ```
- **funcotrs stl**
    - std::plus<T>
        - Açıklama: İki değeri toplar.
        - Kullanım Yerleri: std::accumulate, std::transform

    - std::minus<T>
        - Açıklama: İki değeri çıkarır.
        - Kullanım Yerleri: std::transform, std::inner_product

    - std::multiplies<T>
        - Açıklama: İki değeri çarpar.
        - Kullanım Yerleri: std::transform, std::inner_product
    - std::divides<T>
        - Açıklama: İki değeri böler.
        - Kullanım Yerleri: std::transform

    - std::modulus<T>
        - Açıklama: İki değerin kalanını hesaplar.
        - Kullanım Yerleri: std::transform

    - std::negate<T>
        - Açıklama: Bir değerin negatifini alır.
        - Kullanım Yerleri: std::transform

    - std::equal_to<T>
        - Açıklama: İki değeri eşitlik için karşılaştırır.
        - Kullanım Yerleri: std::find_if, std::adjacent_find, std::unique, std::remove_if

    - std::not_equal_to<T>
        - Açıklama: İki değeri eşitsizlik için karşılaştırır.
        - Kullanım Yerleri: std::find_if, std::adjacent_find, std::unique, std::remove_if

    - std::greater<T>
        - Açıklama: İki değeri büyüklük için karşılaştırır.
        - Kullanım Yerleri: std::sort, std::stable_sort, std::max_element, std::min_element,  - std::partition

    - std::less<T>
        - Açıklama: İki değeri küçüklük için karşılaştırır.
        - Kullanım Yerleri: std::sort, std::stable_sort, std::max_element, std::min_element,  - std::partition

    - std::greater_equal<T>
        - Açıklama: İki değeri büyüklük veya eşitlik için karşılaştırır.
        - Kullanım Yerleri: std::sort, std::stable_sort, std::partition

    - std::less_equal<T>
        - Açıklama: İki değeri küçüklük veya eşitlik için karşılaştırır.
        - Kullanım Yerleri: std::sort, std::stable_sort, std::partition

    - std::logical_and<T>
        - Açıklama: İki değerin mantıksal AND işlemini gerçekleştirir.
        - Kullanım Yerleri: std::accumulate, std::transform

    - std::logical_or<T>
        - Açıklama: İki değerin mantıksal OR işlemini gerçekleştirir.
        - Kullanım Yerleri: std::accumulate, std::transform

    - std::logical_not<T>
        - Açıklama: Bir değerin mantıksal NOT işlemini gerçekleştirir.
        - Kullanım Yerleri: std::transform