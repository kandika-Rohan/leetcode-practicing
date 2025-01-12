//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:

    
    int maxWater(vector<int> &A) {
        // code here
    int n=A.size();
        
    int left=0;

    int right=n-1;

    int ans =0;

    while(left<right){

        int tempwater=min(A[left],A[right])*(right-left);

        ans=max(ans,tempwater);

        if(A[left]<A[right])left++;

        else{

            right--;

        }

    }
    return ans;


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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends