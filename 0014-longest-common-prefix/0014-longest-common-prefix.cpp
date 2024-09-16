class Trie{
    struct trie{
        trie*links[26];
        int cp;
     
        trie() {
            for(int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            cp = 0;
        }
    };
    
    trie*getNode(){
        trie*newNode = new trie();
        return newNode;
    }

    public:
    trie*root;

    Trie(){
        root = getNode();
    }

    void insert(string word){
        trie*temp = root;
        for(auto it : word){
            int ind = it - 'a';
            if(temp->links[ind] == nullptr){
                temp->links[ind] = getNode();
            }
            temp = temp->links[ind];
            temp->cp = temp->cp + 1;
        }
    }

    string lps(string word, int n){
        string ans = "";
        trie*temp = root;
        for(auto it : word){
            int ind = it - 'a';
            if(temp->links[ind] == nullptr){
                break;
            }
            if(temp->links[ind] != nullptr && temp->links[ind]->cp == n){
                ans += it;
                temp = temp->links[ind];
            }
            else{
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return ""; 
        Trie t;
        for(auto it : strs){
            t.insert(it);
        }
        string s = strs[0]; 
        string ans = t.lps(s, n);
        return ans;
    }
};
