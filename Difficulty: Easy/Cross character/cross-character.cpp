//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string crossPattern(string S){
        // code here 
        
        vector<vector<char>>ch(S.size(),vector<char>(S.size(),'.'));
        
        for(int i=0;i<S.size();i++){
            ch[i][i]=S[i];
        }
        
        int j=0;
        int r=S.size()-1;
        int k=0;
        while(j<S.size() && r>=0){
            
           ch[r][j]=S[k++];
           r--;
           j++;
        }
        
        string ans="";
        
        for(auto it:ch){
            for(auto i:it){
                if(i == '.'){
                    ans+=" ";
                }
                else{
                    ans+=i;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.crossPattern(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 
// } Driver Code Ends