class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        int n = s.size();
        if ((n - k) + 1 < pow(2, k))
            return false;

        vector<bool> hash(pow(2, k), false);

        for (int i = 0; i + (k - 1) < n; i++)
        {
            hash[stoi(s.substr(i, k), nullptr, 2)] = true;
        }

        for (bool b : hash)
        {
            if (!b)
            {
                return b;
            }
        }
        return true;
    }
};