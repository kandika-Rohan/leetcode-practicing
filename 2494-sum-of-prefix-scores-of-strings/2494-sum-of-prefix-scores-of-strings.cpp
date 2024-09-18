class Trie{
    private:
    struct trie{
        int prefixCount;
        bool endOfWord;
        trie*links[26];
        trie(){
            prefixCount=0;
            endOfWord=false;
            fill(begin(links),end(links),nullptr);
        }
    };

    public:
    trie*root;
    Trie(){
        root=new trie();
    }

    void insert(string word){
        trie*node=root;

        for(auto it:word){
            int ind=it-'a';

            if(node->links[ind] == nullptr){
                node->links[ind]=new trie();
            }
            node=node->links[ind];
            node->prefixCount=node->prefixCount+1;
        }
        // node->prefixCount+=1;
        node->endOfWord=true;
    }

    int counting(string word){
        int cnt=0;

        trie*node=root;

        for(auto it:word){
            int ind=it-'a';

            if(node->links[ind] == nullptr){
                return 0;
            }
            node=node->links[ind];
            cnt+=node->prefixCount;
        }
        
       if(node->endOfWord == true){
        return cnt;
       }
       
       return 0;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;

        for(auto it:words){
            t.insert(it);
        }
        vector<int>ans;

        for(auto it:words){
            ans.push_back(t.counting(it));
        }

        return ans;
    }
};