class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {

        int n = customers.size();
        double avgWait;
        vector<int> fin(n);

        fin[0] = max(1, customers[0][0]) + customers[0][1];
        avgWait = (double)fin[0] - customers[0][0];

        for (int i = 1; i < n; i++)
        {

            int a = customers[i][0];
            int d = customers[i][1];

            fin[i] = max(fin[i - 1], a) + d;
            avgWait += (fin[i] - a);
        }

        avgWait /= n;
        return avgWait;
    }
};