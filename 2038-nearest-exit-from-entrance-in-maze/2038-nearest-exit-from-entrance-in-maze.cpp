class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        set<pair<int, int>> st; 
        int n = maze.size();
        int m = maze[0].size();

       
        for (int i = 0; i < n; i++) {
            
            if (maze[i][0] == '.' && !(i == entrance[0] && 0 == entrance[1])) {
                st.insert({i, 0});
            }
            if (maze[i][m - 1] == '.' && !(i == entrance[0] && m - 1 == entrance[1])) {
                st.insert({i, m - 1});
            }
        }

        for (int i = 0; i < m; i++) {
            if (maze[0][i] == '.' && !(0 == entrance[0] && i == entrance[1])) {
                st.insert({0, i});
            }
            if (maze[n - 1][i] == '.' && !(n - 1 == entrance[0] && i == entrance[1])) {
                st.insert({n - 1, i});
            }
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {entrance[0], entrance[1]}});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[entrance[0]][entrance[1]] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // If it's an exit, return the steps immediately
            if (st.find({row, col}) != st.end()) {
                return steps;
            }

            // BFS Traversal
            for (int k = 0; k < 4; k++) {
                int i = delrow[k] + row;
                int j = delcol[k] + col;

                if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] &&
                    maze[i][j] == '.') {
                    q.push({steps + 1, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        return -1;  // No exit found
    }
};
