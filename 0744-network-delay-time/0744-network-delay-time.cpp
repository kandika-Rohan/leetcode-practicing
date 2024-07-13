#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        // Priority queue to store {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k}); // {time, source}

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node]) continue; // Skip if we've already found a shorter path to this node

            for (const auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;
                if (time + travelTime < dist[nextNode]) {
                    dist[nextNode] = time + travelTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1; // If any node is unreachable
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
