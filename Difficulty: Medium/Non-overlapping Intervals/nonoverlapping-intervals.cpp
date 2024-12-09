//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        
        sort(begin(intervals),end(intervals));
        
        int curr_end=intervals[0][1];
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s<curr_end){
                curr_end=min(curr_end,e);
                cnt++;
            }
            else{
                curr_end=e;
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends