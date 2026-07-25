// subarrays

/*
Question :

Given an integer array nums, find the subarray with the largest sum, and return its sum.


Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// solution :

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int n = nums.size();
        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {

            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};

/*
Approach (Kadane's Algorithm)

\Step 1: Initialize two variables
Initialize currentSum to 0 to store the sum of the current subarray.
Initialize maxSum to INT_MIN to store the maximum subarray sum found so far.

Step 2: Traverse the array
Iterate through each element of the array.
Add the current element to currentSum.

Step 3: Update the maximum sum
Compare currentSum with maxSum.
If currentSum is greater than maxSum, update maxSum.

Step 4: Reset the current sum if it becomes negative
If currentSum becomes negative, reset it to 0.
A negative running sum cannot increase the sum of any future subarray, so it is discarded and a new subarray is started from the next element.

Step 5: Return the answer
After traversing the entire array, maxSum stores the maximum subarray sum.
Return maxSum.
Time Complexity (TC)
Traversing the array
The array is traversed only once.

Overall Time Complexity

O(n)

Space Complexity (SC)
Only two extra variables (currentSum and maxSum) are used.
No additional data structure is required.

O(1)
*/