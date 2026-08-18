class Solution {
public:
    string reverseWords(string s) {
    int n = s.length();
    int right = 0;
    int i = 0;

    // --- PHASE 1: Clean spaces and shift words to the front ---
    while (i < n) {
        while (i < n && s[i] == ' ') i++; // 1. Skip spaces
        if (i >= n) break;

        if (right > 0) s[right++] = ' ';  // 2. Put a single space before next word

        while (i < n && s[i] != ' ') {    // 3. Copy the word
            s[right++] = s[i++];
        }
    }
    s.resize(right);                      // 4. Cut off the trailing garbage

    // --- PHASE 2: Flip the entire string backwards ---
    reverse(s.begin(), s.end());

    // --- PHASE 3: Flip each word back to normal ---
    int start = 0;
    for (int end = 0; end <= s.length(); end++) {
        if (end == s.length() || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }

    return s;
}
};