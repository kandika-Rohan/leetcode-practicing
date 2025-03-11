//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        
        int prev1=0;
        int prev2=0;
        
        int N=cost.size();
        
        for(int i=2;i<=N;i++){
            int left=prev1+cost[i-1];
            int right=INT_MAX;
            if(i>1){
                right=prev2+cost[i-2];
            }
            int curr=min(right,left);
            prev2=prev1;
            prev1=curr;
            
        }
        return prev1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends