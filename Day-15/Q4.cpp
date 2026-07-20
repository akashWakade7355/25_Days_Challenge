// Topic : Strings

/*
Question :
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 
Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
*/

// solution :

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i=0;
        int j=n-1;

        while(j >= i){
             char temp =s[i];
             s[i]=s[j];
             s[j]=temp;
             i++;
             j--;
        }
    }
};

/*
# Approach

### Step 1:
Initialize two pointers:
- `i = 0` (points to the first character)
- `j = n - 1` (points to the last character)

### Step 2:
Traverse the array while `i < j`.

### Step 3:
Swap the characters at indices `i` and `j`.

### Step 4:
Move both pointers towards the center:
- Increment `i`
- Decrement `j`

### Step 5:
Repeat Steps 3 and 4 until the two pointers meet or cross each other.

### Step 6:
Since the characters are swapped in-place, the input array itself becomes the reversed string.

# Time Complexity

- Each character is swapped at most once.

**Overall Time Complexity:** `O(n)`


# Space Complexity

- No extra data structure is used.
- The reversal is performed in-place using only a few variables.

**Overall Space Complexity:** `O(1)`
*/