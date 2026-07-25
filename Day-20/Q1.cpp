// Topic : subarray

/*
Question :

You are given an integer array nums. The range of a subarray of nums is
the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:

Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.


Constraints:

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/

// solution :

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int max = nums[i];
            int min = nums[i];
            for (int j = i; j < n; j++)
            {

                if (nums[j] > max)
                    max = nums[j];

                if (nums[j] < min)
                    min = nums[j];

                sum += max - min;
            }
        }

        return sum;
    }
};


/*
# Approach (Brute Force with Running Maximum and Minimum)

### Step 1: Generate all possible subarrays
- Use two nested loops.
- The outer loop (`i`) represents the starting index of the subarray.
- The inner loop (`j`) extends the subarray from index `i` to `n - 1`.


### Step 2: Initialize the maximum and minimum
- For every new starting index `i`, initialize:
  - maxi = nums[i]
  - mini = nums[i]
- Initially, the subarray contains only one element, so both the maximum and minimum are the same.

### Step 3: Extend the subarray and update values
- As the inner loop extends the subarray by one element at a time:
  - Update the maximum element if the current element is greater.
  - Update the minimum element if the current element is smaller.

maxi = max(maxi, nums[j]);
mini = min(mini, nums[j]);


### Step 4: Calculate the range
- The range of the current subarray is:

Range = Maximum Element - Minimum Element

- Add this range to the final answer.

sum += (maxi - mini);


### Step 5: Repeat for all starting indices
- Repeat the above process for every possible starting index.
- After processing all subarrays, return the accumulated sum.

# Time Complexity (TC)

### Outer Loop
- Runs for every starting index.

O(n)

### Inner Loop
- Extends the subarray from the current starting index to the end of the array.

O(n)

### Overall Time Complexity

O(n × n) = O(n²)

# Space Complexity (SC)

- Only a few extra variables are used:
  - max
  - min
  - sum

- No extra array or data structure is used.

O(1)


# Summary

- **Approach:** Generate all possible subarrays using two nested loops while maintaining 
the current maximum and minimum values.
- **Time Complexity:** **O(n²)**
- **Space Complexity:** **O(1)**
*/