class Solution {
public:
    int dp2(vector<int>& coins,int amount,vector<vector<long long>> &dp){
    int n=coins.size();

        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Impossible initially
        for(int j = 1; j <= amount; j++) {
            dp[0][j] = 0;
        }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            if(coins[i-1]<=j){  //valid
          
    if(dp[i][j - coins[i-1]] > INT_MAX - dp[i-1][j])     dp[i][j] = INT_MAX;
else
    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
            //dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }

            else{   //invalid case 
            dp[i][j]= dp[i-1][j];
            }

        }
    }

    return dp[n][amount];
    }
      int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //unbounded knapsack sarkha ahe
        vector<vector<long long>> dp(n+1,vector<long long>(amount +1,0));
       return dp2(coins,amount,dp);
    }
};