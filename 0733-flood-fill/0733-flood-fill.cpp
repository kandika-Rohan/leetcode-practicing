class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c=image[sr][sc];
        if(c == color){
            return image;
        }

        vector<vector<int>>vis=image;
        int n=image.size();
        int m=image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});

        vis[sr][sc]=color;

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m &&
                image[nrow][ncol]==c && vis[nrow][ncol] != color ){
                    vis[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return vis;

    }
};