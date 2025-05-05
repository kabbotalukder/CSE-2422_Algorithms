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

void heapify(int a[], int i, int n){
    while(true){
        int largest = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;
    
        if(l < n && a[l] > a[largest]){
            largest = l;
        }
    
        if(r < n && a[r] > a[largest]){
            largest = r;
        }
    
        if(largest != i){
            swap(a[largest], a[i]);
            i = largest;
        }
        else{
            break;
        }
    }
}

void heap_sort(int a[], int n){
    for(int i = (n / 2) - 1; i >= 0; i--){
        heapify(a, i, n);
    }

    for(int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    scana(a, n);
    heap_sort(a, n);
    printa(a, n);
    return 0;
}