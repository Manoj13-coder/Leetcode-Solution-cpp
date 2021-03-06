class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
        {
            if (p[i - 1] == '*' && dp[0][i - 2])
                dp[0][i] = true;
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};