# Timers
- **chrono**: 
    - C++'ta chrono kütüphanesi, süreleri ölçme ve tarih/zaman hesaplamalarını gerçekleştirme amacıyla kullanılan bir zaman kütüphanesidir. Modern C++'ın (C++11 ve sonrası) bir parçası olan bu kütüphane, daha önceki C ve C++'ta kullanılan tarih ve zaman fonksiyonlarına kıyasla daha güvenli, kesin ve okunabilir bir yapıya sahiptir. chrono, süreleri, zaman noktalarını (time points), ve zaman dilimlerini (time intervals) modellemek için sınıflar sunar.
- Temel Bileşenler
    - Süre (Duration): Süre sınıfı (std::chrono::duration), zaman uzunluklarını (örneğin saniyeler, milisaniyeler, vb.) temsil eder. Kullanıcıya bu süreleri istediği birimlerde ifade etme esnekliği tanır.
        ```cpp
        std::chrono::seconds sec(10); // 10 saniyelik bir süre.
        std::chrono::milliseconds ms(500); // 500 milisaniye.
        ```
   - Zaman Noktası (Time Point): Zaman noktası sınıfı (std::chrono::time_point), belirli bir zaman anını ifade eder. Bu sınıf, genellikle sistem saatini veya belirli bir başlangıç noktasına göre bir zamanı ifade etmek için kullanılır.     
        ```cpp
        auto now = std::chrono::system_clock::now(); // Şu anki zamanı alır.
        ```
    - Saatler (Clocks): chrono kütüphanesi, üç ana saat türü sunar:
        - std::chrono::system_clock: Gerçek dünya zamanı ile ilişkilendirilmiştir ve genellikle tarih/zaman almak için kullanılır.
        - std::chrono::steady_clock: Sürekli artan, geri gitmeyen bir saat olup zamanlama ölçümleri için uygundur.
        - std::chrono::high_resolution_clock: Yüksek çözünürlüklü bir saattir, fakat sistem bazlı olarak farklılık gösterebilir.

- Kullanımı
    - Genellikle chrono kütüphanesi, belirli bir işlem süresini ölçmek veya bir işlemi belirli bir süre boyunca bekletmek için kullanılır.
        ```cpp
        #include <iostream>
        #include <chrono>
        #include <thread>

        int main() {
            auto start = std::chrono::steady_clock::now();

            // Örnek bir bekleme süresi
            std::this_thread::sleep_for(std::chrono::seconds(2));

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;

            std::cout << "Geçen süre: " << elapsed_seconds.count() << " saniye\n";
            return 0;
        }
        ```

    - Yukarıdaki örnekte, steady_clock kullanarak bir işlem süresini ölçüyoruz. Bu kütüphane, zaman ölçümleri ve gecikmeler gibi işlemlerde çok kullanışlıdır ve özellikle hassas süre kontrollerinin gerektiği uygulamalarda tercih edilir.

        ```cpp
        #include <iostream>
        #include <chrono>
        #include <thread>

        int main() {
            std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

            // Başlangıç zamanını yazdır
            std::time_t start_time = std::chrono::system_clock::to_time_t(start);
            std::cout << "Başlangıç zamanı: " << std::ctime(&start_time);

            // Örnek bir bekleme süresi
            std::this_thread::sleep_for(std::chrono::seconds(2));

            std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

            // Bitiş zamanını yazdır
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::cout << "Bitiş zamanı: " << std::ctime(&end_time);

            std::chrono::duration<double> elapsed_seconds = end - start;
            std::cout << "Geçen süre: " << elapsed_seconds.count() << " saniye\n";

            return 0;
        }
        ```

        - std::chrono::system_clock kullanılarak start ve end zaman noktaları belirlenmiştir.
        - std::chrono::system_clock::to_time_t ile bu zaman noktaları okunabilir bir biçime dönüştürülerek başlangıç ve bitiş zamanları yazdırılmaktadır.
