//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>map;
        
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        
        using p=pair<int,string>;
        
        priority_queue<p>maxheap;
        
        for(auto it:map){
            maxheap.push({it.second,it.first});
        }
        string a="";
        if(!maxheap.empty()){
            auto it=maxheap.top();
            maxheap.pop();
            a=it.second;
        }
        
        if(maxheap.empty()){
            return "";
        }
        auto it=maxheap.top();
        maxheap.pop();
        return it.second;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends