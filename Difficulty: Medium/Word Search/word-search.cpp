//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
public:



int delrow[4] = { -1, 0, 1, 0 };
int delcol[4] = { 0, 1, 0, -1 };

bool f(int i, int j, string w, int ind, vector<vector<int>>& vis, vector<vector<char>>& m) {
    if (w.size() == ind) return true;
    
    vis[i][j] = 1;
    
    for (int k = 0; k < 4; k++) {
        int nrow = i + delrow[k];
        int ncol = j + delcol[k];
        
        if (nrow >= 0 && nrow < m.size() && ncol >= 0 && ncol < m[0].size()
            && !vis[nrow][ncol] && m[nrow][ncol] == w[ind]) {
            
            if (f(nrow, ncol, w, ind + 1, vis, m)) {
                return true;
            }
        }
    }
    
    vis[i][j] = 0; // Backtrack: unmark the cell
    return false;
}

bool wordSearch(vector<vector<char>>& m, string w) {
    // code here
    
    int r = m.size();
    int c = m[0].size(); // Corrected the column size assignment
    vector<vector<int>> vis(r, vector<int>(c, 0));
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (m[i][j] == w[0] && !vis[i][j]) { // Corrected the condition and fixed syntax error
                // this is meant when the first letter of the word is found
                if (f(i, j, w, 1, vis, m)) { // Start from the second character
                    return true; // Corrected the return value to true if the word is found
                }
            }
        }
    }
    return false; // Corrected the return value to false if the word is not found
}


};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<char>> mat(n,vector<char>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        string str; cin>>str;
        Solution ob;
        auto ans=ob.wordSearch(mat,str);
        cout<<ans<<"\n";
    }
    return 0;
}

// } Driver Code Ends