#include <iostream>
#include <vector> 

using namespace std;
template <typename T>
void print_vector(const vector<T> &vec, bool info = false) {
    cout << "*************************\n";
    cout << "vector: ";
    for (const auto &i : vec) {
        cout << i << ", ";
    }
    cout << "\n";

    cout << "*************************\n";
    if(info) {
        cout << "size: " << vec.size() << endl;
        cout << "capacity: " << vec.capacity() << endl;
        cout << "size_of: " << sizeof(vec) << endl;
        cout << "real_size: " << sizeof(T) * vec.capacity() << endl;
        cout << "empty: " << vec.empty() << endl;
        cout << "*************************\n";
    }
}

// Vector Initilizaiton ##################################################
void vector_initialization() {
    // Boş bir vektör tanımlama
    std::vector<int> vec1;
    print_vector(vec1);

    // Belirli boyutta ve başlangıç değeri ile vektör tanımlama
    std::vector<int> vec2(10, 0);  // 10 elemanlı, her elemanı 0
    print_vector(vec2);

    std::vector<int> vec7(10);  // 10 elemanlı
    print_vector(vec7);

    // Liste başlatıcı ile vektör tanımlama
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    print_vector(vec3);

    // Başka bir vektörden kopyalayarak tanımlama
    std::vector<int> vec4(vec3);
    print_vector(vec4);

    // Başka bir vektörden taşıyarak tanımlama
    std::vector<int> vec5(std::move(vec3));
    print_vector(vec5);

    std::vector<int> vec6({0, 1, 2, 3, 4, 5, 6});
    print_vector(vec6);
}

// Add and delete element ################################################
class MyClass {
public:
    // Basit constructor
    MyClass(int value) : value(value) {
        std::cout << "Constructor called for " << value << std::endl;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : value(other.value) {
        other.value = 0;
        std::cout << "Move constructor called" << std::endl;
    }

    MyClass(const MyClass& other) {
        this->value = other.value;
        std::cout << "copy constructor called" << std::endl;
    }

    // Bir değer döndüren fonksiyon
    int getValue() const {
        return value;
    }

private:
    int value;
};

void add_and_delete_element() {
    std::vector<int> vec;
    
    cout << "push_back(const T& value) ++++++++++++++++++++++++\n";
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);

    print_vector(vec);

    cout << "\npush_back(T&& value) ++++++++++++++++++++++++\n";
    std::vector<MyClass> vec_class;

    MyClass myClass_1(5);
    vec_class.push_back(std::move(myClass_1));

    MyClass myClass_2(6);
    vec_class.push_back(myClass_2);

    cout << "\npop_back() ++++++++++++++++++++++++\n";
    vec.pop_back();
    vec.pop_back();
    print_vector(vec);

    cout << "\ninsert(iterator pos, const T& value) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};

    print_vector(vec);

    vec.insert(vec.begin(), 99);
    vec.insert(vec.begin(), 98);
    vec.insert(vec.begin(), 97);
    vec.insert(vec.begin() + 5, 96);
    vec.insert(vec.begin() + vec.size(), 95);

    print_vector(vec);

    cout << "\ninsert(iterator pos, size_type count, const T& value) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.insert(vec.begin(), 10, 0);
    print_vector(vec);

    cout << "\ninsert(iterator pos, InputIt first, InputIt last) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    std::vector<int> vec_for_insert = {10, 11, 12, 13, 14, 14,15, 16};

    cout << "ex 1 ------------\n";
    vec.insert(vec.begin(), vec_for_insert.begin(), vec_for_insert.end());
    print_vector(vec);

    cout << "ex 2 ------------\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.insert(vec.begin() + 5, vec_for_insert.begin(), vec_for_insert.end());
    print_vector(vec);

    cout << "ex 3 ------------\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.insert(vec.begin(), vec_for_insert.begin() + 1, vec_for_insert.begin() + 2);
    print_vector(vec);

    cout << "ex 4 ------------\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.insert(vec.begin(), {10, 11, 12});
    print_vector(vec);
   
    cout << "\nerase(iterator pos) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.erase(vec.begin() + 2);
    print_vector(vec);

    cout << "\nerase(iterator first, iterator last) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.erase(vec.begin() + 2, vec.end() - 2);
    print_vector(vec);

    cout << "\nclear() ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6}; 
    vec.clear();
    print_vector(vec);

    cout << "\nemplace(iterator pos, Args&&... args) ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    vec.emplace(vec.begin(), 10);
    print_vector(vec);

    cout << "\nemplace_back(Args&&... args) ++++++++++++++++++++++++\n";
    vec.emplace_back(10);
    print_vector(vec);

}

// Reach vector elements ################################################
void reach_vector_elements() {
    cout << "operator[] ++++++++++++++++++++++++\n";
    std::vector<int> vec({0, 1, 2, 3, 4, 5, 6});

    for (int i = 0; i < vec.size() + 5; ++i) {
        cout << "vec[" << i << "]= " << vec[i] << endl;
    }

    cout << "change element ------\n";
    vec[3] = 10;
    vec[4] = 30;
    vec[vec.size() + 2] = 40;

    for (int i = 0; i < vec.size() + 5; ++i) {
        cout << "vec[" << i << "]= " << vec[i] << endl;
    }

    cout << "at() fonksiyonu ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    for (int i = 0; i < vec.size(); ++i) {
        cout << "vec.at(" << i << ")= " << vec.at(i) << endl;
    }

    cout << "change element ------\n";
    vec.at(3) = 10;
    vec.at(4) = 30;
    vec.at(vec.size() - 1) = 40;

    for (int i = 0; i < vec.size(); ++i) {
        cout << "vec.at(" << i << ")= " << vec.at(i) << endl;
    }

    cout << "front() fonksiyonu ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    cout << "front: " << vec.front() << endl;
    vec.front() = 10;
    print_vector(vec);

    cout << "back() fonksiyonu ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    cout << "back: " << vec.back() << endl;
    vec.back() = 10;
    print_vector(vec);

    cout << "data() fonksiyonu ++++++++++++++++++++++++\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    int* vec_ptr = vec.data();
    for (int i = 0; i < vec.size(); ++i) {
        cout << "vec_ptr + " << i << ": " << vec_ptr + i << " || ";
        printf("*(vec_ptr + %d) = %d || ",i , *(vec_ptr + i));
        printf("vec_ptr[%d] = %d\n",i , vec_ptr[i]);
    }
}

// Iterators ############################################################
void iterators_w_vector() {
    cout << "begin() and end() iterator ++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6};

    cout << "begin() ----------------------------------------------------\n";
    /*
    std::vector<int>::iterator it = vec.begin();
    for (int i = 0; i < vec.size(); ++i) {
        printf("&it + %d: %p || ",i , &it+i);
        printf("*(&it + %d): %d || \n",i , *(&it+i));
    }
    */
   std::vector<int>::iterator it = vec.begin();
    for (int i = 0; i < vec.size(); ++i) {
        printf("&(*(it + %d)): %p || ",i , &(*(it+i)));
        printf("*(it + %d): %d || \n",i , *(it+i));
    }

    cout << "Adding, delte and change element --------------------\n";
    std::vector<int>::iterator my_it = vec.begin();
    vec.insert(it + 2, 10);
    print_vector(vec);

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        *it = 0;
    }
    print_vector(vec);

    vec = {0, 1, 2, 3, 4, 5, 6};
    cout << "\nbegin() and end() normal usage ----------------------------------\n";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << "*it: " << *it << endl;
    }

    cout << "\nbegin() and end() reverse_iterator ----------------------------------\n";
    for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << "*it: " << *it << endl;
    }

    cout << "\nbegin() and end() const_iter ----------------------------------\n";
    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
        cout << "*it: " << *it << endl;
    }

    cout << "\nbegin() and end() reverse_const_iter ----------------------------------\n";
    for (std::vector<int>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); ++it) {
        cout << "*it: " << *it << endl;
    }

    cout << "\nrange based iter ----------------------------------\n";
    for (const int& elem : vec) {
        std::cout << elem << "\n";
    }
}

// Memory Management ############################################################
void memory_management() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6};
    cout << "max size----------------------\n";
    cout << "max_size: " << vec.max_size() << endl;
    print_vector(vec, true);

    cout << "resize----------------------\n";
    cout << "before -----" << endl;
    print_vector(vec, true);

    cout << "after increase -----" << endl;
    vec.resize(32, 0);
    print_vector(vec, true);

    cout << "after reduce -----" << endl;
    vec.resize(4, 0);
    print_vector(vec, true);

    cout << "after reduce -----" << endl;
    vec.resize(2);
    print_vector(vec, true);

    cout << "reserve --------------------\n";
    vec = {0, 1, 2, 3, 4, 5, 6};
    
    cout << "before -----" << endl;
    print_vector(vec, true);

    cout << "after increase -----" << endl;
    vec.reserve(100);
    print_vector(vec, true);

    cout << "shrink_to_fit() ----------------\n";
    vec.shrink_to_fit();
    print_vector(vec, true);
}

// Algorithms ############################################################
// Search algortigms ++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <algorithm>

bool isEven(int i) { 
    return i % 2 == 0;     
}

bool isOdd(int i) {
    return i % 2 != 0; 
}

void search_algorithms() {
    cout << "Search Algorithms +++++++++++++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    cout << "find --------------------------------------------------------\n";
    //std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), 3);
    auto it = std::find(vec.begin(), vec.end(), 3);

    if (it < vec.end()) {
        std::cout << "Value 3 found at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "*it: " << *it << endl;
        std::cout << "*(it+1): " << *(it+1) << endl;

    } else {
        std::cout << "Value 3 not found" << std::endl;
    }

    cout << "\nfind_if -----------------------------------------------------\n";
    it = std::find_if(vec.begin(), vec.end(), isEven);
    if (it != vec.end()) {
        std::cout << "First even value found at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "*it: " << *it << endl;
        std::cout << "*(it+1): " << *(it+1) << endl;

    } else {
        std::cout << "No even value found" << std::endl;
    }

    cout << "\nfind_if_not -----------------------------------------------------\n";
    it = std::find_if_not(vec.begin(), vec.end(), isOdd);
    if (it != vec.end()) {
        std::cout << "First non-odd value found at position: " << std::distance(vec.begin(), it) << std::endl;
        std::cout << "*it: " << *it << endl;
        std::cout << "*(it+1): " << *(it+1) << endl;
    } else {
        std::cout << "No non-odd value found" << std::endl;
    }

    cout << "\nbinary_search -----------------------------------------------------\n";
    vec = {3, 4, 1, 0, 2, 5};

    std::sort(vec.begin(), vec.end()); // önce sıralamak lazım.
    print_vector(vec);

    bool found = std::binary_search(vec.begin(), vec.end(), 3);

    if (found) {
        std::cout << "Value 3 found in the sorted vector." << std::endl;
        std::cout << "*it: " << *it << endl;
    } else {
        std::cout << "Value 3 not found in the sorted vector." << std::endl;
    }


    cout << "\ncount -----------------------------------------------------\n";
    vec = {1, 2, 3, 4, 3, 3, 5, 2, 2, 2, 3, 3, 4};
    int count;
    count = std::count(vec.begin(), vec.end(), 3);
    std::cout << "Value 3 appears " << count << " times in the vector." << std::endl;

    cout << "\ncount_if-----------------------------------------------------\n";
    vec = {1, 2, 3, 4, 5};
    count = std::count_if(vec.begin(), vec.end(), isOdd);
    std::cout << "Number of odd values in the vector: " << count << std::endl;

    count = std::count_if(vec.begin(), vec.end(), isEven);
    std::cout << "Number of even values in the vector: " << count << std::endl;

    cout << "\nsearch-----------------------------------------------------\n";
    vec = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> sub_vec = {4, 5, 6};
    it = std::search(vec.begin(), vec.end(), sub_vec.begin(), sub_vec.end());
    if (it != vec.end()) {
        std::cout << "Subsequence found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Subsequence not found" << std::endl;
    }

    cout << "\nstd::search_n -----------------------------------------------------\n";
     vec = {1, 2, 2, 2, 3, 4, 5};
    it = std::search_n(vec.begin(), vec.end(), 3, 2);  // 3 kere tekrarlanan 2 
    if (it != vec.end()) {
        std::cout << "Three consecutive 2s found at position: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Three consecutive 2s not found" << std::endl;
    }
}

// Sort algortigms ++++++++++++++++++++++++++++++++++++++++++++++++++++
struct Person {
    std::string name;
    int age;
};

bool compareByAge(const Person &a, const Person &b) {
    return a.age < b.age;
}

void sort_algorithms() {
    cout << "\nSort Algorithms +++++++++++++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {5, 3, 1, 4, 2, 2, 3, 3, 4, 5};
    
    cout << "sort --------------------------------------------------------\n";
    std::sort(vec.begin(), vec.end());
    print_vector(vec);

    cout << "\nstable_sort --------------------------------------------------------\n";
    std::vector<Person> vec_s = {{"Alice", 30}, {"Charlie", 25}, {"Bob", 25}, {"David", 35}};
    
    std::stable_sort(vec_s.begin(), vec_s.end(), compareByAge);

    std::cout << "Stable Sorted by Age: ";
    for (const auto& p : vec_s) {
        std::cout << "{" << p.name << ", " << p.age << "} ";
    }
    std::cout << std::endl;

    cout << "\npartial_sort --------------------------------------------------------\n";
    vec = {5, 3, 1, 4, 2, 6, 8, 7, 9};
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    print_vector(vec);

    cout << "\nnth_element --------------------------------------------------------\n";
    vec = {5, 3, 1, 4, 2, 0};
    std::nth_element(vec.begin(), vec.begin() + 2, vec.end());
    print_vector(vec);

    cout << "\nis_sorted --------------------------------------------------------\n";
    vec = {1, 2, 3, 4, 5};
    bool sorted = std::is_sorted(vec.begin(), vec.end());
    std::cout << "Is Sorted: " << (sorted ? "Yes" : "No") << std::endl;

    vec = {5, 3, 1, 4, 2, 6, 8, 7, 9};
    sorted = std::is_sorted(vec.begin(), vec.end());
    std::cout << "Is Sorted: " << (sorted ? "Yes" : "No") << std::endl;

    cout << "\nis_sorted --------------------------------------------------------\n";
    vec = {1, 2, 3, 5, 4};
    
    auto it = std::is_sorted_until(vec.begin(), vec.end());
    std::cout << "Sorted Until: " << std::distance(vec.begin(), it) << std::endl;

    vec = {1, 2, 3, 4, 5};
    it = std::is_sorted_until(vec.begin(), vec.end());
    std::cout << "Sorted Until: " << std::distance(vec.begin(), it) << std::endl;

}

// Copy and convert ++++++++++++++++++++++++++++++++++++++++++++++++++++
int square(int x) {
    return x*x;
}

void copy_and_convert_algorithms() {
    cout << "\nCopy and Convert Algorithms +++++++++++++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    cout << "copy --------------------------------------------------------\n";
    std::vector<int> vec_copy;

    cout << "before -------\n";
    print_vector(vec);
    print_vector(vec_copy);

    cout << "after -------\n";
    vec_copy.resize(vec.size());
    std::copy(vec.begin(), vec.end(), vec_copy.begin());
    print_vector(vec);
    print_vector(vec_copy);

    cout << "\ncopy_if --------------------------------------------------------\n";
    vec_copy.clear();
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(vec_copy), isEven);
    print_vector(vec_copy);

    cout << "\nmove --------------------------------------------------------\n";
    std::vector<int> vec_move;
    vec_move.resize(vec.size());
    std::move(vec.begin(), vec.end(), vec_move.begin());
    cout << "vec -----\n";
    print_vector(vec);

    cout << "vec_move -----\n";
    print_vector(vec_move);

    cout << "\ntransform --------------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5};
    std::vector<int> vec_transform(vec.size());
    std::transform(vec.begin(), vec.end(), vec_transform.begin(), square);
    print_vector(vec_transform);

    cout << "\nreplace --------------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5};
    std::replace(vec.begin(), vec.end(), 2, 99);
    print_vector(vec);

    cout << "\nreplace_if --------------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5};
    std::replace_if(vec.begin(), vec.end(), isEven, 99);
    print_vector(vec);
}

// Reordering ++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <random>
void reordering_algorithms() {
    cout << "\nReordering Algorithms +++++++++++++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {0, 1, 2, 3, 4, 5};

    cout << "reverse --------------------------------------------------------\n";
    std::reverse(vec.begin(), vec.end());
    print_vector(vec);

    cout << "\nrotate --------------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5};
    std::rotate(vec.begin(), vec.begin() + 2, vec.end() - 1);
    print_vector(vec);

    cout << "\nshufle --------------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5};
    // Rastgele sayı üreticisi için seed değeri
    std::random_device rd;
    // Mersenne Twister rastgele sayı üreticisi
    std::mt19937 g(rd());

    std::shuffle(vec.begin(), vec.end(), g);
    print_vector(vec);

    cout << "\nunique --------------------------------------------------------\n";
    vec = {1, 2, 2, 3, 3, 4, 5, 6, 6, 6, 2, 2, 2};
    auto it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
    print_vector(vec);

}

// Divide and Conquer Algorithms ++++++++++++++++++++++++++++++++++++++++
void divide_and_conquer_algorithms() {
    cout << "\nReordering Algorithms +++++++++++++++++++++++++++++++++++++++++\n";
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "partition --------------------------------------------------------\n";
    auto it = std::partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    print_vector(vec);

    cout << "stable partition ----------------------------------------------------\n";
    vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::stable_partition(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    print_vector(vec);

    cout << "merge ----------------------------------------------------\n";
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8};
    std::vector<int> result(vec1.size() + vec2.size());

    std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), result.begin());
    print_vector(result);
}

// Functors ++++++++++++++++++++++++++++++++++++++++
class Compare {
public:
    bool operator()(int a, int b) const {
        return a > b;
    }
};

class Print {
public:
    void operator()(int n) const {
        std::cout << n << " ";
    }
};

class Square_for_each {
public:
    void operator()(int &n) const {
        n = n *n;
    }
};

class Cube {
public:
    int operator()(int n) const {
        return n * n * n;
    }
};

void functor_examples() {
    cout << "Custom functor example ++++++++++++++++++++++++++++++++++++\n";
    cout << "\nsort ------------------------------------------------------\n";
    std::vector<int> vec = {1, 5, 3, 4, 2};
    std::sort(vec.begin(), vec.end(), Compare());
    print_vector(vec);

    cout << "\nfor_each ------------------------------------------------------\n";
    cout << "print-----------------\n";
    std::for_each(vec.begin(), vec.end(), Print());

    cout << "\nsquare-----------------\n";
    std::for_each(vec.begin(), vec.end(), Square_for_each());
    print_vector(vec);

    cout << "\ntransform ------------------------------------------------------\n";
    vec = {1, 5, 3, 4, 2};
    std::transform(vec.begin(), vec.end(), vec.begin(), Cube());
    std::sort(vec.begin(), vec.end());
    print_vector(vec);
}

int main() {
    cout << "Vector Initilizaiton ########################################\n";
    vector_initialization();

    cout << "\n\nAdd and delete element ########################################\n";
    add_and_delete_element();

    cout << "\n\nReach vector elements ########################################\n";
    reach_vector_elements();

    cout << "\n\nIterators ########################################\n";
    iterators_w_vector();

    cout << "\n\nMemory Management ########################################\n";
    memory_management();

    cout << "\n\nAlgorithms ########################################\n";
    search_algorithms();
    sort_algorithms();
    copy_and_convert_algorithms();
    reordering_algorithms();
    divide_and_conquer_algorithms();

    cout << "\n\nFunctors ########################################\n";
    functor_examples();
    return 0;
}