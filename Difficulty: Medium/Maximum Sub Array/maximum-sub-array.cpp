//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   vector<int> findSubarray(int n, int arr[]) {
    vector<int> ans;
    int sum = 0;
    int start = 0;
    int arrStart = 0;
    int arrEnd = 0;
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            sum = 0;
            start =i+1;
         }  
         else
        sum += arr[i];
        if(sum> maxi && start!=i){
            maxi = sum;
            arrStart=start;
            arrEnd = i;
        }
        
       
    }

    for(int i=arrStart;i<=arrEnd;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}

};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends