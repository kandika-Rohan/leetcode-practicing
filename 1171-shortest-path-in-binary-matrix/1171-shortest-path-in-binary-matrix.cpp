class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Check if the start or end is blocked
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        
        // Initialize BFS queue
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1}); // Start from (0,0) with a distance of 1

        // Direction vectors for 8 possible moves (up, down, left, right, and 4 diagonals)
        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        // Perform BFS
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            // Check if we've reached the end
            if(x == m-1 && y == n-1) return dist;

            // Explore all 8 possible directions
            for(auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check if the new position is within bounds and is an open cell
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    // Mark the cell as visited by setting it to 1
                    grid[newX][newY] = 1;
                    // Add the new position to the queue with updated distance
                    q.push({{newX, newY}, dist + 1});
                }
            }
        }

        // If we exit the loop, there is no path to the end
        return -1;
    }
};
