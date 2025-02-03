class TRIE{
    struct trie{
        trie*children[26];
        bool isend;

        trie(){
            isend=false;
            fill(begin(children),end(children),nullptr);
        }
    };

    public:
    trie*root;

    TRIE(){

        root=new trie();
    }

    void insert(string word){

        trie*node=root;

        for(auto it:word){
            int ind=it-'a';
            if(node->children[ind] == nullptr){
                node->children[ind]=new trie();
            }
            node=node->children[ind];
        }
        node->isend=true;
    }

    bool search(int start,int end,string word){

        trie*node=root;
        
        for(int i=start;i<=end;i++){
            
            int ind=word[i]-'a';

            if(!node->children[ind]){

                return false;
            }

            node=node->children[ind];
        }
        return node->isend;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        TRIE t;

        for(auto it:wordDict){
            t.insert(it);
        }

        int n=s.size();

        vector<bool>dp(n+1,0);

        dp[0]=true;

        for(int i=1;i<=n;i++){

            for(int j=0;j<i;j++){

                if(dp[j] && t.search(j,i-1,s)){

                    dp[i]=true;

                    break;
                }
            }
        }

        return dp[n];
    }
};