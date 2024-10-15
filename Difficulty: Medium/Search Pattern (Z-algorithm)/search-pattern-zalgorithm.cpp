//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int>lp(string s){
            int n=s.size();
            
            vector<int>lps(n,0);
            
            int i=1;
            
            int len=0;
            
            while(i<n){
                
                if(s[i] == s[len]){
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
        vector <int> search(string pat, string txt)
        {
            //code hee.
            
            vector<int>lps=lp(pat);
            
            int i=0;
            int j=0;
            int n=txt.size();
            int m=pat.size();
            vector<int>ans;
            while(i<n){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                
                if(j == m){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(txt[i] != pat[j]){
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends