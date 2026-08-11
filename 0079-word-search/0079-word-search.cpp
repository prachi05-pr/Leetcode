class Solution {
public:
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& board, string &word,int idx,int row,int col){
    
    int m=board.size();
    int n=board[0].size();

    if(idx==word.size()){
        return true;
    }
    if(row<0 || col<0 || row>=m || col>=n || board[row][col]!=word[idx])  return false;
    
    char temp=board[row][col];
    board[row][col]='#';

    for(auto [x,y]: dir){
        int nr=row+x;
        int nc=col+y;
        
        if(dfs(board,word,idx+1,nr,nc)){
        board[row][col]=temp;
        return true;
        }
    }
        board[row][col]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(dfs(board,word,0,row,col)){
                    return true;
                }
            }
        }
        return false;
    }
};