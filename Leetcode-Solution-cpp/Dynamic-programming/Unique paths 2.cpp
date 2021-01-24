class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int row_end, int col_end, int dp[101][101])
    {
        if (row >= row_end || col >= col_end)
            return 0;
        if (row == row_end - 1 && col == col_end - 1)
            return grid[row][col] == 0 ? 1 : 0;
        if (grid[row][col] == 1)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = dfs(grid, row + 1, col, row_end, col_end, dp) + dfs(grid, row, col + 1, row_end, col_end, dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return dfs(obstacleGrid, 0, 0, obstacleGrid.size(), obstacleGrid[0].size(), dp);
    }
};