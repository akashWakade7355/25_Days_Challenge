// Loops

/*
Question :
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes
the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


Constraints:

-231 <= x <= 231 - 1
*/

// solution :

class Solution
{
public:
    int reverse(int x)
    {
        int newNum = 0;
        while (x != 0)
        {
            int digit = x % 10;

            // overflow in positive direction
            if (newNum > INT_MAX / 10)
                return 0;

            if (newNum == INT_MAX / 10 && digit > 7)
                return 0;

            // overflow in negative direction

            if (newNum < INT_MIN / 10)
                return 0;

            if (newNum == INT_MIN / 10 && digit < -8)
                return 0;

            newNum = newNum * 10 + digit;
            x = x / 10;
        }

        return newNum;
    }
};


/*
Approach
step 1 : Initialize a variable newNum = 0 to store the reversed number.

step 2 : Traverse the number until it becomes 0.

step 3 :Extract the last digit using the modulus operator:
digit = x % 10
Before appending the digit, check for integer overflow:
If newNum > INT_MAX / 10, reversing will exceed the maximum 32-bit integer limit, so return 0.
If newNum == INT_MAX / 10 and digit > 7, appending the digit will overflow, so return 0.
If newNum < INT_MIN / 10, reversing will exceed the minimum 32-bit integer limit, so return 0.
If newNum == INT_MIN / 10 and digit < -8, appending the digit will underflow, so return 0.

step 4 : Append the extracted digit to the reversed number:

step 5 : Multiply newNum by 10 and add the extracted digit.

step 6 : Remove the last digit from the original number by dividing it by 10.

step 7 : Repeat Steps 3 to 6 until the original number becomes 0.

step 8 : Return newNum as the reversed integer.

Time Complexity

O(log₁₀ |x|)

Reason:

In each iteration, one digit of the number is processed.
A number with d digits requires d iterations.

Space Complexity.
O(1)

Reason:
*/