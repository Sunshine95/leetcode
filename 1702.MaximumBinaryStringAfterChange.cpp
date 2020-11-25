class Solution
{
public:
    string maximumBinaryString(string binary)
    {

        string t;
        int n = binary.size();
        int nzeros = 0;

        // do not touch this part of string
        int i = 0;
        while (i < n && binary[i] == '1')
        {
            t += '1';
            i++;
        }

        for (int j = i; j < n; j++)
        {
            if (binary[j] == '0')
            {
                nzeros++;
            }
        }

        for (int j = 0; j < nzeros - 1; j++)
            t += '1';

        if (nzeros)
            t += '0';

        for (int j = t.size(); j < n; j++)
            t += '1';

        return t;
    }
};