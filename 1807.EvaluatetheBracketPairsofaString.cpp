class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {

        unordered_map<string, string> hash;
        int key = 0, value = 1;

        for (int i = 0; i < knowledge.size(); i++)
        {
            hash[knowledge[i][key]] = knowledge[i][value];
        }

        string temp = "";
        string replace = "";
        string answer = "";

        bool flag = false;

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == '(')
            {
                flag = true;
                continue;
            }
            else if (s[i] == ')')
            {

                flag = false;

                if (hash.find(temp) != hash.end())
                {
                    replace = hash[temp];
                }
                else
                {
                    replace = "?";
                }

                answer += replace;
                temp = "";
                continue;
            }

            if (flag)
            {
                temp += s[i];
            }
            else
            {
                answer += s[i];
            }
        }
        return answer;
    }
};