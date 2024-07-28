//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution

{

  public:

  bool possible(int arr[],long long int mid,int n,int k){

     long long int sum=0;

      long long int painter=1;

      for(int i=0;i<n;i++){

          sum=sum+arr[i];

          if(sum>mid)

          {

              painter++;

              sum=arr[i];

          }

          if(painter>k)

          return false;

      }

      

      return true;

  }

    long long minTime(int arr[], int n, int k)

    {

        // code here

        // return minimum time

        int maxi=-1;

        for(int i=0;i<n;i++)

        maxi=max(maxi,arr[i]);

       long long int l=maxi;

       long long int sum=0;

        for(int i=0;i<n;i++)

        sum=sum+arr[i];

        long long int h=sum;

        long long int ans=-1;

        while(l<=h){

           long long int mid=(l+h)/2;

            if(possible(arr,mid,n,k)){

                ans=mid;

                h=mid-1;

            }

            else{

               l=mid+1;

            }

        }

    }

};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends