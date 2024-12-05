//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
static bool comp(pair<int, int>& a, pair<int, int>& b) {
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int, int>> v;
    
    for (int i = 0; i < val.size(); i++) {
        v.push_back({val[i], wt[i]});
    }
    
    sort(begin(v), end(v), comp);
    
    int n = v.size();
    int i = 0;
    double ans = 0.0;
    while (i < n && capacity > 0) {
        int val1 = v[i].first;
        int wt1 = v[i].second;
        
        if (wt1 <= capacity) {
            ans += val1;
            capacity -= wt1;
        } else {
            ans += (double)val1 * capacity / wt1;
            capacity = 0;
        }
        i++;
    }
    
    return ans;
}

};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends