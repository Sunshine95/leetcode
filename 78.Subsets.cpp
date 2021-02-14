class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> supset;

        int n = pow(2, nums.size());
        int bits, nbit;
        vector<int> set;

        for (int i = 0; i < n; i++)
        {

            bits = i;
            nbit = 0;
            set.clear();

            while (bits)
            {
                if (bits & 1)
                {
                    set.push_back(nums[nbit]);
                }

                bits >>= 1;
                nbit++;
            }

            supset.push_back(set);
        }

        return supset;
    }
};