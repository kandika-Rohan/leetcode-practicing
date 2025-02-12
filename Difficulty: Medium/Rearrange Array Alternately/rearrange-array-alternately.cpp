//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void rearrange(vector<int>& arr) {

        // Your code here
        sort(begin(arr),end(arr));
        
        int i=0,k=0;
        int j=arr.size()-1;
        
        vector<int>temp(arr.size());
        
        while(i<=j){
            if(k<arr.size())temp[k++]=arr[j--];
            if(k<arr.size())temp[k++]=arr[i++];
        }
        
        arr=temp;
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
        Solution obj;
        obj.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends