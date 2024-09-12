class Solution {
public:
    double dfs(string a, string b, unordered_map<string, int>& map, unordered_map<string, vector<pair<string ,double>>>& adj, double val){
        if(a == b) return val;
        
        map[a] = 1;
        for(auto it : adj[a]){
            string node = it.first;
            double cost = it.second;
            if(map[node] != 1){
                double result = dfs(node, b, map, adj, val * cost);
                if(result != -1) return result;
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = values.size();

        // Building adjacency list
        for(int i = 0; i < n; i++){
            double cost = values[i];
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, cost});
            adj[b].push_back({a, 1 / cost});
        }

        vector<double> ans;
        for(auto& it : queries){
            unordered_map<string, int> map;
            string u = it[0];
            string v = it[1];
            if(adj.find(u) == adj.end() || adj.find(v) == adj.end()){
                ans.push_back(-1);
            } else {
                ans.push_back(dfs(u, v, map, adj, 1.0));
            }
        }

        return ans;
    }
};
