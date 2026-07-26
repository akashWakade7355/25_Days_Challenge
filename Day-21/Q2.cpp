// Topic : Loops

/*
Question :
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1
*/

// solution :

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf)
        {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // For even number of digits:
        // x == reversedHalf
        //
        // For odd number of digits:
        // x == reversedHalf / 10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

/*
Approach:

step 1 :If the number is negative, return false because negative numbers cannot be palindromes due to the - sign.

step 2 : If the number ends with 0 but is not 0 itself, return false because a palindrome cannot start with 0.

step 3 :
Initialize a variable reversedHalf = 0 to store the reversed second half of the number.

step 4 : Reverse the digits of the number one by one until reversedHalf becomes greater than or equal to the remaining part of the original number.
Extract the last digit using x % 10.

step 5 :Append the digit to reversedHalf using:
reversedHalf = reversedHalf * 10 + digit

step 6 : Remove the last digit from x using:
x /= 10
After the loop:
Even number of digits: Check if x == reversedHalf.
Odd number of digits: Ignore the middle digit by comparing x == reversedHalf / 10.
If either condition is true, return true; otherwise, return false.

Time Complexity

O(log₁₀ n)

Reason:
Only half of the digits of the number are processed.
Since the number of digits is proportional to log₁₀ n, the overall time complexity is O(log₁₀ n).

Space Complexity:

O(1)
*/