//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
         vector<int> ans(N, 1);

    // First pass: from left to right
    for (int i = 1; i < N; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            ans[i] = ans[i - 1] + 1;
        }
    }

    // Second pass: from right to left
    for (int i = N - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            ans[i] = max(ans[i], ans[i + 1] + 1);
        }
    }

   
    int res = accumulate(ans.begin(), ans.end(), 0);
    return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends