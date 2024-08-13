class Solution {
public:
    int f(int i,int j,string s,string t){
        if(i<0 || j<0)return 0;

        //if match
        if(s[i] == t[j]){
            return 1+f(i-1,j-1,s,t);
        }
        else{
            return max(f(i-1,j,s,t),f(i,j-1,s,t));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    // dp[i][j]=1+dp[i-1][j-1];
                    curr[j]=1+prev[j-1];

                }
                else{
                    // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }


        // for(auto it:dp){
        //     for(auto q:it){
        //         cout<<q<<" ";
        //     }
        //     cout<<endl;
        // }

        return prev[m];

    }
};