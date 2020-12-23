class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();
        int num = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(grid, i, j);
                }
            }
        }

        return num;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {

        if (grid[i][j] == '1')
        {

            grid[i][j] = 'f';
            if (j < (grid[0].size() - 1))
                dfs(grid, i, j + 1);
            if (i < (grid.size() - 1))
                dfs(grid, i + 1, j);
            if (j > 0)
                dfs(grid, i, j - 1);
            if (i > 0)
                dfs(grid, i - 1, j);
        }

        return;
    }
};