class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;

        // Boundary before the string
        st.push(-1);

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                // Try to match this ')'
                st.pop();

                if (st.empty()) {
                    // This ')' is unmatched.
                    // It becomes the new boundary.
                    st.push(i);
                }
                else {
                    // Valid substring ends at i.
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};