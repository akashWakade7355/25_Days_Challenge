// Topic : Seacrhing

/*
Question :

Given a sorted array arr[] of positive integers. The task is to find the closest value in the array to the given number k. The array may contain duplicate values.
Note: If the difference with k is the same for two values in the array return the greater value.

Examples :

Input:  arr[] = [1, 3, 6, 7], k = 4
Output: 3
Explanation: We have array arr={1, 3, 6, 7} and target is 4. If we look at the absolute difference of target with every element of the array we will get { |1-4|, |3-4|, |6-4|, |7-4| }  = {3, 1, 2, 3}. So, the closest number is 3.

Input: arr[] = [1, 2, 3, 5, 6, 8, 9], k = 4
Output: 5
Explanation: The absolute difference of 4 is 1 from both 3 and 5. According to the question, we have to return greater value, which is 5.

Input: arr[] = [6, 8, 8, 8, 9, 11, 13, 13, 15, 18, 19], k = 10
Output: 11

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k ≤ 109
1 ≤ arr[i] ≤ 109
*/

// solution :

class Solution
{
public:
    int findClosest(vector<int> &arr, int k)
    {

        int n = arr.size();

        if (k <= arr[0])
            return arr[0];

        if (k >= arr[n - 1])
            return arr[n - 1];

        int low = 0;
        int high = n - 1;

        while (low <= high)
        {

            int mid = low + (high - low) / 2;
            if (arr[mid] == k)
                return arr[mid];
            if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        int diff1 = abs(arr[low] - k);
        int diff2 = abs(arr[high] - k);

        if (diff1 < diff2)
            return arr[low];
        else if (diff2 < diff1)
            return arr[high];
        else
            return max(arr[low], arr[high]);
    }
};

/*
# Approach

1. Since the array is sorted, first handle the edge cases:
   - If `k` is smaller than or equal to the first element, return the first element.
   - If `k` is greater than or equal to the last element, return the last element.

2. Perform **Binary Search** to find the position of `k`.
   - If `arr[mid] == k`, return `arr[mid]` immediately since it is the closest value.
   - If `arr[mid] < k`, search in the right half.
   - Otherwise, search in the left half.

3. If the loop ends without finding `k`:
   - `low` points to the **smallest element greater than `k`**.
   - `high` points to the **largest element smaller than `k`**.

4. Compare the absolute differences:
   - `|arr[low] - k|`
   - `|arr[high] - k|`

5. Return:
   - `arr[low]` if it is closer.
   - `arr[high]` if it is closer.
   - If both differences are equal, return the **greater value** as required by the problem.

# Time Complexity

- **Binary Search:** `O(log n)`
- **Overall:** `O(log n)`

# Space Complexity

- **O(1)**

Only a few variables are used, and no extra data structure is required.
*/