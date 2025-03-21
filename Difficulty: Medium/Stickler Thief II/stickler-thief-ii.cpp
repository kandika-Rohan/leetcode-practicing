//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {   
public:     
    int solve(vector<int>& arr, int i, vector<int>& dp) {                  
        if (i < 0) {  // Mistake: `i <= 0` should be `i < 0` because when `i == 0`, we can take `arr[0]`.
            return 0;  
        }  
        if (dp[i] != -1) {  
            return dp[i];  
        }  
        int nottake = solve(arr, i - 1, dp); // `+0` is unnecessary  
        int take = arr[i] + (i > 1 ? solve(arr, i - 2, dp) : 0); // Mistake: Avoid `i-2` going negative  

        return dp[i] = max(take, nottake);  
    }  

    int maxValue(vector<int>& arr) {          
        if (arr.size() == 1) return arr[0]; // Mistake: Single element case should be handled explicitly  

        vector<int> arr1, arr2;  
        for (int i = 1; i < arr.size(); i++) {  
            arr1.push_back(arr[i]);  
        }  
        for (int i = 0; i < arr.size() - 1; i++) {  
            arr2.push_back(arr[i]);  
        }  

        vector<int> dp(arr1.size(), -1);  
        int v1 = solve(arr1, arr1.size() - 1, dp);  

        fill(begin(dp), end(dp), -1);  
        int v2 = solve(arr2, arr2.size() - 1, dp);  

        return max(v2, v1);  
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
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends