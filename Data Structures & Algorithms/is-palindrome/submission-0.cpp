class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j)
        {
            if (!std::isalnum(s[i]))
                i++;
            else if (!std::isalnum(s[j]))
                j--;
            else if (std::tolower(s[i]) != std::tolower(s[j]))
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
