class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        vector<int> dp(s.size() + 1, 0);

        
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

       
        for (int i = 1; i <= s.size(); i++) {
           
            dp[i] = dp[i - 1] + 1;

            
            for (int j = 0; j < i; j++) {
          
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                   
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

       
        return dp[s.size()];
    }
};
