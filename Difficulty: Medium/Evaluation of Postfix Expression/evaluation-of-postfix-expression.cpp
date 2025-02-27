//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
     int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] == "+"){
                int a1 = st.top(); st.pop();
                int a2 = st.top(); st.pop();
                int res = a1+a2;
                st.push(res);
                
            }else if(arr[i] == "-"){
                int a1 = st.top(); st.pop();
                int a2 = st.top(); st.pop();
                int res = a2-a1;
                st.push(res);
                
            }else if(arr[i] == "*"){
                int a1 = st.top(); st.pop();
                int a2 = st.top(); st.pop();
                int res = a1*a2;
                st.push(res);
                
            }else if(arr[i] == "/"){
                int a1 = st.top(); st.pop();
                int a2 = st.top(); st.pop();
                int res = a2/a1;
                st.push(res);
                
            }else{
                int num = stoi(arr[i]);
                st.push(num);
            }
        }   
        return !st.empty()?st.top():-1;
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends