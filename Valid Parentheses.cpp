class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unsigned int i = 0, len = s.length();
        while(i < len)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.size() != 0) {
                    char c = st.top();
                    if(c == '(' && s[i] == ')')
                        st.pop();
                    else if(c == '[' && s[i] == ']')
                        st.pop(); 
                    else if(c == '{' && s[i] == '}')
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
                
            }
            i++;
        }
        if(st.size() != 0)
            return false;
        else
            return true;
    }
};
