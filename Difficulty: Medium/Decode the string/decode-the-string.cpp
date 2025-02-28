//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        
        int n=s.size();
        
        
        stack<int>integer;
        
        stack<string>String;
        bool prev=false;
       
        for(auto it:s){
            
            if(isdigit(it)){
                
                if(prev == true){
                    
                    int val=integer.top();
                    
                    integer.pop();
                    
                    val=val*10+(it-'0');
                    
                    integer.push(val);
                    
                }
                
                else{
                    
                    integer.push(it-'0');
                    
                    prev=true;
                }
            
            }
            else if(it == '['){
                string str="";
                str+=it;
                String.push(str);
                prev=false;
                
            }
            
            else if(islower(it) || isupper(it)){
                string str="";
                str+=it;
                String.push(str);
                prev=false;
                
            }
            
            else if(it == ']'){
                
                string ans="";
                
                while(!String.empty() && String.top() != "["){
                    
                    ans=String.top()+ans;
                    
                    String.pop();
                    
                }
                
                String.pop();
              
                int val=integer.top();
                
                integer.pop();
                
                string res="";
                
                for(int i=0;i<val;i++){
                    
                    res=res+ans;
                }
                
                String.push(res);
                prev=false;
            }
        }
        
        string res="";
        
        while(!String.empty()){
            
            res=String.top()+res;
            String.pop();
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends