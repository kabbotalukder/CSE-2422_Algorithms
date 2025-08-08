#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

void huffmanCoding(vector<char> chars, vector<int> freqs) {
    int n = chars.size();

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freqs[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int combinedFreq = left->freq + right->freq;
        Node* newNode = new Node('$', combinedFreq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    for (auto& pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << "\n";
    }
}

int main() {
    vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<int> freqs = {5, 9, 12, 13, 16, 45};

    huffmanCoding(chars, freqs);

    return 0;
}
