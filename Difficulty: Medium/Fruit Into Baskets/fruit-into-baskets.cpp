//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        
        unordered_map<int,int>map;
        
        int i=0;
        
        int cnt=0;
        //this is for counting the different types of the fruits
        
        for(int j=0;j<arr.size();j++){
            
            map[arr[j]]++;
            
            if(map.size()>2){
                
                map[arr[i]]--;
                
                if(map[arr[i]] == 0){
                    map.erase(arr[i]);
                }
                
                i++;
            }
            
            cnt=max(cnt,j-i+1);
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends