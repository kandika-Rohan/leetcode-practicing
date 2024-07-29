class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        
        // Initialize indegree vector
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        // Create a queue and enqueue all nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Initialize count of visited nodes
       vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // Decrease the indegree of neighboring nodes by 1
            for (auto it : adj[node]) {
                indegree[it]--;
                // If indegree becomes 0, add it to the queue
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // If count of visited nodes is equal to the number of courses, return true
        if(topo.size()==numCourses){
            reverse(topo.begin(),topo.end());
            return topo;
        }
        return {};
    }
};