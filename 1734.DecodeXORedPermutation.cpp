class Solution
{
public:
    vector<int> decode(vector<int> &encoded)
    {

        int n = encoded.size() + 1;
        vector<int> perm;

        int x = 0;
        for (int i = 1; i <= n; i++)
            x ^= i;

        for (int i = 1; i < n - 1; i += 2)
            x ^= encoded[i];

        perm.push_back(x);
        for (int i = 1; i < n; i++)
            perm.push_back(encoded[i - 1] ^ perm[i - 1]);

        return perm;
    }
};