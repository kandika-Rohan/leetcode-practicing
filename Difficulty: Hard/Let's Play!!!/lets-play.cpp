//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


int isSuperSimilar(int n, int m, std::vector<std::vector<int>>& mat, int x) {
    std::vector<std::vector<int>> res = mat;  // Store original matrix
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {  
            // Left rotate for even-indexed rows
            std::rotate(mat[i].begin(), mat[i].begin() + (x % m), mat[i].end());
        } else {  
            // Right rotate for odd-indexed rows
            std::rotate(mat[i].rbegin(), mat[i].rbegin() + (x % m), mat[i].rend());
        }
    }
    
    return res == mat ? 1 : 0;
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        int x;
        cin >> x;
        
        Solution ob;
        cout<<ob.isSuperSimilar(n,m,mat,x)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends