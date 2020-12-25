class Solution
{
public:
    int rob(vector<int> &nums)
    {

        int i, temp;
        int localmax[2] = {0, 0};

        for (i = 0; i < nums.size(); i++)
        {

            temp = localmax[1];
            localmax[1] = max(localmax[1], localmax[0] + nums[i]);
            localmax[0] = temp;
        }

        return max(localmax[0], localmax[1]);
    }
};