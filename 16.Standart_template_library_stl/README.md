# Standart Template Library
- programlama dilinin önemli bir parçasıdır ve algoritmalar, konteynerler, iteratörler ve fonksiyonel objeler (functors) gibi bileşenleri içeren bir kütüphanedir. STL, yazılım geliştirme sürecini hızlandırmak ve kodun yeniden kullanılabilirliğini artırmak amacıyla tasarlanmıştır. STL bileşenleri genel olarak şu dört ana kategoriye ayrılır:

- Konteynerler (Containers):
    - Veri yapılarının saklanması ve yönetilmesi için kullanılır.
    - Örnekler: std::vector, std::list, std::deque, std::set, std::map, std::unordered_set, std::unordered_map.

- Algoritmalar (Algorithms):
    - Veri üzerinde işlem yapmak için kullanılan genel fonksiyonlardır.
    - Örnekler: std::sort, std::find, std::accumulate, std::copy.

- İteratörler (Iterators):
    - Konteynerlerin elemanları üzerinde gezinmek için kullanılan nesnelerdir.
    - Türler: Input iterators, output iterators, forward iterators, bidirectional iterators, random access iterators.

- Fonksiyonel Obje (Functors):
    - Fonksiyon gibi davranan, fakat nesne olan yapılardır. STL algoritmalarına parametre olarak geçebilirler.
    - Örnekler: std::plus, std::minus, std::multiplies, std::divides, std::less, std::greater.

- Adapter
    -  adapter'lar, veri yapılarının veya algoritmaların kullanımını değiştirmek veya genişletmek için kullanılan yapısal bileşenlerdir. Bu adapter'lar, mevcut STL bileşenlerini daha spesifik ihtiyaçlara uygun hale getirmek için kullanılır. STL'de üç ana tür adapter bulunur:
    
    - Container Adapters (Konteyner Adaptörleri):
        - Mevcut konteynerleri farklı bir arayüzle kullanmayı sağlar.
        - Örnekler:
            - std::stack: Bir yığın (stack) veri yapısı sağlar. std::deque veya std::vector gibi temel bir konteyneri yığın gibi kullanır.
            - std::queue: Bir kuyruk (queue) veri yapısı sağlar. std::deque veya std::list gibi temel bir konteyneri kuyruk gibi kullanır.
            - std::priority_queue: Bir öncelik kuyruğu (priority queue) veri yapısı sağlar. std::vector gibi temel bir konteyneri öncelik kuyruğu gibi kullanır.

    - Iterator Adapters (İteratör Adaptörleri):
        - Mevcut iteratörlerin işlevselliğini genişletir veya değiştirebilir.
        - Örnekler:
            - std::reverse_iterator: İteratörün elemanları ters sırada gezmesini sağlar.
            - std::istream_iterator ve std::ostream_iterator: Akışlardan veri okumak ve akışlara veri yazmak için iteratörler sağlar.
            - std::insert_iterator, std::back_insert_iterator, ve std::front_insert_iterator: Eleman ekleme işlemlerini kolaylaştıran iteratörlerdir.

    - Function Adapters (Fonksiyon Adaptörleri):
        - Fonksiyon nesnelerinin veya lambda ifadelerinin işlevselliğini genişletir veya değiştirir.
        - Örnekler:
            - std::bind: Bir fonksiyonu belirli argümanlarla bağlar ve yeni bir fonksiyon nesnesi oluşturur.
            - std::function: Genel amaçlı bir fonksiyon sarmalayıcısıdır ve herhangi bir çağrılabilir nesneyi saklayabilir.
            - std::mem_fn: Üye fonksiyon işaretçilerini bağlamak ve çağırmak için kullanılır.