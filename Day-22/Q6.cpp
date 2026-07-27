// Topic : Arrays

/*
Question :

You are given an integer array nums. The unique elements of an array are the elements
 that appear exactly once in the array.

Return the sum of all the unique elements of nums.


Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
Example 3:

Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

// solution :

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int sum = 0;

        for (int i : nums)
            freq[i]++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i]] == 1)
                sum += nums[i];
        }

        return sum;
    }
};

/*
Approach:

step 1 : Create an unordered_map to store the frequency of each element in the array.

step 2 : Traverse the array once and update the frequency of every element.

step 3 : Initialize a variable sum to 0.

step 4 : Traverse the array again:
If the frequency of the current element is 1, it means the element is unique.
Add that element to sum.
After completing the traversal, return sum.
*/