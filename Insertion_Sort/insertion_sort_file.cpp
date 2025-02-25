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

void insertion_sort(vector<long long>& a) {
    long long count = 0;
    for (long long i = 1; i < a.size(); ++i) {
        count++;
        cout << count << " sorted" << endl;
        long long key = a[i];
        long long j = i - 1;
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
    ifstream inputFile("inputs_500K.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file 'inputs.txt'" << endl;
        return 1;
    }

    vector<long long> a;
    long long value;
    while (inputFile >> value) {
        a.push_back(value);
    }
    inputFile.close();
    // cout << "Array before sorting: " << endl;
    // printarr(a);
    start = clock();
    insertion_sort(a);
    finish = clock();
    est = (double)((finish - start) / CLOCKS_PER_SEC);
    // cout << "Array after sorting: " << endl;
    // printarr(a);
    cout << "Input Size: " << a.size() << endl;
    cout << "Time taken: " << est << endl;
    return 0;
}
