//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void ans(vector<int>& nums, int s, int e, vector<int>& ds) {
    if (s > e) {
        return;
    }
    int mid = s + (e - s) / 2;
    ds.push_back(nums[mid]);
    ans(nums, s, mid - 1, ds);
    ans(nums, mid + 1, e, ds);
}

vector<int> sortedArrayToBST(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;
    vector<int> ds;
    ans(nums, i, j, ds);
    return ds; 
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.sortedArrayToBST(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends