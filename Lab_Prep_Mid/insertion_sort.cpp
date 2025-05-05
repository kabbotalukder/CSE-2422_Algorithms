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

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    scana(a, n);
    insertion_sort(a, n);
    printa(a, n);
    return 0;
}