class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans=0;
        for(auto it:tokens){

            if(it =="+" || it == "*" || it == "-" || it =="/"){

                if(st.size()<=1){
                    continue;
                }
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(it == "+"){
                    st.push(a+b);
                }
                else if(it == "*"){
                    st.push(a*b);
                }
                else if(it == "/"){
                    st.push(b/a);
                }
                else{
                    st.push(b-a);
                }
            }
            else{
                int val=stoi(it);
                st.push(val);
            }
        }
        return st.top();

    }
};