//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int shotestPath(vector<vector<int>> &mat, int n, int m, int k) {
     
        if (k == 0 && mat[0][0] == 1) return -1;
        

        queue<pair<int, pair<int, pair<int, int>>>> q;
        q.push({0, {0, {0, k}}});

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k + 1, 0)));
        vis[0][0][k] = 1;
        
  
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second.first;
            int remainingK = it.second.second.second;
            

            if (row == n - 1 && col == m - 1) {
                return steps;
            }
            

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
    
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {

                    if (mat[nrow][ncol] == 1 && remainingK > 0 && !vis[nrow][ncol][remainingK - 1]) {
                        vis[nrow][ncol][remainingK - 1] = 1;
                        q.push({steps + 1, {nrow, {ncol, remainingK - 1}}});
                    }
                   
                    else if (mat[nrow][ncol] == 0 && !vis[nrow][ncol][remainingK]) {
                        vis[nrow][ncol][remainingK] = 1;
                        q.push({steps + 1, {nrow, {ncol, remainingK}}});
                    }
                }
            }
        }
        
    
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends