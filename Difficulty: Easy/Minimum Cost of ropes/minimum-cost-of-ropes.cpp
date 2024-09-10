//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>>q;
        
        for(auto it:arr){
            q.push(it);
        }
        long long  totalcost=0;
        
        while(q.size()>1){
            
            
            long long first=q.top();
            q.pop();
            long long second=q.top();
            q.pop();
            int cost=first+second;
            
            q.push(cost);
            totalcost=totalcost+cost;
        }
        return totalcost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends