class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zeros=0;
        int left=0,right=0;
        int len=0;
        int mxlen=0;
        while(right<n){
            if(nums[right]==0){
                zeros++;
            }
             while(zeros>k){
                if(nums[left]==0){    zeros--; }
                left++;
            }
        len=right-left+1;
        mxlen=max(mxlen,len);
        right++;
        }
        return mxlen;
    }
};