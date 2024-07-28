//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool ispossible(int mid,vector<int>&nums,int K){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
            if(sum > K){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int K) {
        int l=1;
        int ans=-1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid=(l+r)/2;
            if(ispossible(mid,nums,K)==true){
                r=mid-1;
                ans=mid;
            }
            else{
                 l=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends