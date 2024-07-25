class Solution {
public:
    // bool solve(int i, int j, string s, string p, vector<vector<int>>& dp) {
    //     // Base cases
    //     if (i == 0 && j == 0) return true;  // Both strings are exhausted
    //     if (i > 0 && j == 0) return false; // Pattern exhausted but string not
    //     if (i == 0 && j > 0) { // String exhausted but pattern not
    //         for (int k = 1; k <= j; k++) {
    //             if (p[k] != '*') {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }

    //     // If already computed
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     // Match condition
    //     if (s[i-1] == p[j-1] || p[j-1] == '?') {  // Correction: added check for '?' wildcard
    //         return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    //     } else if (p[j-1] == '*') {
    //         return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
    //     } else {
    //         return dp[i][j] = false;
    //     }
    // }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false)); 

        dp[0][0]=true;

        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if match
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                //if not match the another condition
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};
