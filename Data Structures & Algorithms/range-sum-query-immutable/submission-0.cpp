class NumArray {
public:
    NumArray(vector<int>& nums) {
        m_nums = nums;
    }
    
    int sumRange(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            count += m_nums[i];
        }
        return count;
    }
private:
    vector<int> m_nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */