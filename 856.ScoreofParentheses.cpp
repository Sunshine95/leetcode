class Solution
{
public:
    int scoreOfParentheses(string S)
    {

        int n = S.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (S[i] == ')')
            {
                if (st.top() == -1)
                {
                    st.pop();
                    st.push(1);
                }
                else
                {
                    int temp = 0;
                    while (!st.empty() && st.top() != -1)
                    {
                        temp += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(temp * 2);
                }
            }
            else
            {
                st.push(-1);
            }
        }

        int out = 0;
        while (!st.empty())
        {
            out += st.top();
            st.pop();
        }

        return out;
    }
};