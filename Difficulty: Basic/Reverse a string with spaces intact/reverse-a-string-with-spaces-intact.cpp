//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
  
        string reverseWithSpacesIntact (string s)
        {
            //code here.
            vector<int>spaces;
            int j=0;
            string ans="";
            for(auto it:s){
                
                if(it == ' '){
                    spaces.push_back(j);
                }
                else{
                    ans+=it;
                }
                j++;
            }
            
            reverse(ans.begin(),ans.end());
            
            int k=0;
            j=0;
            string res="";
            int m=0;
            for(int i=0;i<s.size();i++){
                
                if(k<spaces.size() && i == spaces[k]){
                    res+=" ";
                    k++;
                }
                else{
                    if(m<ans.size()){
                    res+=ans[m];
                    m++;
                    }
                }
            }
            
            return res;
        }
      

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    cin.ignore ();
    while (t--)
    {
        string s;
        getline (cin, s);
        Solution ob;
        cout << ob.reverseWithSpacesIntact (s) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// Contributed By: Pranay Bansal

// } Driver Code Ends