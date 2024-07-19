class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<int, int>> adj[n];  // Create adjacency list
        for (auto& nbr : roads) {
            adj[nbr[0]].push_back({nbr[1], nbr[2]});
        adj[nbr[1]].push_back({nbr[0], nbr[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LLONG_MAX);  
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        const long long mod = 1e9 + 7;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                long long adjNode = it.first;
                long long edw = it.second;

                if (dis + edw < dist[adjNode]) {
                    dist[adjNode] = dis + edw;
                    pq.push({dis + edw, adjNode});
                    ways[adjNode] = ways[node];
                } else if (dis + edw == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;

    }
};