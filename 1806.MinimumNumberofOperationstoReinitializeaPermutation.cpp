class Solution
{
public:
    int reinitializePermutation(int n)
    {

        int out = 0, i = 1;
        while (out == 0 || i > 1)
        {
            i = (i * 2) % (n - 1);
            out++;
        }
        return out;
    }
};