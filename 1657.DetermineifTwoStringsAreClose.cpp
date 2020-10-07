class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        if (word1.size() != word2.size())
            return false;
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for (int i = 0; i < word1.size(); i++)
        {
            hash1[word1[i] - 'a']++;
            hash2[word2[i] - 'a']++;
        }

        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for (int j = 0; j < 26; j++)
        {

            if (hash1[j] && !hash2[j] || !hash1[j] && hash2[j])
                return false;

            if (map1.find(hash1[j]) == map1.end())
                map1[hash1[j]] = 1;
            else
                map1[hash1[j]]++;

            if (map2.find(hash2[j]) == map2.end())
                map2[hash2[j]] = 1;
            else
                map2[hash2[j]]++;
        }

        return map1 == map2;
    }
};