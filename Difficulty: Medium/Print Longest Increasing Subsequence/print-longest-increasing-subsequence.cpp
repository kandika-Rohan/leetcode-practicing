//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   #include <vector>
#include <algorithm>

std::vector<int> longestIncreasingSubsequence(int n, std::vector<int>& arr) {
    // Initialize the dp array to store the length of LIS ending at each index
    std::vector<int> dp(n, 1);
    // Initialize the hash array to store the previous index in the LIS
    std::vector<int> hash(n, -1);

    // Calculate the length of LIS for each element
    for (int i = 1; i < n; i++) {
        for (int prev_ind = 0; prev_ind < i; prev_ind++) {
            if (arr[prev_ind] < arr[i] && dp[prev_ind] + 1 > dp[i]) {
                dp[i] = dp[prev_ind] + 1;
                hash[i] = prev_ind;
            }
        }
    }

    // Find the index of the maximum length LIS
    int largest = -1;
    int lastind = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > largest) {
            largest = dp[i];
            lastind = i;
        }
    }

    // Reconstruct the LIS
    std::vector<int> lis;
    while (lastind != -1) {
        lis.push_back(arr[lastind]);
        lastind = hash[lastind];
    }
    // Reverse the sequence to get the correct order
    std::reverse(lis.begin(), lis.end());

    return lis;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends