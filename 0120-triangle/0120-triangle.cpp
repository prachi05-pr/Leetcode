class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
       // int n=triangle[0].size();
        
        vector<vector<int>>dp(m);
        //if(m==1 && n==1)  return triangle[0][0];
       for(int row = 0; row < m; row++) {
            dp[row] = vector<int>(triangle[row].size(), 0);
        }

        dp[0][0] = triangle[0][0];

        for(int row=1; row<m; row++){
            for(int col=0; col<triangle[row].size(); col++){
                int up=INT_MAX;
             dp[0][0]= triangle[0][0];
                if(col < triangle[row-1].size()){
                 up=dp[row-1][col];
                }

                int leftDiagonal=INT_MAX;

                if(col > 0) {
                 leftDiagonal=dp[row-1][col-1];
                }
               
                dp[row][col] = triangle[row][col] + min(up,leftDiagonal);

            }
        }
        int mn=INT_MAX;
        //ans is min of last row
        for(int col=0;col<triangle[m-1].size();col++){
        mn=min(mn,dp[m-1][col]);
        }
        return mn;
    }
};