class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {

        int n = min(grid.size(), grid[0].size());
        bool flag;

        while (n)
        {
            for (int is = 0; is + n <= grid.size(); is++)
            {
                for (int js = 0; js + n <= grid[0].size(); js++)
                {

                    flag = false;

                    for (int i = is; i < is + n; i++)
                    {
                        if (!grid[i][js] || !grid[i][js + n - 1])
                        {
                            flag = true;
                            break;
                        }
                    }

                    if (flag)
                    {
                        continue;
                    }

                    for (int j = js; j < js + n; j++)
                    {
                        if (!grid[is][j] || !grid[is + n - 1][j])
                        {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag)
                    {
                        return n * n;
                    }
                }
            }
            n--;
        }

        return 0;
    }
};