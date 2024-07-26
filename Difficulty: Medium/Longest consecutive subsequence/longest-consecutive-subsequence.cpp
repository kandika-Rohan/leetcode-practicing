//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
     
      int sum=1;
      int maxi=0;
      
      unordered_map<int,int>map;
      for(int i=0;i<N;i++){
          map[arr[i]]++;
      }
     vector<int>temp;
      for(auto it:map){
          temp.push_back(it.first);
      }
      sort(temp.begin(),temp.end());
      for(int i=1;i<temp.size();i++){
          if(temp[i]==temp[i-1]+1){
              sum=sum+1;
              maxi=max(maxi,sum);
          }
          else{
              sum=1;
          }
      }
      return maxi==0?1:maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends