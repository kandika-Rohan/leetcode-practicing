//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,
    int n,int m){
        vis[i][j]=1;
        
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty()){
            auto val=q.front();
            q.pop();
            int row=val.first;
            int col=val.second;
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol] == 'X'&&
                !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int m=grid[0].size();
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'X'){
                    cnt++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends