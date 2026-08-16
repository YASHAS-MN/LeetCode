class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currentStr = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Build multi-digit multiplier
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                // Save current state onto stacks
                countStack.push(currentNum);
                stringStack.push(currentStr);

                // Reset for the new inner context
                currentNum = 0;
                currentStr = "";
            } else if (c == ']') {
                // Retrieve multiplier and previous string
                int repeatCount = countStack.top();
                countStack.pop();

                string prevStr = stringStack.top();
                stringStack.pop();

                // Expand current string repeatCount times
                string expanded = "";
                for (int i = 0; i < repeatCount; i++) {
                    expanded += currentStr;
                }

                // Append expanded inner string to previous outer string
                currentStr = prevStr + expanded;
            } else {
                // Regular character
                currentStr += c;
            }
        }

        return currentStr;
    }
};