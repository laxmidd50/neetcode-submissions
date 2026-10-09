class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int num: nums)
        {
            if (hashset.contains(num))
                hashset.erase(num);
            else
                hashset.insert(num);
        }

        for (auto it = hashset.begin(); it != hashset.end(); it++)
        {
            return *it;
        }
        return -1;
    }
};
