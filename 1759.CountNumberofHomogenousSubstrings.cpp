class Solution
{
public:
#define MOD 1000000007
    int countHomogenous(string s)
    {

        string::iterator it = s.begin();

        char c;
        long long int count;
        long long int sum = 0;

        while (it != s.end())
        {

            c = *it;
            count = 0;

            while (c == *it)
            {
                count++;
                it++;

                if (it == s.end())
                    break;
            }

            sum = (sum + (count * (count + 1)) / 2) % MOD;
        }

        return sum;
    }
};