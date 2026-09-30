// Custom hash map
// act = cat = tac

// a = 1
// b = 2
// c = 3




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        vector<unordered_map<char, int>> char_maps;
        for (string str: strs)
        {
            unordered_map<char, int> str_map;
            for (char c: str)
            {
                str_map[c]++;
            }
            int idx = anagramIndex(str_map, char_maps);
            if (idx >= 0)
            {
                anagrams[idx].push_back(str);
            }
            else
            {
                anagrams.push_back({str});
                char_maps.push_back(str_map);
            }
        }
        return anagrams;
    }

private:
    // Returns index into anagrams and char_maps, or -1 if it doesn't exist
    int anagramIndex(unordered_map<char, int> & str_map,
                     vector<unordered_map<char, int>> & char_maps) {
        for (int i = 0; i < char_maps.size(); i++)
        {
            bool match = true;
            for (char x = 'a'; x <= 'z'; x++)
            {
                if (str_map[x] != char_maps[i][x])
                {
                    match = false;
                    break;
                }
            }
            if (match == true)
                return i;
        }
        return -1;
    }
};
