class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {

        int n = nums.size();
        if (n < 3)
            return false;

        int one = INT_MAX;
        int two = INT_MAX;

        for (int i : nums)
        {

            if (i <= one)
            {
                one = i;
            }
            else if (one < i && i <= two)
            {
                two = i;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};