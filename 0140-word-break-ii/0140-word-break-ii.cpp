class Solution {
public:
    unordered_map<string,vector<string>>dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        vector<string>res;
        for(auto w:wordDict){
            if(s.substr(0,w.length()) == w){
                if(w.length() == s.length() ){
                    res.push_back(w);
                }
                else{
                    vector<string>temp=wordBreak(s.substr(w.length()),wordDict);
                    for(string t:temp){
                        res.push_back(w+" "+t);
                    }
                }
            }
        }
        dp[s]=res;
        return res;
    }
};