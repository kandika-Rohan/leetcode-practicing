class Solution {
public:
    string tobinary(int n){
        string ans="";
        while(n!=0){
            int digit=n%2;
            ans+=(digit+'0');
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        string ans="";
        string val="";
        for(int i=0;i<date.length();i++){
            if(date[i] == '-'){
                int num=stoi(val);
                ans+=tobinary(num)+"-";
                val="";
            }
            else{ val+=date[i];
            }
           
        }
        if(!val.empty()){
            int num = stoi(val);
            ans += tobinary(num); 
        }
        return ans;
    }
};