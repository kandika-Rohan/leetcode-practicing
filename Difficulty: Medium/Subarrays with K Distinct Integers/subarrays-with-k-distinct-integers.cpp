//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(vector<int>& arr ,int n,int k){
        
        int i = 0, j = 0,res=0;
        unordered_map<int, int> mp;
        while (j<n) {
            mp[arr[j]]++;
            while (mp.size()>k) {
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
        
    }
    int subarrayCount(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        return solve(arr,n,k)-solve(arr,n,k-1);
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
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.subarrayCount(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends