class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        

        int n=str1.size();

        int m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        int maxi=0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(str1[i-1] == str2[j-1]){

                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }

                maxi=max(maxi,dp[i][j]);
            }
        }

        
        cout<<maxi<<endl;

        string res="";

        int i=n;

        int j=m;

        while(i>0 && j>0){

            if(str1[i-1] == str2[j-1]){

                res+=str1[i-1];

                i--;
                j--;

            }
            else if(dp[i][j-1]>dp[i-1][j]){


                res+=str2[j-1];

                j--;

            }

            else{

                res+=str1[i-1];

                i--;
            }
        }

        while(i>0){

            res+=str1[i-1];
            i--;
        }
        while(j>0){

            res+=str2[j-1];
            j--;
        }


        return res;
    }
};