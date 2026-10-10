class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int> st;
       string ans="";

       for(int i=0;i<s.size(); i++){
        if(s[i]=='('){
            st.push(i);
        }
        else if(s[i]==')'){
            if(!st.empty()){
                st.pop();
            }
            else{
                s[i]='*';
            }
        }
       }
        while(!st.empty()){
            s[st.top()]='*';
            st.pop();
        }

        for(char &ch:s){
            if(ch!='*'){
                ans+=ch;
            }
        }
        return ans;
       
    }
};