class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i=0;i<n;i++){
            dp[0][i]= matrix[0][i];
        }
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                int up = dp[row-1][col];

                int leftDiagonal = INT_MAX;
                if(col > 0) {
                    leftDiagonal = dp[row-1][col-1];
                }

                int rightDiagonal = INT_MAX;
                if(col < n-1) {
                    rightDiagonal = dp[row-1][col+1];
                }
            dp[row][col]= matrix[row][col] + min(dp[row-1][col],min(leftDiagonal,rightDiagonal));
            }
        }
        int mn=INT_MAX;
        //ans is min of last row
        for(int col=0;col<n;col++){
        mn=min(mn,dp[m-1][col]);
        }
        return mn;
    }
};