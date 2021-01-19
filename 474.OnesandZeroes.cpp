class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs)
        {

            int mm = 0, nn = 0;
            for (char b : s)
            {
                if (b == '0')
                {
                    mm++;
                }
                else
                {
                    nn++;
                }
            }

            for (int i = m; i >= mm; i--)
            {
                for (int j = n; j >= nn; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - mm][j - nn] + 1);
                }
            }
        }

        return dp[m][n];
    }
};