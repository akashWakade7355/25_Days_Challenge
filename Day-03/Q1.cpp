// Topic : Hashmap

/*
Question :
Given a string s, determine whether its characters can be rearranged to form a palindrome.
 Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.

Examples

Input: s = "baba"
Output: true
Explanation: Can be rearranged to form a palindrome "abba"
Input: s = "geeksogeeks"
Output: true
Explanation: The characters of the string can be rearranged to form the palindrome "geeksoskeeg".
Input: s = "geeksforgeeks"
Output: false
Explanation: The given string can't be converted into a palindrome.

Constraints:
1 ≤ s.length ≤ 106
s consists of only lowercase English letters.

*/

// solution

class Solution
{
public:
    bool canFormPalindrome(string &s)
    {
        // code here
        int len = s.length();

        unordered_map<char, int> pal;

        for (int i = 0; i < len; i++)
            pal[s[i]]++;

        int oddCount = 0;
        for (auto i : pal)
            if (i.second % 2 != 0)
                oddCount++;

        if (oddCount <= 1)
            return true;
        else
            return false;
    }
};

// TC:0(n)

// SC:0(n)

/*
Approach:

1. Create a HashMap to store the frequency of each character
   present in the given string.

2. Traverse the string and update the frequency of every character
   in the HashMap.

3. Count how many characters have an odd frequency.
   - Traverse the HashMap and check the frequency of each character.
   - If a character appears an odd number of times,
     increment the odd count.

4. Check the value of the odd count.
   - A string can be rearranged into a palindrome only if
     at most one character has an odd frequency.
   - If the odd count is greater than 1, return false.
   - Otherwise, return true.

*/