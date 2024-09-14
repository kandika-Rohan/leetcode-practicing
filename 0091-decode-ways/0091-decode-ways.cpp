class Solution {
public:
    bool isvalid(const string& s) {
        if (s.empty() || s[0] == '0') return false; 
        if (s.size() > 2) return false; 
        int num = stoi(s); 
        return num >= 1 && num <= 26;
    }

    int f(int i, const string& s, vector<int>& dp) {
        if (i == s.size()) return 1; 
        if (dp[i] != -1) return dp[i]; 

        int count = 0;
        string temp = "";
        for (int j = i; j < s.size(); ++j) {
            temp += s[j];
            if (isvalid(temp)) {
                count += f(j + 1, s, dp); 
            } else {
                break; 
            }
        }
        return dp[i] = count; 
    }

    int numDecodings(const string& s) {
        vector<int> dp(s.size(), -1); 
        return f(0, s, dp);
    }
};
