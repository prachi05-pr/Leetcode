class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        int sidx=-1;
        int mnlen=INT_MAX;
        // for(int i=0;i<n;i++){
            int cnt=0;
            vector<int>mp(256,0);

            for(int j=0;j<m;j++){
            mp[t[j]]++;
            }
          int j=0;
          int i=0;
            // for(int j=i;j<n;j++){
            while(j<n){
                if(mp[s[j]]>0 )  cnt++;

                mp[s[j]]--;
                j++;
        //         int len=j-i+1;
        //         if(cnt==m)   {
        //             if(len<mnlen){
        //                 mnlen =len;
        //                 sidx=i;
                      
        //             }
        //             break;
        //         }
        //     }
        // }

         while(cnt == m) {

                int len = j - i;

                if(len < mnlen) {
                    mnlen = len;
                    sidx = i;
                }

                // remove s[i] from window
                if(mp[s[i]] >= 0) {
                    cnt--;
                }

                mp[s[i]]++;
                i++;
         }
            }
          if(sidx == -1)
            return "";

        return s.substr(sidx,mnlen);
    }
};