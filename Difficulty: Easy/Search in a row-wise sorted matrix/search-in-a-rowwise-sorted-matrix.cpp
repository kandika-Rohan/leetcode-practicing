//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    
    
    bool find_x(vector<int> row, int x) {
        int l=0, r=row.size();
        
        while(l < r) {
            int mid = l + (r-l)/2;
            if(row[mid] == x)
                return true;
            else if(row[mid] < x)
                l = mid+1;
            else
                r = mid;
        }
        
        return false;
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        
        
        for(auto it:mat){
            if(find_x(it,x)){
                return true;
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
        if (obj.searchRowMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends