//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    static bool comp(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }
    string findLargest(vector<int> &arr) {
        // code here
        
        string ans="";
        
        sort(begin(arr),end(arr),comp);
        
        for(auto it:arr){
            ans+=to_string(it);
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i] > '0'){
                return ans.substr(i);
            }
        }
        return "0";
        
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.findLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends