//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int i=0;
        int minlen=INT_MAX;
        vector<int>hash(256,0);
        int n=s.size();int m=p.size();
        int start=-1;
        
        for(auto it:p){
            hash[it]++;
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            if(hash[s[j]]>0){
                cnt++;
            }
            hash[s[j]]--;
            while(cnt == m){
                if(minlen > j-i+1){
                    minlen=j-i+1;
                    start=i;
                }
                hash[s[i]]++;
                if(hash[s[i]] > 0){
                    cnt--;
                }
                i++;
            }
        }
        if(start == -1)return "-1";
        return s.substr(start,minlen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends