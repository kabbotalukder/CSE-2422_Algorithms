#include<bits/stdc++.h>
using namespace std;

void scana(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printa(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void counting_sort(int a[], int n){
    int max_val = *max_element(a, a + n);
    int frq[max_val + 1] = { 0 };
    int output[n + 1];

    for(int i = 0; i < n; i++){
        frq[a[i]]++;
    }

    for(int i = 1; i < max_val + 1; i++){
        frq[i] += frq[i - 1];
    }

    for(int i = n - 1; i >= 0; i--){
        int val = a[i];
        int pos = frq[val];
        output[pos] = val;
    }
    // printa(output, n + 1);
    for(int i = 0; i < n; i++){
        a[i] = output[i + 1];
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    scana(a, n);
    counting_sort(a, n);
    printa(a, n);
    return 0;
}