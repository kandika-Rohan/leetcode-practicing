//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(int n,string m,char last,vector<string>&ans){
        if(m.size()==n){
            ans.push_back(m);
            return;
        }
        solve(n,m+'0','0',ans);
        if(last != '1'){
            solve(n,m+'1','1',ans);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        string m="";
        solve(num,m,'0',ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends