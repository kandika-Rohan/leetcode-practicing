class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int original = x;
        long long num = 0;
        while(original > 0)
        {
            int digit = original % 10;
            original = original / 10;
            num = num * 10 + digit; 
        }
        return num == (long)x;
    }
};