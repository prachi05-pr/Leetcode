class Solution {
public:
    int dp2(vector<int>& coins,int amount,vector<vector<int>> &dp){
    int n=coins.size();

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Impossible initially
        for(int j = 1; j <= amount; j++) {
            dp[0][j] = amount +1;
        }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            if(coins[i-1]<=j){  //valid
            dp[i][j] = min(1+ dp[i][j - coins[i-1]] , dp[i-1][j]);
            //dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }

            else{   //invalid case 
            dp[i][j]= dp[i-1][j];
            }

        }
    }

     if(dp[n][amount] > amount)
            return -1;

    return dp[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        //unbounded knapsack sarkha ahe
        vector<vector<int>> dp(n+1,vector<int>(amount +1,0));
       return dp2(coins,amount,dp);
    }
};