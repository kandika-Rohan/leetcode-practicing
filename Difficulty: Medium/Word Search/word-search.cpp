//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public: 
    bool dfs(int i, int j, string word, int ind, vector<vector<char>>& board) {
    if (ind == word.size()) {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[ind]) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';  // mark as visited

    bool found = dfs(i + 1, j, word, ind + 1, board) ||
                 dfs(i - 1, j, word, ind + 1, board) ||
                 dfs(i, j + 1, word, ind + 1, board) ||
                 dfs(i, j - 1, word, ind + 1, board);

    board[i][j] = temp;  // unmark

    return found;
}

bool isWordExist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[0]) {
                if (dfs(i, j, word, 0, board)) {
                    return true;
                }
            }
        }
    }
    return false;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends