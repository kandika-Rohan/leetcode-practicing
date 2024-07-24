//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
  long long countSubarraysWithSumLessThanOrEqual(vector<int>& arr, long long value) {
    long long count = 0;
    long long sum = 0;
    int start = 0;

    for (int end = 0; end < arr.size(); ++end) {
        sum += arr[end];

        while (sum > value) {
            sum -= arr[start++];
        }

        count += (end - start + 1);
    }

    return count;
}

long long countSubarray(int N, vector<int> A, long long L, long long R) {
    return countSubarraysWithSumLessThanOrEqual(A, R) - countSubarraysWithSumLessThanOrEqual(A, L - 1);
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends