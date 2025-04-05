//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of substrings that start and end with 1.
    long binarySubstring(int n, string a){
        
        // Your code here
        vector<int>ans(n,0);
        int count=0;
        for(int i=n-1;i>=0;i--){
            
            if(a[i] == '1'){
                
                ans[i]=count;
                count++;
            }
            
        }
        
        
        long long total=accumulate(begin(ans),end(ans),0);
        
        return total;
    }

};


//{ Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        Solution obj;
        cout << obj.binarySubstring(n, a) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends