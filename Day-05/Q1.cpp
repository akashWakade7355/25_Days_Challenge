// Topic : 2D Matrix

/*
Question :

Given a square matrix mat[][] of size n x n. The task is to rotate it by 
90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[0, 1, 2], 
                [3, 4, 5], 
                [6, 7, 8]] 
Output: [[2, 5, 8],
        [1, 4, 7],
        [0, 3, 6]]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: [[2, 4],
        [1, 3]]

Constraints:
1 ≤ n ≤ 102
0 ≤ mat[i][j] ≤ 103

*/

// solution 

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(j>i){
                    int temp=mat[i][j];
                     mat[i][j]=mat[j][i];
                     mat[j][i]=temp;
                }
          int n=mat.size();      
          int top=0;
          int bottom=n-1;
          
          while(bottom > top){
              swap(mat[top],mat[bottom]);
              top++;
              bottom--;
          }               
            
               
    }
};

//TC:0(n^2)

// SC:0(1)

/*
Apprach :

Step 1: Transpose the matrix

Convert the given matrix into its transpose by swapping mat[i][j] with mat[j][i] for all j > i.
Swapping only the elements above the main diagonal ensures that each pair is swapped exactly once.

Step 2: Reverse the rows

Initialize two pointers:
top = 0 (first row)
bottom = n - 1 (last row)
Swap the entire top row with the bottom row.
Increment top and decrement bottom.
Continue this process until top >= bottom.

After transposing and reversing the rows, the matrix is rotated 90° in the anti-clockwise direction without using any extra space. it till top == bottom . 


*/

