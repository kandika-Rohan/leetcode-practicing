//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

double findSmallestMaxDist(vector<int>& stations, int k) {
    // Max heap to store the segments
    priority_queue<pair<double,int>> pq;

   
    for (int i = 0; i < stations.size() - 1; i++) {
        double val = static_cast<double>(stations[i + 1] - stations[i]);
        pq.push({val,i});
    }
    
    vector<int>countGs(stations.size()-1,0);

    for (int i = 0; i < k; i++) {
       auto it=pq.top();
       pq.pop();
       int ind=it.second;
       countGs[ind]++;
       double inidiff=stations[ind+1]-stations[ind];
       double newval=inidiff/(double)(countGs[ind]+1);
       pq.push({newval,ind});
    }

    
    return pq.top().first+1e-4;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends