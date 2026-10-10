class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

        int n=s.size();
        for(int i=0;i<n;i++){
           char ch=s[i];
            if(s[i]=='(' ||s[i]=='{' ||s[i]=='['){
            st.push(s[i]);
        }

          else {
                if (st.empty())
                    return false;

                if ((ch == ')' && st.top() == '(') ||
                    (ch == '}' && st.top() == '{') ||
                    (ch == ']' && st.top() == '[')) {
                    st.pop();
                } 
                else {
                    return false;
                }
            }//else
        }//for
            return st.empty();
    }
};