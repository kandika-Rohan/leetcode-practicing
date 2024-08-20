class DisjointSet {
private:
    vector<int> parent, rank, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void uniteBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;
        if (size[rootU] < size[rootV]) {
            size[rootV] += size[rootU];
            parent[rootU] = rootV;
        } else {
            size[rootU] += size[rootV];
            parent[rootV] = rootU;
        }
    }

    int getSize(int x) {
        return size[findParent(x)];
    }
};

class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Connect the components
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int k = 0; k < 4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int node = i * n + j;
                        int adjnode = nrow * n + ncol;
                        ds.uniteBySize(node, adjnode);
                    }
                }
            }
        }

        // Add a zero to connect components and find the maximum size
        int maxSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> components;
                for (int k = 0; k < 4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        components.insert(ds.findParent(nrow * n + ncol));
                    }
                }

                int totalSize = 0;
                for (auto comp : components) {
                    totalSize += ds.getSize(comp);
                }
                maxSize = max(maxSize, totalSize + 1);
            }
        }

        // Check for the largest component without flipping any 0
        for (int i = 0; i < n * n; i++) {
            maxSize = max(maxSize, ds.getSize(i));
        }

        return maxSize;
    }
};
