class Solution
{
public:
    vector<int> minOperations(string boxes)
    {

        int n = boxes.size();
        int counter;

        vector<int> moves_left(n);
        vector<int> moves_right(n);

        moves_left[0] = 0;
        counter = boxes[0] - '0';
        for (int i = 1; i < n; i++)
        {
            moves_left[i] = moves_left[i - 1] + counter;
            if (boxes[i] - '0' == 1)
            {
                counter++;
            }
        }

        moves_right[n - 1] = 0;
        counter = boxes[n - 1] - '0';
        for (int i = n - 2; i >= 0; i--)
        {
            moves_right[i] = moves_right[i + 1] + counter;
            if (boxes[i] - '0' == 1)
            {
                counter++;
            }
        }

        vector<int> moves(n);
        for (int i = 0; i < n; i++)
        {
            moves[i] = moves_left[i] + moves_right[i];
        }

        return moves;
    }
};