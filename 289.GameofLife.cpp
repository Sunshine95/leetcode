class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> next(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int temp = 0;

                if (i - 1 >= 0 && j - 1 >= 0)
                    if (board[i - 1][j - 1] == 1)
                        temp++;
                if (i - 1 >= 0)
                    if (board[i - 1][j] == 1)
                        temp++;
                if (i - 1 >= 0 && j + 1 < n)
                    if (board[i - 1][j + 1] == 1)
                        temp++;
                if (j - 1 >= 0)
                    if (board[i][j - 1] == 1)
                        temp++;
                if (j + 1 < n)
                    if (board[i][j + 1] == 1)
                        temp++;
                if (i + 1 < m && j - 1 >= 0)
                    if (board[i + 1][j - 1] == 1)
                        temp++;
                if (i + 1 < m)
                    if (board[i + 1][j] == 1)
                        temp++;
                if (i + 1 < m && j + 1 < n)
                    if (board[i + 1][j + 1] == 1)
                        temp++;

                if (temp < 2)
                    next[i][j] = 0;
                else if (temp <= 3 && board[i][j] == 1)
                    next[i][j] = 1;
                else if (temp == 3 && board[i][j] == 0)
                    next[i][j] = 1;
                else
                    next[i][j] = 0; // dead cells with >2 and live >3 neighbours
            }
        }

        board = next;
        return;
    }
};