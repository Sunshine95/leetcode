class Solution
{
public:
    int maxArea(vector<int> &height)
    {

        int left = 0;
        int right = height.size() - 1;
        int area = min(height[left], height[right]) * (right - left);
        int max_area = area;

        while (left < right)
        {

            int temp;
            if (height[left] <= height[right])
            {

                temp = left;
                while (temp < right && height[temp] <= height[left])
                {
                    temp++;
                }

                left = temp;
                area = min(height[left], height[right]) * (right - left);
                max_area = max(area, max_area);
                cout << area;
            }

            if (height[right] <= height[left])
            {

                temp = right;
                while (temp > left && height[temp] <= height[right])
                {
                    temp--;
                }

                right = temp;
                area = min(height[left], height[right]) * (right - left);
                max_area = max(area, max_area);
            }
        }

        return max_area;
    }
};