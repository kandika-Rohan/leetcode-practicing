class Solution {
public:

    int climbStairs(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        int prev1=0;
        int prev2=1;
       for(int i=1;i<=n;i++){
        int curr=prev1+prev2;
        prev1=prev2;
        prev2=curr;
       }
       return prev2;
    }
};