#include <bits/stdc++.h>
#define ll long long
using namespace std;

void printarr(vector<ll>& a) {
    for (auto it: a) {
        cout << it << endl;
    }
    cout << endl;
}

void insertion_sort(vector<long long>& a) {
    for (long long i = 1; i < a.size(); ++i) {
        long long key = a[i];
        long long j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge_sort(vector<long long>& a, ll l, ll r) {
    if(l >= r)
        return;
    ll mid = (l + r) / 2;
    cout << mid << endl;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
}

int main() {
    vector<ll> arr = {0, 9, 2, 3, 5, 4};
    ll n = arr.size();
    // printarr(arr);
    merge_sort(arr, 0, n - 1);
    // printarr(arr);

    // clock_t start, finish;
    // double est;
    // ifstream inputFile("inputs_10K.txt");
    // if (!inputFile.is_open()) {
    //     cerr << "Error opening file" << endl;
    //     return 1;
    // }

    // vector<long long> a;
    // long long value;
    // while (inputFile >> value) {
    //     a.push_back(value);
    // }
    // inputFile.close();

    // cout << "Array before sorting: " << endl;
    // printarr(a);

    // start = clock();
    // insertion_sort(a);
    // finish = clock();
    // est = ((double) (finish - start) / CLOCKS_PER_SEC);

    // cout << "Array after sorting: " << endl;
    // printarr(a);
    // cout << "Input Size: " << a.size() << endl;

    // printf("Time taken: %.2lf", est);
    // cout << "Time taken: " << est << endl;
    return 0;
}
