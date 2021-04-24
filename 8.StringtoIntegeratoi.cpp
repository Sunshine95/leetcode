class Solution
{
public:
    int myAtoi(string str)
    {

        long int x = 0;

        if (!str.size())
            return x;

        int i = 0;
        int nflag = 1;

        while (isspace(str[i]))
        {
            i++;
        }

        if (str[i] == '-')
        {
            nflag = -1;
            i++;
        }
        else if (str[i] == '+')
        {
            nflag = 1;
            i++;
        }

        int start = i;

        while (isdigit(str[i]))
        {
            i++;
        }

        int end = i;

        string num(str.begin() + start, str.begin() + end);

        if (!num.size())
            return x;

        stringstream temp(num);
        temp >> x;
        x *= nflag;

        if (x < -2147483648)
        {
            return -2147483648;
        }
        else if (x > 2147483647)
        {
            return 2147483647;
        }

        return x;
    }
};