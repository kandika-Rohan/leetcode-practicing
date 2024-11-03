//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
  
    string validate(string temp){
        if(temp[0] != '0'){
            return temp;
            
        }
        
        string ans="";
        int start=-1;
        for(int i=0;i<temp.size();i++){
            if(temp[i] != '0'){
                start=i;
                break;
            }
        }
        for(int i=start;i<temp.size();i++){
            ans+=temp[i];
        }
        
        return ans;
    }
    string newIPAdd (string s)
    {
        //code here.
        
        vector<string>ans;
        
        string temp="";
        
        for(auto it:s){
            
            if(it == '.'){
                
                if(!temp.empty()){
                    
                    string t=validate(temp);
                    
                    // cout<<t<<endl;
                    if(t.empty()){
                        ans.push_back("0.");
                    }
                    else{
                        ans.push_back(t+".");
                    }
                    
                    temp="";
                }
            }
            else{
                temp+=it;
            }
        }
        if(!temp.empty()){
            string t=validate(temp);
            if(t.empty()){
                        ans.push_back("0");
            }
            else{
                ans.push_back(t);
            }
            
        }
        
        string res="";
        for(auto it:ans){
            res+=it;
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends