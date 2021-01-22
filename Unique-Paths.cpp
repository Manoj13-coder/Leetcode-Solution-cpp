class Solution {
public:
    int go(int row,int col,int i,int j,int dp[101][101])
    {
        if(i == row-1 && j == col-1)
            return 1;
        if(i >= row || j >= col)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = go(row,col,i+1,j,dp)+go(row,col,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
        return go(m,n,0,0,dp);
    }
};