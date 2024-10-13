//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:    
    bool sameFreq(string s) {
        vector<int> hash(26, 0);


        for (auto it : s) {
            hash[it - 'a']++;
        }


        int val = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                val = hash[i];
                break;
            }
        }


        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0 && hash[i] != val) {
                flag = false;
                break;
            }
        }

        if (flag) {
            return true;
        }

       
        for (int i = 0; i < s.size(); i++) {
            
            hash[s[i] - 'a']--;

            int xr = -1; 
            
            bool f = true;


            for (auto it : hash) {
                if (it > 0) {
                    if (xr == -1) {
                        xr = it;
                    } else if (it != xr) {
                        f = false;
                        break;
                    }
                }
            }

            if (f) return true;

       
            hash[s[i] - 'a']++;
        }

        return false;
    }
};


//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends