class DSU {
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
        return parent[x] = find(parent[x]);
    }
    void union1(int u, int v) {
        int x = find(u);
        int y = find(v);

        if (x == y) return;
        if (size[x] < size[y]) {
            size[y] += size[x];
            parent[x] = y; // Corrected: Set parent[x] to y
        } else {
            size[x] += size[y];
            parent[y] = x;
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        DSU ds(maxi);
        for (auto it : nums) {
            for (int i = 2; i <= sqrt(it); i++) {
                if (it % i == 0) {
                    ds.union1(it, i);
                    ds.union1(it, it / i);
                }
            }
        }

        unordered_map<int, int> map;
        for (auto it : nums) { 
            map[ds.find(it)]++;
        }

        int ans = 0;
        for (auto it : map) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};
