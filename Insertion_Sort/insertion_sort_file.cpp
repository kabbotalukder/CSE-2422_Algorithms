#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

void printarr(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << endl;
    }
    cout << endl;
}

void insertion_sort(vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main() {
    clock_t start, finish;
    double est;
    ifstream inputFile("inputs_100K.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file 'inputs.txt'" << endl;
        return 1;
    }

    vector<int> a;
    int value;
    while (inputFile >> value) {
        a.push_back(value);
    }
    inputFile.close();
    cout << "Array before sorting: " << endl;
    printarr(a);
    start = clock();
    insertion_sort(a);
    finish = clock();
    est = (double)((finish - start) / CLOCKS_PER_SEC);
    cout << "Array after sorting: " << endl;
    printarr(a);
    cout << "Input Size: " << a.size() << endl;
    cout << "Time taken: " << est << endl;
    return 0;
}
