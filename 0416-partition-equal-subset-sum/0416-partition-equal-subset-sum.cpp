class Solution {
public:
    // bool solve(int i, vector<int>& nums,int target,vector<vector<bool>>& dp(n+1,vector<bool>(target+1))){
    // int n=nums.size();
    // for(int i=0;i<n+1;i++){
    //     dp[i][0]=true;
    // }

    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<target+1;j++){
    //         bool nottake=dp[i-1][j];
    //         bool take=false;

    //         if(nums[i-1]<=j){
    //             take = dp[i-1][j-nums[i-1]];
    //         }
    //         dp[i][j]=take || nottake;
    //     }
    // }
    // return dp[n][target];
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total = 0;

        for (int x : nums) {
            total += x;
        }

        if (total % 2 != 0)
            return false;

        int target = total / 2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            bool nottake=dp[i-1][j];
            bool take=false;

            if(nums[i-1]<=j){
                take = dp[i-1][j-nums[i-1]];
            }
            dp[i][j]=take || nottake;
        }
    }
    return dp[n][target];
    }
};