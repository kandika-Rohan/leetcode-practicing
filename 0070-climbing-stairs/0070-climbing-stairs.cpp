class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)return 1;
        if(n== 1)return 1;
        int prev0=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev0+prev1;
            prev0=prev1;
            prev1=curr;
        }
        return prev1;
    }
};