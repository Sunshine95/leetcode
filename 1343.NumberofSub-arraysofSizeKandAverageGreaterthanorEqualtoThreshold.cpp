class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold)
    {

        int sum = 0, avg, i;
        int count = 0;

        // window creating
        for (i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        avg = sum / k;

        if (avg >= threshold)
            count++;

        for (; i < arr.size(); i++)
        {
            sum += arr[i];
            sum -= arr[i - k];
            avg = sum / k;

            if (avg >= threshold)
                count++;
        }

        return count;
    }
};