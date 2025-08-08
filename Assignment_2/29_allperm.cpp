#include <bits/stdc++.h>
using namespace std;

void generatePermutations(string &s, int l, int r) {
    if (l == r) {
        cout << s << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        generatePermutations(s, l + 1, r);
        swap(s[l], s[i]);
    }
}

int main() {
    string s;
    cin >> s;
    generatePermutations(s, 0, s.size() - 1);
    return 0;
}
