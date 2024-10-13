//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int maxi=INT_MIN;
	    int max_u=0;
	    for(int i=0;i<s.size();i++){
	        
	        int x=s[i]== '0'?1:-1;
	        
	        max_u+=x;
	        if(maxi<max_u)maxi=max_u;
	        if(max_u<0)max_u=0;
	    }
	    return maxi;
	    
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends