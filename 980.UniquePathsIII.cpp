//980. Unique Paths III
class Solution
{
public:
    int count = 0;
    int zeros, n, m;

    void backtrack(int r, int c, vector<vector<int>> &grid)
    {

        vector<int> r_dir{0, 1, 0, -1};
        vector<int> c_dir{1, 0, -1, 0};

        for (int k = 0; k < 4; k++)
        {

            int rr = r + r_dir[k];
            int cc = c + c_dir[k];

            if (rr < 0 || rr >= n)
                continue;
            if (cc < 0 || cc >= m)
                continue;

            if (grid[rr][cc] == -1)
                continue;
            if (grid[rr][cc] == 1)
                continue;

            if (grid[rr][cc] == 2)
            {
                if (zeros == 0)
                {
                    count++;
                }
                continue;
            }

            grid[rr][cc] = 1;
            zeros--;

            backtrack(rr, cc, grid);

            grid[rr][cc] = 0;
            zeros++;
        }

        return;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {

        n = grid.size();
        m = grid[0].size();
        int r, c;

        zeros = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    r = i;
                    c = j;
                }
                else if (grid[i][j] == 0)
                {
                    zeros++;
                }
            }
        }

        backtrack(r, c, grid);

        return count;
    }
};