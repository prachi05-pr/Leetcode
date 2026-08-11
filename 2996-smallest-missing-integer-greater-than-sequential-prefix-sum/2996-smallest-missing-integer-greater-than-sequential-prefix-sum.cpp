class Solution {
public:
    int missingInteger(vector<int>& nums) {
        //int mnsum= INT_MAX;
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
         // mnsum=min(mnsum,sum);
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else{
                break;
            }
              
        }
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.count(sum)){
       sum++;
        } 
        return sum;
    }
};