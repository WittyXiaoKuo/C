class Solution {
public:
    string reverseOnlyLetters(string s) {
        if (s.empty())
            return s;
        int n1 = 0, n2 = s.size() - 1;
        while (n1 < n2)
        {
            while (n1 < n2 && !isalpha(s[n1]))
                n1++;
            while (n1 < n2 && !isalpha(s[n2]))
                n2--;
            swap(s[n1++], s[n2--]);
        }
        return s;
    }
};