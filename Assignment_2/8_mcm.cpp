#include<bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << matrixChainMultiplication(arr) << endl;
    return 0;
}
