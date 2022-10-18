#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }
            if (st.empty() ||
            (c == ')' && st.top() != '(') ||
            (c == ']' && st.top() != '[') ||
            (c == '}' && st.top() != '{') ) {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};