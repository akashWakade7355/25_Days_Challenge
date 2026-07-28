// Topic : 2D Matrix

/*
Question :

Given a rectangular matrix mat[][] of size n x m, and return a 1D array containing all its elements in
spiral order.

Examples:

Input: mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]
Output: [1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]
Explanation: Applying same technique as shown above.

Input: mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]
Output: [32, 44, 27, 23, 62, 50, 28, 54]
Explanation: Applying same technique as shown above, output will be [32, 44, 27, 23, 62, 50, 28, 54].

Constraints:
1 ≤ n, m ≤1000
0 ≤ mat[i][j] ≤100
*/

// solution :

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        int Lc = 0;
        int Rc = m - 1;
        int Tr = 0;
        int Br = n - 1;

        vector<int> ans;

        while (Rc >= Lc && Br >= Tr)
        {

            for (int j = Lc; j <= Rc; j++)
                ans.push_back(mat[Tr][j]);

            if (Br > Tr)
                for (int i = Tr + 1; i <= Br; i++)
                    ans.push_back(mat[i][Rc]);

            if (Rc > Lc && Br > Tr)
                for (int j = Rc - 1; j >= Lc; j--)
                    ans.push_back(mat[Br][j]);

            if (Rc > Lc && Br > Tr)
                for (int i = Br - 1; i >= Tr + 1; i--)
                    ans.push_back(mat[i][Lc]);

            Lc++;
            Rc--;
            Tr++;
            Br--;
        }

        return ans;
    }
};

// TC:0(N*M)

//SC:0(1)

/*
Approach:


step 1 : Initialize four boundaries to represent the current layer of the matrix:
Tr → Top Row (0)
Br → Bottom Row (n - 1)
Lc → Left Column (0)
Rc → Right Column (m - 1)

step 2 : Traverse the Top Row from Lc to Rc and add all elements to the answer.

step 3 : Traverse the Right Column from Tr + 1 to Br and add all elements.

step 4 : Perform this traversal only if Br > Tr to avoid traversing the same row twice.

step 5 : Traverse the Bottom Row from Rc - 1 to Lc and add all elements.

step 6 : Perform this traversal only if Rc > Lc && Br > Tr to avoid duplicate traversal when only one row or one column remains.

step 7 : Traverse the Left Column from Br - 1 to Tr + 1 and add all elements.
Perform this traversal only if Rc > Lc && Br > Tr to avoid duplicate traversal.
Move the boundaries inward after completing one layer:
Tr++
Br--
Lc++
Rc--
Repeat Steps 2–6 until all layers of the matrix have been traversed.
*/

