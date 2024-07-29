//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool isvalid(int i, int j, int n, int m, vector<vector<int>>& mat) {
        return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
    }

    void dfs(int i, int j, int n, int m, vector<string>& ans, string path, vector<vector<int>>& mat) {
        if (i == n - 1 && j == m - 1) {
            ans.push_back(path);
            return;
        }
        
        // Mark the cell as visited
        mat[i][j] = 0;

        // Move up
        if (isvalid(i - 1, j, n, m, mat)) {
            dfs(i - 1, j, n, m, ans, path + 'U', mat);
        }
        
        // Move right
        if (isvalid(i, j + 1, n, m, mat)) {
            dfs(i, j + 1, n, m, ans, path + 'R', mat);
        }
        
        // Move down
        if (isvalid(i + 1, j, n, m, mat)) {
            dfs(i + 1, j, n, m, ans, path + 'D', mat);
        }
        
        // Move left
        if (isvalid(i, j - 1, n, m, mat)) {
            dfs(i, j - 1, n, m, ans, path + 'L', mat);
        }

        // Restore the cell to its original state for other paths
        mat[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0 || mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return {};
        }

        vector<string> ans;
        dfs(0, 0, n, n, ans, "", mat);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends