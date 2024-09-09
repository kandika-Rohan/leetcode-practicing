//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    
	    vector<int>pat1(26,0),txt1(26,0);
	    
	    int m=pat.size();
	    int n=txt.size();
	    
	    for(auto it:pat){
	        pat1[it-'a']++;
	    }
	    int i=0;
	    int cnt=0;
	    for(int j=0;j<n;j++){
	        txt1[txt[j]-'a']++;
	        
	        while((j-i+1)>m){
	            txt1[txt[i]-'a']--;
	            i++;
	        }
	        
	        if(pat1 == txt1){
	            cnt++;
	        }
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends