class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int startColor=image[sr][sc];

        //if out start color is equals the color 
        //we need to fill then return image
        if(startColor == color)return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        int n=image.size();
        int m=image[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int row=val.first;
            int col=val.second;
            image[row][col]=color;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] &&
                image[nrow][ncol]==startColor){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

        return image;
    }
};