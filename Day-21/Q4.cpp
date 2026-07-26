// Topic : Loops

/*
Question :

You are given a number n. You need to find the digital root of n. Digital Root of a number is the recursive sum of its digits until we get a single digit number.

Examples :

Input: n = 1
Output:  1
Explanation: Digital root of 1 is 1

Input: n = 99999
Output: 9
Explanation: Sum of digits of 99999 is 45 which is not a single digit number, hence sum of digit of 45 is 9 which is a single digit number.

Constraints:
1 ≤ n ≤ 107
*/

// solution :

class Solution
{
public:
    int digitalRoot(int n)
    {
        // code here
        while (n >= 10)
        {

            int sum = 0;

            while (n != 0)
            {
                int digit = n % 10;
                sum += digit;
                n = n / 10;
            }

            n = sum;
        }

        return n;
    }
};


/*
Approach:

step 1 : Continue the process until the number becomes a single-digit number (n < 10).

step 2 : For each iteration, initialize a variable sum = 0 to store the sum of the digits.

step 3 : Traverse all the digits of the current number:

step 4 : Extract the last digit using n % 10.
Add the digit to sum.

step 5 : Remove the last digit using n /= 10.
After processing all the digits, assign n = sum.

step 6 : Repeat Steps 2 to 4 until n becomes a single-digit number.

step 7 : Return n, which is the digital root of the original number.

Time Complexity: O((log₁₀ n)²)

Reason:
Each pass processes all the digits of the number, taking O(log₁₀ n) time.
The digit-summing process is repeated a few times until a single-digit number is obtained.
Therefore, the overall worst-case time complexity is O((log₁₀ n)²).

Space Complexity: O(1)

Reason:
Only a constant amount of extra space is used regardless of the input size.
*/