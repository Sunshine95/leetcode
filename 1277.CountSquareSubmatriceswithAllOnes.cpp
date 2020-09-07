class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        int sz = min(m, n);

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += matrix[i][j];
            }
        }

        for (int s = 1; s < sz; s++)
        {
            for (int i = s; i < m; i++)
            {
                for (int j = s; j < n; j++)
                {
                    if (matrix[i][j] == s && matrix[i - 1][j] >= s && matrix[i][j - 1] >= s && matrix[i - 1][j - 1] >= s)
                    {
                        matrix[i][j]++;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};