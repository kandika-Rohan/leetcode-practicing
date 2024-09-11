class Solution {
public:
    int count(int n){
        int cnt=0;
        while(n!=0){
            if(n&1){
                cnt++;
            }
            n=n>>1;
        }
        return cnt;

    }
    int minBitFlips(int start, int goal) {
        int mask=start^goal;

        return count(mask);
    }
};