class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l_b= lower_bound(nums.begin(),nums.end(),target) -nums.begin(); 
        int u_b= upper_bound(nums.begin(),nums.end(),target) -nums.begin();
         
        
         if(l_b==nums.size() || nums[l_b] != target){
        return {-1,-1};
         }
         return {l_b,u_b-1};
    }
};