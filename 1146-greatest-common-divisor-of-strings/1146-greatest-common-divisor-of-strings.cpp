class Solution {
public:
    bool isvalid(int i,string str,string s,int len){
        if(i>=str.size())return true;
        if(str.substr(i,len) != s){
            return false;
        }
        return isvalid(i+len,str,s,len);
    }
    string gcdOfStrings(string str1, string str2) {
        
        int n=str1.size();
        int m=str2.size();

        
        string ans="";

        if(str1[0] != str2[0])return ans;

        for(int len=1;len<=min(n,m);len++){

            string s=str1.substr(0,len);
            cout<<s<<endl;

            if(isvalid(0,str1,s,len)&&isvalid(0,str2,s,len)){
                ans=s;
            }
        }
        return ans;
    }
};