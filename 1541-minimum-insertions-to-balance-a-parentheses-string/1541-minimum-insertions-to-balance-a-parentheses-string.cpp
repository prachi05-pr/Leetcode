
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else {
                // If the next character is not ')',
                // insert the missing closing bracket
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    res++;
                }

                // Match the pair )) with an opening (
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    // Insert a missing opening (
                    res++;
                }
            }
        }

        return res + 2 * st.size();
    }
};
