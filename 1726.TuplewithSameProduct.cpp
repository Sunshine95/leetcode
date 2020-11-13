class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {

        int n = nums.size();
        unordered_map<int, int> hash;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int temp = nums[i] * nums[j];
                count += 8 * hash[temp];
                hash[temp]++;
            }
        }

        return count;
    }
};