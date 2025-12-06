class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // 8 directions
        vector<vector<int>> dirs = {
            {0,1}, {1,0}, {0,-1}, {-1,0},
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };

        // Step 1: Traverse each cell and calculate next state
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                
                int liveNeighbors = 0;

                // Count live neighbors
                for(auto &d : dirs){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                        // If neighbor is currently live (1) or marked to die (-1)
                        if(abs(board[nr][nc]) == 1){
                            liveNeighbors++;
                        }
                    }
                }

                // Rule 1 & 3: Change states using encoding
                if(board[r][c] == 1) {
                    // live → die
                    if(liveNeighbors < 2 || liveNeighbors > 3)
                        board[r][c] = -1;
                }
                else {
                    // dead → live
                    if(liveNeighbors == 3)
                        board[r][c] = 2;
                }
            }
        }

        // Step 2: Convert encoded values to final state
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(board[r][c] == -1) board[r][c] = 0;
                if(board[r][c] == 2) board[r][c] = 1;
            }
        }
    }
};
