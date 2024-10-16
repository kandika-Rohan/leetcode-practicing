//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        unordered_map<int, int> map;
    
  
    for (int i = 0; i < arr.size(); i++) {
        map[arr[i]] = i;
    }
    
   
    vector<int> nums(arr.begin(), arr.end());
    sort(nums.begin(), nums.end());
    
    int cnt = 0;  
    for (int i = 0; i < arr.size(); i++) {
        
        while (arr[i] != nums[i]) {
         
            int correctIndex = map[nums[i]];
            
          
            map[arr[i]] = correctIndex;
            map[nums[i]] = i;
            
            
            swap(arr[i], arr[correctIndex]);
            
            cnt++; 
            if(cnt>2)return false;
        }
    }
  
    if(cnt == 2 || cnt == 0){
        return true;
    }
    return false;
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
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends