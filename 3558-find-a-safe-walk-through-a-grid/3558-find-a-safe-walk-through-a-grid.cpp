class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();   
        int m = grid[0].size();  

        using p = pair<int, pair<int, int>>;
        queue<p> q;

        // Visited array stores max health at which a cell is visited
        vector<vector<int>> vis(n, vector<int>(m, -1));

        // Start BFS from (0,0) with the initial health
        
        int initial=grid[0][0] == 1?health-1:health;
        if(initial < 1)return false;
        vis[0][0] = initial;
        q.push({initial, {0, 0}});

        // Directions for moving up, right, down, left
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int h = it.first;         // Current health
            int r = it.second.first;  // Current row
            int c = it.second.second; // Current column

            // Check if we've reached the last cell
            if (r == n - 1 && c == m - 1) {
                if (h >= 1) return true;
            }

            // Explore all 4 possible directions
            for (int k = 0; k < 4; ++k) {
                int nrow = delrow[k] + r;
                int ncol = delcol[k] + c;

                // Check if the next row and column are within bounds
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newHealth = h;

                    // Decrease health if moving to an unsafe cell
                    if (grid[nrow][ncol] == 1) {
                        newHealth -= 1;
                    }

                    // Only proceed if new health is valid (>= 0) and better than the last visit
                    if (newHealth >= 0 && newHealth > vis[nrow][ncol]) {
                        vis[nrow][ncol] = newHealth;
                        q.push({newHealth, {nrow, ncol}});
                    }
                }
            }
        }

        // If no valid path is found, return false
        return false;
    }
};
