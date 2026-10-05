class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int cnt=0;
        int r=0,l=0;
        unordered_map<int ,int> mp;
        int mxlen=0;
      while(r<n){
        mp[fruits[r]]++;
        while(mp.size()>2){
            mp[fruits[l]]--;
            if(mp[fruits[l]]==0){
            mp.erase(fruits[l]);
            }
            l++;
        }
        if(mp.size()<3){
            mxlen=max(mxlen,r-l+1);
        }
        r++;
      }
      return mxlen;
    }
};