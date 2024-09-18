class Trie {
    private:

    struct TrieNode {
        bool endOfWord;  
        TrieNode* links[26];  

        TrieNode() {
            endOfWord = false;  
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;  
            }
        }
    };

    public:
    TrieNode* root;  
    Trie() {
        root = new TrieNode();  
    }

    void insert(string word) {
        TrieNode* node = root;  
        for (char ch : word) {
            int index = ch - 'a';

            if (node->links[index] == nullptr) {
                node->links[index] = new TrieNode();  
            }
            node = node->links[index];  
        }
        node->endOfWord = true;  
    }

 
    void search(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& ans, string s) {
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || board[i][j] == '*' || !node->links[board[i][j] - 'a']) {
            return;  
        }

        char ch = board[i][j];  
        node = node->links[ch - 'a']; 

        s += ch; 
        if (node->endOfWord) {
            ans.push_back(s);  
            node->endOfWord = false;  
        }

        board[i][j] = '*'; 

        search(board, node, i + 1, j, ans, s);
        search(board, node, i - 1, j, ans, s); 
        search(board, node, i, j + 1, ans, s);  
        search(board, node, i, j - 1, ans, s);  

        board[i][j] = ch; 
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;  
        for (string word : words) {
            trie.insert(word); 
        }

        vector<string> ans; 

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                trie.search(board, trie.root, i, j, ans, ""); 
            }
        }
        return ans;
    }
};
