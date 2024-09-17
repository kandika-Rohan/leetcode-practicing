//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Trie{
    
    struct trie{
        trie*links[26];
        
        trie(){
        fill(begin(links),end(links),nullptr);
        }
    };
    
    
    
    public:
    
    trie*root;
    Trie(){
        root=new trie();
    }
    
    int insert(string word){
        trie*temp=root;
        int cnt=0;
        for(auto it:word){
            int ind=it-'a';
            if(temp->links[ind] == nullptr){
                temp->links[ind]=new trie();
                cnt++;
            }
            temp=temp->links[ind];
        }
        return cnt;
    }
    
};
int countDistinctSubstring(string s)
{
    
     Trie t;
    int cnt = 0;


    for (int i = 0; i < s.size(); i++) {
        string suffix = s.substr(i);  
        cnt += t.insert(suffix); 
    }
    return cnt + 1;
}