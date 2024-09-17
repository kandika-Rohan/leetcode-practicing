//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Trie {
private:
    struct trie {
        trie* links[26];
        bool endOfWord;

        trie() {
            endOfWord = false;
            fill(begin(links), end(links), nullptr);
        }
    };

public:
    trie* root;
    Trie() {
        root = new trie();
    }

    void insert(string word) {
        trie* node = root;

        for (auto it : word) {
            int ind = it - 'a';

            if (node->links[ind] == nullptr) {
                node->links[ind] = new trie();
            }
            node = node->links[ind];
        }

        node->endOfWord = true;
    }

    bool search(string word) {
        trie* node = root;

        for (auto it : word) {
            int ind = it - 'a';

            if (node->links[ind] == nullptr) {
                return false;
            }
            node = node->links[ind];
        }

        return node->endOfWord;
    }

    bool searchPrefix(string word, int start, int end) {
        trie* node = root;

        for (int i = start; i <= end; i++) {
            int ind = word[i] - 'a';

            if (node->links[ind] == nullptr) {
                return false;
            }
            node = node->links[ind];
        }

        return node->endOfWord;
    }
};

class Solution {
public:
    int wordBreak(string A, vector<string> &B) {
        Trie t;

        // Insert all the words from dictionary B into the Trie
        for (auto it : B) {
            t.insert(it);
        }

        int n = A.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // base case: empty string can be segmented

        // Dynamic Programming approach
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && t.searchPrefix(A, j, i - 1)) {
                    dp[i] = true;
                    break; // No need to check further if A[0..i-1] can be segmented
                }
            }
        }

        return dp[n] ? 1 : 0;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends