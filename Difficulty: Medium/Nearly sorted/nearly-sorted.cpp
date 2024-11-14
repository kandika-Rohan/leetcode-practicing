//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<k+1;i++){
            pq.push(arr[i]);
        }
        int j=0;
        
        for(int i=k+1;i<arr.size();i++){
            int val=pq.top();
            pq.pop();
            arr[j++]=val;
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            int val=pq.top();
            pq.pop();
            arr[j++]=val;
        }
        
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        obj.nearlySorted(arr, k);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends