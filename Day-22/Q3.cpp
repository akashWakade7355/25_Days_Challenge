// Topic : Arrays

/*
Question :
Given an array arr[] of integers, find and return the elements with even occurrences in the array.
If no such element exists, return -1. Elements should be returned in order of occurrence.

Examples:

Input: arr[] = [9, 12, 23, 10, 12, 12, 15, 23, 14, 12, 15]
Output: [12, 15, 23]
Explanation: The numbers 12, 15, and 23 each appear an even number of times.

Input: arr[] = [23, 12, 56, 34, 32]
Output: [-1]
Explanation: Every number in the array occurs an odd number of times.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 105
*/

// solution :

class Solution
{
public:
    vector<int> findEvenOccurrences(vector<int> &arr)
    {
        // code here
        unordered_map<int, int> freq;
        unordered_set<int> visited;
        vector<int> ans;

        for (int i : arr)
            freq[i]++;

        for (int i = 0; i < arr.size(); i++)
        {

            if (freq[arr[i]] % 2 == 0 && visited.find(arr[i]) == visited.end())
            {
                ans.push_back(arr[i]);
                visited.insert(arr[i]);
            }
        }

        if (ans.empty())
            return {-1};

        return ans;
    }
};

// TC:0(n)

// SC:0(n)

/*
Approach:

step 1 : Create an unordered_map to store the frequency of each element in the array.

step 2 : Traverse the array once and update the frequency of every element.

step 3 : Create an unordered_set named visited to keep track of elements that have already been added to the answer.

step 4 : Traverse the array again:
Check if the frequency of the current element is even.
Also check that the element has not already been added to the answer using the visited set.
If both conditions are satisfied:
Add the element to the answer vector.
Mark it as visited.

steo 5 : After the traversal:
If the answer vector is empty, return {-1}.
Otherwise, return the answer vector.
*/