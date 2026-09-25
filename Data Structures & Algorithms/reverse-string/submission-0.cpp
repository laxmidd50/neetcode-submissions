class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0)
            return;
        for (int i = 0, j = s.size()-1; i < j; i++, j--)
        {
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};