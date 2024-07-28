//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int mid,vector<int> &bloomDay,int K){
        int val=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                val++;
                if(val==K){
                    count++;
                    val=0;
                }
            }
            else{
                val=0;
            }
        }
        return count;
    }
    int solve(int M, int K, vector<int> &bloomDay){

      int ans=-1;
      int l=*min_element(bloomDay.begin(),bloomDay.end());
      int r=*max_element(bloomDay.begin(),bloomDay.end());
      while(l<=r){
          int mid=(l+r)/2;
          int val=f(mid,bloomDay,K);
          if(val>=M){
              r=mid-1;
              ans=mid;
          }
          else{
              l=mid+1;
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends