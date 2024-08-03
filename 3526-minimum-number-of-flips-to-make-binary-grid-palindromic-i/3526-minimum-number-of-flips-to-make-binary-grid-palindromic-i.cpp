class Solution {
public:
    int f(vector<int>&arr){
        int i=0;
        int j=arr.size()-1;
        int cnt=0;
        while(i<j){
            if(arr[i] != arr[j]){
                cnt++;
            }
            i++;
            j--;
        }
        return cnt;
    }
    int minFlips(vector<vector<int>>& grid) {
        

        int rowflips=0;
        for(auto it:grid){
            int cnt=f(it);
            rowflips+=cnt;
        }
        int colflips=0;
        for(int i=0;i<grid[0].size();i++){
            vector<int>col(grid.size());
            for(int j=0;j<grid.size();j++){
                col[j]=grid[j][i];
            }
            int cnt=f(col);
            colflips+=cnt;
        }
        return min(rowflips,colflips);
    }
};