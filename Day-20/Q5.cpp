// Topic : subarray

/*
Question :
Given an array arr[], find the sub-array containing at least one number which has the minimum sum
and return its sum.

Examples :

Input: arr[] = {3,-4, 2,-3,-1, 7,-5}
Output: -6
Explanation: The subarray is {-4,2,-3,-1} = -6

Input: arr[] = {2, 6, 8, 1, 4}
Output: 1
Explanation: The sub-array is {1} = 1

Constraints:
1 ≤ N ≤ 106
-107 ≤ A[i] ≤ 107
*/

// solution :

class Solution
{
public:
    int smallestSumSubarray(vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        int currentSum = 0;
        int minSum = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            currentSum += arr[i];
            minSum = min(currentSum, minSum);

            if (currentSum > 0)
                currentSum = 0;
        }

        return minSum;
    }
};

/*
Approach (Modified Kadane's Algorithm)

Step 1: Initialize two variables
Initialize currentSum to 0 to store the sum of the current subarray.
Initialize minSum to INT_MAX to store the minimum subarray sum found so far.

Step 2: Traverse the array
Iterate through each element of the array.
Add the current element to currentSum.

Step 3: Update the minimum sum
Compare currentSum with minSum.
If currentSum is smaller than minSum, update minSum.

Step 4: Reset the current sum if it becomes positive
If currentSum becomes positive, reset it to 0.
A positive running sum cannot help in obtaining a smaller subarray sum in the future, so it is discarded and a new subarray is started from the next element.

Step 5: Return the answer
After traversing the entire array, minSum stores the minimum subarray sum.
Return minSum.

Overall Time Complexity : 0(n)

Space Complexity (SC) : 0(1)


O(1)
*/