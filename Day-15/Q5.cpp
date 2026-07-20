// Topic : string

/*
Question :
Given a string s. Your task is to remove the vowels from the string.

Examples:

Input: s = "welcome to geeksforgeeks"
Output: "wlcm t gksfrgks"
Explanation: Vowels were ignored only consonents were returned in the same order.

Input: s = "what is your name ?"
Output: wht s yr nm ?

Constraints:
1 <= |s| <= 105
Alphabets are lower cases only
*/

// solution :

class Solution {
  public:
    string removeVowels(string& s) {
        // code here
        for(int i = 0; i < s.size(); i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {
                s.erase(i,1);
                i--;
            }
        return s;
    }
};

/*
# Approach

### Step 1:
Traverse the string from left to right using an index `i`.

### Step 2:
For each character, check whether it is a vowel (`a`, `e`, `i`, `o`, or `u`).

### Step 3:
If the current character is a vowel:
- Remove it from the string using `erase(i, 1)`.
- Decrement `i` by `1` so that the next character, which shifts to the current index after deletion, is not skipped.

### Step 4:
Continue traversing the string until all characters have been processed.

### Step 5:
Return the modified string after all vowels have been removed.

# Time Complexity

- Each call to `erase()` shifts the remaining characters of the string.
- In the worst case (when many characters are removed), each deletion takes `O(n)` time.

**Overall Time Complexity:** `O(n²)`

# Space Complexity

- The string is modified in-place.
- No extra data structure is used.

**Overall Space Complexity:** `O(1)`
*/