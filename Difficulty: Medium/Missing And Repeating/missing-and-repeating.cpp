//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        vector<int>hash(arr.size()+1,0);
        
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]++;
        }
        int mis=-1;
        int rep=-1;
        for(int i=1;i<=arr.size();i++){
            if(hash[i]==0){
                mis=i;
            }
            if(hash[i] == 2){
                rep=i;
            }
        }
        
        return {rep,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends