class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int val=n*n;

        vector<int>hash(val+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]=hash[grid[i][j]]+1;
            }
        }
        vector<int>ans(2,0);
        for(int i=1;i<=val;i++){
            if(hash[i] == 2){
                ans[0]=i;
            }
            else if(hash[i] == 0){
                ans[1]=i;
            }
        }

        return ans;
    }
};