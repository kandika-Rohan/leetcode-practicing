//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string solve(int n,vector<string>&words,vector<int>&values){
        
        string res="";
        
        for(int i=0;i<values.size();i++){
            
            int value=values[i];
            string word=words[i];
            
            if(n>=value){
                
                if(n>=100){
                    
                    res+=solve(n/value,words,values)+" ";
                }
                
                res+=word;
                
                if(n%value > 0){
                    
                    res+=" "+solve(n%value,words,values);
                }
                
                return res;
            }
            
        }
        
        
        return res;
    }
    string convertToWords(int n) {
        // code here
        if(n == 0){
            return "Zero";
        }
        
        vector<int>values={1000000000,1000000,1000,100,90,80,
        70,60,50,40,30,20,19,18,17,16,15,14,13,12,11,10,9,
        8,7,6,5,4,3,2,1};
        
        vector<string>words={"Billion","Million","Thousand",
        "Hundred","Ninety","Eighty","Seventy","Sixty","Fifty",
        "Forty","Thirty","Twenty","Nineteen","Eighteen","Seventeen",
        "Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven",
        "Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two",
        "One"};
        
        string ans=solve(n,words,values);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << "\"" << ans << "\""
             << "\n";
    }
    return 0;
}

// } Driver Code Ends