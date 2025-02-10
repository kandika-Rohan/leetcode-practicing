class Solution {
public:
    string clearDigits(string s) {
         stack<char>st;

         for(auto it:s){
            if(isalpha(it)){
                st.push(it);
            }
           else if(isdigit(it)){
            if(!st.empty()){
                st.pop();
            }
           }
         }

         string ans="";
         while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
         }
         return ans;
    }
};