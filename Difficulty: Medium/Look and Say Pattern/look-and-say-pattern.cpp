//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        
    if (n == 1) return "1";
    
    if (n == 2) return "11";

    string prev = lookandsay(n - 1);
    
    string res = "";

    int i = 0;
    
    while (i < prev.size()) {
        
        int cnt = 1;
        
        while (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
            
            cnt++;
            
            i++;
        }
        
        res += to_string(cnt) + prev[i];
        
        i++; 
    }

    return res;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends