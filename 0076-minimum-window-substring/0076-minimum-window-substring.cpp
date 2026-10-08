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
          int right=0;
          int left=0;
            // for(int j=i;j<n;j++){
            while(right<n){
                if(mp[s[right]]>0 )  cnt++;

                mp[s[right]]--;
               
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

                int len = right - left +1;

                if(len < mnlen) {
                    mnlen = len;
                    sidx = left;
                }

                // remove s[i] from window
                if(mp[s[left]] >= 0) {
                    cnt--;
                }

                mp[s[left]]++;
                left++;
         }
         right++;
            }
          if(sidx == -1)
            return "";

        return s.substr(sidx,mnlen);
    }
};