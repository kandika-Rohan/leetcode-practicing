//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:


std::string reverse(std::string str) { 
    std::vector<int> hash;
    std::string ans = "";
    
    for (int i = 0; i < str.size(); i++) {
        if (!isalpha(str[i])) {
            hash.push_back(i);
        } else {
            ans += str[i];
        }
    }
    
    std::reverse(ans.begin(), ans.end());
    
    std::string res = "";
    int k = 0, j = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (k < hash.size() && hash[k] == i) {  // Ensure k is within bounds
            res += str[i];
            k++;
        } else {
            res += ans[j];
            j++;
        }
    }
    
    return res;
}

};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends