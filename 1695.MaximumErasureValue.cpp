class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {

        unordered_set<int> hash;
        vector<int> prefix(nums.size());
        int maxSum = 0;

        int a = 0;
        int b = 0;

        prefix[0] = nums[a];
        hash.insert(nums[a]);

        b++;

        while (b < nums.size())
        {

            prefix[b] = prefix[b - 1] + nums[b];

            if (hash.find(nums[b]) == hash.end())
            {
                hash.insert(nums[b]);
            }
            else
            {
                maxSum = max(maxSum, prefix[b - 1] - prefix[a] + nums[a]);

                while (nums[a] != nums[b])
                {
                    hash.erase(nums[a]);
                    a++;
                }

                a++;
            }

            b++;
        }

        maxSum = max(maxSum, prefix[b - 1] - prefix[a] + nums[a]);

        return maxSum;
    }
};