class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] ==1 || grid[n-1][n-1] == 1)return -1;


        queue<pair<int,pair<int,int>>>q;

        q.push({1,{0,0}});

        grid[0][0]=1;
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int dist=val.first;
            int row=val.second.first;
            int col=val.second.second;

            if(row == n-1 && col == n-1)return dist;

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow >=0 && nrow <n && ncol>=0 && 
                    ncol <n && grid[nrow][ncol] == 0){
                        q.push({dist+1,{nrow,ncol}});
                        grid[nrow][ncol]=1;
                    }
                }
            }
        }

        return -1;

    }
};