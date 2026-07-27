// Topic : Arrays

/*
Question :

You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that
are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.


Example 1:
Input: nums = [3,1,2], k = 1
Output: 2
Explanation:
The elements 1 and 2 each have at least k = 1 element greater than themselves.
​​​​​​​No element is greater than 3. Therefore, the answer is 2.

Example 2:
Input: nums = [5,5,5], k = 2
Output: 0
Explanation:
Since all elements are equal to 5, no element is greater than the other. Therefore, the answer is 0.

Constraints:

1 <= n == nums.length <= 105
1 <= nums[i] <= 109
0 <= k < n
*/

// solution:

class Solution
{
public:
    int countElements(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < n; i++)
            lastIndex[nums[i]] = i;

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            int greater = n - lastIndex[nums[i]] - 1;

            if (greater >= k)
                ans++;
        }

        return ans;
    }
};

// TC:0(logN)

// SC:0(n)

/*
Approach:

step 1 : Sort the given array in ascending order.

step 2 : Create an unordered_map to store the last index of every distinct element in the sorted array.

step 3 : If an element appears multiple times, its entry in the map will always contain its last occurrence.
Traverse the sorted array:

For each element, calculate the number of elements that are strictly greater than it using:

greater = n - lastIndex[element] - 1;
If greater >= k, then the current element is qualified, so increment the answer.
Return the total count of qualified elements.
*/

