//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int i,int n,int arr[],
    unordered_map<int,string>&map,vector<string>&ans,string m){
        if(i >= n){
            if(m.size() == n){
                ans.push_back(m);
            }
            return;
        }
        int val=arr[i];
        string s=map[val];
        
        for(int ind=0;ind<s.size();ind++){
            m+=s[ind];
            solve(i+1,n,arr,map,ans,m);
            m.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        unordered_map<int,string>map;
        
        map[1]="";
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
        
        vector<string>ans;
        solve(0,N,a,map,ans,"");
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends