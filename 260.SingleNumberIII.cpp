class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {

        long long int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x ^= nums[i];
        }

        long long int right_most_set_bit = x & ~(x - 1);

        int a = 0, b = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if ((nums[i] & right_most_set_bit) != 0)
                a ^= nums[i];
            else
                b ^= nums[i];
        }

        return vector<int>{a, b};
    }
};