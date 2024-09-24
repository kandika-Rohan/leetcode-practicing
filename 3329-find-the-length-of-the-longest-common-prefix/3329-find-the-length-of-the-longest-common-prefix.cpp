
class Trie{
    private:
    struct trie{
        trie*digits[10];

        trie(){
        fill(begin(digits),end(digits),nullptr);
        }
    };
    public:
    trie*root;

    Trie(){
        root=new trie();
    }

    void insert(int n){


        trie*node=root;
        string num=to_string(n);

        for(auto it:num){
            int val=it-'0';
            if(node->digits[val] == nullptr){
               node->digits[val]=new trie();
            }
            node=node->digits[val];
        }
    }

    int search(int n){

        trie*node=root;
        string num=to_string(n);
        int cnt=0;
        for(auto it:num){
            int val=it-'0';
            if(node->digits[val] == nullptr){
               break;
            }
            cnt++;
            node=node->digits[val];
        }

        return cnt;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(auto it:arr1){
            t.insert(it);
        }
        int maxi=0;
        for(auto it:arr2){
            maxi=max(maxi,t.search(it));
        }

        return maxi;
    }
};