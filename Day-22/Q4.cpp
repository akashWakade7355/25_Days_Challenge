// Topic : Arrays

/*
Question :

You are given a sorted array arr[] that may contain duplicate elements. Your task is to find the
index of the last occurrence of any duplicate element and return the index along with the value of
that element. If no duplicate element is found, return [-1, -1].

Examples :

Input: arr[] = [1, 5, 5, 6, 6, 7]
Output: [4, 6]
Explanation: Last duplicate element is 6 having index 4.

Input: arr[] = [1, 2, 3, 4, 5]
Output: [-1, -1]
Explanation: No duplicate elements are present in the array.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/

// solution :

class Solution
{
public:
    vector<int> dupLastIndex(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int i : arr)
            freq[i]++;

        for (int i = n - 1; i >= 0; i--)
            if (freq[arr[i]] > 1)
            {

                ans.push_back(i);
                ans.push_back(arr[i]);
                return ans;
            }

        return {-1, -1};
    }
};

// TC:0(n)

//SC:0(n)

/*
Apprach :

step 1 : Create an unordered_map to store the frequency of each element in the array.

step 2 : Traverse the array once and count the frequency of every element.

step 3 : Traverse the array from right to left:
For each element, check if its frequency is greater than 1.
The first such element encountered is the last duplicate element in the array.

step 4 : Return its index and value as {index, value}.
If no element with frequency greater than 1 is found after the traversal, return {-1, -1}.
*/