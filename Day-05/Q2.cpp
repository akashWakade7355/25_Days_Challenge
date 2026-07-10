// Topic : 2D Matrix 

/*
Question :
Given a 2D square matrix mat[][] of size n x n, rotate it by 180 degrees without using extra space.

Note: You must rotate the matrix in place and modify the input matrix directly.

Examples:

Input:  mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: [[9, 8, 7], [6, 5, 4], [3, 2, 1]]
Explanation:

The output matrix is the input matrix rotated by 180 degress.
 

Input: mat[][] = [[1, 2], [3, 4]]
Output: [[4, 3], [2, 1]]
Explanation : The output matrix is the input matrix rotated by 180 degrees.

Constraints:
1 ≤ n ≤ 500
0 ≤ mat[i][j] ≤ 104
*/

// solution :

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        
           int n=mat.size();
                
           for(int i=0;i<mat.size();i++)
              for(int j=0;j<mat[0].size();j++)
                 if(i>j){
                     int temp=mat[i][j];
                     mat[i][j]=mat[j][i];
                     mat[j][i]=temp;
                 }
        
        for(int i=0;i<mat.size();i++)
           for(int j=0;j<mat[0].size();j++)
               if(i+j<n-1)
                  swap(mat[i][j],mat[n-1-j][n-1-i]);
               
             
    }
};

// TC: 0(N^2)

// SC: 0(1)

/*
Apprach :

Step 1: Transpose the matrix

Convert the given matrix into its transpose by swapping mat[i][j] with mat[j][i] for all i > j.
Swapping only one half of the matrix ensures that every pair of elements is swapped exactly once.

Step 2: Swap elements about the secondary diagonal

Traverse the matrix and swap each element mat[i][j] with its corresponding element across the secondary diagonal, i.e., mat[n-1-j][n-1-i].
Perform the swap only when i + j < n - 1 so that each pair is swapped only once.
After transposing and swapping across the secondary diagonal, the matrix becomes rotated by 180°.
*/