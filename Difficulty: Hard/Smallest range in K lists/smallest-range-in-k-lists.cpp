//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class node{
        public:
        int data;
        int row;
        int col;
        node(int d,int r,int c){
            this->data=d;
            this->row=r;
            this->col=c;
        }
    };
    class compare{
        public:
        bool operator()(node*a,node*b){
            return a->data > b->data;
        }
        
    };
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int mini=INT_MAX;
          int maxi=INT_MIN;
          priority_queue<node*,vector<node*>,compare>q;
          for(int i=0;i<k;i++){
              int element=KSortedArray[i][0];
              maxi=max(maxi,element);
              mini=min(mini,element);
              node*newnode=new node(element,i,0);
              q.push(newnode);
          }
          int start=mini;
          int end=maxi;
          while(!q.empty()){
              auto temp=q.top();
              q.pop();
              mini=temp->data;
              int row=temp->row;
              int col=temp->col;
              
              //updating the current range
              if(end-start> maxi-mini){
                  start=mini;
                  end=maxi;
              }
              
              if(col + 1 < n){
                  maxi=max(KSortedArray[row][col+1],maxi);
                  node*newnode=new node(KSortedArray[row][col+1],row,col+1);
                  q.push(newnode);
              }
              else{
                  break;
              }
          }
          pair<int,int>ans={start,end};
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends