class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {

        int n = aliceValues.size();
        if (n == 1)
            return 1;

        int aliceScore = 0;
        vector<pair<int, int>> totalValues(n);

        for (int i = 0; i < n; i++)
        {
            totalValues[i].first = aliceValues[i] + bobValues[i];
            totalValues[i].second = i;
        }

        sort(totalValues.begin(), totalValues.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; });

        int i;
        for (i = 0; i + 1 < n; i += 2)
        {
            int j1 = totalValues[i].second;
            int j2 = totalValues[i + 1].second;
            aliceScore += (aliceValues[j1] - bobValues[j2]);
        }

        if (i < n)
        {
            int j1 = totalValues[i].second;
            aliceScore += aliceValues[j1];
        }

        if (aliceScore > 0)
        {
            return 1;
        }
        else if (aliceScore == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
};