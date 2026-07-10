// Topic : 2 D Matrix 

/*
Question :

Given a matrix of size n x m, reverse the order of its columns in-place so that the last column becomes the first, the second-last becomes the second, and so on.

Examples:

Input: n = 4, m = 3, matrix[][] = [[1, 2, 3], [5, 6, 7], [11, 10, 9], [13, 14, 15]]
Output: [[3, 2, 1], [7, 6, 5], [9, 10, 11], [15, 14, 13]]
Explanation: Array after exchanging columns:
              [[3, 2, 1],
               [7, 6, 5],
               [9, 10, 11],
               [15, 14, 13]]
Input: n = 2, m = 5, matrix[][] = [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]]
Output: [[5, 4, 3, 2, 1], [10, 9, 8, 7, 6]]
Explanation: After reversing the column of matrix
                [[5, 4, 3, 2, 1]
                 [10, 9, 8, 7, 6]]

Constraints:
1 ≤ n, m ≤ 100
0 ≤ matrix[i][j] ≤ 1000
*/

// solution :

class Solution {
  public:

    void reverseCol(vector<vector<int> > &matrix) {
        // code here
        int n = matrix[0].size();
        int start =0;
        int end=n-1;
        
        while(end > start){
            
            for(int i=0;i<matrix.size();i++)
                 swap(matrix[i][start],matrix[i][end]);
        
            start++;
            end--;
        }
    }
};

// TC: 0(N*M)

// SC:0(1)

/*
Apprach :

 Step 1: Initialize two pointers:

start = 0 (first column)
end = m - 1 (last column), where m is the number of columns.

Step 2: While start < end:

Traverse all the rows.
For each row, swap the elements at the start and end columns, i.e., swap matrix[i][start] with matrix[i][end].
After swapping an entire pair of columns, increment start and decrement end.

Step 3: Continue this process until start >= end.

This reverses the order of the columns in-place, making the last column the first, the second-last column the second, and so on, without using any extra space.
*/