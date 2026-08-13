class Solution {
public:
    bool rowUsed[9][10]= {};
    bool colUsed[9][10]= {};
    bool boxUsed[9][10]= {};

//     bool isSafe(vector<vector<char>>& board,int row,int col,int dig){
//     for(int j=0;j<row;j++){
//        if(board[j][col]== dig){
//        return false;
//        }
//     }

//     for(int j=0;j<col;j++){
//        if(board[row][j]== dig){
//        return false;
//        }
//     }

//    int startRow = (row / 3) * 3;
//    int startCol = (col / 3) * 3;

//         for (int i = startRow; i < startRow + 3; i++) {
//             for (int j = startCol; j < startCol + 3; j++) {
//                 if(board[i][j] == dig){
//                     return false;
//                 }
//             }
//     }
//     return true;
//     }

    bool solve(vector<vector<char>>& board,int row,int col){

    if(row==9){
        return true;
    }
    int nr=row;
    int nc=col+1;

    
    if(nc==9){
     nr=row+1;
     nc=0;
    }

    if( board[row][col] != '.'){
       return solve(board,nr,nc);
    }
    
     int box = (row / 3) * 3 + (col / 3);

    for(int dig=1;dig<=9;dig++){
         if(rowUsed[row][dig] ||
                colUsed[col][dig] ||
                boxUsed[box][dig]) {
                continue;
            }

            // Place digit
            board[row][col] = char('0' + dig);

            rowUsed[row][dig] = true;
            colUsed[col][dig] = true;
            boxUsed[box][dig] = true;

            if(solve(board,nr,nc)){
                return true;
            }

            board[row][col]='.';
            rowUsed[row][dig] = false;
            colUsed[col][dig] = false;
            boxUsed[box][dig] = false;

        
    }
    return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
         for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {

                    int dig = board[i][j] - '0';
                    int box = (i / 3) * 3 + (j / 3);

                    rowUsed[i][dig] = true;
                    colUsed[j][dig] = true;
                    boxUsed[box][dig] = true;
                }
            }
         }
        solve(board,0,0);
    }
};