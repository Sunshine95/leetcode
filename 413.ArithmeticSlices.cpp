class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {

        int n = A.size();

        if (n < 3)
            return 0;

        vector<int> diff(n);
        int len = 0;
        int count = 0;
        int c;

        diff[0] = 0;
        for (int i = 1; i < n; i++)
        {
            diff[i] = A[i] - A[i - 1];
        }

        len = 2;
        c = diff[1];
        for (int i = 2; i < n; i++)
        {
            if (diff[i] == c)
            {
                len++;
            }
            else
            {
                c = diff[i];
                if (len >= 3)
                {
                    count += (((len - 2) * (len - 1)) / 2);
                }
                len = 2;
            }
        }

        if (len >= 3)
        {
            count += (((len - 2) * (len - 1)) / 2);
        }

        return count;
    }
};