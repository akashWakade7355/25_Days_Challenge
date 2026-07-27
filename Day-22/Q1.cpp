// Topic : Loops

/*
Question :

Given an array arr[] of positive integers. Return true if all the array elements are palindrome otherwise, return false.

Examples:

Input: arr[] = [111, 222, 333, 444, 555]
Output: true
Explanation:
arr[0] = 111, which is a palindrome number.
arr[1] = 222, which is a palindrome number.
arr[2] = 333, which is a palindrome number.
arr[3] = 444, which is a palindrome number.
arr[4] = 555, which is a palindrome number.
As all numbers are palindrome so This will return true.

Input: arr[] = [121, 131, 20]
Output: false
Explanation: 20 is not a palindrome hence the output is false.

Constraints:
1 <=arr.size<= 20
1 <=arr[i]<= 105
*/

// solution :

class Solution
{
public:
    bool isPalinArray(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {

            int newNum = 0;
            int num = arr[i];

            while (num != 0)
            {
                int digit = num % 10;
                newNum = newNum * 10 + digit;
                num = num / 10;
            }

            if (newNum != arr[i])
                return false;
        }

        return true;
    }
};

// TC: 0(NlogM)

// SC:0(1)

/*
Approach:

step 1 : Traverse each element of the array one by one.

step 2 : For every element, store its value in a temporary variable num and initialize another variable newNum = 0 to store its reversed number.

step 3 : Reverse the number:

step 4 : Extract the last digit using num % 10.

step 5 : Append the digit to newNum using:
newNum = newNum * 10 + digit
Remove the last digit from num using num /= 10.
After reversing the number, compare newNum with the original array element.

step 6 : If they are not equal, the number is not a palindrome, so return false.
If all the array elements are palindrome numbers, return true.
*/