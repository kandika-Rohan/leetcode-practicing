//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        string str1=arr[0];
        string str2=arr[n-1];
        
        int m=min(str1.size(),str2.size());
        string ans="";
        for(int i=0;i<m;i++){
            if(str1[i] != str2[i]){
                break;
            }
            ans+=str1[i];
        }
        
        return ans ==""?"-1":ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends