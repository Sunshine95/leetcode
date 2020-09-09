class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int n = grid.size();
        if (grid[0][0] == 1)
            return -1;
        if (grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        bool reached_end = false;

        int move_count = 1;
        queue<int> rq;
        queue<int> cq;
        int r = 0;
        int c = 0;

        int node_left_in_layer = 1;
        int node_in_next_layer = 0;

        rq.push(r);
        cq.push(c);
        visited[r][c] = true;

        while (!rq.empty())
        { // or !rc.empty();

            r = rq.front();
            rq.pop();
            c = cq.front();
            cq.pop();

            if (r == n - 1 && c == n - 1)
            {
                reached_end = true;
                break;
            }

            // explore neighbours
            vector<int> dr = {1, 1, 0, -1, -1, -1, 0, 1};
            vector<int> dc = {0, 1, 1, 1, 0, -1, -1, -1};

            for (int dir = 0; dir < 8; dir++)
            {
                int rr = r + dr[dir];
                int cc = c + dc[dir];

                // out of grid
                if (rr < 0 || rr >= n)
                    continue;
                if (cc < 0 || cc >= n)
                    continue;

                // blocked path or already visited
                if (grid[rr][cc] == 1)
                    continue;
                if (visited[rr][cc])
                    continue;

                rq.push(rr);
                cq.push(cc);
                visited[rr][cc] = true;
                node_in_next_layer++;
            }

            node_left_in_layer--;

            if (!node_left_in_layer)
            {
                move_count++;
                node_left_in_layer = node_in_next_layer;
                node_in_next_layer = 0;
            }
        }

        if (reached_end)
            return move_count;
        return -1;
    }
};