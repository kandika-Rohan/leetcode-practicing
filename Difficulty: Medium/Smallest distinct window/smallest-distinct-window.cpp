//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int>map;
        for(auto it:str){
            map[it]++;
        }
        int k=map.size();
        int maxi=INT_MAX;
        int i=0;
        unordered_map<char,int>m;
        for(int j=0;j<str.length();j++){
            m[str[j]]++;
            
            while(m.size()>=k && i<=j){
                maxi=min(maxi,j-i+1);
                m[str[i]]--;
                if(m[str[i]] == 0){
                    m.erase(str[i]);
                }
                i++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends