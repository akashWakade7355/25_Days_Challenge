// Topic : Loops

/*
Question :
Given an integer n, find all Pronic Numbers less than or equal to n. A Pronic Number is a number that can be expressed as the product of two consecutive integers, i.e., i × (i + 1) for some non-negative integer i. Return all such Pronic Numbers in increasing order.

Examples:

Input: n = 6
Output: 0 2 6

Explanation: 0 is the product of 0 and 1. 2 is the product of 1 and 2. 6 is the product of 2 and 3.

Input: n = 56
Output: 0 2 6 12 20 30 42 56

Explanation:
0 is the product of 0 and 1.
2 is the product of 1 and 2.
6 is the product of 2 and 3.
12 is the product of 3 and 4. and so on.

Constraints:
0 ≤ n ≤ 109
*/

// solution :

class Solution
{
public:
    vector<int> pronicNumbers(int n)
    {
        // code here
        vector<int> pronic;

        int i = 0;

        while (i * (i + 1) <= n)
        {
            pronic.push_back(i * (i + 1));
            i++;
        }

        return pronic;
    }
};

// TC:0(sqrt(n))

// SC:0(1)

/*
 
Approach:

step 1 : Initialize an empty vector pronic to store all the Pronic Numbers.

step 2 : Initialize a variable i = 0.

step 3 : Generate Pronic Numbers using the formula:

step 4 : Pronic Number = i × (i + 1)

step 5 : While the generated Pronic Number is less than or equal to n:

step 6 : Add the Pronic Number to the vector.
Increment i by 1.
Stop the loop when i × (i + 1) becomes greater than n.
Return the vector containing all the Pronic Numbers.
*/