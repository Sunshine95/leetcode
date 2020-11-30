class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(nums[i]) == hash.end())
                hash[nums[i]] = 1;
            else
                hash[nums[i]]++;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(k - nums[i]) != hash.end())
            {

                if (k == 2 * nums[i])
                {
                    if (hash[nums[i]] > 1)
                    {
                        count += hash[nums[i]] / 2;
                        hash[nums[i]] -= 2 * (hash[nums[i]] / 2);
                    }
                }
                else if (hash[k - nums[i]] > 0 && hash[nums[i]] > 0)
                {
                    int t = min(hash[k - nums[i]], hash[nums[i]]);
                    count += t;
                    hash[k - nums[i]] -= t;
                    hash[nums[i]] -= t;
                }
            }
        }

        return count;
    }
};