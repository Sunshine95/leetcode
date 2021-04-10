class Solution
{
public:
    int countPairs(vector<int> &d)
    {

        unordered_set<int> pow2;
        unordered_map<int, long long int> hash;
        long long int count = 0;

        for (int i = 0; i <= 21; i++)
        {
            pow2.insert(pow(2, i));
        }

        for (int i = 0; i < d.size(); i++)
        {

            if (hash.find(d[i]) == hash.end())
            {
                hash[d[i]] = 1;
            }
            else
            {
                hash[d[i]]++;
            }
        }

        for (auto i : hash)
        {
            for (auto p : pow2)
            {
                if (p < 2 * i.first)
                    continue;

                if (hash.find(p - i.first) != hash.end())
                {
                    if (p - i.first == i.first)
                    {
                        count += ((i.second * (i.second - 1)) / 2);
                    }
                    else
                    {
                        count += (i.second * hash[p - i.first]);
                    }
                }
            }
        }

        return count % 1000000007;
    }
};