//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> bitonicGenerator(vector<int>& arr) {
        // Your code goes here
        
        priority_queue<int,vector<int>,greater<int>>minheap;
        priority_queue<int>maxheap;
        
        for(int i=0;i<arr.size();i++){
            if(i&1){
                maxheap.push(arr[i]);
            }
            else{
                minheap.push(arr[i]);
            }
        }
        
        int n=arr.size();
        
        int k=0;
        
        while(!minheap.empty()&& k<n){
            
            arr[k]=minheap.top();
            
            minheap.pop();
            k++;
        }
        
         while(!maxheap.empty() && k<n){
           arr[k]=maxheap.top();
            maxheap.pop();
            k++;
        }
        
        return arr;
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
        vector<int> ans = obj.bitonicGenerator(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends