class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {

        int mul = -1, t = n, d = k;
        vector<int> out;

        out.push_back(t);
        do
        {
            t = t + (mul * d);
            out.push_back(t);
            mul *= -1;

        } while (--d);

        for (int i = n - k - 1; i > 0; i--)
        {
            out.push_back(i);
        }

        return out;
    }
};