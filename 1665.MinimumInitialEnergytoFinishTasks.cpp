class Solution
{
public:
    static bool myComp(const vector<int> &a, const vector<int> &b)
    {
        return (a[1] - a[0] > b[1] - b[0]);
    }

    int minimumEffort(vector<vector<int>> &tasks)
    {

        int minEng = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            minEng += tasks[i][0];
        }

        sort(tasks.begin(), tasks.end(), myComp);

        int addendum = 0, temp = minEng;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (temp < tasks[i][1])
            {
                addendum += (tasks[i][1] - temp);
                temp = tasks[i][1];
            }
            temp -= tasks[i][0];
        }

        return addendum + minEng;
    }
};