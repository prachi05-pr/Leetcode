class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
      
        for(int c=0;c<numRows;c++){
          vector<int> temp(c+1,1);
            for(int r=1;r<c;r++){
                temp[r]= ans[c-1][r]+ ans[c-1][r-1];
          
            
        }
        ans.push_back(temp);
        }
        return ans;
    }
};