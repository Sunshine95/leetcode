class Solution
{
public:
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
    int leadBy(int i, int j, vector<int> &nums, int turn)
    {

        if (visited[i][j])
        {
            return memo[i][j];
        }

        if (j - i == 1)
        {
            memo[i][j] = turn * abs(nums[i] - nums[j]);
            visited[i][j] = true;
            return memo[i][j];
        }

        int t1 = nums[i] + turn * leadBy(i + 1, j, nums, -1 * turn);
        int t2 = nums[j] + turn * leadBy(i, j - 1, nums, -1 * turn);
        memo[i][j] = turn * max(t1, t2);
        visited[i][j] = true;
        return memo[i][j];
    }

    bool PredictTheWinner(vector<int> &nums)
    {

        int n = nums.size();
        if (n < 3)
            return true;

        memo.resize(n, vector<int>(n, -1));
        visited.resize(n, vector<bool>(n, false));

        if (leadBy(0, n - 1, nums, 1) >= 0)
        {
            return true;
        }

        return false;
    }
};