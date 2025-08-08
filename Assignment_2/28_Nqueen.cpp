#include <bits/stdc++.h>
using namespace std;

int solutions = 0;

void printBoard(const vector<int>& queenPos, int n) {
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (queenPos[r] == c) cout << 'Q';
            else cout << '.';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solveNQueensBacktrack(int row, int n, vector<int>& queenPos, vector<bool>& colUsed, vector<bool>& diag1Used, vector<bool>& diag2Used) {
    if (row == n) {
        ++solutions;
        printBoard(queenPos, n);
        return;
    }

    for (int c = 0; c < n; ++c) {
        int d1 = row + c;
        int d2 = row - c + (n - 1);
        if (!colUsed[c] && !diag1Used[d1] && !diag2Used[d2]) {
            queenPos[row] = c;
            colUsed[c] = diag1Used[d1] = diag2Used[d2] = true;

            solveNQueensBacktrack(row + 1, n, queenPos, colUsed, diag1Used, diag2Used);

            colUsed[c] = diag1Used[d1] = diag2Used[d2] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter n (size of board): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n\n";
        return 0;
    }

    vector<int> queenPos(n, -1);
    vector<bool> colUsed(n, false);
    vector<bool> diag1Used(2 * n - 1, false);
    vector<bool> diag2Used(2 * n - 1, false);

    solutions = 0;
    cout << "All solutions (Q = queen, . = empty):\n\n";
    solveNQueensBacktrack(0, n, queenPos, colUsed, diag1Used, diag2Used);

    cout << "Total solutions for n = " << n << " : " << solutions << '\n';
    return 0;
}
