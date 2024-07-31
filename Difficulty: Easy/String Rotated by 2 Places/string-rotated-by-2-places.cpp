//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size() != str2.size()){
            return false;
        }
        string a=str1;
        bool flag=false;
        rotate(str1.begin(),str1.begin()+2,str1.end());
        if(str1 == str2){
            flag=true;
        }
        rotate(a.rbegin(),a.rbegin()+2,a.rend());
        
        if(a == str2){
            flag=true;
        }
        return flag;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends