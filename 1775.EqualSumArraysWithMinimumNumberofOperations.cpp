class Solution
{
public:
    int minOperations(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int sum1 = 0;
        int sum2 = 0;

        int bucket1[6] = {0};
        int bucket2[6] = {0};

        for (int i = 0; i < n1; i++)
        {
            bucket1[nums1[i] - 1]++;
            sum1 += nums1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            bucket2[nums2[i] - 1]++;
            sum2 += nums2[i];
        }

        int *large = sum1 >= sum2 ? bucket1 : bucket2;
        int *small = sum1 >= sum2 ? bucket2 : bucket1;

        int count = 0;
        double diff = abs(sum1 - sum2);

        int i, j, n;
        for (i = 5, j = 0; i >= 1; i--, j++)
        {

            n = large[i] + small[j];

            if ((diff / i) <= n)
            {
                return count + ceil(diff / i);
            }
            else
            {
                diff = diff - (n * i);
                count += n;
            }
        }

        return -1;
    }
};