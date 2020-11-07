class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {

        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> out(m, vector<int>(n, -2));
        // -2 not visited.
        // -1 seen, not visited.
        // non-negative integer is assignmed answer

        queue<int> rq;
        queue<int> cq;

        int r;
        int c;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    rq.push(i);
                    cq.push(j);
                    out[i][j] = -1;
                }
            }
        }

        int height = 0;
        int size = rq.size(); // equivalent to cq.size()

        while (!rq.empty())
        { //equivalent to !cq.empty()

            r = rq.front();
            c = cq.front();

            out[r][c] = height;

            rq.pop();
            cq.pop();

            vector<int> r_dir{-1, 0, 1, 0};
            vector<int> c_dir{0, 1, 0, -1}; // up, right, down, left

            for (int k = 0; k < 4; k++)
            {

                int rr = r + r_dir[k];
                int cc = c + c_dir[k];

                if (rr < 0 || rr >= m)
                    continue;
                if (cc < 0 || cc >= n)
                    continue;

                if (out[rr][cc] >= 0)
                    continue; // visited
                if (out[rr][cc] == -1)
                    continue; // seen

                rq.push(rr);
                cq.push(cc);

                out[rr][cc] = -1;
            }

            size--;
            if (size == 0)
            {
                height++;
                size = rq.size();
            }
        }

        return out;
    }
};