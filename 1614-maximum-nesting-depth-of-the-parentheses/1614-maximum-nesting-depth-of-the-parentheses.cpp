class Solution {
public:
    int maxDepth(string s) {
       int depth=0;
       int maxDepth=0;
       int n=s.size();
       for(char ch: s){
       if(ch=='('){
        depth+=1;
         maxDepth = max(maxDepth, depth);
       }
       if(ch==')'){
        depth-=1;
       }
       }
       return maxDepth;
    }
};