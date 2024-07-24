//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string s,int ind,vector<string>&ans){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        for(int i=ind;i<s.size();i++){
            swap(s[i],s[ind]);
            solve(s,ind+1,ans);
            swap(s[i],s[ind]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>ds;
        solve(S,0,ds);
        sort(ds.begin(),ds.end());
        return ds;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends