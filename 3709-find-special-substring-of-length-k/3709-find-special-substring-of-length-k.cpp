class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        for (int i = 0; i <= s.size() - k; i++) {
            char chars = s[i];
            int cnt = 0;
            int end = -1;
            string str = "";
            
            for (int j = i; j < i + k; j++) { // Fixed condition
                if (s[j] == chars) {
                    cnt++;
                    str += s[j];
                    end = j;
                } else {
                    break;
                }
            }
            
            if (cnt == k) { // Ensuring the substring length is exactly k
                if ((i - 1 < 0 || s[i - 1] != chars) && (end + 1 >= s.size() || s[end + 1] != chars)) {
                    return true;
                }
            }
        }
        return false;
    }
};
