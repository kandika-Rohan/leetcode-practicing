//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int,int>map;
        int len=0;
        int count=0;
        for(int i=0;i<N;i++){
            
            count+=(arr[i] == 1)?1:-1;
            
            if(count == 0){
                len=i+1;
            }
            
            if(map.find(count) != map.end()){
                len=max(len,i-map[count]);
            }
            else{
                map[count]=i;
            }
        }
        
        return len;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends