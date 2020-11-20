class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {

        int score = 0;
        int fisecounter = 0;
        int seficounter = 0;
        char fi, se;
        int gr, sm;

        if (x > y)
        {
            fi = 'a';
            se = 'b';
            gr = x;
            sm = y;
        }
        else
        {
            fi = 'b';
            se = 'a';
            gr = y;
            sm = x;
        }

        for (int i = 0; i < s.size(); i++)
        {

            if (s[i] == fi)
            {
                fisecounter++;
            }
            else if (s[i] == se)
            {
                if (fisecounter > 0)
                {
                    score += gr;
                    fisecounter--;
                }
                else
                {
                    seficounter++;
                }
            }
            else
            {
                score += (min(seficounter, fisecounter) * sm);
                fisecounter = seficounter = 0;
            }
        }

        score += (min(seficounter, fisecounter) * sm);
        fisecounter = seficounter = 0;

        return score;
    }
};