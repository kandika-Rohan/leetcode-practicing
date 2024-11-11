//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        // Code here
        
        int ans=0;
        
        map<int,int> mp;
        
        for(auto it:arr) mp[it]++;
        
        for(auto it:mp){
            int num=it.first;int freq=it.second;
            if(freq==1){
                continue;
            }
            int cnt=freq-1;
            
            int val=num+1;
            while(cnt--){
                while(mp[val]>0) val++;
                mp[val]++;
                ans+=(val++)-num;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends