class Solution
{
public:
    vector<vector<int>> visited;
    int m, n;

    void dfs(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &visited, int marker)
    {

        visited[r][c] += marker;

        vector<int> row = {0, 1, 0, -1};
        vector<int> col = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++)
        {

            int rr = r + row[k];
            int cc = c + col[k];

            if (rr >= m || rr < 0)
                continue;
            if (cc >= n || cc < 0)
                continue;

            if (visited[rr][cc] >= marker)
                continue;

            if (matrix[rr][cc] >= matrix[r][c])
            {
                dfs(rr, cc, matrix, visited, marker);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {

        vector<vector<int>> relief;
        int pacific = 1, atlantic = 2;

        m = matrix.size();
        if (m == 0)
            return relief;

        n = matrix[0].size();
        if (n == 0)
            return relief;

        visited.resize(m, vector<int>(n, 0));

        // draining into Pacific
        for (int i = 0; i < m; i++)
        {
            if (visited[i][0] < pacific)
            {
                dfs(i, 0, matrix, visited, pacific);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (visited[0][j] < pacific)
            {
                dfs(0, j, matrix, visited, pacific);
            }
        }

        // do not change order, as marker is int.
        // if you want to do it in any order, make
        // visited a matrix of strings, and just appended
        // a custom marker for each ocean.

        // draining into Atlantic
        for (int i = 0; i < m; i++)
        {
            if (visited[i][n - 1] < atlantic)
            {
                dfs(i, n - 1, matrix, visited, atlantic);
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (visited[m - 1][j] < atlantic)
            {
                dfs(m - 1, j, matrix, visited, atlantic);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == (pacific + atlantic))
                {
                    relief.push_back(vector<int>{i, j});
                }
            }
        }

        return relief;
    }
};