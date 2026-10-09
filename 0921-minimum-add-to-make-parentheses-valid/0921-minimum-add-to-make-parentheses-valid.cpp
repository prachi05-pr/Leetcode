class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        
        int res=0;
        stack<char> st;
        for(char &c:s){
        
        if(c=='(')   st.push(c);

        if(c==')') {
        if(!st.empty()) {
             st.pop();

        if (&c == nullptr) {}
        }
        else res++;
        
        }

        }
        return st.size() + res;
    }
};