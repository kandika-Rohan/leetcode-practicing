class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        int r=n-1;
        while(r>=0 && c<m){
            if(grid[r][c]<0){
                r=r-1;
                count+=m-c;
            }
            else{
                c++;
            }
        }
        return count;
    }
};