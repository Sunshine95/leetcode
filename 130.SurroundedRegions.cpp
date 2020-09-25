class Solution
{
private:
    void dfs(vector<vector<char>> &board, int i, int j)
    {

        board[i][j] = '*';

        if (j < board[0].size() - 1 && board[i][j + 1] == 'O')
            dfs(board, i, j + 1);
        if (i < board.size() - 1 && board[i + 1][j] == 'O')
            dfs(board, i + 1, j);
        if (j > 0 && board[i][j - 1] == 'O')
            dfs(board, i, j - 1);
        if (i > 0 && board[i - 1][j] == 'O')
            dfs(board, i - 1, j);

        return;
    }

public:
    void solve(vector<vector<char>> &board)
    {

        int m = board.size();
        if (m == 0)
            return;
        int n = board[0].size();
        if (n == 0)
            return;

        int i, j;

        for (j = 0; j < n; j++)
        {

            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }

        for (i = 1; i < m - 1; i++)
        {

            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }

        return;
    }
};