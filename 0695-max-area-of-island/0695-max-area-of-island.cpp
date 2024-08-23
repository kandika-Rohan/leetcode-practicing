class DisjointSet{
    private:
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int x){
        if(x == parent[x])return x;
        return parent[x]=findParent(parent[x]);
    }

    void uniteBySize(int u,int v){
        int x=findParent(u);
        int y=findParent(v);
        if( x == y)return ;
        if(size[x] < size[y]){
            parent[x]=y;
            size[y] += size[x];  // Corrected: size[y] should increase by size[x] only
        }
        else{
            parent[y]=x;
            size[x] += size[y];  // Corrected: size[x] should increase by size[y] only
        }
    }

    int findSize(int x){
        return size[findParent(x)]; // Corrected: Find size using the root node
    }
};

class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DisjointSet ds(n*m);

        // Direction vectors for moving up, right, down, and left
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                int node = i*m + j; // Current node
                for(int k=0;k<4;k++){
                   int nrow = i + drow[k];
                   int ncol = j + dcol[k];
                   if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        int adjnode = nrow*m + ncol; // Adjacent node
                        ds.uniteBySize(node, adjnode); // Union operation
                   }
                }
            }
        }

        int maxi = 0;
        for(int i=0;i<n*m;i++){
            if(grid[i/m][i%m] == 1){
                maxi = max(maxi, ds.findSize(i)); // Track the maximum component size
            }
        }

        return maxi;

    }
};
