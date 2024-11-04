#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void basic_example() {
     auto start = std::chrono::steady_clock::now();

    // Örnek bir bekleme süresi
    std::this_thread::sleep_for(std::chrono::seconds(2));

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    std::cout << "Geçen süre: " << elapsed_seconds.count() << " saniye\n";
}

void advanced_example() {
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
}

int main() {

    cout << "Basic example ---------------------------\n";
    basic_example();

    cout << "Advanced example ---------------------------\n";
    advanced_example();

    return 0;
}