// Topic : String

/*
Question :
Given a string s, reverse the string without reversing its individual words. Words are separated by dots(.).

Note: The string may contain leading or trailing dots(.) or multiple dots(.) between two words.
The returned string should only have a single dot(.) separating the words, and no extra dots should be included.

Examples :

Input: s = "i.like.this.program.very.much"
Output: "much.very.program.this.like.i"
Explanation: The words in the input string are reversed while maintaining the dots as separators, resulting in "much.very.program.this.like.i".

Input: s = "..geeks..for.geeks."
Output: "geeks.for.geeks"
Explanation: After removing extra dots and reversing the whole string, the input string becomes "geeks.for.geeks".

Input: s = "..home....."
Output: "home"
Explanation: The input string contains only one word with extra dots around it. After removing the extra dots, the output is "home".

Constraints:
1 ≤ s.length() ≤ 106
String s contains only lowercase English alphabets and dots.
*/

// solution :

class Solution
{
public:
    string reverseWords(string &s)
    {
        // code here
        vector<string> words;

        string temp = "";

        for (char ch : s)
        {

            if (ch == '.')
            {
                if (temp.length() != 0)
                {
                    words.push_back(temp);
                    temp.clear();
                }
            }
            else
                temp += ch;
        }

        if (temp.length() != 0)
            words.push_back(temp);

        reverse(words.begin(), words.end());

        string ans = "";

        for (int i = 0; i < words.size(); i++)
        {
            if (i == words.size() - 1)
                ans += words[i];
            else
            {
                ans += words[i];
                ans += ".";
            }
        }
        return ans;
    }
};

/*
# Approach

### Step 1:
Create a vector `words` to store all the words from the string and a temporary string `temp` to build each word.

### Step 2:
Traverse the given string character by character.

- If the current character is **not** a dot (`.`), append it to `temp`.
- If the current character is a dot (`.`):
  - Check if `temp` is non-empty.
  - If it is, push `temp` into the vector and clear `temp`.
  - Ignore consecutive dots since `temp` will already be empty.

### Step 3:
After completing the traversal, check whether `temp` is non-empty. If it is, push it into the vector to store the last word.

### Step 4:
Reverse the vector of words using:

```cpp
reverse(words.begin(), words.end());
```

### Step 5:
Create an empty string `ans`.

Traverse the reversed vector:
- Append the current word to `ans`.
- If it is **not** the last word, append a single dot (`.`).

### Step 6:
Return the final string `ans`.

# Time Complexity

- Extracting all words: `O(n)`
- Reversing the vector: `O(m)` (where `m` is the number of words)
- Constructing the final string: `O(n)`

**Overall Time Complexity:** `O(n)`


# Space Complexity

- The vector stores all the extracted words.
- The answer string stores the final reversed string.

**Overall Space Complexity:** `O(n)`
*/