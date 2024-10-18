//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

#include <string>
using namespace std;

class Solution {
public:
    string roundToNearest(string str) {
        int n = str.size();
        
       
        if (n == 1) {
            
            if(str[0]-'0'>5){
                return "10";
            }
            else{
                return str;
            }
        }
        
        int ones = str[n - 1] - '0'; 
        int tens = str[n - 2] - '0'; 
        
        string ans = ""; 

        if (ones <= 5) {
            for (int i = 0; i < n - 1; i++) {
                ans += str[i];
            }
            ans += "0"; 
        } else {
            int carry = 1; 
            for (int i = n - 2; i >= 0; i--) {
                int v = str[i] - '0' + carry; 
                ans = to_string(v % 10) + ans; 
                carry = v / 10; 
            }
            if (carry > 0) {
                ans = to_string(carry) + ans; 
            }
            ans += "0"; 
        }
        
        return ans; 
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends