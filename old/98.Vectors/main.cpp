#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> my_vector;

    my_vector.push_back(0);
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);
    my_vector.push_back(4);
    my_vector.push_back(5);

    cout << my_vector[0] << endl;
    cout << my_vector[1] << endl;
    cout << my_vector[2] << endl;
    cout << my_vector[3] << endl;
    cout << my_vector[4] << endl;
    cout << my_vector[5] << endl;


    for (int i = 0; i < my_vector.size(); i++) {
        cout << "my_vetor[" << i << "]=" << my_vector[i] << endl;
    }
    cout << "--------------------\n";

    my_vector.erase(my_vector.begin() + 0);

    for (int i = 0; i < my_vector.size(); i++) {
        cout << "my_vetor[" << i << "]=" << my_vector[i] << endl;
    }
    return 0;
}