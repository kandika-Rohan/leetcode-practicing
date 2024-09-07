//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool f(int i, int j, int ind, string s, vector<vector<char>>& board, int n, int m) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') return false;
        if (ind == s.size() - 1) return s[ind] == board[i][j]; // Check if last character matches
        if (s[ind] != board[i][j]) return false;
        
        char original = board[i][j];
        board[i][j] = '$';
        
        bool op1 = f(i + 1, j, ind + 1, s, board, n, m);
        bool op2 = f(i - 1, j, ind + 1, s, board, n, m);
        bool op3 = f(i, j - 1, ind + 1, s, board, n, m);
        bool op4 = f(i, j + 1, ind + 1, s, board, n, m);
        bool op5 = f(i - 1, j - 1, ind + 1, s, board, n, m);
        bool op6 = f(i + 1, j + 1, ind + 1, s, board, n, m);
        bool op7 = f(i - 1, j + 1, ind + 1, s, board, n, m);
        bool op8 = f(i + 1, j - 1, ind + 1, s, board, n, m);
        
        board[i][j] = original;
        
        return op1 || op2 || op3 || op4 || op5 || op6 || op7 || op8;
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();
        unordered_set<string> st;

        for (const string& word : dictionary) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (word[0] == board[i][j]) {
                        if (f(i, j, 0, word, board, n, m)) {
                            st.insert(word);
                        }
                    }
                }
            }
        }

        for (const string& word : st) {
            ans.push_back(word);
        }

        return ans;
    }


};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends