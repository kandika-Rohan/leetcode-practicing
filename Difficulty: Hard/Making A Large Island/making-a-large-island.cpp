//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DSU {
private:
    vector<int> parent, size;
    
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    
    void unite(int u, int v) {
        int x = find(u);
        int y = find(v);
        if (x == y) return;
        
        if (size[x] < size[y]) {
            size[y] += size[x];
            parent[x] = y;
        } else {
            size[x] += size[y];
            parent[y] = x;
        }
    }
    
    int sizeofcomponent(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU ds(n * m);
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        // Union the components of 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m 
                    && grid[nrow][ncol] == 1) {
                        int node = i * m + j;
                        int adjnode = nrow * m + ncol;
                        ds.unite(node, adjnode);
                    }
                }
            }
        }

        // Now, find the largest possible island
        int maxIsland = 0;
        
        // First, consider the original islands without changing any 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxIsland = max(maxIsland, ds.sizeofcomponent(i * m + j));
                }
            }
        }
        
        // Consider changing each 0 to 1 and calculate the possible maximum island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                
                set<int> uniqueComponents;
                for (int k = 0; k < 4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m 
                    && grid[nrow][ncol] == 1) {
                        uniqueComponents.insert(ds.find(nrow * m + ncol));
                    }
                }
                
                int newSize = 1; 
                for (auto comp : uniqueComponents) {
                    newSize += ds.sizeofcomponent(comp);
                }
                maxIsland = max(maxIsland, newSize);
            }
        }
        
        return maxIsland;
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends