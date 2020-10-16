class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        int min_prod, max_prod, res;
        res = min_prod = max_prod = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {

            int t1 = max_prod;
            int t2 = min_prod;

            max_prod = max({nums[i], t1 * nums[i], t2 * nums[i]});
            min_prod = min({nums[i], t1 * nums[i], t2 * nums[i]});

            res = max(max_prod, res);
        }

        return res;
    }
};