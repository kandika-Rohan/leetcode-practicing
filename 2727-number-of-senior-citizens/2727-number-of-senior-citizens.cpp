class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(int i=0;i<details.size();i++){
            int age=0;
            string s=details[i];
            if(s.size()==15){
            age=age*10+s[11]-'0';
            age=age*10+s[12]-'0';
            cout<<age<<endl;

            if(age>60){
                cnt++;
            }
            }
           
        }
        return cnt;
    }
};