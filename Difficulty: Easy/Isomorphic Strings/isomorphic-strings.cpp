//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        
      
        if(s.size()!=t.size()) return false;

        int size = s.size();

        vector<int>s1(256,0);
        vector<int>s2(256,0);

        for(int i=0; i<size;i++){

            if(s1[s[i]]!=s2[t[i]])
              return false;
            s1[s[i]] = i+1;
            s2[t[i]] = i+1;
        }

       
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends