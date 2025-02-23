class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.size()>2){
            string res="";
            for(int i=0;i<s.size();i++){

                if(i+1<s.size()){
                    res+=((s[i]-'0'+s[i+1]-'0')%10)+'0';
                }
            }
            cout<<res<<endl;
            s=res;
        }

        return s[0] == s[1];
    }
};