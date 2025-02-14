//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        // code here
        
        int n1=arr1.size();
        int n2=arr2.size();
        
        int diff=abs(n1-n2);
        
        if(n1<n2){
            for(int i=0;i<diff;i++){
                arr1.insert(arr1.begin(),0);
            }
        }
        else if(n1>n2){
            for(int i=0;i<diff;i++){
                arr2.insert(arr2.begin(),0);
            }
        }
        
        n1=arr1.size();
        vector<int>ans;
        int carry=0;
        for(int i=n1-1;i>=0;i--){
            int val=arr1[i]+arr2[i]+carry;
            carry=val/10;
            ans.push_back(val%10);
        }
        
        if(carry>0){
            ans.push_back(carry);
        }
        reverse(begin(ans),end(ans));
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.findSum(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends