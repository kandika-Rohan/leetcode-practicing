//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    // class comp{
    //     public:
    //     bool operator()(pair<int,int>a,pair<int,int>b){
    //         return a.first > b.first;
    //     }
    // };
    
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second < b.second;
    }
    int maxMeetings(int n, int start[], int end[]) {
        
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({start[i],end[i]});
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        int cnt=1;
        int e=vec[0].second;
        
        for(int i=1;i<n;i++){
            if(vec[i].first > e){
                cnt++;
                e=vec[i].second;
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
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends