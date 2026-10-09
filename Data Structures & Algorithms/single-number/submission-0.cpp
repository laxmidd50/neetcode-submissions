class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for (int num: nums)
        {
            hashmap[num]++;
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            if (it->second < 2)
                return it->first;
        }
        return -1;
    }
};
