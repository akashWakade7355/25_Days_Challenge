// Topoc : searching

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

// solution

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
Approach:

1. Create a copy of the given array and sort it.
   - The sorted array represents the target position of every element.

2. Store the index of every element in the sorted array using a HashMap.
   - The key will be the array element.
   - The value will be its index in the sorted array.

3. Traverse the original array.
   - For each element, find its correct position in the sorted array
     using the HashMap.
   - Calculate the absolute difference between its current index
     and its sorted index.

4. Check the distance of every element.
   - If the distance of any element is greater than k,
     then the array is not k-sorted, so return "No".

5. If every element is at most k positions away from its
   correct sorted position, then the array is k-sorted.
   Return "Yes".

*/