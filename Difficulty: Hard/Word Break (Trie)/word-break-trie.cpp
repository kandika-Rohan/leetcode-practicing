//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Node{
    public:
    Node* children[26];
    bool isTerminal;
    Node()
    {
        for(int i=0;i<26;i++){
          this->children[i]=NULL;
        }
        
        this->isTerminal = false;
    }
};

class Trie{
    private:
    Node* root;
    public:
    Trie()
    {
        root=new Node();
    }
    
    void insert(string &str)
    {
        Node* curr = root;
        for(int i=0;i<str.size();i++)
        {
            int index = str[i]-'a';
            if(curr->children[index]==NULL)
            {
                curr->children[index] = new Node();
            }
            curr=curr->children[index];
        }
        curr->isTerminal = true;
    }
    
    bool solve(string str,int start)
    {
        if(start>=str.size())
        return true;
        Node* curr = root;
        bool ans = 0;
        for(int i=start;i<str.size();i++)
        {
            int index = str[i]-'a';
            if(curr->children[index]==NULL)
            return false;
            else{
                 curr=curr->children[index];
                 if(curr->isTerminal==true)
                 {
                   if(solve(str,i+1)==true)
                   return true;
                 }
            }
        }
        return false;
    }
    
};

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie trie;
        for(int i=0;i<B.size();i++)
        {
            trie.insert(B[i]);
        }
        
        return trie.solve(A,0);
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
    
cout << "~" << "\n";
}
}

// } Driver Code Ends