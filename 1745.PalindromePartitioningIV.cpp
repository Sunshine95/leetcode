class Solution
{
public:
    bool checkPartitioning(string s)
    {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int i = 1; i < n; i++)
        {
            dp[i - 1][i] = (s[i - 1] == s[i]);
        }

        for (int j = 2; j < n; j++)
        {
            for (int i = 0; i + j < n; i++)
            {
                dp[i][i + j] = (s[i] == s[i + j] && dp[i + 1][i + j - 1]);
            }
        }

        for (int i = 0; i < n - 2; i++)
        {
            if (dp[0][i])
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (dp[i + 1][j] && dp[j + 1][n - 1])
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};