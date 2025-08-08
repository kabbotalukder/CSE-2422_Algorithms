#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string X, string Y) {
    int n = X.length();
    int m = Y.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(X[i-1] == Y[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    
    cout << longestCommonSubsequence(X, Y) << endl;
    
    return 0;
}
