//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int isPowerOfAnother(long long X, long long Y){
        // code here 
        
        if (Y == 1 || Y == X) return 1;
        
        if (X == 1) return 0;
        
        double ans = log(Y) / log(X);
        
        return ans == floor(log(Y) / log(X));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long int X, Y;
        cin >> X >> Y;
        Solution ob;
        cout << ob.isPowerOfAnother(X,Y) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends