//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  
    int f(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& vis) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j] == 1) {
            return 0;
        }
        
        vis[i][j] = 1;
        int area = 1;

        int delRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++) {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];
            area += f(nrow, ncol, grid, n, m, vis);
        }

        return area;
    }

    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    maxi = max(maxi, f(i, j, grid, n, m, vis));
                }
            }
        }

        return maxi;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends