class Solution
{

#define MOD 1000000007
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {

        long long int max_sum = 0;
        long long int max_end_at_this = 0;
        long long total = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            long long int temp = (long long int)arr[i];
            max_end_at_this = max(max_end_at_this + temp, temp);
            max_sum = max(max_sum, max_end_at_this);
            total += temp;
        }

        if (k == 1)
            return max_sum;

        for (int i = 0; i < arr.size(); i++)
        {
            long long int temp = (long long int)arr[i];
            max_end_at_this = max(max_end_at_this + temp, temp);
            max_sum = max(max_sum, max_end_at_this);
        }

        // now we have the maximum subarray sum for once concatenated array. If the
        // total is positive, we include all the other k-2 arrays in full.
        // if sum of array is negative, the subarray must span the two

        if (total < 0)
            return max_sum;

        return ((max_sum % MOD) + ((k - 2) * total % MOD)) % MOD;
    }
};