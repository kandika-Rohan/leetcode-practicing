//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
    // Code here
    // sort(begin(arr), end(arr));
    
     
        // Code here
        int n = arr.size();
        
        unordered_map<int,int>mpp;
        
        for(int i=0;i<n;i++){
             mpp[arr[i]] = i;
        }
        
        set<vector<int>>st;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                int third = -(arr[i]+arr[j]);
                
                if(mpp.find(third)!=mpp.end() && mpp[third]!=i && mpp[third]!=j){
                    vector<int>temp = {i,j,mpp[third]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                
                mpp[arr[j]] = j;
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends