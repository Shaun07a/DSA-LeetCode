class Solution {
public:
    bool check(int left, int right, string &s) {
        if (left >= right)
            return true;

        if (s[left] != s[right])
            return false;

        return check(left + 1, right - 1, s);
    }

    bool isPalindrome(string s) {
        string str = "";

        for (char c : s) {
            if (isalnum(c))
                str += tolower(c);
        }

        return check(0, str.size() - 1, str);
    }
};