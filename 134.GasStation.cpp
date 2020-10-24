class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int n = gas.size();
        vector<int> diff(n);

        int canRound = 0;
        for (int i = 0; i < n; i++)
        {
            diff[i] = gas[i] - cost[i];
            canRound += diff[i];
        }

        if (canRound < 0)
            return -1;

        int sum = 0;
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            if (sum + diff[i] > diff[i])
            {
                sum += diff[i];
            }
            else
            {
                start = i;
                sum = diff[i];
            }
        }

        return start;
    }
};