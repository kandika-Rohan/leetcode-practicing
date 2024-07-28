//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    bool ispossible(long long int mid, int n, int arr[], int m) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                cnt++;
                if(cnt>m || arr[i]>mid){
                    return false;
                }
                sum=arr[i];
            }
        }
        return cnt <= m; 
    }
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1; 


        
        
    long long int totalsum = accumulate(arr, arr + n, 0);
        
       
      long long int l = *max_element(arr, arr + n);
       
       long long int r = totalsum;
       
        long long int ans = -1;
        while (l <= r) {
           long long int mid = l + (r - l) / 2;
            if (ispossible(mid, n, arr, m)) {
                ans = mid;
                r=mid-1;
            } else {
                l= mid + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends