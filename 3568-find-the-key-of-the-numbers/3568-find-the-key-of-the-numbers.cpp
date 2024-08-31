class Solution {
public:
    string f(int n, string &s) {
        for (int i = 0; i < n; i++) {
            s = "0" + s;
        }
        return s;
    }
    
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
       
        if (len1 < 4) {
            for (int i = 0; i < (4 - len1); i++) {
                s1 = "0" + s1;
            }
        }
        if (len2 < 4) {
            for (int i = 0; i < (4 - len2); i++) {
                s2 = "0" + s2;
            }
        }
        if (len3 < 4) {
            for (int i = 0; i < (4 - len3); i++) {
                s3 = "0" + s3;
            }
        }
       
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int digit = min({s1[i] - '0', s2[i] - '0', s3[i] - '0'});
            ans = ans * 10 + digit;
        }
        return ans;
    }
};
