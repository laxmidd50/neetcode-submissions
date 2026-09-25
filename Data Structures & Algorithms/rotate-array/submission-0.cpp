class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = k % nums.size();
        if (n == 0)
            return;

        vector<int> nums2 = nums;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = (i + n) % nums.size();
            nums[j] = nums2[i];
        }
    }
};