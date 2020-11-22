class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        pair<int, int> pos;
        vector<int> destination(n, -1);

        for (int i = 0; i < n; i++)
        {
            pos = make_pair(0, i);

            do
            {
                if (grid[pos.first][pos.second] == 1)
                {
                    if (pos.second == n - 1 || grid[pos.first][pos.second + 1] == -1)
                    {
                        break;
                    }
                    else
                    {
                        pos.first++;
                        pos.second++;
                    }
                }
                else
                {
                    if (pos.second == 0 || grid[pos.first][pos.second - 1] == 1)
                    {
                        break;
                    }
                    else
                    {
                        pos.first++;
                        pos.second--;
                    }
                }
            } while (pos.first < m);

            destination[i] = pos.first == m ? pos.second : -1;
        }

        return destination;
    }
};