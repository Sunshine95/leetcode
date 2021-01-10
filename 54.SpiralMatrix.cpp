class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int i = 0;
        int j = 0;

        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;

        int w = 420;

        int dir = 0;
        // right = 0
        // down = 1
        // left = 2
        // up = 3

        vector<int> set;
        set.push_back(matrix[0][0]);

        while (matrix[i][j] != w)
        {

            matrix[i][j] = w;

            if (dir == 0)
                j++;
            else if (dir == 1)
                i++;
            else if (dir == 2)
                j--;
            else
                i--;

            if (j > m || i > n || j < 0 || i < 0 || matrix[i][j] == w)
            {

                if (dir == 0)
                {
                    j--;
                    i++;
                }
                else if (dir == 1)
                {
                    i--;
                    j--;
                }
                else if (dir == 2)
                {
                    j++;
                    i--;
                }
                else
                {
                    i++;
                    j++;
                }

                dir = (dir + 1) % 4;

                if (j > m || i > n || j < 0 || i < 0 || matrix[i][j] == w)
                    break;
            }

            set.push_back(matrix[i][j]);
        }

        return set;
    }
};