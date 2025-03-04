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

void merge(vector<ll> &a, ll l, ll mid, ll r) {
    ll nl = mid - l + 1;
    ll nr = r - mid;
    
    vector<ll> left(nl), right(nr);
    
    for (ll i = 0; i < nl; i++) left[i] = a[l + i];
    for (ll i = 0; i < nr; i++) right[i] = a[mid + 1 + i];
    
    ll i = 0, j = 0, k = l;
    
    while (i < nl && j < nr) {
        if (left[i] <= right[j]) a[k++] = left[i++];
        else a[k++] = right[j++];
    }
    
    while (i < nl) a[k++] = left[i++];
    while (j < nr) a[k++] = right[j++];
}

void merge_sort(vector<ll> &a, ll l, ll r) {
    if (l < r) {
        ll mid = l + (r - l) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    // vector<ll> arr = {0, 9, 2, 3, 5, 4};
    // ll n = arr.size();
    // printarr(arr);
    // merge_sort(arr, 0, n - 1);
    // printarr(arr);

    clock_t start, finish;
    double est;
    ifstream inputFile("inputs_5M.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    vector<long long> a;
    long long value;
    while (inputFile >> value) {
        a.push_back(value);
    }
    inputFile.close();
    ll n = a.size();
    // cout << "Array before sorting: " << endl;
    // printarr(a);

    start = clock();
    merge_sort(a, 0, n - 1);
    finish = clock();
    est = ((double) (finish - start) / CLOCKS_PER_SEC);

    // cout << "Array after sorting: " << endl;
    // printarr(a);
    
    cout << "Input Size: " << a.size() << endl;
    printf("Merge Sort Time taken: %.2lf\n", est);
    // cout << "Time taken: " << est << endl;
    return 0;
}
