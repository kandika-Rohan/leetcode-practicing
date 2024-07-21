//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        // code here
        
        set<pair<int,int>>st;
        priority_queue<pair<int,pair<int,int>>>q;
        //{sum ,{row,col}};
        
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        
        q.push({A[0]+B[0],{0,0}});
        st.insert({0,0});
        
        vector<int>ans;
        for(int i=0;i<k;i++){
            auto node=q.top();
            q.pop();
            int sum=node.first;
            int row=node.second.first;
            int col=node.second.second;
            ans.push_back(sum);
            
            if(row+1 < n && col <n && st.find({row+1,col}) == st.end()){
                q.push({A[row+1]+B[col],{row+1,col}});
                st.insert({row+1,col});
            }
              if(col+1 < n && row <n && st.find({row,col+1}) == st.end()){
                q.push({A[row]+B[col+1],{row,col+1}});
                st.insert({row,col+1});
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
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends