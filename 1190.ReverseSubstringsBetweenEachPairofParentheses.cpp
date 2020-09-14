class Solution
{
public:
    string reverseParentheses(string s)
    {

        string out;
        stack<char> sub;
        int brackt = 0;

        for (char ch : s)
        {

            if (ch == '(')
                brackt++;

            if (!brackt)
            {
                out += ch;
                continue;
            }

            if (ch != ')')
            {
                sub.push(ch);
                continue;
            }

            string temp = "";
            while (!sub.empty() && sub.top() != '(')
            {
                temp += sub.top();
                sub.pop();
            }
            sub.pop();
            brackt--;

            if (!brackt)
            {
                out += temp;
            }
            else
            {
                for (char t : temp)
                {
                    sub.push(t);
                }
            }
        }

        return out;
    }
};