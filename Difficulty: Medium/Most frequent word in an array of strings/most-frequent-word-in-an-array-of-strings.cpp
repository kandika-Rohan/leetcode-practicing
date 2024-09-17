//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++


class Trie{
    private:
    struct trie{
        trie*links[26];
        int countWords;
        bool endOfWord;
        
        trie(){
            fill(begin(links),end(links),nullptr);
            countWords=0;
            endOfWord=false;
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
        }
        
        if(node->endOfWord == true){
            //already we have come through that word
            node->countWords=node->countWords+1;
        }
        else{//first time we are seeing
            node->endOfWord=true;
            node->countWords=1;
        }
    }
    
    int occurances(string word){
        
        trie*node=root;
        
        for(auto it:word){
            int ind=it-'a';
            if(node->links[ind] == nullptr){
                return 0;
            }
            node=node->links[ind];
        }
        
        if(node->endOfWord == true){
            return node->countWords;
        }
        
        else{
            return 0;
        }
    }
};

class Solution
{
    public:
  
    string mostFrequentWord(string arr[], int n) 
    {
        Trie t;
        unordered_map<string,int>map;
        for(int i=0;i<n;i++){
            t.insert(arr[i]);
            if(map.find(arr[i]) == map.end()){
                map[arr[i]]=i;
            }
        }
        
        int maxi=0;
        
        string ans;
       
        for(int i=0;i<n;i++){
            
            int cnt=t.occurances(arr[i]);
            
            if(cnt > maxi || (cnt == maxi && 
            map[arr[i]] > map[ans])) {
                maxi = cnt;
                ans = arr[i];
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends