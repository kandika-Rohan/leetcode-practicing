#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    int bfs(vector<vector<int>>& forest, int start_x, int start_y, int target_x, int target_y) {
        int n = forest.size();
        int m = forest[0].size();
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        q.push({start_x, start_y});
        visited[start_x][start_y] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

          
                if (x == target_x && y == target_y) {
                    return steps;
                }

           
                for (auto& dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];

                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && 
                        !visited[new_x][new_y] && forest[new_x][new_y] != 0) {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                    }
                }
            }
            steps++;
        }

 
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();
        int m = forest[0].size();
        vector<pair<int, pair<int, int>>> trees;

  
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (forest[i][j] > 1) {
                    trees.push_back({forest[i][j], {i, j}});
                }
            }
        }

       
        sort(trees.begin(), trees.end());

    
        int total_steps = 0;
        int curr_x = 0, curr_y = 0;

        for (auto& tree : trees) {
            int target_x = tree.second.first;
            int target_y = tree.second.second;

           
            int steps = bfs(forest, curr_x, curr_y, target_x, target_y);
            if (steps == -1) {
                return -1; 
            }

            total_steps += steps;
            curr_x = target_x;
            curr_y = target_y;
        }

        return total_steps;
    }
};
