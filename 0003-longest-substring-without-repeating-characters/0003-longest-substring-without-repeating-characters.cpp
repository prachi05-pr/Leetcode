class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.size();
    int l=0;
    int r=0;
    int len=0;
    int mxlen=0;
    unordered_map<char,int>mp;
    while(r<n){
        while(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
            l=mp[s[r]]+1;
        }
        mp[s[r]]=r;
        len=r-l+1;
        mxlen=max(mxlen,len);
        r++;
    }
    return mxlen;
    }
};