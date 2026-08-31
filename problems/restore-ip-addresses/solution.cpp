class Solution {
public:
    vector<string> result;

    bool valid(string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;

        int num = stoi(s);

        return num <= 255;
    }

    void solve(string& s, int start, int parts, string current) {

        if (parts == 4) {
            if (start == s.size())
                result.push_back(current);

            return;
        }

        for (int end = start; end < s.size() && end < start + 3; end++) {

            string part = s.substr(start, end - start + 1);

            if (!valid(part))
                continue;

            if (parts == 0)
                solve(s, end + 1, parts + 1, part);
            else
                solve(s, end + 1, parts + 1, current + "." + part);
        }
    }

    vector<string> restoreIpAddresses(string s) {

        solve(s, 0, 0, "");

        return result;
    }
};