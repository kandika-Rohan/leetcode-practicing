//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.second == b.second){
            return a.first<b.first;
        }
        else{
            return a.first<b.first;
        }
    }
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        vector<pair<int,int>>v;
        
        for(auto it:arr){
            v.push_back({it[0],it[1]});
        }
        
        sort(begin(v),end(v),comp);
        
        int start=v[0].first;
        int end=v[0].second;
        
        for(int i=1;i<v.size();i++){
            int s=v[i].first;
            int e=v[i].second;
            if(s<end){
                return false;
            }
            end=max(end,e);
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends