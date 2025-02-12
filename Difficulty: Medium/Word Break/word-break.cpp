//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

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
    int wordBreak(int n, string s, vector<string> &wordDict) {
        

        TRIE t;
       
        

        for(auto it:wordDict){
            t.insert(it);
        }

       

        vector<bool>dp(s.size()+1,0);

        dp[0]=true;

        for(int i=1;i<=s.size();i++){

            for(int j=0;j<i;j++){

                if(dp[j] && t.search(j,i-1,s)){

                    dp[i]=true;

                    break;
                }
            }
        }

        return dp[s.size()];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends