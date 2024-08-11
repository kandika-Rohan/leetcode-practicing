class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
    // Initialize the grid with positions
    vector<vector<int>> grid(n, vector<int>(n));
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = k++;
        }
    }
    
    // Starting position of the snake
    int i = 0, j = 0;
    int ans = grid[i][j];
    
    // Process each command
    for (const auto& it : commands) {
        if (it == "UP") {
            i--;
        } else if (it == "RIGHT") {
            j++;
        } else if (it == "DOWN") {
            i++;
        } else if (it == "LEFT") {
            j--;
        }
        ans = grid[i][j];
    }
    
    return ans;
}

};