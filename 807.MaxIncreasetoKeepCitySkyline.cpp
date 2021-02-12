class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {

        int n = grid.size();
        vector<int> vert(n), horz(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                horz[i] = max(horz[i], grid[i][j]);
                vert[i] = max(vert[i], grid[j][i]);
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += (min(horz[i], vert[j]) - grid[i][j]);
            }
        }

        return count;
    }
};