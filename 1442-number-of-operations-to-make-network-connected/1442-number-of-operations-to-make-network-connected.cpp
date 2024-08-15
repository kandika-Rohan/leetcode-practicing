class DisjointSet {
    vector<int> parent, size, rank;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int x) {
        if (x == parent[x]) return x;
        else {
            return parent[x] = findParent(parent[x]);
        }
    }

    void UnionByRank(int u, int v) {
        int x = findParent(u);
        int y = findParent(v);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y; // Corrected parent[u] = v to parent[x] = y
            rank[y]++; // Corrected rank[v]++ to rank[y]++
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n); // Corrected Disjointset to DisjointSet

        int extra = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                extra++;
            } else {
                ds.UnionByRank(u, v);
            }
        }

        int cntc = 0;
        for (int i = 0; i < n; i++) { // Changed i <= n to i < n
            if (ds.findParent(i) == i) cntc++; // Corrected ds.parent[i] == i to ds.findParent(i) == i
        }

        int ans = cntc - 1;
        if (extra >= ans) return ans;
        return -1;
    }
};
