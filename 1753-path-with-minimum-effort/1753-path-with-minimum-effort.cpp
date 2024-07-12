class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        q.push({0, {0, 0}});
        dis[0][0] = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.top().second.first;
            int col = q.top().second.second;
            int dist = q.top().first;
            q.pop();

            if (row == n-1 && col == m-1) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int effort = max(abs(heights[nrow][ncol] - heights[row][col]), dist);
                    if (effort < dis[nrow][ncol]) {
                        dis[nrow][ncol] = effort;
                        q.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
