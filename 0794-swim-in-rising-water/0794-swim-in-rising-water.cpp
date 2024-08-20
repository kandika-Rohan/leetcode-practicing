class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

  
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;


        q.push({grid[0][0], {0, 0}});

    
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

      
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto val = q.top();
            q.pop();
            
            int cost = val.first;  
            int row = val.second.first;
            int col = val.second.second;

  
            if (row == n - 1 && col == m - 1) {
                return cost;
            }

    
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;

                    q.push({max(cost, grid[nrow][ncol]), {nrow, ncol}});
                }
            }
        }
        
        return -1;  
    }
};
