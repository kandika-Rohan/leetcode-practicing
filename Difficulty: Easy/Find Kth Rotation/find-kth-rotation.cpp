//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int mini=INT_MAX;
        int ind=-1;
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            
            if(arr[l]<=arr[r]){
                if(arr[l]<mini){
                    mini=arr[l];
                    ind=l;
                }
                break;
            }
            int mid=(l+r)/2;
            if(arr[mid]>=arr[l]){
                if(arr[l]<mini){
                    mini=arr[l];
                    ind=l;
                }
                l=mid+1;
            }
            else{
                if(arr[mid]<mini){
                    mini=arr[mid];
                    ind=mid;
                }
                r=mid-1;
            }
        }
        return ind;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
// } Driver Code Ends