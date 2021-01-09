class Solution
{
public:
    bool sortHelp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> set;
        sort(intervals.begin(), intervals.end());

        set.push_back(intervals[0]);

        int j = 0;
        for (int i = 1; i < intervals.size(); i++)
        {

            if (intervals[i][0] <= set[j][1])
            {
                set[j][1] = max(set[j][1], intervals[i][1]);
            }
            else
            {
                set.push_back(intervals[i]);
                j++;
            }
        }

        return set;
    }
};