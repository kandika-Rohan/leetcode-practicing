//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
    if (arr.empty()) return 0; // Edge case: Empty array.

    sort(begin(arr), end(arr)); // Sort the array.
    
    int cnt = 1;       // Count of the current consecutive sequence.
    int maxi = 1;      // Maximum length of consecutive sequences found.

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            // Skip duplicates.
            continue;
        } else if (arr[i] == arr[i - 1] + 1) {
            // Current number continues the sequence.
            cnt++;
            maxi = max(maxi, cnt);
        } else {
            // Reset count as the sequence breaks.
            cnt = 1;
        }
    }

    return maxi;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends