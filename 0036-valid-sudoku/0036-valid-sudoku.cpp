class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rowHash(9);
        vector<unordered_set<int>> colHash(9);
        vector<unordered_set<int>> boxHash(9);
        for(int r = 0 ; r < 9 ; ++r) {
            for(int c = 0 ; c < 9 ; ++c) {
                if( board[r][c] == '.') continue;
                if( rowHash[r].count( board[r][c] - '0' ) ) return false;
                if( colHash[c].count( board[r][c] - '0' ) ) return false;
                int boxId = r / 3 * 3 + c / 3;
                if( boxHash[boxId].count( board[r][c] - '0' ) ) return false;

                rowHash[r].insert( board[r][c] - '0' );
                colHash[c].insert( board[r][c] - '0' );
                boxHash[boxId].insert( board[r][c] - '0' );
            }
        }
        return true;
    }
};