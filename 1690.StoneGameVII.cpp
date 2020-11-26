class Solution
{
public:
    vector<vector<int>> dp;

    int turn(vector<int> &stones, int i, int j, int sum)
    {

        if (i >= j)
        {
            return dp[i][j] = 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        dp[i][j] = max(sum - stones[i] - turn(stones, i + 1, j, sum - stones[i]),
                       sum - stones[j] - turn(stones, i, j - 1, sum - stones[j]));

        return dp[i][j];
    }

    int stoneGameVII(vector<int> &stones)
    {

        int n = stones.size();
        dp.resize(n, vector<int>(n, -1));

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += stones[i];
        }

        return dp[0][n - 1] = turn(stones, 0, n - 1, sum);
    }
};