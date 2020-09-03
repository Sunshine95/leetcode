class Solution
{
public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<int> rq;
        queue<int> cq;

        int free = grid[r0][c0];

        rq.push(r0);
        cq.push(c0);

        while (!rq.empty())
        {

            int r = rq.front();
            int c = cq.front();

            rq.pop();
            cq.pop();
            visited[r][c] = true;

            vector<int> r_dir = {1, 0, -1, 0};
            vector<int> c_dir = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {

                int rr = r + r_dir[i];
                int cc = c + c_dir[i];

                if ((rr < 0 || rr >= m) || (cc < 0 || cc >= n))
                {
                    grid[r][c] = color;
                    continue;
                }

                if (visited[rr][cc])
                    continue;

                if (grid[rr][cc] != free)
                {

                    grid[r][c] = color;
                    continue;
                }

                rq.push(rr);
                cq.push(cc);
            }
        }

        return grid;
    }
};