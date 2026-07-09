// Tpoic : 2D matrix

/*

Question:
You are given two square matrices mat1[][] and mat2[][], each of size n × n. You have to multiply
these two matrices and return the resulting matrix.

Examples:

Input: mat1[][] = [[1, 1, 1], mat2[][] = [[1, 1, 1],
                 [1, 1, 1],             [1, 1, 1],
                 [1, 1, 1]]             [1, 1, 1]]
Output: [[3, 3, 3],
        [3, 3, 3],
        [3, 3, 3]]
Explanation: After multiplying mat1 and mat2 we get the resulting matrix equal to [[3, 3, 3], [3, 3, 3], [3, 3, 3]].
Input: mat1[][] = [[1, 2], mat2[][] = [[4, 3],
                 [3, 4]]             [2, 1]]
Output: [[8, 5],
       [20, 13]]
Explanation: After multiplying mat1 and mat2 we get the resulting matrix equal to [[8, 5], [20, 13]]

Constraints:
1 ≤ n ≤ 100
1 ≤ mat1[i][j], mat2[i][j] ≤ 100

*/

// solution

class Solution
{
public:
    vector<vector<int>> multiply(vector<vector<int>> &mat1,
                                 vector<vector<int>> &mat2)
    {

        int n = mat1.size();

        vector<vector<int>> result(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                for (int k = 0; k < n; k++)
                {

                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }

        return result;
    }
};

// TC:0(n^3)

// SC:0(n^2)

/*
Approach:
1. Create a result matrix of size n x n and initialize all elements to 0.
2. Traverse each row 'i' of the first matrix.
3. Traverse each column 'j' of the second matrix.
4. For every cell (i, j), calculate the sum of the products of
   corresponding elements from the i-th row of mat1 and the j-th
   column of mat2.

   result[i][j] += mat1[i][k] * mat2[k][j]

   where k varies from 0 to n-1.
5. Store the computed sum in result[i][j].
6. Return the resultant matrix.

*/