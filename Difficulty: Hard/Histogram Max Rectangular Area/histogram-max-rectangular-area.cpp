//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <stack>
#include <climits>

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
   vector<long long> leftsmaller(long long arr[], int n) {
    vector<long long> ans(n, -1);
    stack<long long> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<long long> rightsmaller(long long arr[], int n) {
    vector<long long> ans(n, n);
    stack<long long> st;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        if (!st.empty()) {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

long long getMaxArea(long long arr[], int n) {
    vector<long long> left = leftsmaller(arr, n);
    vector<long long> right = rightsmaller(arr, n);
    
    long long maxi = LLONG_MIN; 
    
    for (int i = 0; i < n; i++) {
        long long length = right[i] - left[i] - 1;
        long long breadth = arr[i];
        
        maxi = max(maxi, length * breadth);
    }
    return maxi;
}
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends