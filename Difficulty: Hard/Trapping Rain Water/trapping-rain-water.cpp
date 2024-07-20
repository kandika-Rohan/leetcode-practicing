//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    vector<int>leftmaxi(int arr[],int n){
        vector<int>ans(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            ans[i]=maxi;
            maxi=max(maxi,arr[i]);
        }
        return ans;
    }
    
     vector<int>rightmaxi(int arr[],int n){
        vector<int>ans(n);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=maxi;
            maxi=max(maxi,arr[i]);
        }
        return ans;
    }
    long long trappingWater(int arr[], int n){
        // code here
        
        vector<int>left=leftmaxi(arr,n);
        vector<int>right=rightmaxi(arr,n);
        long long  totalwater=0;
        for(int i=0;i<n;i++){
            int water=min(left[i],right[i]);
            if(water > arr [i]){
                totalwater+=water-arr[i];
            }
        }
        return totalwater;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends