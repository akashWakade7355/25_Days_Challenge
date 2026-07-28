// Topic : 2D Matrix

/*
Question :

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]

Constraints:

1 <= n <= 20
*/

// solution :

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int val = 1;

        int Lc = 0;
        int Rc = n - 1;
        int Tr = 0;
        int Br = n - 1;

        while (Tr <= Br && Lc <= Rc)
        {

            // Top Row
            for (int j = Lc; j <= Rc; j++)
                matrix[Tr][j] = val++;

            // Right Column
            if (Br > Tr)
                for (int i = Tr + 1; i <= Br; i++)
                    matrix[i][Rc] = val++;

            // Bottom Row
            if (Rc > Lc && Br > Tr)
                for (int j = Rc - 1; j >= Lc; j--)
                    matrix[Br][j] = val++;

            // Left Column
            if (Rc > Lc && Br > Tr)
                for (int i = Br - 1; i >= Tr + 1; i--)
                    matrix[i][Lc] = val++;

            Lc++;
            Rc--;
            Tr++;
            Br--;
        }

        return matrix;
    }
};

// TC:(n^2)

// SC:0(1)

/*
Approach:

step 1 : Create an n × n matrix initialized with 0 to store the spiral values.

step 2 Initialize four boundaries to represent the current layer of the matrix:
Tr → Top Row (0)
Br → Bottom Row (n - 1)
Lc → Left Column (0)
Rc → Right Column (n - 1)

step 3 : Initialize a variable val = 1 that stores the current number to be inserted into the matrix.

step 4 : Traverse the Top Row from Lc to Rc and fill each cell with val, incrementing val after every insertion.

step 5 : Traverse the Right Column from Tr + 1 to Br and fill the cells.

step 6 : Perform this traversal only if Br > Tr to avoid filling the same row twice.

step 7 : Traverse the Bottom Row from Rc - 1 to Lc and fill the cells.

step 8 : Perform this traversal only if Rc > Lc && Br > Tr to avoid duplicate traversal when only one row or one column remains.

step 9 : Traverse the Left Column from Br - 1 to Tr + 1 and fill the cells.
Perform this traversal only if Rc > Lc && Br > Tr to avoid duplicate traversal.
Move all four boundaries inward after completing one layer:
Tr++
Br--
Lc++
Rc--
Repeat Steps 4–8 until all cells of the matrix are filled.
Return the generated spiral matrix.
*/