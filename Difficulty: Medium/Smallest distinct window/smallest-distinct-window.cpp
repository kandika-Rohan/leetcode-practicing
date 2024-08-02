//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
   int findSubString(string str) {
    // Step 1: Count all unique characters in the input string
    unordered_set<char> uniqueChars(str.begin(), str.end());
    int uniqueCount = uniqueChars.size();

    // Step 2: Use a sliding window to find the smallest substring containing all unique characters
    unordered_map<char, int> windowCharCount;
    int i = 0;
    int minLength = INT_MAX;

    for (int j = 0; j < str.size(); j++) {
        windowCharCount[str[j]]++;
        
        // Check if the current window contains all unique characters
        while (windowCharCount.size() == uniqueCount) {
            // Update minimum length
            minLength = min(minLength, j - i + 1);
            
            // Slide the window to the right
            windowCharCount[str[i]]--;
            if (windowCharCount[str[i]] == 0) {
                windowCharCount.erase(str[i]);
            }
            i++;
        }
    }

    return minLength;
}

};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends