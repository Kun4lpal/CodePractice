
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of 
// last word in the string.

// If the last word does not exist, return 0.

// Note: A word is defined as a character sequence consists of non-space characters only.

int lengthOfLastWord(string s) {
    int count = 0, tail = s.size() - 1;
    while (tail >= 0 && s[tail] == ' ') --tail;
    while (tail >= 0 && s[tail] != ' ')
    {
            --tail;
            ++count;
    }
    return count;
}