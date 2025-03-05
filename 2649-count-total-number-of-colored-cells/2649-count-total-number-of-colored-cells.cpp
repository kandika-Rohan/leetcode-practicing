class Solution {
public:
    long long coloredCells(int n) {
        
        long long ans=0;
        int j=1;
        for(int i=0;i<n;i++){
            ans+=j;
            j+=2;
        }
        j=1;
        for(int i=0;i<n-1;i++){
            ans+=j;
            j+=2;
        }

        return ans;
    }
};