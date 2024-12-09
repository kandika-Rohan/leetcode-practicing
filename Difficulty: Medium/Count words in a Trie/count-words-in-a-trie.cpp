//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
    static const int ALPHABET_SIZE = 26;
    TrieNode* children[ALPHABET_SIZE];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& key) {
    int length = key.length();
    TrieNode* pCrawl = root;

    for (int level = 0; level < length; level++) {
        int index = key[level] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = new TrieNode();
        }
        pCrawl = pCrawl->children[index];
    }

    // Mark the last node as a leaf (end of word)
    pCrawl->isLeaf = true;
}


// } Driver Code Ends

class Solution {
  public:
    void search(TrieNode* root, int &count) {
        if (root->isLeaf) {
            count++;
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != nullptr) {
                search(root->children[i], count);
            }
        }
    }

    int wordCount(TrieNode* root) {
        int count = 0;
        search(root, count);
        return count; // No need to subtract 1 unless required for specific logic
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after reading `tc`

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the entire line of input

        vector<string> words;
        string word;

        // Use stringstream to split the input into words
        stringstream ss(input);
        while (ss >> word) {
            words.push_back(word);
        }

        TrieNode* root = new TrieNode();

        // Insert each word into the Trie
        for (const string& w : words) {
            insert(root, w);
        }

        Solution obj;
        cout << obj.wordCount(root) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends