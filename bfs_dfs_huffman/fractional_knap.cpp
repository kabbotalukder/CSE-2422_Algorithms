#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
};

void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

void sortItems(Item items[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            double r1 = (double)items[j].value / items[j].weight;
            double r2 = (double)items[j+1].value / items[j+1].weight;
            if (r1 < r2) {
                swap(items[j], items[j+1]);
            }
        }
    }
}

double fractionalKnapsack(int capacity, Item items[], int n) {
    sortItems(items, n);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (capacity == 0) break;

        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += (double)items[i].value * capacity / items[i].weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    cin >> n;

    Item items[100]; 
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }
    cin >> capacity;

    double result = fractionalKnapsack(capacity, items, n);
    cout << result << endl;

    return 0;
}