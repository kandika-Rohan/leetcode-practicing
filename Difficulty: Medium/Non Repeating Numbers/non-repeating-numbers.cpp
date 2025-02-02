//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> singleNumber(vector<int>& arr) {
        // Code here.
        
        int xr=0;
        
        for(auto it:arr)xr^=it;
        
        int num=xr&-xr;
        
        int val1=0,val2=0;
        
        for(auto it:arr){
            
            if(num & it){
                val1=val1^it;
            }
            else{
                val2^=it;
            }
        }
        
        if(val1<val2){
            return {val1,val2};
        }
        else if(val1>val2){
            return {val2,val1};
        }
        
        return {};
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

        Solution ob;
        vector<int> ans = ob.singleNumber(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends