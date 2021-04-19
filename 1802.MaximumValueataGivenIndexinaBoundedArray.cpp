class Solution
{
public:
    int maxValue(int n, int index, int maxSum)
    {

        long long int k, sum;

        int l = 1, r = maxSum;
        int parts[2] = {index, n - 1 - index};

        while (l < r)
        {

            k = l + (r - l + 1) / 2;
            sum = k;

            for (int len : parts)
            {

                if (k < len + 1)
                {
                    sum = sum + ((k * (k - 1)) / 2) + (len - (k - 1));
                }
                else if (k == len + 1)
                {
                    sum = sum + (k * (k - 1)) / 2;
                }
                else
                {
                    sum = sum + ((len * ((2 * k) - len - 1)) / 2);
                }
            }

            if (sum > maxSum)
            {
                r = k - 1;
            }
            else
            {
                l = k;
            }
        }

        k = l + (r - l + 1) / 2;
        return k;
    }
};