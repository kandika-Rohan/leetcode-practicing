//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isvalid(int row,int col,vector<vector<int>>&mat,int k){
        
        for(int i=0;i<9;i++){
            
            if(mat[row][i] == k){
                return false;
            }
            if(mat[i][col] == k){
                return false;
            }
            if(mat[3*(row/3)+(i/3)][3*(col/3) + (i%3)] == k){
                return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<int>>&mat){
        
        int n=mat.size();
        
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    for(int k=1;k<=9;k++){
                        if(isvalid(i,j,mat,k)){
                            mat[i][j]=k;
                            if(solve(mat)==true){
                                return true;
                            }
                            else{
                                mat[i][j]=0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
      
        
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends