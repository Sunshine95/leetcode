class Solution
{
public:
    void reverse(stack<pair<char, int>> &s, string &out)
    {

        if (s.empty())
            return;

        char temp = s.top().first;
        s.pop();
        reverse(s, out);
        out += temp;

        return;
    }

    string removeDuplicates(string s, int k)
    {

        stack<pair<char, int>> apilar;

        for (int i = 0; i < s.size(); i++)
        {

            pair<char, int> temp = make_pair(s[i], 1);

            if (apilar.empty() || apilar.top().first != temp.first)
            {
                ;
            }
            else
            {
                temp.second = apilar.top().second + 1;
            }

            apilar.push(temp);
            if (apilar.top().second == k)
            {
                for (int j = 0; j < k; j++)
                    apilar.pop();
            }
        }

        string out;
        reverse(apilar, out);

        return out;
    }
};