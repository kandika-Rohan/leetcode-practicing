//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<start.size();i++){
            v.push_back({start[i],finish[i]});
        }
        
        sort(begin(v),end(v),[&](pair<int,int>&a,pair<int,int>&b){
            
            if(a.second == b.second){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        
        
        int count=1;
        
        int e=v[0].second;
        
        for(int i=1;i<v.size();i++){
            
            int s=v[i].first;
            
            if(s>e){
                count++;
                e=max(e,v[i].second);
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends