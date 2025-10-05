class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));  // Cells reachable by Pacific
        vector<vector<int>> atlantic(m, vector<int>(n, 0)); // Cells reachable by Atlantic

        // DFS function
        function<void(int, int, vector<vector<int>> &)> dfs = [&](int i, int j, vector<vector<int>>& ocean) {
            ocean[i][j] = 1;
            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 4 directions

            for (auto& d : dirs) {
                int x = i + d[0], y = j + d[1];
                // Conditions: inside matrix, not visited, and next cell >= current (reverse flow)
                if (x >= 0 && x < m && y >= 0 && y < n && !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                    dfs(x, y, ocean);
                }
            }
        };

        // Pacific → top & left borders
        for (int i = 0; i < m; i++) dfs(i, 0, pacific); // left column
        for (int j = 0; j < n; j++) dfs(0, j, pacific); // top row

        // Atlantic → bottom & right borders
        for (int i = 0; i < m; i++) dfs(i, n-1, atlantic); // right column
        for (int j = 0; j < n; j++) dfs(m-1, j, atlantic); // bottom row

        // Collect intersection cells
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }
};
