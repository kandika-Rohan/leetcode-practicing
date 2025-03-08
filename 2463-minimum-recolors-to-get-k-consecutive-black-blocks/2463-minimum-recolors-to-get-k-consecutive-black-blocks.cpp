class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n=blocks.size();
        if(n == 0 || k == 0){
            return 0;
        }
        int mini=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int cnt=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j] == 'B'){
                    cnt++;
                }
            }
            mini=min(mini,k-cnt);
        }  
        return mini;

    }
};