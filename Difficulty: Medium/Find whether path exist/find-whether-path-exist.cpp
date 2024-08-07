//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
   bool is_Possible(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return false;
    
    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    
    int destrow = -1, destcol = -1;
    
    // Find the source and destination and initialize the queue with the source
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                q.push({i, j});
                vis[i][j] = 1;
            }
            if (grid[i][j] == 2) {
                destrow = i;
                destcol = j;
            }
        }
    }
    
    // If there's no destination, return false
    if (destrow == -1 || destcol == -1) return false;
    
    // Define the directions for movement: up, right, down, left
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    
    // Perform BFS
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int row = it.first;
        int col = it.second;
        
        // If the destination is reached, return true
        if (row == destrow && col == destcol) {
            return true;
        }
        
        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            // Check boundaries and whether the cell is not visited and not a wall
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] != 0) {
                vis[nrow][ncol] = 1; // Mark the cell as visited
                q.push({nrow, ncol}); // Add the cell to the queue
            }
        }
    }
    
    // If the queue is empty and the destination hasn't been reached, return false
    return false;
   }

    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends