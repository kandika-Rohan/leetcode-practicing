//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        else{
            return a.first>b.first;
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        
         sort(v.begin(),v.end(),comp);
         
         vector<int>ans;
         for(auto it:v){
             int size=it.first;
             int val=it.second;
             while(size!=0){
                 ans.push_back(val);
                 size--;
             }
         }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends