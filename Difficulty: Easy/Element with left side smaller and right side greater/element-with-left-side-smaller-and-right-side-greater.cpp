//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> leftGreater(vector<int>&arr){
        
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
    
    vector<int> rightSmaller(vector<int>&arr){
        
        int n=arr.size();
        
        vector<int>ans(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
        
    }
    int findElement(vector<int> &arr) {
        
        
        vector<int>left=leftGreater(arr);
        vector<int>right=rightSmaller(arr);
        
        for(int i=0;i<arr.size();i++){
            if(left[i] == -1 && right[i] == -1 && i != 0 && i != arr.size()-1){
                return arr[i];
            }
        }
        return -1;
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
        int ans = ob.findElement(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends