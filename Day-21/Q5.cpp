// Topic : Loops

/*
Question :

Given a number N. Check if it is perfect or not. A number is perfect if sum of factorial of its digit is equal to the given number.

Example 1:

Input: N = 23
Output: 0
Explanation: The sum of factorials of
digits of 23 is 2! + 3! = 2 + 6 = 8
which is not equal to 23. Thus, answer
is 0.

Example 2:

Input: N = 145
Output: 1
Explanation: The sum of factorials of digits
of 145 is 1! + 4! + 5! = 1 + 24 + 120 = 145
which is equal to 145.Thus, answer is 1.

Your Task:
You don't need to read input or print anything.Your task is to complete the function isPerfect() which takes a number N as input parameter and returns 1 if N is perfect.Otherwise, it returns 0.

Expected Time Complexity: O(Log10N)
Expected Auxillary Space: O(constant)

Constraints:
1<=N<=109

*/

// solution :

class Solution
{
public:
    int isPerfect(int N)
    {
        // code here

        int originalNum = N;
        vector<int> factVector;
        int start = 1;

        factVector.push_back(1);

        for (int i = 1; i <= 9; i++)
        {
            start = start * i;
            factVector.push_back(start);
        }

        int factSum = 0;

        while (N != 0)
        {
            int digit = N % 10;
            factSum += factVector[digit];
            N = N / 10;
        }

        if (originalNum == factSum)
            return 1;
        else
            return 0;
    }
};

// TC:0(logn)

// SC:0(1)

/*
Approach:

step 1 : Store the original number in a variable originalNum for comparison at the end.

step 2 : Precompute the factorials of digits from 0 to 9 and store them in a vector.

step 3 : Since every digit of a number lies between 0 and 9, factorials only need to be computed once.

step 4 : Initialize a variable factSum = 0 to store the sum of the factorials of the digits.

step 5 : Traverse all the digits of the number:

step 6 : Extract the last digit using N % 10.

step 7 : Add the precomputed factorial of the digit to factSum.
Remove the last digit using N /= 10.

step 8 : After processing all the digits, compare factSum with originalNum.
If both are equal, return 1 because the number is a perfect number; otherwise, return 0.
*/