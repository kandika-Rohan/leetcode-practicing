//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
       
        int start=-1;
        
        int c=0;
        
        for(int it=0;it<s.size();it++){
            if(s[it] == ch){
                c++;
            }
            
            if(c == count){
                start=it;
                break;
            }
        }
        
        if(start == -1 || start >= s.size()){
            return "";
        }
        
       return s.substr(start+1);
        
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
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends