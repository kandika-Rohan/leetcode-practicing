//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // Code here
        
        int row = mat.size() - 1;
        
        for (int i = 0; i < mat.size(); i++) { 
            if (mat[i][0] > x) {
                row = i - 1; 
                if (row < 0) {
                    row = 0; 
                }
                break;
            }
        }
        
        int l = 0;
        int r = mat[row].size() - 1; 
        
   
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (mat[row][mid] == x) {
                return true; 
            } else if (mat[row][mid] < x) {
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends