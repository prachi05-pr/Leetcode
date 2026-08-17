class Solution {
public:
    int solve(int st,int end,vector<int>& nums){
    int n=nums.size();
     if(st == end)
        return nums[st];
    //vector<int>dp(n);
    int prev2=nums[st];
    int prev1= max(nums[st],nums[st +1]);
    int res=0;
    for(int i=st + 2;i<=end;i++){
        res= max(prev2 + nums[i],prev1);
        prev2 = prev1;
        prev1 = res;
    }
    return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1)       return nums[0];
        int idx1 =  solve(1,n-1,nums);
        int idx2 =  solve(0,n-2,nums);
        return max(idx1,idx2);
    }
};