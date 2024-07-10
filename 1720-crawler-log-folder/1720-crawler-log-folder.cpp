class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(auto s:logs){

            if(!st.empty() && s=="../"){
                st.pop();
            }
            if(s == "../" || s=="./"){
                continue;
            }
            st.push(s);
        }
        return st.size();
    }
};