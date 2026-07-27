// Topic : Arrays

/*
Question :

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
*/

// solution :

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int low = 0;
        int high = n - 1;

        while (high >= low)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }

        low = 0;
        high = k - 1;

        while (high >= low)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }

        low = k;
        high = n - 1;

        while (high >= low)
        {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
};

// TC:0(n)

// SC: 0(1)

/*
Approach:

step 1 : Find the size of the array n.

Since rotating the array by n positions gives the same array, update:

k = k % n;

step 2 : Reverse the entire array.

step 3 : Reverse the first k elements.

step 4 : Reverse the remaining n - k elements.

step 5 : The array is now rotated to the right by k positions.
*/