//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <iostream>

class Solution {
  public:
    int rotateDelete(std::vector<int>& arr) {
        int n = arr.size(); 
        int k = 1; 

        while (n > 1) {

            arr.insert(arr.begin(), arr[n - 1]); 
            arr.pop_back();

      

            int deleteIndex = n - k;
            if (deleteIndex < 0) deleteIndex = 0;


            arr.erase(arr.begin() + deleteIndex);

            
            ++k;
            --n;
        }

        return arr[0];
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends