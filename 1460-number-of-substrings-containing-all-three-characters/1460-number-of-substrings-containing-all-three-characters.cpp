class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3]={-1,-1,-1};
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            lastseen[s[i]-'a']=i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
            {
                int mini;
               for(int i=0;i<3;i++)
               {
                mini=min(lastseen[i],mini);
               }
               count+=1+mini;
            }
        }
        return count;
    }
};