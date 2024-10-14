//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char>a1;
        vector<char>a2;
        for(auto it:str){
            if(it>='a' && it<='z'){
                a1.push_back(it);
            }
            else{
                a2.push_back(it);
            }
        }
        sort(begin(a1),end(a1));
        sort(begin(a2),end(a2));
        
        string ans="";
        int k=0;
        int l=0;
        for(int i=0;i<n;i++){
            if(str[i]>='a' && str[i]<='z'){
                ans+=a1[k++];
                
            }
            else{
                ans+=a2[l++];
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
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends