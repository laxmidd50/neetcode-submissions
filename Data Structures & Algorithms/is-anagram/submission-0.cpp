class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> map_s;
        std::map<char, int> map_t;
        for (const char& c : s)
        {
            map_s[c]++;
        }
        for (const char& c: t)
        {
            map_t[c]++;
        }

        if (map_s.size() != map_t.size())
        {
            return false;
        }

        for (const auto& x: map_s)
        {
            if (map_t[x.first] != x.second)
            {
                return false;
            }
        }
        return true;
    }
};
