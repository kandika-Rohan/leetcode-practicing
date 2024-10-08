//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void toposort(int node,vector<int>&vis,vector<int>adj[],stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                toposort(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        
        
        
        vector<int>adj[K];
     
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int n=s1.size();
            int m=s2.size();
            for(int j=0;j<min(n,m);j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        stack<int>st;
        
        vector<int>vis(K,0);
        for(int i=0;i<K;i++){
            if(!vis[i]){
                toposort(i,vis,adj,st);
            }
        }
        string ans="";
        while(!st.empty()){
            int it=st.top();
            st.pop();
            ans+=it+'a';
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends