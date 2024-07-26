class Solution {
public:
    bool checkPossible(const string& a, const string& b) {
        if (a.size() != b.size() + 1) {
            return false;
        }
        int first = 0, second = 0;
        while (first < a.size()) {
            if (second < b.size() && a[first] == b[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return second == b.size(); // Ensure `b` is fully matched
    }

    static bool compare(const string& a, const string& b) {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (checkPossible(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
