//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
        int getCount (string S, int N)
        {
            //code here.
            char curr=' ';
            
            vector<int>hash(26,0);
            
            for(int i=0;i<S.size();i++){
                if(S[i] != curr){
                    hash[S[i]-'a']++;
                    curr=S[i];
                }
            }
            
            int cnt=0;
            
            
            for(auto it:hash){
                if(it == N){
                    cnt++;
                }
            }
            
            return cnt;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n; cin >> n;
        
        Solution ob;
        cout <<ob.getCount (s, n) << endl;
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends