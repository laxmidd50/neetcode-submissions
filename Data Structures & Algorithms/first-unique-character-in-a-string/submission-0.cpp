class Solution {
public:
    int firstUniqChar(string s) {
        for (char c: s)
        {
            m_map[c]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (m_map[s[i]] == 1)
                return i;
        }
        return -1;
    }
private:
    std::unordered_map<char, int> m_map;
};