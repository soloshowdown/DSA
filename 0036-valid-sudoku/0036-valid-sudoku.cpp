class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9),cols(9),boxes(9);
        
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char val = board[r][c];

                if( val=='.') continue; //for empty cell
                int boxIndex =(r/3)*3 +(c/3);

                if (rows[r].count(val) || cols[c].count(val) || boxes[boxIndex].count(val) ){
                    return false;

                }
                   // insert
                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxIndex].insert(val);
            }
        }

        return true;




    }
};