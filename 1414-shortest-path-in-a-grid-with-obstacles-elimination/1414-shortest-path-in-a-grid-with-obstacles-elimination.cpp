class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0] == 1 && k == 0)return -1;

        queue<pair<int,pair<pair<int,int>,int>>>q;
        q.push({0,{{0,0},k}});
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        vis[0][0][k]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int row=it.second.first.first;
            int col=it.second.first.second;
            int remaining=it.second.second;
            if(row == n-1 && col == m-1){
                return steps;
            }
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m){
                    if(grid[nrow][ncol] ==1
                    && remaining > 0 && vis[nrow][ncol][remaining-1] ==0 ){
                        vis[nrow][ncol][remaining-1] = 1;
                        q.push({steps+1,{{nrow,ncol},remaining-1}});
                    }
                    else if(grid[nrow][ncol] ==0  && vis[nrow][ncol][remaining] ==0){
                        vis[nrow][ncol][remaining] = 1;
                        q.push({steps+1,{{nrow,ncol},remaining}});
                    }
                }
            }
        }

        return -1;
    }
};