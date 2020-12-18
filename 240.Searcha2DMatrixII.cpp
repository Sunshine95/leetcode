class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.size() == 0)
        {
            return false;
        }
        int top = 0;
        int bottom = matrix.size() - 1;

        if (matrix[0].size() == 0)
        {
            return false;
        }
        int left = 0;
        int right = matrix[0].size() - 1;

        return binarySearch(matrix, top, left, bottom, right, target);
    }

private:
    bool binarySearch(vector<vector<int>> &matrix, int top, int left, int bottom, int right, int target)
    {

        int midRow = (top + bottom) / 2;
        int midCol = (left + right) / 2;
        bool q = false;

        if (left >= right && top >= bottom)
        {
            return matrix[midRow][midCol] == target;
        }

        if (matrix[top][left] <= target && target <= matrix[midRow][midCol])
        {
            q = binarySearch(matrix, top, left, midRow, midCol, target);
            if (q)
            {
                return q;
            }
        }
        // if not a column matrix
        if ((left < right) && matrix[top][midCol + 1] <= target && target <= matrix[midRow][right])
        {
            q = binarySearch(matrix, top, midCol + 1, midRow, right, target);
            if (q)
            {
                return q;
            }
        }
        // if not a row matrix
        if ((top < bottom) && matrix[midRow + 1][left] <= target && target <= matrix[bottom][midCol])
        {
            q = binarySearch(matrix, midRow + 1, left, bottom, midCol, target);
            if (q)
            {
                return q;
            }
        }
        // if neither column nor row matrix
        if ((left < right) && (top < bottom) && matrix[midRow + 1][midCol + 1] <= target && target <= matrix[bottom][right])
        {
            q = binarySearch(matrix, midRow + 1, midCol + 1, bottom, right, target);
            if (q)
            {
                return q;
            }
        }
        return q;
    }
};