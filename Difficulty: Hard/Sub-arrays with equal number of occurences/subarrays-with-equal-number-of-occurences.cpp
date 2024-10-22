//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        
        int xcount=0;
        int ycount=0;
        
        int i=0;
        
        int cnt=0;
        
        unordered_map<int,int>map;
        
        map[cnt]=1;
        
        for(int j=0;j<arr.size();j++){
            if(arr[j] == x){
                xcount++;
            }
            else if(arr[j] == y){
                ycount++;
            }
            int sum=xcount - ycount;
            
            if(map.find(sum) != map.end()){
                cnt+=map[sum];
            }
            map[sum]++;
        }
        
        return cnt ;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends