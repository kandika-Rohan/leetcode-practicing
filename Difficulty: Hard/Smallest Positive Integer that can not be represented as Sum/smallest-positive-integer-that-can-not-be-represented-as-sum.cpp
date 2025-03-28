//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        // code here 
        sort(begin(array),end(array));
        
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(array[i]>ans+1){
                return ans+1;
            }
            ans+=array[i];
        }
        return ans+1;
    } 
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends