//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class TRIE {
private:
    struct trie {
        trie *links[2];

        trie() {
            fill(begin(links), end(links), nullptr);
        }
    };

public:
    trie *root;

    TRIE() {
        root = new trie();
    }

    void insert(int num) {
        trie *node = root;

        for (int i = 31; i >= 0; i--) {
            int val = (num >> i) & 1;

            if (node->links[val] == nullptr) {
                node->links[val] = new trie();
            }
            node = node->links[val];
        }
    }

    int maximum_xr_value(int num) {
        trie *node = root;
        int maxi = 0;

        for (int i = 31; i >= 0; i--) {
            int val = (num >> i) & 1;
            int req = !val;

            if (node->links[req]) {
                maxi |= (1 << i);
                node = node->links[req];
            } else {
                node = node->links[val];
            }
        }
        return maxi;
    }
};


class Solution {
  public:
    // comperator function for sorting;
    static bool comp(pair<int,pair<int,int>>&a,
    pair<int,pair<int,int>>&b){
        return a.second.second<b.second.second;
    }
    vector<long long> maximumXor(int N, int Q, vector<int> &arr,
                                 vector<vector<int>> &queries) {
     
        using p=pair<int,pair<int,int>>;
        sort(begin(arr),end(arr));
        vector<p>pq;
        
        for(int i=0;i<queries.size();i++){
            pq.push_back({i,{queries[i][0],queries[i][1]}});
        }
        
        sort(begin(pq),end(pq),comp);
        
        int j=0;
        
        TRIE*t=new TRIE();
        int i=0;
        
        vector<long long>ans(queries.size());
        
        for(auto it:pq){
            
            int index=it.first;
            int xi=it.second.first;
            int mi=it.second.second;
            
            while(j<arr.size() && mi>=arr[j]){
                t->insert(arr[j]);
                j++;
            }
            
            if(j == 0){
                ans[index]=-1;
            }
            else{
                ans[index]=t->maximum_xr_value(xi);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, Q;
        cin >> N >> Q;
        vector<vector<int>> queries(Q, vector<int>(2));
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < Q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        Solution obj;
        vector<long long> ans = obj.maximumXor(N, Q, arr, queries);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends