class WordDictionary {
    struct Trie {
        Trie* links[26];
        bool isEnd;

        Trie() {
            isEnd = false;
            fill(begin(links), end(links), nullptr);
        }
    };

public:
    Trie* root;
    
    WordDictionary() {
        root = new Trie();
    }

    // Adds a word into the trie
    void addWord(string word) {
        Trie* node = root;
        for (char it : word) {
            int ind = it - 'a';
            if (node->links[ind] == nullptr) {
                node->links[ind] = new Trie();
            }
            node = node->links[ind];
        }
        node->isEnd = true;
    }


    bool searchInNode(string& word, Trie* node, int index) {
        if (index == word.size()) {
            return node->isEnd;
        }
        
        char ch = word[index];
        if (ch == '.') {
    
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && searchInNode(word, node->links[i], index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            int ind = ch - 'a';
            if (node->links[ind] == nullptr) {
                return false;
            }
            return searchInNode(word, node->links[ind], index + 1);
        }
    }

 
    bool search(string word) {
        return searchInNode(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
