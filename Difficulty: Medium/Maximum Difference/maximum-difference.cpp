//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> leftsmaller(int n, vector<int>& arr) {
        vector<int> ans(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = arr[st.top()];
            } else {
                ans[i] = 0;  // If no smaller element to the left, use 0
            }
            st.push(i);
        }
        return ans;
    }
    
    vector<int> rightsmaller(int n, vector<int>& arr) {
        vector<int> ans(n, n);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = arr[st.top()];
            } else {
                ans[i] = 0;  // If no smaller element to the right, use n
            }
            st.push(i);
        }
        return ans;
    }
    
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> left = leftsmaller(n, arr);
        vector<int> right = rightsmaller(n, arr);
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int val1 = left[i] == 0 ? 0 : left[i];
            int val2 = right[i] == 0 ? 0 : right[i];
            int diff = abs(val1 - val2);
            maxi = max(maxi, diff);
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends