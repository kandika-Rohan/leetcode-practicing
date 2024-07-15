//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
         if (s > 9 * d) {
            return "-1";
        }
        
        string st ="";
        for(int i=d-1;i>=0;i--){
            
            for(int j=9;j>=0;j--){
                
                if(i != 0){
                    if(s - j > 0){
                        st += j +'0';
                        s = s-j;
                        break;
                    }
                }
                else{
                    st += s +'0';
                    break;
                }
            }
        }
        reverse(st.begin(),st.end());
        return st;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends