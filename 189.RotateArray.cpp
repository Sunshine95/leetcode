class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();

        if (k == 0 || n == 1)
        {
            return;
        }

        int NOC = __gcd(n, k);

        int p;
        int q = -1;

        for (int i = 0; i < NOC; i++)
        {

            p = i;
            int s = nums[p];

            while (q != i)
            {

                q = (p + k) % n;
                int t = nums[q];
                nums[q] = s;
                s = t;

                p = q;
            }
        }

        return;
    }
};