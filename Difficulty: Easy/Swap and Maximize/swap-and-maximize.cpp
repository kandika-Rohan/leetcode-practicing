//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long ans=0;
        int l=0;
        int r=n-1;
        vector<int>v;
        while(l<=r){
        
            if(l == r){
                v.push_back(arr[l]);
            }
            else{
                v.push_back(arr[l]);
                v.push_back(arr[r]);
            }
            l++;
            r--;
        }
        
        for(int i=1;i<n;i++){
            ans+=abs(v[i]-v[i-1]);
        }
        return ans+abs(v[0]-v[n-1]);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends