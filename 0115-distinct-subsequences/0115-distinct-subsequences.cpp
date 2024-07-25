class Solution {
public:
    // int f(int i,int j,string s,string t){
    //      if(j<0){
    //         return 1;
    //     }
    //     if(i<0){
    //         return 0;
    //     }
    //     if(s[i] == t[j]){
    //         return f(i-1,j-1,s,t)+f(i-1,j,s,t);
    //     }
    //     else{
    //         return f(i-1,j,s,t);
    //     }
    // }
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    const int MOD=INT_MAX;
    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

};