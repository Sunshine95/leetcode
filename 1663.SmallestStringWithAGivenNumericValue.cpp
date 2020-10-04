class Solution
{
public:
    string getSmallestString(int n, int k)
    {

        int d = k - n;
        int nz = d / 25;
        d -= nz * 25;

        string out;

        for (int i = 0; i < n - nz - 1; i++)
            out += 'a';

        if (n - nz)
            out += 'a' + d;

        for (int i = 0; i < nz; i++)
            out += 'z';

        return out;
    }
};