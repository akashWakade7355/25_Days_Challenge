// Topic : subarray

/*
Question :
You are given an array, arr[]. Find the minimum index based distance between two different elements
of the array, x and y. Return -1, if either x or y does not exist in the array.

Examples:

Input: arr[] = [1, 2, 3, 2], x = 1, y = 2
Output: 1

Explanation: x = 1 and y = 2. There are two distances between x and y, which are 1 and 3 out of which the least is 1.
Input: arr[] = [86, 39, 90, 67, 84, 66, 62], x = 42, y = 12
Output: -1

Explanation: x = 42 and y = 12. We return -1 as x and y don't exist in the array.
Input: arr[] = [10, 20, 30, 40, 50], x = 10, y = 50

Output: 4
Explanation: The distance between x = 10 (index 0) and y = 50 (index 4) is 4, which is the only distance between them.

Constraints:
1 <= arr.size() <= 105
0 <= arr[i], x, y <= 105
x != y
*/

// solution :

class Solution
{
public:
    int minDist(vector<int> &arr, int x, int y)
    {
        // code here
        int n = arr.size();
        int ans = INT_MAX;

        vector<int> posX;
        vector<int> posY;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                posX.push_back(i);

            if (arr[i] == y)
                posY.push_back(i);
        }

        for (int a : posX)
            for (int b : posY)
                if (abs(a - b) < ans)
                    ans = abs(a - b);

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};


/*
Approach
Step 1: Store the indices of x and y
Traverse the array once.
Whenever x is found, store its index in the posX vector.
Whenever y is found, store its index in the posY vector.

Step 2: Compare every occurrence
Traverse both posX and posY.
For every index of x, compare it with every index of y.
Compute the absolute difference between their indices.

Step 3: Update the minimum distance
Keep a variable ans initialized to INT_MAX.
Update ans whenever a smaller distance is found.

Step 4: Return the answer
If ans is still INT_MAX, it means either x or y does not exist in the array, so return -1.
Otherwise, return ans.

Time Complexity (TC)
Traversing the array
The array is traversed once to store the indices of x and y.

O(n)

Comparing the indices
Let:
m = number of occurrences of x
k = number of occurrences of y
Every index of x is compared with every index of y.

O(m × k)

Overall Time Complexity

O(n + m × k)

Worst Case: O(n²)

Space Complexity (SC)
Two extra vectors are used to store the indices of x and y.

O(m + k)

Worst Case: O(n)
*/