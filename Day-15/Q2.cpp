// Topic : Strings

/*
Question :

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.


Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

// solution :

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int n =s.length();
        int i = n - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        int count = 0;

        while (i >= 0 && s[i] != ' ')
        {
            count++;
            i--;
        }
        return count;
    }
};

/*
# Approach

step 1. Start traversing the string from the **last index**.
step 2. Skip all the trailing spaces (if any) by moving the pointer to the left.
step 3. Once the first non-space character is found, it marks the end of the last word.
step 4. Initialize a counter to `0`.
step 5. Continue moving left while the current character is **not** a space:
   - Increment the counter.
   - Move the pointer one position to the left.
step 6. As soon as a space (or the beginning of the string) is reached, stop and return the counter, which represents the length of the last word.

# Time Complexity

- Traversing the string from the end takes at most one pass.
- **Overall Time Complexity:** `O(n)`

where `n` is the length of the string.

# Space Complexity

- No extra data structures are used.
- Only a few variables (`i` and `count`) are maintained.

**Overall Space Complexity:** `O(1)`
*/