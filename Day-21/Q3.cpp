// Loops

/*
Question :
You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371.

Examples:

Input: n = 153
Output: true
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153.

Input: n = 372
Output: false
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378.

Input: n = 100
Output: false
Explanation: 100 is not an Armstrong number since 13 + 03 + 03 = 1.

Constraints:
100 ≤ n <1000
*/

// solution :

class Solution
{
public:
    bool armstrongNumber(int n)
    {
        // code here
        int num = n;

        int newNum = 0;

        while (n != 0)
        {
            int digit = n % 10;
            newNum += digit * digit * digit;
            n = n / 10;
        }

        return num == newNum;
    }
};

/*
Approach:

step 1 :Store the original number in a variable num so that it can be compared later.

step 2 : Initialize a variable newNum = 0 to store the sum of the cubes of the digits.

step 3 : Traverse the digits of the number until it becomes 0.

step 4 :Extract the last digit using n % 10.

step 5 :Find the cube of the digit (digit × digit × digit) and add it to newNum.

step 6 : Remove the last digit from the number using n /= 10.
After processing all the digits, compare newNum with the original number num.
If both are equal, return true because the number is an Armstrong number; otherwise, return false.

Time Complexity: O(log₁₀ n)

Reason:
Each iteration processes one digit of the number.
A number with d digits requires d iterations.

Space Complexity: O(1)

Reason:
Only a constant amount of extra space is used regardless of the input size.
*/