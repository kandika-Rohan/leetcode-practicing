class Solution {
public:
    // Helper function to check if the substring s[i..j] is a palindrome
    bool isPalindrome(const string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    // Function to find the minimum cuts needed for palindrome partitioning using tabulation
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);  // dp[i] will store the minimum cuts needed for substring s[i..n-1]

        // Initialize the dp array for the base case
        for (int i = 0; i <= n; i++) {
            dp[i] = n - 1 - i;  // maximum cuts needed
        }

        // Fill the dp array in bottom-up manner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];  // The answer for the entire string is stored in dp[0]
    }
};
