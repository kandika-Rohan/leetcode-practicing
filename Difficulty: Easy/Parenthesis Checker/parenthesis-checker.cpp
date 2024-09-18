//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        
        for(auto it:x){
            
            if(it == '[' || it=='{' || it == '('){
                st.push(it);
            }
            else{
                
                if(!st.empty()){
                    
                    char ch=st.top();
                    
                    if((it == ')' && ch =='(')|| 
                    (it == ']' && ch =='[') || (it == '}' && ch =='{')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends