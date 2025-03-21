//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        sort(begin(arr),end(arr));
        
        int res=0;
        
        int minDiff=INT_MAX;
        
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            
            while(l<r){
                
                int currSum=arr[i]+arr[l]+arr[r];
                
                if(abs(currSum-target)<minDiff){
                    minDiff=abs(currSum-target);
                    res=currSum;
                }
                
                else if(abs(currSum-target) == minDiff){
                    res=max(res,currSum);
                }
                if(currSum>target){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return res;
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
        getline(cin, input);
        int target = stoi(input);

        Solution obj;
        cout << obj.closest3Sum(arr, target) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends