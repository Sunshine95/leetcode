class Solution
{
public:
    string reverseWords(string s)
    {

        stack<string> pile;
        string ans, temp;
        int n = s.size();

        for (int i = 0; i < n;)
        {
            while (i < n && s[i] == ' ')
            {
                i++;
            }

            while (i < n && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }

            if (temp.size() != 0)
            {
                pile.push(temp);
                temp.clear();
            }
        }

        while (!pile.empty())
        {
            ans += pile.top();
            pile.pop();
            ans += " ";
        }
        ans.pop_back();

        return ans;
    }
};