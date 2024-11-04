# Concurrency
- **Concurrency**
    - Tanım: Eşzamanlılık, birden fazla görevin (iş parçacığı veya işlem) aynı anda ilerlemesi anlamına gelir. Bu görevler birbirinin peşinden gelebilir ve sıralı olarak işlenebilir.
    - Amaç: Kullanıcı deneyimini iyileştirmek, kaynakları verimli bir şekilde kullanmak ve aynı anda birden fazla iş yapabilme yeteneği kazandırmaktır.
    - Gerçekleşme: Genellikle tek bir işlem içinde, iş parçacıklarının zaman dilimlerinde (time slices) çalışmasıyla sağlanır. Her iş parçacığı, belirli bir süre boyunca çalışır ve ardından başka bir iş parçacığına geçilir.
    - Örnek: Bir web sunucusu, bir istemciden gelen istekleri eşzamanlı olarak işlerken, başka bir istemciye yanıt vermek için arka planda diğer isteği işleyebilir.

- Parallelism
    - Tanım: Paralellik, birden fazla görevin gerçekten aynı anda yürütülmesi anlamına gelir. Bu, çok çekirdekli bir işlemci gibi donanım özelliklerinden yararlanarak gerçekleştirilir.
    - Amaç: İşlem süresini kısaltmak ve hesaplama görevlerini daha hızlı tamamlamak için kaynakları tam olarak kullanmaktır.
    - Gerçekleşme: Genellikle birden fazla iş parçacığının veya işlemin aynı anda çalışması yoluyla sağlanır. Bu, işlemcinin birden fazla çekirdeği veya işlemci çekirdeği kullanılarak gerçekleştirilir.
    - Örnek: Büyük veri setleri üzerinde paralel hesaplamalar yaparak, aynı anda birden fazla iş parçacığının veri işlemesi.

- Özet
    - Concurrency: Görevlerin zaman dilimlerinde sıralı olarak işlenmesi; görevler eşzamanlı ilerler ama aynı anda çalışmayabilir. Eş zamanlıymış gibi hissiyat veriyor. tasklar arasında çok hızlı geçiş olmaktadır.
    - Parallelism: Görevlerin gerçek anlamda aynı anda yürütülmesi; birden fazla çekirdek veya işlemci kullanılarak yapılır. Gerçekten eş zamanlı oluyor çünkü farklı core lar kullanılmaktadır.