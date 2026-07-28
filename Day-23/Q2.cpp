// Topic : 2D Matrix

/*
Question :

Given an n × m matrix, return its elements in reverse spiral order.

Note: Reverse spiral order starts from the center of the matrix (or the closest valid center for even dimensions) and moves outward in a spiral.

Examples :

Input: n = 3, m = 3

Output: [5, 6, 3, 2, 1, 4, 7, 8, 9]
Explanation: Spiral form of the matrix in reverse order starts from the centre and goes outward.

Input: n = 4, m = 4

Output: [10, 11, 7, 6, 5, 9, 13, 14, 15, 16, 12, 8, 4, 3, 2, 1]
Explanation:

Constraints:
1 ≤ n, m ≤ 500
1 ≤ mat[i][j] ≤ 500
*/

// solution

class Solution
{
public:
    vector<int> reverseSpiral(vector<vector<int>> &mat)
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

        reverse(ans.begin(), ans.end());

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

step 2 : Traverse the matrix in normal spiral order:

step 3 : Traverse the Top Row from left to right.

step 4: Traverse the Right Column from top to bottom.

step 5 : Traverse the Bottom Row from right to left (only if Br > Tr and Rc > Lc).

step 6 : Traverse the Left Column from bottom to top (only if Br > Tr and Rc > Lc).
After completing one layer, move all four boundaries inward:
Tr++
Br--
Lc++
Rc--
Repeat Steps 2–3 until all the elements have been traversed.

Since reverse spiral order is simply the reverse of the normal spiral traversal, reverse the obtained spiral array using:

reverse(ans.begin(), ans.end());
Return the reversed array as the final answer.
*/

