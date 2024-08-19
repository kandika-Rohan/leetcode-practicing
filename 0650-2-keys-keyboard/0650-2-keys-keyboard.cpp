class Solution {
public:
    int f(int i, int n, int val) {
        if (i == n) return 0;
        if (i > n) return 1e9;
      
        int copy = 2 + f(i * 2, n, i); // Copy all and paste (val becomes i)
        int paste = 1 + f(i + val, n, val); // Paste the last copied value
        return min(copy, paste);
    }

    int minSteps(int n) {
        if (n <= 1) return 0;
        return f(1, n, 1)+1;
    }
};
