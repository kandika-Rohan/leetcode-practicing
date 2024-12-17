//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool ispossible(vector<int>&stalls,int mid,int k,int n){
      int cnt=1;
      int last=stalls[0];
      
      for(int i=1;i<stalls.size();i++){
          if(stalls[i]-last >= mid){
              cnt++;
              last=stalls[i];
          }
      }
      if(cnt>=k){
          return true;
      }
      else{
         return false;
      }
  }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        
        sort(begin(stalls),end(stalls));
        
        int n=stalls.size();
        
        
        int l=0;
        int r=stalls[n-1];
        int ans=-1;
        
        while(l<=r){
            
            int mid=(l+r)/2;
            
            if(ispossible(stalls,mid,k,n)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends