//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,string digits,vector<int>&dp){
        
        if(i >= digits.size()){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        string temp="";
        int count=0;
        for(int j=i;j<digits.size();j++){
            temp+=digits[j];
            if(temp.size()>=1 && temp.size()<=2 && temp[0] != '0'){
                
                int val=std::stoi(temp);
                
                if(val>=1 && val<=26){
                    count+=0+f(j+1,digits,dp);
                }
            }
            else{
                break;
            }
        }
        return dp[i]=count;
    }
    int countWays(string &digits) {
        // Code here
        vector<int>dp(digits.size(),-1);
        return f(0,digits,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends