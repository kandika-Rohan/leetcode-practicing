//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int>hash(26,0);
        int count=0;
        for(auto it:str){
            if(isalpha(it)){
                count++;
                hash[it-'a']=1;
            }
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(hash[i] == 0){
                c++;
            }
        }
        return c<=k && count>=26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends