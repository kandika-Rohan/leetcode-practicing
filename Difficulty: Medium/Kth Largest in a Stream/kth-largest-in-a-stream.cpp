//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        
        priority_queue<int,vector<int>,greater<int>>q;
        
        vector<int>ans(n,-1);
        
        for(int i=0;i<n;i++){
            
            q.push(arr[i]);
            
            if(q.size()>k){
                q.pop();
            }
            
            if(q.size() == k){
                ans[i]=q.top();
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends