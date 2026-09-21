class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int x: nums)
        {
            m_map[x]++;
        }

        int num2;
        for (int i = 0; i < nums.size(); i++)
        {
            num2 = target - nums[i];
            int totalNum2 = 1;
            if (num2 == nums[i])
                totalNum2 = 2;

            if (m_map[num2] >= totalNum2)
            {
                for (int j = i+1; j < nums.size(); j++)
                {
                    if (nums[j] == num2)
                    {
                        ret.push_back(i);
                        ret.push_back(j);
                        return ret;
                    }
                }
                return ret;
            }
        }
        return ret;
    }
private:
    std::unordered_map<int, int> m_map;
};
