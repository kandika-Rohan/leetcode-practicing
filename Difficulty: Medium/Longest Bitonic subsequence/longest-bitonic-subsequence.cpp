//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
   int LongestBitonicSequence(int n, vector<int> &nums) {
    if (n == 0 || n == 1) {
        return 0; // A single element or no elements cannot form a bitonic sequence
    }

    // dp1[i] will store the length of the longest increasing subsequence ending at index i
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp1[i] < 1 + dp1[j]) {
                dp1[i] = 1 + dp1[j];
            }
        }
    }

    // dp2[i] will store the length of the longest decreasing subsequence starting at index i
    vector<int> dp2(n, 1);
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (nums[j] < nums[i] && dp2[i] < 1 + dp2[j]) {
                dp2[i] = 1 + dp2[j];
            }
        }

        // Only consider it bitonic if both parts are greater than 1
        if (dp1[i] > 1 && dp2[i] > 1) {
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }
    }
    return maxi;
}


};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends