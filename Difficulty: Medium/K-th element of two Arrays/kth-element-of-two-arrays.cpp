//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int v, vector<int>& arr1, vector<int>& arr2) {
       
        int k=0;
        int i=0;
        int j=0;
        int n=arr1.size();
        int m=arr2.size();
        vector<int>temp(n+m,0);
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                temp[k]=arr1[i];
                k++;
                i++;
            }else{
                temp[k]=arr2[j];
                k++;
                j++;
            }
        }
        
        while(i<n){
            temp[k]=arr1[i];
                k++;
                i++;
        }
        while(j<m){
           temp[k]=arr2[j];
                k++;
                j++;
        }
        return temp[v-1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends