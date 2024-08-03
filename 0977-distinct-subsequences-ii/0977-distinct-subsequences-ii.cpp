class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        const int M = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;  // Base case: empty string

        unordered_map<char, int> map;

        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            dp[i + 1] = (dp[i] * 2) % M;

            if (map.find(ch) != map.end()) {
                int j = map[ch];
                dp[i + 1] = (dp[i + 1] - dp[j] + M) % M;  
            }

            map[ch] = i;
        }

        return (dp[n] - 1 + M) % M;  
    }
};
