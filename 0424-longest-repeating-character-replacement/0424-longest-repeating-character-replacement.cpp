class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int mxlen=0;
        int mxfreq=0;//int extra=0;
        unordered_map<int,int> mp(26);

        while(r<n){
            
            mp[s[r]-'A']++;
            mxfreq=max(mxfreq, mp[s[r]-'A']);

            if((r-l+1 ) - mxfreq >k){  //not possible shift left
            mp[s[l]-'A']--;
            mxfreq=0;
            l++;  
            }

            if((r-l+1) - mxfreq<=k){  //possible
             mxlen=max(mxlen,r-l +1);
            }
        
            r++;

        }
        return mxlen;
    }
};