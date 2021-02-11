class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        nRow = board.size();
        nCol = board[0].size();

        const char *letter = word.c_str();

        for (int i = 0; i < nRow; i++)
        {
            for (int j = 0; j < nCol; j++)
            {
                if (exist(i, j, board, letter))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    int nRow;
    int nCol;
    bool exist(int i, int j, vector<vector<char>> &board, const char *letter)
    {

        if (*(letter + 1) == '\0')
        {
            return *letter == board[i][j];
        }

        if (*letter == board[i][j])
        {
            char t = *letter;
            board[i][j] = '\0';
            if ((j > 0 && exist(i, j - 1, board, letter + 1)) ||
                (j < nCol - 1 && exist(i, j + 1, board, letter + 1)) ||
                (i > 0 && exist(i - 1, j, board, letter + 1)) ||
                (i < nRow - 1 && exist(i + 1, j, board, letter + 1)))
            {
                return true;
            }
            board[i][j] = t;
        }

        return false;
    }
};