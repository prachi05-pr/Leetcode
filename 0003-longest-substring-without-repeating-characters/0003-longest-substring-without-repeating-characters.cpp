class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       unordered_map<char,int> mp;
        int len=0;
        int maxLen=0;
        int left=0;
        int right=0;
       while(right<n){
       if(mp.find(s[right]) !=mp.end() && mp[s[right]] >= left ){
            left= mp[s[right]] + 1;
        
       }
        mp[s[right]]=right;
       len=right-left+1;
       maxLen=max(len,maxLen);
       right++;
       }
        
        return maxLen;
    }
};