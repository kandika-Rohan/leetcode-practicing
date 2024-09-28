class Solution {
public:
    int f(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto it:nums){
            mini=min(mini,f(it));
        }
        return mini;
    }
};