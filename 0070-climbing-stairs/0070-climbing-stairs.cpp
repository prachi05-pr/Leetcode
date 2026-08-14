class Solution {
public:
    int solve(int n,vector<int> &c){
         if(n==1 || n==2){
            return n;
        }
        if(c[n]!=0) return c[n];
        c[n] = solve(n-1,c)+ solve(n-2,c);
        return c[n];
    }
    int climbStairs(int n) {
        vector<int> c(n+1);
        return solve(n,c);
    }
};