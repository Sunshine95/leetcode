class Solution
{
public:
    int findArea(vector<int> &heights)
    {

        int n = heights.size();
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());

        int area = -1;
        for (int j = 0; j < n; j++)
        {
            int t = temp[j] * (n - j);
            area = max(area, t);
        }

        return area;
    }

    int largestSubmatrix(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maxArea, area;

        maxArea = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                heights[j] = (matrix[i][j] == 0) ? 0 : heights[j] + 1;
            }
            area = findArea(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};