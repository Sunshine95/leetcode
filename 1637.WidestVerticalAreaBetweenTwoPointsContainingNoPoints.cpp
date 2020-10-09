class Solution
{
public:
    static bool myCompare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {

        int ans = 0;
        sort(points.begin(), points.end(), myCompare);

        for (int i = 1; i < points.size(); i++)
        {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }

        return ans;
    }
};