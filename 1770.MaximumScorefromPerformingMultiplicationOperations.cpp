class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {

        int n = nums.size();
        int m = multipliers.size();
        int k = n - m;
        vector<vector<int>> memo(m, vector<int>(m, -1));

        for (int i = m - 1; i >= 0; i--)
        {

            int s = m - 1;
            int j = i;
            memo[i][j] = max(multipliers[s] * nums[i], multipliers[s] * nums[j + k]);

            int t = 1;
            for (j = i + 1; j < m; j++)
            {
                memo[i][j] = max((multipliers[s - t] * nums[j + k]) + memo[i][j - 1], (multipliers[s - t] * nums[i]) + memo[i + 1][j]);
                t++;
            }

            s--;
        }

        return memo[0][m - 1];
    }
};