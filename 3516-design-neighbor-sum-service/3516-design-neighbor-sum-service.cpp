class neighborSum {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    vector<vector<int>> grid;
    int n, m;
    
    neighborSum(vector<vector<int>>& grid) : grid(grid) {
        n = grid.size();
        m = grid[0].size();
    }
    
    int adjacentSum(int value) {
        pair<int, int> ans = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == value) {
                    ans = {i, j};
                    break;
                }
            }
            if (ans.first != -1) break; // Exit outer loop if the value is found
        }

        int sum = 0;
        if (ans.first == -1) return sum; // Value not found

        for (int i = 0; i < 4; i++) {
            int nrow = ans.first + delrow[i];
            int ncol = ans.second + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                sum += grid[nrow][ncol];
            }
        }
        return sum;
    }
    
    int diagonalSum(int value) {
        pair<int, int> ans = {-1, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == value) {
                    ans = {i, j};
                    break;
                }
            }
            if (ans.first != -1) break; // Exit outer loop if the value is found
        }

        int sum = 0;
        if (ans.first == -1) return sum; // Value not found

        for (auto it : directions) {
            int nrow = ans.first + it.first;
            int ncol = ans.second + it.second;
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                sum += grid[nrow][ncol];
            }
        }
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
