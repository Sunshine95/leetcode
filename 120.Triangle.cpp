class Solution
{
public:
    vector<vector<int>> memo;
    vector<vector<bool>> visited;

    int dfs(int r, int c, vector<vector<int>> &triangle)
    {

        if (r >= triangle.size() || c > r)
        {
            return 0;
        }

        if (visited[r][c])
        {
            return memo[r][c];
        }

        visited[r][c] = true;
        memo[r][c] = triangle[r][c] + min(dfs(r + 1, c, triangle), dfs(r + 1, c + 1, triangle));

        return memo[r][c];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();
        memo.resize(n, vector<int>(n));
        visited.resize(n, vector<bool>(n, false));

        return dfs(0, 0, triangle);
    }
};