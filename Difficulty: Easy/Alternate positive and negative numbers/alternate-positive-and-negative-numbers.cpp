//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>pos;
        vector<int>neg;
        
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                neg.push_back(arr[i]);
            }
            else{
                pos.push_back(arr[i]);
            }
        }
        
        int i=0;
        int j=0;
        int nn=pos.size();
        int mm=neg.size();
        int k=0;
        bool flag=true;
        while(i<nn && j<mm){
            
            if(flag){
                arr[k]=pos[i];
                k++;
                i++;
                flag=!flag;
            }
            else{
                arr[k]=neg[j];
                j++;
                k++;
                flag=!flag;
            }
        }
        
        if(i<nn){
            while(i<nn){
            arr[k]=pos[i];
            i++;
            k++;
            }
        }
        else if(j<mm){
            while(j<mm){
            arr[k]=neg[j];
            j++;
            k++;
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends