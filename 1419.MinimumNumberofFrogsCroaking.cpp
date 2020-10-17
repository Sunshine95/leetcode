class Solution
{
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {

        vector<int> frogAt{0, 0, 0, 0, 0}; //croak
        int At;
        bool found;

        for (int i = 0; i < croakOfFrogs.size(); i++)
        {

            char c = croakOfFrogs[i];

            switch (c)
            {
            case 'c':
                At = 0;
                break;
            case 'r':
                At = 1;
                break;
            case 'o':
                At = 2;
                break;
            case 'a':
                At = 3;
                break;
            case 'k':
                At = 4;
                break;
            default:
                return -1;
            }

            if (frogAt[At] >= 1)
            {
                frogAt[At]--;
                frogAt[(At + 1) % 5]++;
            }
            else if (At == 0)
            {
                frogAt[1]++;
            }
            else
            {
                return -1;
            }
        }

        for (int j = 1; j < 5; j++)
        {
            if (frogAt[j] != 0)
            {
                return -1;
            }
        }

        return frogAt[0];
    }
};