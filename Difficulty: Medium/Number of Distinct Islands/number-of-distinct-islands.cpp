//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1 && !vis[i][j]) {
            return true;
        }
        return false;
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, string& path) {
        vis[i][j] = 1;
        
        if (isvalid(i + 1, j, grid, vis, n, m)) {
            path += 'D';
            dfs(i + 1, j, grid, vis, n, m, path);
            path += 'B'; 
        }
        if (isvalid(i, j + 1, grid, vis, n, m)) {
            path += 'R';
            dfs(i, j + 1, grid, vis, n, m, path);
            path += 'B'; 
        }
        if (isvalid(i - 1, j, grid, vis, n, m)) {
            path += 'U';
            dfs(i - 1, j, grid, vis, n, m, path);
            path += 'B';
        }
        if (isvalid(i, j - 1, grid, vis, n, m)) {
            path += 'L';
            dfs(i, j - 1, grid, vis, n, m, path);
            path += 'B'; 
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<string> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    string path = "";
                    dfs(i, j, grid, vis, n, m, path);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends