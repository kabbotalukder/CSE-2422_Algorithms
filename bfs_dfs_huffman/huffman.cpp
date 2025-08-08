*Huffman Code*

#include <bits/stdc++.h>
using namespace std;

vector<char> chars;
vector<int> freq;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(int f, Node* l, Node* r) : ch('\0'), freq(f), left(l), right(r) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, char code[], int top) {
    if (!root) return;
    if (!root->left && !root->right) {
        code[top] = '\0';
        cout << root->ch << ": " << code << "\n";
        return;
    }
    code[top] = '0';
    printCodes(root->left, code, top + 1);
    code[top] = '1';
    printCodes(root->right, code, top + 1);
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char c;
        int f;
        cin >> c >> f;
        chars.push_back(c);
        freq.push_back(f);
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->freq + right->freq, left, right);
        pq.push(parent);
    }

    Node* root = pq.top();
    char code[100];
    printCodes(root, code, 0);

    return 0;
}


*Input*
4
A 5
B 1
C 6
D 3

*Output*
C: 0
B: 100
D: 101
A: 11