class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
                matrix[i][j] = matrix[i][j - 1] ^ matrix[i][j];
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < m; i++)
            {
                matrix[i][j] = matrix[i - 1][j] ^ matrix[i][j];
            }
        }

        vector<int> fin;
        for (int i = 0; i < m; i++)
        {
            fin.insert(fin.end(), matrix[i].begin(), matrix[i].end());
        }

        sort(fin.begin(), fin.end());
        return fin[(m * n) - k];
    }
};