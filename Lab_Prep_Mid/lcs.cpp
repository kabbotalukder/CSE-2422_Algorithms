#include<bits/stdc++.h>
using namespace std;

string findLCS(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int dp[101][101];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string lcs = "";

    while(i > 0 && m > 0){
        if(s1[i - 1] == s2[j - 1]){
            lcs += s1[i - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string s1 = "abcde";
    string s2 = "abcfde";
    cout << findLCS(s1, s2) << endl;
    return 0;
}