// Topic : subarray

/*
Question :
Given an array arr[], find the sum of all the subarrays of the given array.

Note: It is guaranteed that the total sum will fit within a 32-bit integer range.

Examples:

Input: arr[] = [1, 2, 3]
Output: 20
Explanation: All subarray sums are: [1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6. Thus total sum is 1 + 2 + 3 + 3 + 5 + 6 = 20.
Input: arr[] = [1, 3]

Output: 8
Explanation: All subarray sums are: [1] = 1, [3] = 3, [1, 3] = 4. Thus total sum is 1 + 3 + 4 = 8.

Constraints :
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

// solution :

class Solution
{
public:
    int subarraySum(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i] * (i + 1) * (n - i);
        }

        return sum;
    }
};

/*
Approach:

Step 1: Observe the contribution of each element
Instead of generating every possible subarray, calculate how many subarrays contain each element.
Every element contributes its value to all the subarrays in which it is present.

Step 2: Count the possible starting positions
For an element at index i, the starting index of the subarray can be any index from 0 to i.
Therefore, the number of possible starting positions is:

i + 1

Step 3: Count the possible ending positions
The ending index of the subarray can be any index from i to n - 1.
Therefore, the number of possible ending positions is:

n - i

Step 4: Find the total contribution of the current element
The total number of subarrays containing arr[i] is:

(i + 1) × (n - i)

Hence, the contribution of arr[i] to the final answer is:

arr[i] × (i + 1) × (n - i)

Add this contribution to the final sum.

Step 5: Return the final answer
After processing all the elements, return the accumulated sum.
Time Complexity (TC)
Traversing the array
The array is traversed only once.

Overall Time Complexity

O(n)

Space Complexity (SC)
No extra data structure is used.
Only a few variables are required.

O(1)
*/