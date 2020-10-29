class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<int>> ans(m, vector<int>(n));

        dp[0][0] = mat[0][0];

        for (int i = 1; i < m; i++)
        {
            dp[i][0] = mat[i][0] + dp[i - 1][0];
        }

        for (int j = 1; j < n; j++)
        {
            dp[0][j] = mat[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = mat[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int b = min(i + k, m - 1);
                int r = min(j + k, n - 1);

                int tr = i - k - 1 < 0 ? 0 : dp[i - k - 1][r];
                int bl = j - k - 1 < 0 ? 0 : dp[b][j - k - 1];

                int tl = i - k - 1 < 0 || j - k - 1 < 0 ? 0 : dp[i - k - 1][j - k - 1];

                ans[i][j] = dp[b][r] - bl - tr + tl;
            }
        }

        return ans;
    }
};