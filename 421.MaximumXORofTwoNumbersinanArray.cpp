class Solution
{
public:
    struct TrieNode
    {
        TrieNode *bit[2] = {NULL, NULL};
    };

    void insert(int l, TrieNode *root)
    {

        for (int i = 31; i >= 0; i--)
        {

            int b = (l >> i) & 1;

            if (root->bit[b] == NULL)
            {
                root->bit[b] = new TrieNode();
            }

            root = root->bit[b];
        }

        return;
    }

    int findMaximumXOR(vector<int> &nums)
    {

        TrieNode *root = new TrieNode();

        for (int i = 0; i < nums.size(); i++)
        {
            insert(nums[i], root);
        }

        // find max XOR for each number

        long int maxXOR = -1;
        for (int j = 0; j < nums.size(); j++)
        {

            TrieNode *temp = root;
            int l = nums[j];
            long int m = 0;

            for (int i = 31; i >= 0; i--)
            {

                int b = (l >> i) & 1;

                if (temp->bit[!b] != NULL)
                {
                    temp = temp->bit[!b];
                    m += (1 << i);
                }
                else
                {
                    temp = temp->bit[b];
                }
            }

            maxXOR = max(maxXOR, m);
        }

        return maxXOR;
    }
};