//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
   int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),1e9));
        vis[0][0]=grid[0][0];
        set<pair<int,pair<int,int>>>s;
        s.insert({grid[0][0],{0,0}});
        int r[4]={-1,1,0,0};
        int c[4]={0,0,1,-1};
        while (!s.empty()){
            auto it=s.begin();
            s.erase(it);
            int wt=it->first;
            int row=it->second.first;
            int col=it->second.second;
            for (int k=0;k<4;k++){
                int nr=row+r[k];
                int nc=col+c[k];
                if (nr>=0 and nc>=0 and nr<n and nc<m ){
                    if (wt+grid[nr][nc]<vis[nr][nc]){
                        vis[nr][nc]=wt+grid[nr][nc];
                        s.insert({wt+grid[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends