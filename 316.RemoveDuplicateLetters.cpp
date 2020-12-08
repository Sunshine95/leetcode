class Solution
{
public:
    string removeDuplicateLetters(string s)
    {

        vector<int> hash(26, 0);
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++)
            hash[s[i] - 'a']++;

        string out = "";
        for (char c : s)
        {

            if (visited[c - 'a'])
            {
                hash[c - 'a']--;
                continue;
            }

            while (!out.empty() && hash[out.back() - 'a'] && out.back() > c)
            {
                visited[out.back() - 'a'] = false;
                out.pop_back();
            }

            out += c;
            hash[c - 'a']--;
            visited[c - 'a'] = true;
        }

        return out;
    }
};