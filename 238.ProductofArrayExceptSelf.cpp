class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> left, right;
        left.push_back(1);
        right.push_back(1);

        vector<int> res;

        for (int i = 1; i < n; i++)
        {
            left.push_back(nums[i - 1] * left[i - 1]);
            right.push_back(nums[n - i] * right[i - 1]);
        }

        for (int i = 0; i < n; i++)
        {
            res.push_back(left[i] * right[n - 1 - i]);
        }

        return res;
    }
};