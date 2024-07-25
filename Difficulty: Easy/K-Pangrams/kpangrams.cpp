//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool kPangram(string str, int k) {
        vector<bool> arr(26, false);
        int total=0;
        for (char c : str) {
            if (isalpha(c)) {
                arr[tolower(c) - 'a'] = true;
                total++;
            }
        }
        if(total<26) return false;
        int count = 0;
        for (bool present : arr) {
            if (!present) count++;
        }
        return count <= k;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends