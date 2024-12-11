//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
        int lower=-1,upper=-1;
        
        lower=lower_bound(begin(arr),end(arr),target)-arr.begin();
        
        upper=upper_bound(begin(arr),end(arr),target)-arr.begin();
        
        if(lower != -1 && upper != -1){
            return upper-lower;
        }
        if(lower != -1 && upper == -1){
            return 1;
        }
        else if(upper != -1 && lower == -1){
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends