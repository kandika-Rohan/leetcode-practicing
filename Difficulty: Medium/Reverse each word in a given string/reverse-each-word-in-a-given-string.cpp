//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //code here.
        string temp="";
        vector<string>a;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i] == '.'){
                if(!temp.empty()){
                    a.push_back(temp+".");
                    temp="";
                }
                else if(temp.empty()){
                    a.push_back(".");
                }
            }
            else{
                temp=s[i]+temp;
            }
        }
        if(!temp.empty()){
            a.push_back(temp);
        }
        string ans="";
        for(auto it:a){
            ans+=it;
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
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends