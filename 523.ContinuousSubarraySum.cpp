//523. Continuous Subarray Sum

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {

        vector<int> prefix;
        prefix.push_back(nums[0]);

        if (nums.size() < 2)
            return false;
        if (k == 0)
        {
            for (int i = 1; i < nums.size(); i++)
                if (nums[i - 1] == 0 && nums[i] == 0)
                    return true;
            return false;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            prefix.push_back(nums[i] + prefix[i - 1]);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if ((prefix[j] - prefix[i] + nums[i]) % k == 0)
                    return true;
        }

        return false;
    }
};