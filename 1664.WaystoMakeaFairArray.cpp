class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {

        if (nums.size() == 1)
            return 1;

        vector<int> prefixEve;
        vector<int> prefixOdd;

        int count = 0;
        int sumEve, sumOdd;

        prefixEve.push_back(nums[0]);
        prefixOdd.push_back(nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            if (i & 1)
                prefixOdd.push_back(prefixOdd.back() + nums[i]);
            else
                prefixEve.push_back(prefixEve.back() + nums[i]);
        }

        if (prefixEve.back() - nums[0] == prefixOdd.back())
            count++;
        if (prefixOdd.back() - nums[1] + nums[0] == prefixEve.back() - nums[0])
            count++;

        for (int i = 2; i < nums.size(); i += 2)
        {

            sumEve = prefixEve[(i / 2) - 1] + (prefixOdd.back() - prefixOdd[i / 2 - 1]);
            sumOdd = prefixOdd[(i / 2) - 1] + (prefixEve.back() - prefixEve[i / 2]);

            if (sumEve == sumOdd)
                count++;
        }

        for (int i = 3; i < nums.size(); i += 2)
        {

            sumEve = prefixEve[i / 2] + (prefixOdd.back() - prefixOdd[i / 2]);
            sumOdd = prefixOdd[(i / 2) - 1] + (prefixEve.back() - prefixEve[i / 2]);

            if (sumEve == sumOdd)
                count++;
        }

        return count;
    }
};