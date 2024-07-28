//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
   
   
    bool ispossible(int mid,int k,vector<int>&stalls){
        int cowcount=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-last>=mid){
                cowcount+=1;
                last=stalls[i];
            }
        }
        if(cowcount>=k){
            return true;
        }
        else{
            return false;
        }
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int l=1;
        int r=stalls[n-1];
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispossible(mid,k,stalls)==true){
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
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends