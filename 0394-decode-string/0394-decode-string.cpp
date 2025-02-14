class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {

            if (isdigit(c)) {

                num = num * 10 + (c - '0'); 

            } 

            else if (c == '[') {

                numStack.push(num);

                num = 0;

                st.push(c);

            } else if (c == ']') {

                string decodedStr = "";

                while (!st.empty() && st.top() != '[') {

                    decodedStr = st.top() + decodedStr;

                    st.pop();

                }
                st.pop(); 

                int repeat = numStack.top();

                numStack.pop();

                string expandedStr = "";

                while (repeat--) expandedStr += decodedStr;

                for (char ch : expandedStr) st.push(ch);

            } 
            else {
                st.push(c);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
