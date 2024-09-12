//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int cols, vector<vector<int>> &heights) {
        using p = pair<int, pair<int, int>>;
        
        priority_queue<p, vector<p>, greater<p>> q;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        q.push({0, {0, 0}});
        dist[0][0] = 0;
        
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if (row == n - 1 && col == m - 1) {
                return cost;
            }
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    
                    int effort = max(abs(heights[nrow][ncol] - heights[row][col]), cost);
                    
                    if (effort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = effort;
                        q.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends