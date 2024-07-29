class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        int ones=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j]=2;
                }
                else if(grid[i][j] == 1){
                    ones++;
                }
            }
        }

        int tm=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int time=node.first;
            int row=node.second.first;
            int col=node.second.second;

            tm=max(time,tm);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow >=0 && nrow<n && ncol >=0 && ncol < m && vis[nrow][ncol] != 2 &&
                grid[nrow][ncol] == 1){
                    vis[nrow][ncol]=2;
                    ones--;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        if(ones==0){
            return tm;
        }
        return -1;
    }
};