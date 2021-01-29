class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int row[9][10] = {{0}};
        int col[9][10] = {{0}};
        int grid[9][10] = {{0}};
        int ngrid;
        int a;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                ngrid = ((i / 3) * 3) + (j / 3);
                if (board[i][j] != '.')
                {
                    a = board[i][j] - '0';

                    if (row[i][a] || col[j][a] || grid[ngrid][a])
                    {
                        return false;
                    }
                    else
                    {
                        row[i][a]++;
                        col[j][a]++;
                        grid[ngrid][a]++;
                    }
                }
            }
        }

        return true;
    }
};