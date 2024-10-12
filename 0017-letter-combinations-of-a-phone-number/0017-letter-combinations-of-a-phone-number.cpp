class Solution {
public:
    void solve(int index,string digits,string m,vector<string>&ans,string mapping [])
    {
        if(index>=digits.size())
        {
            ans.push_back(m);
            return ;
        }
        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.size();i++)
        {
            m.push_back(value[i]);
            solve(index+1,digits,m,ans,mapping);
            m.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()<=0)
        {
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,"",ans,mapping);
        return ans;
    }

};