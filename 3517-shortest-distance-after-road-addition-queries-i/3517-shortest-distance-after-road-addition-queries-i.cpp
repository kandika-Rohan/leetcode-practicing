#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> adjlist(n);

        // Initially, there's a road from city i to city i + 1
        for (int i = 0; i < n - 1; ++i) {
            adjlist[i].push_back(i + 1);
        }

        auto dijkstra = [&](int start, int target) {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                auto [distance, node] = pq.top();
                pq.pop();

                if (distance > dist[node]) continue;

                for (int neighbor : adjlist[node]) {
                    if (dist[node] + 1 < dist[neighbor]) { // edge weight is 1
                        dist[neighbor] = dist[node] + 1;
                        pq.push({dist[neighbor], neighbor});
                    }
                }
            }
            return dist[target];
        };

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            adjlist[u].push_back(v);
            answer.push_back(dijkstra(0, n - 1));
        }

        return answer;
    }
};
