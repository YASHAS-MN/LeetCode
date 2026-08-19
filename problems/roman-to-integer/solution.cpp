class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r = 
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int t = 0;
        int n = s.length();

        for(int i=0; i<n; i++)
        {
            if(i < n-1 && r[s[i]] < r[s[i+1]])
            t -= r[s[i]];
            else
            t += r[s[i]];
        }
        return t;
    }
};