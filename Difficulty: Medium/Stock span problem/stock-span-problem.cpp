//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>leftLarget(vector<int>&arr){
        
        int n=arr.size();
        
        vector<int>ans(n,-1);
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
         
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        
        return ans;
    }
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        
        vector<int>ans=leftLarget(arr);
        vector<int>res(arr.size(),1);

        
        for(int i=0;i<ans.size();i++){
            
            res[i]=i-ans[i];
        }
        return res;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends