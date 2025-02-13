//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int delrow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int delcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    bool checkDirection(int i, int j, vector<vector<char>> &grid, string &word, int dir) {
        int n = grid.size(), m = grid[0].size();
        int len = word.size();
        
        for (int k = 0; k < len; k++) {
            int newRow = i + k * delrow[dir];
            int newCol = j + k * delcol[dir];
            
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != word[k]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        if (checkDirection(i, j, grid, word, dir)) {
                            ans.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends