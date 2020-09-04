class Solution
{
public:
    string alphabetBoardPath(string target)
    {

        vector<vector<int>> board(26, vector<int>(2));

        board[0] = vector<int>{0, 0};
        board[1] = vector<int>{0, 1};
        board[2] = vector<int>{0, 2};
        board[3] = vector<int>{0, 3};
        board[4] = vector<int>{0, 4};
        board[5] = vector<int>{1, 0};
        board[6] = vector<int>{1, 1};
        board[7] = vector<int>{1, 2};
        board[8] = vector<int>{1, 3};
        board[9] = vector<int>{1, 4};
        board[10] = vector<int>{2, 0};
        board[11] = vector<int>{2, 1};
        board[12] = vector<int>{2, 2};
        board[13] = vector<int>{2, 3};
        board[14] = vector<int>{2, 4};
        board[15] = vector<int>{3, 0};
        board[16] = vector<int>{3, 1};
        board[17] = vector<int>{3, 2};
        board[18] = vector<int>{3, 3};
        board[19] = vector<int>{3, 4};
        board[20] = vector<int>{4, 0};
        board[21] = vector<int>{4, 1};
        board[22] = vector<int>{4, 2};
        board[23] = vector<int>{4, 3};
        board[24] = vector<int>{4, 4};
        board[25] = vector<int>{5, 0};

        int ch = 0;
        int r = 0;
        int c = 0;
        string out = "";

        for (int i = 0; i < target.size(); i++)
        {

            ch = target[i] - 'a';

            int row_diff;
            int col_diff;

            row_diff = r - board[ch][0];
            col_diff = c - board[ch][1];

            if (col_diff > 0)
            {
                while (col_diff)
                {
                    out += 'L';
                    col_diff--;
                }
            }

            if (row_diff < 0)
            {
                while (row_diff)
                {
                    out += 'D';
                    row_diff++;
                }
            }

            if (row_diff > 0)
            {
                while (row_diff)
                {
                    out += 'U';
                    row_diff--;
                }
            }

            if (col_diff < 0)
            {
                while (col_diff)
                {
                    out += 'R';
                    col_diff++;
                }
            }

            out += '!';

            r = board[ch][0];
            c = board[ch][1];
        }

        return out;
    }
};