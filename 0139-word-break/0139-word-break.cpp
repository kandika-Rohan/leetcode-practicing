class Solution {
public:

    int helper(int i,string s,unordered_set<string>&st,vector<int>&dp){
        if(i==s.size()){
            return dp[i]=1;
        }
        if(dp[i] != -1){  return dp[i];}
          
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp) != st.end()){
                if(helper(j+1,s,st,dp)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<int>dp(s.size()+1,-1);
        return helper(0,s,st,dp);
    }
};