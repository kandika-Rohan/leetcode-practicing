//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   void dfs(int node, int vis[], vector<int>adj[]) {
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                dfs(it,vis,adj);
            }
        } 
    }
    int isCircle(vector<string> &A) {
        // code here
         vector<int>adj[26];
        int vis[26] = {0};
        int ind;
        for(auto it: A) {
            int first = it[0]-'a';
            int second = it[it.size()-1]-'a';
            adj[first].push_back(second);
            adj[second].push_back(first);
            ind = first;
        }
        
        dfs(ind,vis,adj);
        for(int i=0;i<26;i++) {
            if(!vis[i] && adj[i].size()>0) return 0;
            if(adj[i].size()%2==1) return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends