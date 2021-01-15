class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, int> hash;
        vector<vector<string>> anaSet;

        for (string w : strs)
        {

            string t = w;
            sort(t.begin(), t.end());

            if (hash.find(t) != hash.end())
            {
                anaSet[hash[t]].push_back(w);
            }
            else
            {
                hash[t] = anaSet.size();
                anaSet.push_back(vector<string>{w});
            }
        }

        return anaSet;
    }
};