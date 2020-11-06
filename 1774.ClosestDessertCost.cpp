class Solution
{
public:
    int out = INT_MAX;
    int ans = INT_MAX;
    int m, n;
    int targ;

    void find(int topping, int cost, int minDiff, vector<int> &toppingCosts)
    {

        if (topping >= m)
        {
            if (out > minDiff)
            {
                out = minDiff;
                ans = cost;
            }
            else if (out == minDiff)
            {
                ans = min(ans, cost);
            }

            return;
        }

        find(topping + 1, cost, minDiff, toppingCosts);

        cost += toppingCosts[topping];
        if (minDiff <= abs(targ - cost))
        {
            return;
        }
        find(topping + 1, cost, abs(targ - cost), toppingCosts);

        minDiff = abs(targ - cost);

        cost += toppingCosts[topping];
        if (minDiff <= abs(targ - cost))
        {
            return;
        }
        find(topping + 1, cost, abs(targ - cost), toppingCosts);
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {

        n = baseCosts.size();
        m = toppingCosts.size();
        targ = target;

        for (int i = 0; i < n; i++)
        {
            find(0, baseCosts[i], abs(target - baseCosts[i]), toppingCosts);
        }

        return ans;
    }
};