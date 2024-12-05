//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr[]: input array
    // Function to find the maximum index difference.
    int maxIndexDiff(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> leftMin(n), rightMax(n);

    // Fill leftMin array
    leftMin[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], arr[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        rightMax[j] = max(rightMax[j + 1], arr[j]);
    }

    // Find the maximum index difference
    int i = 0, j = 0, maxDiff = 0;
    while (i < n && j < n) {
        if (leftMin[i] <= rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++;
        } else {
            i++;
        }
    }

    return maxDiff;
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}
// } Driver Code Ends