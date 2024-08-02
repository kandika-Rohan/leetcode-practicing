//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
    int n = s.size();
    if (n == 0) {
        return 0;
    }
    
    int sign = 1;
    int start = 0;
    
    if (s[0] == '-') {
        sign = -1;
        start = 1;
    } else if (!isdigit(s[0])) {
        return -1;
    }

    int num = 0;
    for (int i = start; i < n; i++) {
        if (!isdigit(s[i])) {
            return -1;
        }
        num = num * 10 + (s[i] - '0');
    }

    return sign * num;
}

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends