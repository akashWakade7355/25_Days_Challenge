// Topic : Loops 

/*
Question :
Given a positive integer n, count the number of ways to represent n as the sum of four positive integers.

In each representation: a + b + c + d = n
where: a > 0, b > 0, c > 0, d > 0
Return the total number of such representations.

Examples:

Input: n = 5
Output: 1
Explanation: The only possible representation is: 1 + 1 + 1 + 2 = 5. Therefore, the answer is 1.

Input: n = 41
Output: 511
Explanation: There are 511 different ways to represent 41 as the sum of four positive integers. Therefore, the answer is 511.

Constraints:
0 ≤ n ≤ 100
*/

// solution :

class Solution {
  public:
    int countWays(int n) {
        // code here
        
        int count=0;
        
        for(int i=1;i<n;i++){
            for(int j =i;j<n;j++){
                for(int k =j;k<n;k++){
                    int a=i;
                    int b=j;
                    int c=k;
                    int d = n-(a+b+c);
                    
                    if(c <=d && d >0)
                      count++;
                }
            }
        }
        
        return count;
    }
    
};

// tc: 0(n^3)

// sc : 0(1)

/*
Approach:

step 1 : Initialize a variable count = 0 to store the total number of valid representations.

step 2 : Iterate over the first three numbers a, b, and c using three nested loops:

step 3 : Start a from 1 since all numbers must be positive.

step 4 : Start b from a to ensure a ≤ b.
Start c from b to ensure b ≤ c.
Compute the fourth number using:
d = n - (a + b + c)

step 5 : Check whether the representation is valid:
d must be positive (d > 0).
d must be greater than or equal to c (c ≤ d) to maintain the order a ≤ b ≤ c ≤ d.

step 6 : If both conditions are satisfied, increment count.
After all iterations are complete, return count.
*/