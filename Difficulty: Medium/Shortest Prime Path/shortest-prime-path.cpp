//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isPrime(long n){
        if(n<2)return false;
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0)return false;
        }
        return true;
    }
    int solve(int n1,int n2)
    {   
      //code here
      vector<int>vis(1e6,0);
      queue<pair<string,int>>q;
      string s1=to_string(n1);
      string s2=to_string(n2);
      
      q.push({s1,0});
      vis[n1]=1;
      
      while(!q.empty()){
          
          auto it=q.front();
          q.pop();
          string num1=it.first;
          int steps=it.second;
          if(num1 == s2) return steps;
          
          for(int i=0;i<num1.size();i++){
              char ch=num1[i];
              for(int j=0;j<=9;j++){
                  if(i ==0 &&  j==0 )continue;
                  num1[i]=j+'0';
                  int val=stoi(num1);
                  if(isPrime(val) && !vis[val]){
                      q.push({num1,steps+1});
                      vis[val]=1;
                  }
              }
              num1[i]=ch;
          }
      }
      
      return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends