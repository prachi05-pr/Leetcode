class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int a=0;
        int b=0;
        //2pointer
        while(a<m && b<n){
        if(g[b] <= s[a]){
            cnt++;
            b++;
            a++;
        }
        else{
            
            a++;
            
        }
        }
        return cnt;
    }
};