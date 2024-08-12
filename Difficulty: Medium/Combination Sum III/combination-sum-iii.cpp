//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void f(int i, int n, int k, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    // Base case: if n is 0, check if the size of the current combination (ds) is k
    if (n == 0) {
        if (ds.size() == k) {
            ans.push_back(ds); // Add the current combination to the answer
        }
        return;
    }

    // If we reach the end of the array, return
    if (i >= arr.size()) {
        return;
    }

    // Include the current element if it is less than or equal to n
    if (arr[i] <= n) {
        ds.push_back(arr[i]); // Include the element
        f(i + 1, n - arr[i], k, arr, ds, ans); // Recur for the next element with reduced sum
        ds.pop_back(); // Backtrack and remove the element
    }

    // Exclude the current element and recur for the next element
    f(i + 1, n, k, arr, ds, ans);
}

vector<vector<int>> combinationSum(int K, int N) {
    // Initialize the array with values 1 to 9
    vector<int> val(9, 0);
    for (int i = 1; i <= 9; i++) {
        val[i - 1] = i;
    }

    vector<vector<int>> ans; // Vector to store the result
    vector<int> ds; // Temporary vector to store the current combination
    f(0, N, K, val, ds, ans); // Call the recursive function
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends