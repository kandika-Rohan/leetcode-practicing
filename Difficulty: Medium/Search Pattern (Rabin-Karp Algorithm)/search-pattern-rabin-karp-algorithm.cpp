//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int>kmp(string p){
            
            int n=p.size();
            
            vector<int>lps(n,0);
            
            int i=1;
            int len=0;
            
            while(i<n){
                
                if(p[i] == p[len]){
                    
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    
                    if(len != 0){
                        len=lps[len-1];
                    }
                    else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
            
            return lps;
        }
        vector <int> search(string pattern, string text)
        {
            vector<int>lps=kmp(pattern);
            
            int i=0;
            int j=0;
            int n=text.size();
            
            vector<int>ans;
            
            while(i<n){
                
                if(pattern[j] == text[i]){
                    i++;
                    j++;
                }
                
                if(j == pattern.size()){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n && pattern[j] != text[i]){
                    
                    if(j != 0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends