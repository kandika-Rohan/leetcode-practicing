//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sortIt(vector<long long>& arr) {
        // code here.
        sort(begin(arr),end(arr));
        
        vector<long long>ans(arr.size());
        
        int k=0;
        
        for(int i=arr.size()-1;i>=0;i--){
            
            if(arr[i] & 1){
                
                ans[k]=arr[i];
                k++;
            }
        }
       
        for(int i=0;i<arr.size();i++){
            if(arr[i] % 2 == 0){
                ans[k]=arr[i];
                k++;
            }
        }
        
        arr=ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.sortIt(arr);

        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends