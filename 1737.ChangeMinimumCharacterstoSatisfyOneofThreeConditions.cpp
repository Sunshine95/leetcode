class Solution
{
public:
    int minCharacters(string a, string b)
    {

        vector<int> hashA(26, 0);
        vector<int> hashB(26, 0);

        int lenA = a.size();
        int lenB = b.size();

        for (int i = 0; i < a.size(); i++)
        {
            hashA[a[i] - 'a']++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            hashB[b[i] - 'a']++;
        }

        int ans = lenA + lenB + 1;
        for (int c = 0; c < 26; c++)
        {
            ans = min(ans, ((lenA - hashA[c]) + (lenB - hashB[c]))); // op3

            if (c > 0)
            {
                hashA[c] += hashA[c - 1];
                hashB[c] += hashB[c - 1];
            }

            if (c == 25)
                continue; //except z!

            ans = min(ans, lenA - hashA[c] + hashB[c]); //op1
            ans = min(ans, lenB - hashB[c] + hashA[c]); //op2
        }

        return ans;
    }
};